/*
 * lt_cancel.c: cancel a call whose send is blocked by a stopped server.
 *
 * A thread sends an endless pipe to the server (lt_pipe_in).  Once data
 * flows, the server process is stopped (SIGSTOP), so the socket buffers
 * fill up and the client blocks in its send.  Then the thread is canceled
 * with a cancel timeout set: the call must give up after about that
 * timeout (neither early nor by waiting for the peer).  The server is continued
 * (SIGCONT), and a further call on the same binding must succeed.
 *
 * usage: lt_cancel -h host -e endpoint -p server_pid [options]
 *   -h host      server host
 *   -e endpoint  server endpoint (TCP port)
 *   -p pid       process id of the server (must be stoppable by this user)
 *   -c secs      cancel timeout of the calling thread (default 3)
 *   -w secs      give up waiting for the call after secs seconds (default 60)
 *
 * The exit status is 0 if the call ended between the cancel timeout minus
 * 0.5 seconds and the timeout plus 3 seconds and the further call
 * succeeded, else 1.  DCE RPC only (Linux).
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <signal.h>
#include <sys/types.h>
#include "lt_data.h"

#define STARTED_ELTS    16384   /* 64 KB: data flows */

/* options */
static const char   *host, *endpoint;
static long         server_pid;
static long         cancel_timeout = 3;
static long         watchdog = 60;

static handle_t     h;
static lt_key_t     key;

/* set by the worker, read by main */
static volatile unsigned long pulled;
static volatile int           returned;
static char                   result[256];

static void pipe_pull(lt_pipe_state_t state, idl_ulong_int *buf,
                      idl_ulong_int esize, idl_ulong_int *ecount)
{
    unsigned long done = pulled;
    idl_ulong_int i;

    (void) state;
    for (i = 0; i < esize; i++)
        buf[i] = lt_pipe_elt(&key, LT_REQ, (unsigned32) (done + i));
    pulled = done + esize;
    *ecount = esize;
}

static void pipe_alloc(lt_pipe_state_t state, idl_ulong_int bsize,
                       idl_ulong_int **buf, idl_ulong_int *bcount)
{
    static idl_ulong_int b[1024];

    (void) state;
    (void) bsize;
    *buf = b;
    *bcount = sizeof b;         /* bytes */
}

static void pipe_push(lt_pipe_state_t state, idl_ulong_int *buf,
                      idl_ulong_int ecount)
{
    (void) state;
    (void) buf;
    (void) ecount;
}

static void *worker(void *arg)
{
    lt_pipe_t  p;
    unsigned32 st;
    char       exc[160];

    (void) arg;
    rpc_mgmt_set_cancel_timeout((signed32) cancel_timeout, &st);
    if (st != rpc_s_ok)
    {
        snprintf(result, sizeof result, "rpc_mgmt_set_cancel_timeout failed (0x%lx)",
                 (unsigned long) st);
        returned = 1;
        return NULL;
    }

    p.pull = pipe_pull;
    p.push = pipe_push;
    p.alloc = pipe_alloc;
    p.state = NULL;

    lt_call_begin();
    LT_TRY
    {
        lt_pipe_in(h, &key, 0xffffffffUL, p);
        snprintf(result, sizeof result, "call returned normally");
    }
    LT_CATCH(exc)
        snprintf(result, sizeof result, "exception %s", exc);
    LT_ENDTRY
    lt_call_end();
    returned = 1;
    return NULL;
}

static void usage(void)
{
    fprintf(stderr, "usage: lt_cancel -h host -e endpoint -p server_pid "
                    "[-c cancel_timeout] [-w watchdog]\n");
    exit(2);
}

int main(int argc, char *argv[])
{
    pthread_t     t;
    double        t0, cancel_at, deadline, ended_at, elapsed;
    unsigned long before;
    char          exc[160];
    volatile int  rc;
    int           c;

    while ((c = lt_getopt(argc, argv, "h:e:p:c:w:")) != -1)
    {
        switch (c)
        {
            case 'h': host = lt_optarg; break;
            case 'e': endpoint = lt_optarg; break;
            case 'p': server_pid = atol(lt_optarg); break;
            case 'c': cancel_timeout = atol(lt_optarg); break;
            case 'w': watchdog = atol(lt_optarg); break;
            default: usage();
        }
    }
    if (host == NULL || endpoint == NULL || server_pid <= 0 || cancel_timeout <= 0)
        usage();

    if (lt_bind("ncacn_ip_tcp", host, endpoint, &h) != 0)
    {
        fprintf(stderr, "lt_cancel: cannot bind to %s[%s]\n", host, endpoint);
        return 2;
    }
    memset(&key, 0, sizeof key);
    lt_uhyper_set(&key.seed, 1);
    key.client = (unsigned32) lt_getpid();
    key.call = 1;

    if (pthread_create(&t, &pthread_attr_default, worker, NULL) != 0)
    {
        fprintf(stderr, "lt_cancel: cannot create the thread\n");
        return 2;
    }

    /* wait until data flows */
    t0 = lt_now();
    while (pulled < STARTED_ELTS && !returned)
    {
        if (lt_now() - t0 > 10)
        {
            fprintf(stderr, "lt_cancel: no data sent after 10 s\n");
            return 2;
        }
        lt_sleep_until(lt_now() + 0.01);
    }
    if (returned)
    {
        fprintf(stderr, "lt_cancel: the call ended early: %s\n", result);
        return 2;
    }

    /* stop the server: the socket buffers fill up and the send blocks */
    if (kill((pid_t) server_pid, SIGSTOP) != 0)
    {
        perror("lt_cancel: SIGSTOP");
        return 2;
    }
    lt_sleep_until(lt_now() + 1.5);
    before = pulled;
    lt_sleep_until(lt_now() + 0.5);
    printf("server stopped; %lu pipe elements pulled, send %s\n", pulled,
           pulled == before ? "blocked" : "still running");

    cancel_at = lt_now();
    pthread_cancel(t);
    deadline = cancel_at + watchdog;
    while (!returned && lt_now() < deadline)
        lt_sleep_until(lt_now() + 0.01);
    ended_at = lt_now();

    kill((pid_t) server_pid, SIGCONT);

    if (!returned)
    {
        printf("FAIL: the call did not end within %ld s of the cancel\n", watchdog);
        fflush(stdout);
        lt_quick_exit(1);
    }

    elapsed = ended_at - cancel_at;
    printf("call ended %.1f s after the cancel (cancel timeout %ld s): %s\n",
           elapsed, cancel_timeout, result);
    rc = 0;
    if (elapsed > cancel_timeout + 3)
    {
        printf("FAIL: the cancel did not interrupt the send\n");
        rc = 1;
    }
    else if (elapsed < cancel_timeout - 0.5)
    {
        printf("FAIL: the cancel timeout expired early\n");
        rc = 1;
    }
    pthread_join(t, NULL);

    /* the binding must still work (over a new connection) */
    LT_TRY
    {
        lt_null(h);
    }
    LT_CATCH(exc)
        printf("FAIL: the next call on the binding failed: %s\n", exc);
        rc = 1;
    LT_ENDTRY
    if (rc == 0)
        printf("PASS\n");
    lt_unbind(&h);
    return rc;
}
