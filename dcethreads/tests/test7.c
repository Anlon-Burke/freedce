/*
 * test7: no lost wakeups in pthread_cond_wait() at the end of a wait slice.
 *
 * With its own cancel implementation, dcethreads waits on a condition
 * variable in slices of one second, so that it can notice a cancel.  A
 * signal that arrives just when a slice times out must still wake the
 * waiter (or at least let it recheck its predicate); the RPC runtime
 * waits for a response exactly this way and a lost wakeup hangs the
 * call for good.
 *
 * PAIRS pairs of threads run for the given number of seconds (default
 * 60).  In every round the waiter notes the time and waits in
 * "while (!flag) pthread_cond_wait()"; its partner sets the flag and
 * signals one slice later plus a small offset, sweeping the offsets
 * around the slice boundary, and then waits up to 2.5 seconds for the
 * waiter to wake up.  A waiter that does not is counted as a lost
 * wakeup (and freed with another signal).
 */

#include "dce/dcethreads_conf.h"
#include <signal.h>
#include <stdlib.h>

#include <dce/pthread_exc.h>
#include <stdio.h>
#include <string.h>
#include <time.h>
#include <unistd.h>

#define PAIRS       8
#define SLICE_NS    1000000000L     /* wait slice of pthd4__cond_wait */
#define SPREAD_US   800             /* offsets from -SPREAD_US/2 to +SPREAD_US/2 */

typedef struct
{
    pthread_mutex_t mutex;
    pthread_cond_t  cond;
    int             flag;           /* the waiter's predicate */
    int             waiting;        /* the waiter is in its wait loop */
    int             stop;
    unsigned long   wakes;          /* rounds the waiter finished */
    struct timespec t0;             /* when the waiter began to wait */
    int             id;
    int             rounds;
    int             lost;
} pair_t;

static pair_t pairs[PAIRS];
static struct timespec deadline;

static void now(struct timespec *ts)
{
    clock_gettime(CLOCK_REALTIME, ts);
}

static long diff_us(const struct timespec *a, const struct timespec *b)
{
    return (a->tv_sec - b->tv_sec) * 1000000L + (a->tv_nsec - b->tv_nsec) / 1000;
}

static void add_ns(struct timespec *ts, long ns)
{
    ts->tv_nsec += ns;
    while (ts->tv_nsec >= 1000000000L)
    {
        ts->tv_nsec -= 1000000000L;
        ts->tv_sec++;
    }
    while (ts->tv_nsec < 0)
    {
        ts->tv_nsec += 1000000000L;
        ts->tv_sec--;
    }
}

static pthread_addr_t waiter(pthread_addr_t arg)
{
    pair_t *p = (pair_t *) arg;

    pthread_mutex_lock(&p->mutex);
    while (!p->stop)
    {
        now(&p->t0);
        p->waiting = 1;
        while (!p->flag)
        {
            pthread_cond_wait(&p->cond, &p->mutex);
        }
        p->flag = 0;
        p->waiting = 0;
        p->wakes++;
    }
    pthread_mutex_unlock(&p->mutex);
    return NULL;
}

static pthread_addr_t signaler(pthread_addr_t arg)
{
    pair_t *p = (pair_t *) arg;
    struct timespec t, target;
    unsigned long wakes;
    long offset_us;
    int i;

    for (;;)
    {
        /* wait until the waiter is in its wait loop */
        for (;;)
        {
            pthread_mutex_lock(&p->mutex);
            if (p->waiting && !p->flag)
            {
                target = p->t0;
                wakes = p->wakes;
                pthread_mutex_unlock(&p->mutex);
                break;
            }
            pthread_mutex_unlock(&p->mutex);
            usleep(100);
        }

        now(&t);
        if (diff_us(&t, &deadline) >= 0)
        {
            break;
        }

        /* signal one slice after the start of the wait, plus an offset */
        offset_us = (long) ((p->rounds * PAIRS + p->id) * 37 % SPREAD_US) - SPREAD_US / 2;
        add_ns(&target, SLICE_NS + offset_us * 1000L);
        clock_nanosleep(CLOCK_REALTIME, TIMER_ABSTIME, &target, NULL);

        pthread_mutex_lock(&p->mutex);
        p->flag = 1;
        pthread_cond_signal(&p->cond);
        pthread_mutex_unlock(&p->mutex);
        p->rounds++;

        /* the waiter must finish this round within 2.5 seconds */
        for (i = 0; i < 2500 && p->wakes == wakes; i++)
        {
            usleep(1000);
        }
        if (p->wakes == wakes)
        {
            p->lost++;
            printf("pair %d round %d: lost wakeup (signal at slice end %+ld us)\n",
                   p->id, p->rounds, offset_us);
            while (p->wakes == wakes)
            {
                pthread_mutex_lock(&p->mutex);
                pthread_cond_signal(&p->cond);
                pthread_mutex_unlock(&p->mutex);
                usleep(10000);
            }
        }
    }

    /* let the waiter leave its loop */
    pthread_mutex_lock(&p->mutex);
    p->stop = 1;
    p->flag = 1;
    pthread_cond_signal(&p->cond);
    pthread_mutex_unlock(&p->mutex);
    return NULL;
}

int main(int argc, char *argv[])
{
    pthread_t w[PAIRS], s[PAIRS];
    pthread_addr_t status;
    int secs = argc > 1 ? atoi(argv[1]) : 60;
    int i, rounds = 0, lost = 0;

    setvbuf(stdout, NULL, _IONBF, 0);
    now(&deadline);
    deadline.tv_sec += secs;

    for (i = 0; i < PAIRS; i++)
    {
        memset(&pairs[i], 0, sizeof pairs[i]);
        pairs[i].id = i;
        pthread_mutex_init(&pairs[i].mutex, &pthread_mutexattr_default);
        pthread_cond_init(&pairs[i].cond, &pthread_condattr_default);
        pthread_create(&w[i], &pthread_attr_default, waiter, (pthread_addr_t) &pairs[i]);
        pthread_create(&s[i], &pthread_attr_default, signaler, (pthread_addr_t) &pairs[i]);
    }
    for (i = 0; i < PAIRS; i++)
    {
        pthread_join(s[i], &status);
        pthread_join(w[i], &status);
        rounds += pairs[i].rounds;
        lost += pairs[i].lost;
    }

    printf("%d signals around the end of a wait slice, %d lost wakeups%s\n",
           rounds, lost, lost ? "  <-- FAILED" : "");
    return lost ? 1 : 0;
}
