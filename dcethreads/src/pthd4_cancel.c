/*
 * pthd4_cancel.c - DCE thread cancel state
 *
 * Every DCE thread gets a pthd4_cancel_state_t.  It is reachable from
 * the thread itself through a thread-specific data key and from other
 * threads through a registry, so that a cancel can be posted to a
 * thread by its pthread_t.
 *
 * Threads created with pthd4_create() get their state before their
 * start routine runs; other threads (the main thread, threads created
 * directly with pthread_create()) get it on first use.
 *
 * Lifetime: the state is freed when its reference count drops to zero.
 * A state created by pthd4__create() starts with two references, one
 * for the creator (dropped after it has registered the new thread) and
 * one for the thread (dropped by the key destructor at thread exit), so
 * neither side can use freed memory whichever finishes first.  All
 * registry and reference count updates are done under registry_lock.
 */

#include <dce/dcethreads_conf.h>

#include <errno.h>
#include <pthread.h>
#include <signal.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <poll.h>
#include <sys/select.h>

#include <dce/pthread_dce_common.h>
#include "pthd4_cancel.h"

int pthd4__own_cancel = 0;

static int                   wake_sig;      /* set by cancel_init_once() */
static pthread_once_t        cancel_once = PTHREAD_ONCE_INIT;
static pthread_key_t         state_key;
static pthread_mutex_t       registry_lock = PTHREAD_MUTEX_INITIALIZER;
static pthd4_cancel_state_t *registry = NULL;

typedef struct
{
    void                 *(*proc)(void *);
    void                 *arg;
    pthd4_cancel_state_t *state;
} pthd4_start_t;

/*
 * The wake-up signal only has to interrupt a blocking system call.  It is
 * unblocked only while a thread waits in pthd4__wait() or pthd4__select(),
 * and the handler notes for them that it was this signal that ended the
 * wait (static TLS, so it can be used in a signal handler).
 */
static __thread volatile sig_atomic_t woken
    __attribute__((__tls_model__("initial-exec")));

static void
wake_handler(int sig __attribute__((__unused__)))
{
    woken = 1;
}

/* Drop one reference; the caller holds registry_lock. */
static void
state_release(pthd4_cancel_state_t *s)
{
    if (--s->refs == 0)
    {
        pthread_mutex_destroy(&s->lock);
        free(s);
    }
}

/* Put the state into the registry; the caller holds registry_lock. */
static void
state_list(pthd4_cancel_state_t *s, pthread_t thread)
{
    if (!s->listed && !s->dead)
    {
        s->thread = thread;
        s->next = registry;
        registry = s;
        s->listed = 1;
    }
}

/* Key destructor: the thread exits. */
static void
state_destructor(void *arg)
{
    pthd4_cancel_state_t  *s = arg;
    pthd4_cancel_state_t **pp;

    pthread_mutex_lock(&registry_lock);
    if (s->listed)
    {
        for (pp = &registry; *pp != NULL; pp = &(*pp)->next)
        {
            if (*pp == s)
            {
                *pp = s->next;
                break;
            }
        }
        s->listed = 0;
    }
    s->dead = 1;
    state_release(s);
    pthread_mutex_unlock(&registry_lock);
}

/* In the child of fork() only the forking thread exists. */
static void
atfork_prepare(void)
{
    pthread_mutex_lock(&registry_lock);
}

static void
atfork_parent(void)
{
    pthread_mutex_unlock(&registry_lock);
}

static void
atfork_child(void)
{
    pthd4_cancel_state_t *self = pthread_getspecific(state_key);

    pthread_mutex_init(&registry_lock, NULL);
    registry = NULL;
    if (self != NULL)
    {
        self->listed = 0;
        state_list(self, pthread_self());
    }
}

static void
cancel_init_once(void)
{
    const char       *mode = getenv("DCETHREADS_CANCEL");
    const char       *sig = getenv("DCETHREADS_WAKE_SIG");
    struct sigaction  sa;

    pthd4__own_cancel = !(mode != NULL && strcmp(mode, "nptl") == 0);

    /* a real-time signal number; anything else keeps the default */
    wake_sig = PTHD4_WAKE_SIG;
    if (sig != NULL && *sig != '\0')
    {
        char *end;
        long  n = strtol(sig, &end, 10);

        if (*end == '\0' && n >= SIGRTMIN && n <= SIGRTMAX)
            wake_sig = (int)n;
    }

    pthread_key_create(&state_key, state_destructor);

    memset(&sa, 0, sizeof(sa));
    sa.sa_handler = wake_handler;
    sigemptyset(&sa.sa_mask);
    sa.sa_flags = 0;                /* no SA_RESTART: interrupt the call */
    sigaction(wake_sig, &sa, NULL);

    pthread_atfork(atfork_prepare, atfork_parent, atfork_child);
}

