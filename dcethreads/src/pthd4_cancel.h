/*
 * pthd4_cancel.h - internal interface of the DCE cancel implementation
 *
 * DCE threads expect a cancel to be delivered as the pthread_cancel_e
 * exception, which the thread may catch and then continue.  NPTL does
 * not allow that: once it has acted on a cancel, the thread stays
 * marked as canceled and exiting and ignores every further
 * pthread_cancel().  This module keeps the DCE cancel state per thread
 * so that dcethreads can post and deliver cancels itself.
 *
 * Mode selection (transition period): the environment variable
 * DCETHREADS_CANCEL=own selects the own implementation, anything else
 * keeps using NPTL cancellation.
 */

#ifndef PTHD4_CANCEL_H
#define PTHD4_CANCEL_H

#include <pthread.h>
#include <signal.h>

/*
 * Signal used to interrupt a thread that waits in a system call.  It is
 * kept blocked in DCE threads and only unblocked atomically while they
 * wait (ppoll/pselect), so a wake-up can never get lost.
 */
#ifndef PTHD4_WAKE_SIG
#define PTHD4_WAKE_SIG (SIGRTMAX - 2)
#endif

typedef struct pthd4_cancel_state
{
    pthread_mutex_t             lock;
    int                         pending;    /* a cancel has been posted */
    int                         general;    /* CANCEL_ON / CANCEL_OFF */
    int                         async;      /* CANCEL_ON / CANCEL_OFF */
    pthread_cond_t             *wait_cond;  /* cond the thread waits on */
    pthread_t                   thread;
    int                         listed;     /* in the registry */
    int                         dead;       /* thread has exited */
    int                         refs;       /* see pthd4__create() */
    struct pthd4_cancel_state  *next;
} pthd4_cancel_state_t;

/* Non-zero if DCETHREADS_CANCEL=own was set when the library started. */
extern int pthd4__own_cancel;

/* Initialize the module (idempotent). */
extern void pthd4__cancel_init(void);

/* Cancel state of the calling thread; attaches it on first use. */
extern pthd4_cancel_state_t *pthd4__cancel_self(void);

/*
 * pthread_create() replacement: the new thread gets its cancel state
 * before it runs the start routine.  Returns a pthread_create() status.
 */
extern int pthd4__create(pthread_t *thread, const pthread_attr_t *attr,
                         void *(*proc)(void *), void *arg);

/*
 * Post a cancel to a DCE thread and wake it up.  Returns 0, or -1 if
 * the thread has no cancel state (not a DCE thread, or already gone).
 */
extern int pthd4__cancel_post(pthread_t thread);

/* Deliver a pending cancel if cancelability is on (a cancellation point). */
extern void pthd4__check_cancel(void);

/*
 * Cancellation points that block: a condition wait (abstime may be NULL;
 * returns 0, ETIMEDOUT or another pthread error) and a join.  A cancel
 * is raised as pthread_cancel_e; for the condition wait the mutex is
 * held again at that point, as DCE threads specify.
 */
extern int pthd4__cond_wait(pthread_cond_t *cond, pthread_mutex_t *mutex,
                            const struct timespec *abstime);
extern int pthd4__join(pthread_t thread, void **status);

/*
 * Support for the system call wrappers (pthd4_libc_wrapers.c).
 *
 * pthd4__cancel_peek() returns the caller's state without attaching
 * the thread; threads that never used DCE threads keep plain behavior.
 * pthd4__cancel_point() is a cancellation point in either mode.
 * pthd4__take_cancel() returns non-zero (and clears it) if a cancel
 * must be delivered now.
 * pthd4__wait() is ppoll() with the wake-up signal unblocked; it returns
 * PTHD4_WAIT_CANCEL when a cancel must be delivered, so that the caller
 * can clean up first and then call pthd4__raise_cancel().
 * pthd4__select() is select() as a cancellation point.
 */
#include <poll.h>
#include <sys/select.h>

#define PTHD4_WAIT_CANCEL (-2)

extern pthd4_cancel_state_t *pthd4__cancel_peek(void);
extern void pthd4__cancel_point(void);
extern int pthd4__take_cancel(pthd4_cancel_state_t *s);
extern int pthd4__wait(pthd4_cancel_state_t *s, struct pollfd *fds,
                       nfds_t nfds, const struct timespec *timeout);
extern int pthd4__select(pthd4_cancel_state_t *s, int nfds, fd_set *readfds,
                         fd_set *writefds, fd_set *exceptfds,
                         struct timeval *timeout);

/* DCE semantics of setcancel/setasynccancel; return the previous value. */
extern int pthd4__setcancel(int state);
extern int pthd4__setasynccancel(int state);

/*
 * Raise pthread_cancel_e in the calling thread, or end the thread with
 * PTHREAD_CANCELED if it has no exception context (exc_handling.c).
 */
extern void pthd4__raise_cancel(void) __attribute__((__noreturn__));

#endif /* PTHD4_CANCEL_H */
