/*
 * test6: repeated cancels of the same thread.
 *
 * The RPC runtime cancels its long-lived threads (listener, receivers,
 * call executors) again and again and expects each cancel to show up
 * as a pthread_cancel_e exception that can be caught, after which the
 * thread goes on working.  For each kind of cancellation point below a
 * worker thread is canceled ROUNDS times and must catch every cancel:
 *
 *   testcancel  - busy loop calling pthread_testcancel()
 *   cond_wait   - blocked in pthread_cond_wait()
 *   select      - blocked in select()
 *   poll        - blocked in poll()
 *   reposted    - cancel posted while cancelability is off, delivered
 *                 by pthread_testcancel() after turning it on again
 */

#include "dce/dcethreads_conf.h"
#include <signal.h>
#include <stdlib.h>

#include <dce/pthread_exc.h>
#include <stdio.h>
#include <string.h>
#include <poll.h>
#include <sys/select.h>
#include <sys/time.h>
#include <unistd.h>

#define ROUNDS 3

enum mode { M_TESTCANCEL, M_COND_WAIT, M_SELECT, M_POLL, M_REPOSTED };

static const char *mode_names[] =
{
    "testcancel", "cond_wait", "select", "poll", "reposted"
};

static pthread_mutex_t mutex;
static pthread_cond_t cond;
static volatile int release;        /* frees a worker stuck in cond_wait */
static volatile int round_ready;    /* round the worker is waiting in */
static volatile int rounds_posted;  /* cancels posted by main */
static volatile int caught;

static double now(void)
{
    struct timeval tv;

    gettimeofday(&tv, NULL);
    return tv.tv_sec + tv.tv_usec / 1e6;
}

/*
 * Wait for cancel number "round" (at most 2 seconds) at the
 * cancellation point selected by the mode.
 */
static void wait_for_cancel(enum mode mode, int round)
{
    double end = now() + 2.0;

    switch (mode)
    {
    case M_TESTCANCEL:
        round_ready = round;
        while (now() < end)
        {
            pthread_testcancel();
        }
        break;

    case M_COND_WAIT:
        pthread_mutex_lock(&mutex);
        round_ready = round;
        while (!release)
        {
            pthread_cond_wait(&cond, &mutex);
        }
        pthread_mutex_unlock(&mutex);
        break;

    case M_SELECT:
        {
            struct timeval tv = { 2, 0 };

            round_ready = round;
            select(0, NULL, NULL, NULL, &tv);
        }
        break;

    case M_POLL:
        round_ready = round;
        poll(NULL, 0, 2000);
        break;

    case M_REPOSTED:
        pthread_setcancel(CANCEL_OFF);
        round_ready = round;
        while (rounds_posted < round && now() < end)
        {
            usleep(10000);
        }
        pthread_setcancel(CANCEL_ON);
        pthread_testcancel();
        break;
    }
}

static void *worker(void *arg)
{
    enum mode mode = (enum mode) (long) arg;
    volatile int i;     /* modified between the TRY's setjmp and a longjmp */

    for (i = 1; i <= ROUNDS; i++)
    {
        TRY
        {
            wait_for_cancel(mode, i);
        }
        CATCH (pthread_cancel_e)
        {
            caught++;
            if (mode == M_COND_WAIT)
            {
                /* the mutex is held again when the exception is raised */
                pthread_mutex_unlock(&mutex);
            }
        }
        ENDTRY
    }
    return NULL;
}

static int run(enum mode mode)
{
    pthread_t t;
    pthread_addr_t status;
    int i;

    caught = 0;
    release = 0;
    round_ready = 0;
    rounds_posted = 0;
    pthread_create(&t, &pthread_attr_default, worker, (pthread_addr_t) (long) mode);

    for (i = 1; i <= ROUNDS; i++)
    {
        double end = now() + 3.0;

        while (round_ready < i && now() < end)
        {
            usleep(10000);
        }
        usleep(100000);             /* let the worker block */
        pthread_cancel(t);
        rounds_posted = i;
    }

    usleep(300000);                 /* let the worker catch the last one */

    /* free a worker that missed a cancel and still waits */
    pthread_mutex_lock(&mutex);
    release = 1;
    pthread_cond_broadcast(&cond);
    pthread_mutex_unlock(&mutex);

    pthread_join(t, &status);
    printf("%-10s: caught %d of %d cancels%s\n", mode_names[mode], caught,
           ROUNDS, caught == ROUNDS ? "" : "  <-- FAILED");
    return caught == ROUNDS;
}

int main(void)
{
    int ok = 1;

    setvbuf(stdout, NULL, _IONBF, 0);
    pthread_mutex_init(&mutex, &pthread_mutexattr_default);
    pthread_cond_init(&cond, &pthread_condattr_default);

    ok &= run(M_TESTCANCEL);
    ok &= run(M_COND_WAIT);
    ok &= run(M_SELECT);
    ok &= run(M_POLL);
    ok &= run(M_REPOSTED);

    return ok ? 0 : 1;
}