void
pthd4__cancel_init(void)
{
    pthread_once(&cancel_once, cancel_init_once);
}

static pthd4_cancel_state_t *
state_new(int refs)
{
    pthd4_cancel_state_t *s = calloc(1, sizeof(*s));

    if (s != NULL)
    {
        pthread_mutex_init(&s->lock, NULL);
        s->general = CANCEL_ON;
        s->async = CANCEL_OFF;
        s->refs = refs;
    }
    return s;
}

/* Make the calling thread the owner of s. */
static void
state_attach(pthd4_cancel_state_t *s)
{
    sigset_t set;

    pthread_setspecific(state_key, s);

    pthread_mutex_lock(&registry_lock);
    state_list(s, pthread_self());
    pthread_mutex_unlock(&registry_lock);

    sigemptyset(&set);
    sigaddset(&set, wake_sig);
    pthread_sigmask(SIG_BLOCK, &set, NULL);

    if (pthd4__own_cancel)
    {
        /* NPTL must never start its own cancel unwinding. */
        pthread_setcancelstate(PTHREAD_CANCEL_DISABLE, NULL);
    }
}

pthd4_cancel_state_t *
pthd4__cancel_self(void)
{
    pthd4_cancel_state_t *s;

    pthd4__cancel_init();
    s = pthread_getspecific(state_key);
    if (s == NULL)
    {
        s = state_new(1);
        if (s != NULL)
        {
            state_attach(s);
        }
    }
    return s;
}

static void *
start_trampoline(void *arg)
{
    pthd4_start_t start = *(pthd4_start_t *) arg;

    free(arg);
    state_attach(start.state);
    return start.proc(start.arg);
}

int
pthd4__create(pthread_t *thread, const pthread_attr_t *attr,
              void *(*proc)(void *), void *arg)
{
    pthd4_start_t        *start;
    pthd4_cancel_state_t *state;
    int                   istat;

    pthd4__cancel_init();

    start = malloc(sizeof(*start));
    state = state_new(2);
    if (start == NULL || state == NULL)
    {
        free(start);
        if (state != NULL)
        {
            pthread_mutex_destroy(&state->lock);
            free(state);
        }
        return EAGAIN;
    }
    start->proc = proc;
    start->arg = arg;
    start->state = state;

    istat = pthread_create(thread, attr, start_trampoline, start);
    if (istat != 0)
    {
        pthread_mutex_destroy(&state->lock);
        free(state);
        free(start);
        return istat;
    }

    /*
     * Register the thread here as well, so that a cancel posted right
     * after pthd4_create() returns finds it even if the new thread has
     * not run yet.  "start" belongs to the new thread by now.
     */
    pthread_mutex_lock(&registry_lock);
    state_list(state, *thread);
    state_release(state);
    pthread_mutex_unlock(&registry_lock);
    return 0;
}

int
pthd4__cancel_post(pthread_t thread)
{
    pthd4_cancel_state_t *s;

    pthd4__cancel_init();
    if (pthread_equal(thread, pthread_self()))
    {
        pthd4__cancel_self();       /* make sure the caller is attached */
    }

    pthread_mutex_lock(&registry_lock);
    for (s = registry; s != NULL; s = s->next)
    {
        if (pthread_equal(s->thread, thread))
        {
            break;
        }
    }
    if (s == NULL)
    {
        pthread_mutex_unlock(&registry_lock);
        return -1;
    }

    pthread_mutex_lock(&s->lock);
    s->pending = 1;
    if (s->wait_cond != NULL)
    {
        pthread_cond_broadcast(s->wait_cond);
    }
    pthread_mutex_unlock(&s->lock);

    if (!pthread_equal(thread, pthread_self()))
    {
        pthread_kill(thread, wake_sig);
    }
    pthread_mutex_unlock(&registry_lock);
    return 0;
}

void
pthd4__check_cancel(void)
{
    pthd4_cancel_state_t *s = pthd4__cancel_self();
    int                   deliver;

    if (s == NULL)
    {
        return;
    }

    pthread_mutex_lock(&s->lock);
    deliver = s->pending && s->general == CANCEL_ON;
    if (deliver)
    {
        s->pending = 0;
    }
    pthread_mutex_unlock(&s->lock);

    if (deliver)
    {
        pthd4__raise_cancel();
    }
}

