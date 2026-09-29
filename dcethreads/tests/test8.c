/*
 * test8: a cancel that cannot be delivered does not cut a wait short.
 *
 * With its own cancel implementation, dcethreads posts a cancel by
 * setting a pending flag and sending a wake-up signal that interrupts a
 * blocking wait.  Two cases must not make sleep(), poll() or select()
 * return early:
 *
 *   left-over - the cancel was posted while the thread ran with
 *               cancelability off and was then taken by
 *               pthread_testcancel(); the wake-up signal is still
 *               pending when the thread goes to sleep (the RPC server
 *               executor does exactly this: a forwarded cancel is
 *               flushed at the end of one call, and the manager of the
 *               next call sleeps)
 *   disabled  - the cancel is posted while the thread sleeps with
 *               cancelability off; it must stay pending and be
 *               delivered after the sleep
 *
 * Every wait is WAIT_MS long and must last at least MIN_MS.
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

#define WAIT_MS 1000
#define MIN_MS  900

enum how { H_SLEEP, H_POLL, H_SELECT };
enum when { W_LEFTOVER, W_DISABLED };

static const char *how_names[] = { "sleep", "poll", "select" };
static const char *when_names[] = { "left-over", "disabled" };

static volatile int ready;          /* the worker is ready for the cancel */
static volatile int posted;         /* main has posted the cancel */
static volatile long waited_ms;
static volatile int caught;

static double now(void)
{
    struct timeval tv;

    gettimeofday(&tv, NULL);
    return tv.tv_sec + tv.tv_usec / 1e6;
}

static void wait_once(enum how how)
{
    switch (how)
    {
    case H_SLEEP:
        sleep(WAIT_MS / 1000);
        break;

    case H_POLL:
        {
            struct pollfd pfd[1] = { { -1, 0, 0 } };

            poll(pfd, 1, WAIT_MS);
        }
        break;

    case H_SELECT:
        {
            struct timeval tv = { WAIT_MS / 1000, 0 };

            select(0, NULL, NULL, NULL, &tv);
        }
        break;
    }
}

static void *worker_leftover(void *arg)
{
    enum how how = (enum how) (long) arg;
    double end = now() + 3.0, t0;

    pthread_setcancel(CANCEL_OFF);
    ready = 1;
    while (!posted && now() < end)
    {
        ;                           /* busy, like a manager in a CPU loop */
    }
    pthread_setcancel(CANCEL_ON);
    TRY
    {
        pthread_testcancel();
    }
    CATCH (pthread_cancel_e)
    {
        caught = 1;
    }
    ENDTRY

    t0 = now();
    wait_once(how);
    waited_ms = (long) ((now() - t0) * 1000);
    return NULL;
}

static void *worker_disabled(void *arg)
{
    enum how how = (enum how) (long) arg;
    double t0;

    pthread_setcancel(CANCEL_OFF);
    ready = 1;
    t0 = now();
    wait_once(how);
    waited_ms = (long) ((now() - t0) * 1000);
    pthread_setcancel(CANCEL_ON);
    TRY
    {
        pthread_testcancel();
    }
    CATCH (pthread_cancel_e)
    {
        caught = 1;
    }
    ENDTRY
    return NULL;
}

static int run(enum when when, enum how how)
{
    pthread_t t;
    pthread_addr_t status;
    double end;
    int ok;

    ready = 0;
    posted = 0;
    waited_ms = -1;
    caught = 0;
    pthread_create(&t, &pthread_attr_default,
                   when == W_LEFTOVER ? worker_leftover : worker_disabled,
                   (pthread_addr_t) (long) how);

    end = now() + 3.0;
    while (!ready && now() < end)
    {
        usleep(1000);
    }
    usleep(200000);                 /* let the worker spin or block */
    pthread_cancel(t);
    posted = 1;

    pthread_join(t, &status);
    ok = caught && waited_ms >= MIN_MS;
    printf("%-9s %-6s: waited %4ld ms, cancel %s%s\n", when_names[when],
           how_names[how], waited_ms, caught ? "caught" : "lost",
           ok ? "" : "  <-- FAILED");
    return ok;
}

int main(void)
{
    int ok = 1;
    int how;

    setvbuf(stdout, NULL, _IONBF, 0);

    for (how = H_SLEEP; how <= H_SELECT; how++)
    {
        ok &= run(W_LEFTOVER, (enum how) how);
        ok &= run(W_DISABLED, (enum how) how);
    }

    return ok ? 0 : 1;
}