int
pthd4__setcancel(int state)
{
    pthd4_cancel_state_t *s = pthd4__cancel_self();
    int                   old;

    if (s == NULL)
    {
        errno = ENOMEM;
        return -1;
    }
    pthread_mutex_lock(&s->lock);
    old = s->general;
    s->general = (state == CANCEL_OFF) ? CANCEL_OFF : CANCEL_ON;
    pthread_mutex_unlock(&s->lock);
    return old;
}

/*
 * Asynchronous delivery is not implemented: the flag is kept, and a
 * pending cancel is delivered at the next cancellation point.  The RPC
 * runtime only uses it where select() is not a cancellation point.
 */
int
pthd4__setasynccancel(int state)
{
    pthd4_cancel_state_t *s = pthd4__cancel_self();
    int                   old;

    if (s == NULL)
    {
        errno = ENOMEM;
        return -1;
    }
    pthread_mutex_lock(&s->lock);
    old = s->async;
    s->async = (state == CANCEL_ON) ? CANCEL_ON : CANCEL_OFF;
    pthread_mutex_unlock(&s->lock);
    return old;
}

/* Take a pending cancel if it can be delivered now. */
static int
take_cancel(pthd4_cancel_state_t *s)
{
    int deliver;

    pthread_mutex_lock(&s->lock);
    deliver = s->pending && s->general == CANCEL_ON;
    if (deliver)
    {
        s->pending = 0;
    }
    pthread_mutex_unlock(&s->lock);
    return deliver;
}

static int
timespec_before(const struct timespec *a, const struct timespec *b)
{
    return a->tv_sec < b->tv_sec
        || (a->tv_sec == b->tv_sec && a->tv_nsec < b->tv_nsec);
}

/* Absolute CLOCK_REALTIME time one wait slice from now. */
static void
slice_end(struct timespec *ts)
{
    clock_gettime(CLOCK_REALTIME, ts);
    ts->tv_sec += 1;
}

int
pthd4__cond_wait(pthread_cond_t *cond, pthread_mutex_t *mutex,
                 const struct timespec *abstime)
{
    pthd4_cancel_state_t *s = pthd4__cancel_self();
    struct timespec       end;
    int                   r;

    if (s == NULL)
    {
        return abstime ? pthread_cond_timedwait(cond, mutex, abstime)
                       : pthread_cond_wait(cond, mutex);
    }

    for (;;)
    {
        pthread_mutex_lock(&s->lock);
        if (s->pending && s->general == CANCEL_ON)
        {
            s->pending = 0;
            pthread_mutex_unlock(&s->lock);
            pthd4__raise_cancel();      /* with the mutex held, as in DCE */
        }
        s->wait_cond = cond;
        pthread_mutex_unlock(&s->lock);

        slice_end(&end);
        if (abstime != NULL && timespec_before(abstime, &end))
        {
            end = *abstime;
        }
        r = pthread_cond_timedwait(cond, mutex, &end);

        pthread_mutex_lock(&s->lock);
        s->wait_cond = NULL;
        pthread_mutex_unlock(&s->lock);
        if (take_cancel(s))
        {
            pthd4__raise_cancel();
        }

        if (r != ETIMEDOUT)
        {
            return r;
        }
        if (abstime == NULL)
        {
            /*
             * Only the slice has ended.  Do not wait again here: a
             * signal that raced with the slice timeout may have been
             * absorbed by this wait although it timed out, and the
             * caller would never see its predicate change.  Report a
             * spurious wakeup instead, so that the caller rechecks its
             * predicate and waits again.  (A timed wait goes on to its
             * own deadline: its callers often take any return as "time
             * is up", and a lost signal delays them at most until then.)
             */
            return 0;
        }
        if (!timespec_before(&end, abstime))
        {
            return ETIMEDOUT;
        }
        /* only the slice has ended: wait again */
    }
}

int
pthd4__join(pthread_t thread, void **status)
{
    pthd4_cancel_state_t *s = pthd4__cancel_self();
    struct timespec       end;
    int                   r;

    if (s == NULL)
    {
        return pthread_join(thread, status);
    }

    for (;;)
    {
        if (take_cancel(s))
        {
            pthd4__raise_cancel();
        }
        slice_end(&end);
        r = pthread_timedjoin_np(thread, status, &end);
        if (r != ETIMEDOUT)
        {
            return r;
        }
    }
}

pthd4_cancel_state_t *
pthd4__cancel_peek(void)
{
    pthd4__cancel_init();
    return pthread_getspecific(state_key);
}

void
pthd4__cancel_point(void)
{
    pthd4_cancel_state_t *s = pthd4__cancel_peek();

    if (pthd4__own_cancel && s != NULL)
    {
        if (take_cancel(s))
        {
            pthd4__raise_cancel();
        }
    }
    else
    {
        pthread_testcancel();
    }
}

int
pthd4__take_cancel(pthd4_cancel_state_t *s)
{
    return take_cancel(s);
}

/* Absolute CLOCK_MONOTONIC time rel from now. */
static void
deadline_after(struct timespec *end, const struct timespec *rel)
{
    clock_gettime(CLOCK_MONOTONIC, end);
    end->tv_sec += rel->tv_sec;
    end->tv_nsec += rel->tv_nsec;
    if (end->tv_nsec >= 1000000000L)
    {
        end->tv_sec++;
        end->tv_nsec -= 1000000000L;
    }
}

/* Time left until the CLOCK_MONOTONIC time end, zero if it has passed. */
static void
time_left(const struct timespec *end, struct timespec *left)
{
    struct timespec now;

    clock_gettime(CLOCK_MONOTONIC, &now);
    if (!timespec_before(&now, end))
    {
        left->tv_sec = 0;
        left->tv_nsec = 0;
        return;
    }
    left->tv_sec = end->tv_sec - now.tv_sec;
    left->tv_nsec = end->tv_nsec - now.tv_nsec;
    if (left->tv_nsec < 0)
    {
        left->tv_sec--;
        left->tv_nsec += 1000000000L;
    }
}

/*
 * pthd4__wait() and pthd4__select() wait with the wake-up signal
 * unblocked.  If that signal ends the wait but no cancel can be delivered
 * (the cancel is disabled, or the signal is left over from a cancel that
 * was already taken at another cancellation point, e.g. by
 * pthread_testcancel()), they wait again for the rest of the time: the
 * caller must not see an EINTR it did not cause.  (A left-over signal
 * made sleep() return at once, before a cancel that was on its way.)
 */
int
pthd4__wait(pthd4_cancel_state_t *s, struct pollfd *fds, nfds_t nfds,
            const struct timespec *timeout)
{
    struct timespec end, left;
    sigset_t        mask;
    int             r;

    if (timeout != NULL)
    {
        deadline_after(&end, timeout);
    }

    /* unblock the wake-up signal only while waiting */
    pthread_sigmask(SIG_SETMASK, NULL, &mask);
    sigdelset(&mask, wake_sig);

    for (;;)
    {
        if (take_cancel(s))
        {
            return PTHD4_WAIT_CANCEL;
        }
        if (timeout != NULL)
        {
            time_left(&end, &left);
        }
        woken = 0;
        r = ppoll(fds, nfds, timeout != NULL ? &left : NULL, &mask);
        if (!(r < 0 && errno == EINTR && woken))
        {
            break;
        }
    }

    if (r < 0 && errno == EINTR && take_cancel(s))
    {
        return PTHD4_WAIT_CANCEL;
    }
    return r;
}

int
pthd4__select(pthd4_cancel_state_t *s, int nfds, fd_set *readfds,
              fd_set *writefds, fd_set *exceptfds, struct timeval *timeout)
{
    struct timespec ts, end;
    sigset_t        mask;
    int             r;

    if (timeout != NULL)
    {
        ts.tv_sec = timeout->tv_sec;
        ts.tv_nsec = timeout->tv_usec * 1000;
        deadline_after(&end, &ts);
    }

    pthread_sigmask(SIG_SETMASK, NULL, &mask);
    sigdelset(&mask, wake_sig);

    for (;;)
    {
        if (take_cancel(s))
        {
            pthd4__raise_cancel();
        }
        if (timeout != NULL)
        {
            time_left(&end, &ts);
        }
        /* the sets are unchanged when pselect() fails */
        woken = 0;
        r = pselect(nfds, readfds, writefds, exceptfds,
                    timeout != NULL ? &ts : NULL, &mask);
        if (!(r < 0 && errno == EINTR && woken))
        {
            break;
        }
    }

    if (r < 0 && errno == EINTR && take_cancel(s))
    {
        pthd4__raise_cancel();
    }
    return r;
}
