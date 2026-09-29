/*
 * lt_client.c: client of the load test.
 *
 * Builds with DCE RPC and with the Microsoft RPC runtime (see lt_port.h and
 * build_win.cmd).
 *
 * usage: lt_client -h host [options]
 *   -h host      server host (name or address)
 *   -e endpoint  server endpoint; without it the endpoint mapper (rpcd) on
 *                the host resolves it
 *   -P protocol  tcp (default) or udp
 *   -t threads   number of threads, each with its own binding (default 1)
 *   -d secs      run for secs seconds (default 10), or
 *   -n calls     make calls calls per thread
 *   -r rate      calls per second of this process in total (default: no limit)
 *   -m mix       operation weights, e.g. "struct=4,array=2,null=1" (default:
 *                every operation except slow with weight 1); operations:
 *                null null_idem struct array union list graph pipe_in
 *                pipe_out ctx_op slow
 *   -z size      maximum number of array/union/graph elements (default 16);
 *                pipes carry up to 64 * size elements
 *   -T ms        duration of the slow operation (default 100)
 *   -s seed      seed of the test data (default 1)
 *   -C id        client id sent to the server (default: process id)
 *   -a first     thread i connects to the server at 127.0.0.0 + first + i + 1
 *                instead of host (server on this machine): every thread then
 *                has its own association group, like a separate client host
 *   -W           use union discriminants that do not fit into 16 bits
 *   -k           keep the contexts: exit without closing them (rundown test)
 *   -R           recover from errors: after a failed call, reset the binding
 *                (with a dynamic endpoint the endpoint mapper is asked again),
 *                replace a context handle whose call failed, and pause 100 ms
 *   -S           print the server statistics at the end
 *   -Q           only print the server statistics
 *   -v           print every error (default: the first 10)
 *
 * An outage of a thread lasts from the start of its first failed call to
 * the end of its next successful call; the summary shows their number and
 * the longest one.  The exit status is 0 if every call succeeded and all
 * data was correct.
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lt_data.h"

#define MAX_THREADS     4096
#define N_BUCKETS       32      /* latency histogram: bucket b < 2^b us */
#define MAX_EXC_NAMES   16

/* operations that can be in the mix (the others run once per thread) */
static const int mix_ops[] =
{
    LT_OP_NULL, LT_OP_NULL_IDEM, LT_OP_STRUCT, LT_OP_ARRAY, LT_OP_UNION,
    LT_OP_LIST, LT_OP_GRAPH, LT_OP_PIPE_IN, LT_OP_PIPE_OUT, LT_OP_CTX_OP,
    LT_OP_SLOW
};
#define N_MIX_OPS (int) (sizeof mix_ops / sizeof mix_ops[0])

typedef struct
{
    uint64_t    calls, errors, mismatches;
    uint64_t    sum_us, max_us;
    uint64_t    hist[N_BUCKETS];
} op_stats_t;

typedef struct
{
    int         id;
    lt_thread_t thread;
    handle_t    h;
    lt_ctx_t    ctx;
    lt_rng_t    rng;
    lt_key_t    key;
    op_stats_t  ops[LT_N_OPS];
    struct { char name[129]; uint64_t count; } exc[MAX_EXC_NAMES];
    double      down_since;     /* start of the current outage, 0 if none */
    uint64_t    outages, unrecovered;
    double      longest;        /* longest outage in seconds */
} worker_t;

/* options */
static const char   *host, *endpoint;
static const char   *protseq = "ncacn_ip_tcp";
static int          n_threads = 1, duration = 10, verbose;
static long         calls_per_thread;
static double       rate;
static unsigned int weights[LT_N_OPS];
static unsigned int weight_sum;
static unsigned32   size = 16, slow_ms = 100, client_id, flags;
static uint64_t     seed = 1;
static int          keep_contexts, server_stats, query_only, recover;
static long         spread_first = -1;     /* -a */

static double       start_time, end_time;
static int          reports_left = 10;     /* not exact with many threads */

static void report(worker_t *w, int op, const char *what, const char *text)
{
    if (verbose || reports_left-- > 0)
        fprintf(stderr, "lt_client %lu thread %d call %lu %s: %s%s\n",
                (unsigned long) client_id, w->id, (unsigned long) w->key.call,
                lt_op_names[op], what, text);
}

static void count_exception(worker_t *w, const char *name)
{
    /* names are stored truncated: compare only the stored length */
    const size_t len = sizeof w->exc[0].name - 1;
    int i;

    for (i = 0; i < MAX_EXC_NAMES; i++)
    {
        if (w->exc[i].count == 0)
        {
            snprintf(w->exc[i].name, sizeof w->exc[i].name, "%s", name);
            w->exc[i].count = 1;
            return;
        }
        if (strncmp(w->exc[i].name, name, len) == 0)
        {
            w->exc[i].count++;
            return;
        }
    }
}

/* pipes --------------------------------------------------------------------- */

typedef struct
{
    const lt_key_t *key;
    unsigned32     count, done;
    int            bad;
    idl_ulong_int  buf[1024];
} pipe_state_t;

static void LT_CALLBACK pipe_pull(lt_pipe_state_t state, idl_ulong_int *buf,
                                  idl_ulong_int esize, idl_ulong_int *ecount)
{
    pipe_state_t *ps = (pipe_state_t *) state;
    unsigned32   i, n = ps->count - ps->done;

    if (n > esize)
        n = esize;
    for (i = 0; i < n; i++)
        buf[i] = lt_pipe_elt(ps->key, LT_REQ, ps->done + i);
    ps->done += n;
    *ecount = n;
}

static void LT_CALLBACK pipe_alloc(lt_pipe_state_t state, idl_ulong_int bsize,
                                   idl_ulong_int **buf, idl_ulong_int *bcount)
{
    pipe_state_t *ps = (pipe_state_t *) state;

    (void) bsize;
    *buf = ps->buf;
    *bcount = sizeof ps->buf;       /* bytes */
}

static void LT_CALLBACK pipe_push(lt_pipe_state_t state, idl_ulong_int *buf,
                                  idl_ulong_int ecount)
{
    pipe_state_t *ps = (pipe_state_t *) state;
    unsigned32   i;

    for (i = 0; i < ecount; i++, ps->done++)
        if (buf[i] != lt_pipe_elt(ps->key, LT_REP, ps->done))
            ps->bad++;
}

/* one call ------------------------------------------------------------------ */

/*
 * Makes one call of operation op with the data for w->key.  Returns the
 * number of differences found by the server plus those found here;
 * exceptions are passed on.
 */
static int call_op(worker_t *w, int op)
{
    const lt_key_t *key = &w->key;
    char           err[256] = "";
    int            bad = 0, sbad = 0;
    lt_rng_t       r;

    lt_rng_init(&r, key, LT_REQ + 300);     /* sizes */

    switch (op)
    {
        case LT_OP_NULL:
            lt_null(w->h);
            break;

        case LT_OP_NULL_IDEM:
            lt_null_idem(w->h);
            break;

        case LT_OP_STRUCT:
        {
            lt_rec_t rec, reply;

            lt_gen_rec(key, LT_REQ, &rec);
            memset(&reply, 0, sizeof reply);
            sbad = lt_struct(w->h, (lt_key_t *) key, &rec, &reply);
            bad = lt_check_rec(key, LT_REP, &reply, err, sizeof err);
            break;
        }

        case LT_OP_ARRAY:
        {
            unsigned32    max = lt_rng_below(&r, size + 1);
            idl_ulong_int len = lt_rng_below(&r, max + 1);
            lt_item_t     *items = (*lt_alloc)(max * sizeof *items + 1);

            lt_gen_items(key, LT_REQ, len, items);
            sbad = lt_array(w->h, (lt_key_t *) key, max, &len, items);
            if (len != lt_reply_len(key, max))
            {
                lt_errf(err, sizeof err, "reply length %lu, expected %lu",
                        (unsigned long) len, (unsigned long) lt_reply_len(key, max));
                bad = 1;
            }
            else
                bad = lt_check_items(key, LT_REP, len, items, err, sizeof err);
            break;
        }

        case LT_OP_UNION:
        {
            unsigned32 n = 1 + lt_rng_below(&r, size);
            lt_var_t   *vars = (*lt_alloc)(n * sizeof *vars);
            lt_var_t   *reply = (*lt_alloc)(n * sizeof *reply);

            lt_gen_vars(key, LT_REQ, n, vars);
            memset(reply, 0, n * sizeof *reply);
            sbad = lt_union(w->h, (lt_key_t *) key, n, vars, reply);
            bad = lt_check_vars(key, LT_REP, n, reply, err, sizeof err);
            break;
        }

        case LT_OP_LIST:
        {
            lt_node_t *reply = NULL;

            sbad = lt_list(w->h, (lt_key_t *) key, lt_gen_list(key, LT_REQ), &reply);
            bad = lt_check_list(key, LT_REP, reply, err, sizeof err);
            break;
        }

        case LT_OP_GRAPH:
        {
            unsigned32   n = 1 + lt_rng_below(&r, size);
            lt_gnode_t   *nodes = (*lt_alloc)(lt_graph_nodes(n) * sizeof *nodes);
            lt_gnode_p_t *slots = (*lt_alloc)(n * sizeof *slots);

            lt_gen_graph(key, n, nodes, slots);
            sbad = lt_graph(w->h, (lt_key_t *) key, n, slots);
            bad = lt_check_graph(key, n, slots, 1, err, sizeof err);
            break;
        }

        case LT_OP_PIPE_IN:
        case LT_OP_PIPE_OUT:
        {
            pipe_state_t *ps = (*lt_alloc)(sizeof *ps);
            lt_pipe_t    p;

            ps->key = key;
            ps->count = lt_rng_below(&r, 64 * size + 1);
            ps->done = 0;
            ps->bad = 0;
            p.pull = pipe_pull;
            p.push = pipe_push;
            p.alloc = pipe_alloc;
            p.state = (lt_pipe_state_t) ps;
            if (op == LT_OP_PIPE_IN)
                sbad = lt_pipe_in(w->h, (lt_key_t *) key, ps->count, p);
            else
            {
                sbad = lt_pipe_out(w->h, (lt_key_t *) key, ps->count, p);
                bad = ps->bad;
                if (bad != 0)
                    lt_errf(err, sizeof err, "%d pipe elements differ", bad);
                else if (ps->done != ps->count)
                {
                    lt_errf(err, sizeof err, "pipe had %lu elements, expected %lu",
                            (unsigned long) ps->done, (unsigned long) ps->count);
                    bad = 1;
                }
            }
            break;
        }

        case LT_OP_CTX_OP:
            (void) lt_ctx_op(w->ctx);
            break;

        case LT_OP_SLOW:
            lt_slow(w->h, slow_ms, 0);
            break;
    }

    if (sbad != 0)
        report(w, op, "server found differences", "");
    if (bad != 0)
        report(w, op, "", err);
    return sbad + bad;
}

/* outages ------------------------------------------------------------------ */

static void end_outage(worker_t *w)
{
    double d = lt_now() - w->down_since;

    w->outages++;
    if (d > w->longest)
        w->longest = d;
    w->down_since = 0;
}

/*
 * Called after every call that started at t0: keeps track of the outages
 * and, with -R, gets ready for a server that has restarted or moved: the
 * next call asks the endpoint mapper again (dynamic endpoint), a context
 * handle whose call failed is closed or given up (a new one is opened before
 * the next ctx_op), and a server that is down is not called in a busy loop.
 */
static void call_done(worker_t *w, int op, double t0, int failed)
{
    char exc[160];

    if (!failed)
    {
        if (w->down_since != 0)
            end_outage(w);
        return;
    }
    if (w->down_since == 0)
        w->down_since = t0;
    if (!recover)
        return;

    if (endpoint == NULL)
        lt_binding_reset(w->h);
    if (op == LT_OP_CTX_OP && w->ctx != NULL)
    {
        LT_TRY
        {
            lt_close(&w->ctx);
        }
        LT_CATCH(exc)
            (void) exc;
        LT_ENDTRY
        if (w->ctx != NULL)
            lt_ctx_destroy(&w->ctx);
    }
    lt_sleep_until(lt_now() + 0.1);
}

/* calls --------------------------------------------------------------------- */

static void run_op(worker_t *w, int op)
{
    op_stats_t *s = &w->ops[op];
    char       exc[160];
    double     t0 = lt_now();
    uint64_t   us;
    int        b;
    volatile int failed = 0;    /* set in the handler */

    lt_call_begin();
    LT_TRY
    {
        if (call_op(w, op) != 0)
            s->mismatches++;
    }
    LT_CATCH(exc)
        s->errors++;
        failed = 1;
        count_exception(w, exc);
        report(w, op, "exception ", exc);
    LT_ENDTRY
    lt_call_end();

    us = (uint64_t) ((lt_now() - t0) * 1e6);
    s->calls++;
    s->sum_us += us;
    if (us > s->max_us)
        s->max_us = us;
    for (b = 0; b < N_BUCKETS - 1 && (1ULL << b) <= us; b++)
        ;
    s->hist[b]++;
    call_done(w, op, t0, failed);
}

/* lt_open and lt_close, counted but not timed */
static void run_ctx(worker_t *w, int op)
{
    char         exc[160];
    double       t0 = lt_now();
    volatile int failed = 0;    /* set in the handler */

    LT_TRY
    {
        if (op == LT_OP_OPEN)
            lt_open(w->h, &w->key, &w->ctx);
        else
            lt_close(&w->ctx);
        w->ops[op].calls++;
    }
    LT_CATCH(exc)
        w->ops[op].errors++;
        failed = 1;
        count_exception(w, exc);
        report(w, op, "exception ", exc);
    LT_ENDTRY
    call_done(w, op, t0, failed);
}

static int pick_op(worker_t *w)
{
    uint32_t x = lt_rng_below(&w->rng, weight_sum);
    int      i;

    for (i = 0; i < LT_N_OPS; i++)
    {
        if (x < weights[i])
            return i;
        x -= weights[i];
    }
    return LT_OP_NULL;
}

static void *worker(void *arg)
{
    worker_t *w = arg;
    char     addr[32];
    const char *h = host;
    double   interval = rate > 0 ? n_threads / rate : 0;
    double   next;
    lt_key_t rkey;

    if (spread_first >= 0)
    {
        unsigned long n = (unsigned long) spread_first + w->id + 1;

        snprintf(addr, sizeof addr, "127.%lu.%lu.%lu",
                 (n >> 16) & 255, (n >> 8) & 255, n & 255);
        h = addr;
    }
    if (lt_bind(protseq, h, endpoint, &w->h) != 0)
    {
        fprintf(stderr, "lt_client: cannot bind to %s:%s\n", protseq, h);
        exit(2);
    }

    memset(&rkey, 0, sizeof rkey);
    lt_uhyper_set(&rkey.seed, seed);
    rkey.client = client_id;
    rkey.thread = w->id;
    lt_rng_init(&w->rng, &rkey, 7);
    w->key = rkey;
    w->key.flags = flags;

    if (weights[LT_OP_CTX_OP] > 0 || keep_contexts)
    {
        w->key.call = 0;
        run_ctx(w, LT_OP_OPEN);
    }

    /* spread the first calls over one interval */
    next = lt_now() + interval * lt_rng_below(&w->rng, 1000) / 1000.0;

    for (w->key.call = 1; ; w->key.call++)
    {
        int op;

        /* -d: the paced time, or the real clock when calls take longer than planned */
        if (calls_per_thread > 0 ? (long) w->key.call > calls_per_thread
                                 : next >= end_time || lt_now() >= end_time)
            break;
        op = pick_op(w);
        if (interval > 0)
        {
            lt_sleep_until(next);
            next += interval;
        }
        else
            next = lt_now();
        if (op == LT_OP_CTX_OP && w->ctx == NULL && recover)
            run_ctx(w, LT_OP_OPEN);
        if (op == LT_OP_CTX_OP && w->ctx == NULL)
            op = LT_OP_NULL;
        run_op(w, op);
    }

    if (w->ctx != NULL && !keep_contexts)
        run_ctx(w, LT_OP_CLOSE);
    if (w->down_since != 0)
    {
        w->unrecovered++;
        end_outage(w);
    }
    return NULL;
}

/* results ------------------------------------------------------------------- */

static uint64_t percentile(const op_stats_t *s, double p)
{
    uint64_t want = (uint64_t) (s->calls * p), n = 0;
    int      b;

    for (b = 0; b < N_BUCKETS; b++)
    {
        n += s->hist[b];
        if (n > want)
            return 1ULL << b;
    }
    return s->max_us;
}

static int print_results(worker_t *workers, double secs)
{
    op_stats_t total_op[LT_N_OPS], all;
    uint64_t   outages = 0, unrecovered = 0;
    double     longest = 0;
    int        i, j, k, rc = 0;

    memset(total_op, 0, sizeof total_op);
    memset(&all, 0, sizeof all);
    for (i = 0; i < n_threads; i++)
        for (j = 0; j < LT_N_OPS; j++)
        {
            op_stats_t *s = &workers[i].ops[j], *t = &total_op[j];

            t->calls += s->calls;
            t->errors += s->errors;
            t->mismatches += s->mismatches;
            t->sum_us += s->sum_us;
            if (s->max_us > t->max_us)
                t->max_us = s->max_us;
            for (k = 0; k < N_BUCKETS; k++)
                t->hist[k] += s->hist[k];
        }

    for (j = 0; j < LT_N_OPS; j++)
    {
        op_stats_t *t = &total_op[j];

        if (t->calls == 0 && t->errors == 0)
            continue;
        all.calls += t->calls;
        all.errors += t->errors;
        all.mismatches += t->mismatches;
        printf("op %-9s calls %8llu errors %6llu mismatches %6llu  us: avg %7llu "
               "p50 <%7llu p99 <%7llu max %8llu\n",
               lt_op_names[j], (unsigned long long) t->calls,
               (unsigned long long) t->errors, (unsigned long long) t->mismatches,
               (unsigned long long) (t->calls ? t->sum_us / t->calls : 0),
               (unsigned long long) percentile(t, 0.5),
               (unsigned long long) percentile(t, 0.99),
               (unsigned long long) t->max_us);
    }

    /* merge the exception counts by name into thread 0's table */
    for (i = 1; i < n_threads; i++)
        for (k = 0; k < MAX_EXC_NAMES && workers[i].exc[k].count > 0; k++)
        {
            int m;

            for (m = 0; m < MAX_EXC_NAMES; m++)
                if (workers[0].exc[m].count == 0
                    || strcmp(workers[0].exc[m].name, workers[i].exc[k].name) == 0)
                    break;
            if (m == MAX_EXC_NAMES)
                continue;
            if (workers[0].exc[m].count == 0)
                strcpy(workers[0].exc[m].name, workers[i].exc[k].name);
            workers[0].exc[m].count += workers[i].exc[k].count;
        }
    for (k = 0; k < MAX_EXC_NAMES && workers[0].exc[k].count > 0; k++)
        printf("exception %s: %llu\n", workers[0].exc[k].name,
               (unsigned long long) workers[0].exc[k].count);

    for (i = 0; i < n_threads; i++)
    {
        outages += workers[i].outages;
        unrecovered += workers[i].unrecovered;
        if (workers[i].longest > longest)
            longest = workers[i].longest;
    }
    printf("outages %llu longest %llu ms not recovered %llu\n",
           (unsigned long long) outages, (unsigned long long) (longest * 1000),
           (unsigned long long) unrecovered);

    printf("total calls %llu errors %llu mismatches %llu threads %d secs %.1f rate %.1f/s\n",
           (unsigned long long) all.calls, (unsigned long long) all.errors,
           (unsigned long long) all.mismatches, n_threads, secs,
           secs > 0 ? all.calls / secs : 0.0);
    if (all.errors != 0 || all.mismatches != 0)
        rc = 1;
    return rc;
}

static int print_server_stats(void)
{
    handle_t     h;
    lt_stats_t   s;
    uint64_t     total = 0;
    int          i;
    char         exc[160];
    volatile int rc = 0;     /* set in the handler */

    if (lt_bind(protseq, host, endpoint, &h) != 0)
        return 1;
    LT_TRY
    {
        lt_stats(h, &s);
        for (i = 0; i < LT_N_OPS; i++)
            total += lt_uhyper_get(&s.calls[i]);
        printf("server calls %llu mismatches %llu contexts %lu rundowns %llu "
               "threads %lu fds %lu rss %llu kB\n",
               (unsigned long long) total,
               (unsigned long long) lt_uhyper_get(&s.mismatches),
               (unsigned long) s.contexts,
               (unsigned long long) lt_uhyper_get(&s.rundowns),
               (unsigned long) s.threads, (unsigned long) s.fds,
               (unsigned long long) lt_uhyper_get(&s.rss_kb));
    }
    LT_CATCH(exc)
        printf("server statistics: exception %s\n", exc);
        rc = 1;
    LT_ENDTRY
    lt_unbind(&h);
    return rc;
}

/* main ---------------------------------------------------------------------- */

static void usage(void)
{
    fprintf(stderr,
        "usage: lt_client -h host [-e endpoint] [-P tcp|udp] [-t threads]\n"
        "                 [-d secs | -n calls] [-r rate] [-m mix] [-z size] [-T ms]\n"
        "                 [-s seed] [-C id] [-a first] [-W] [-k] [-R] [-S] [-Q] [-v]\n");
    exit(2);
}

static void parse_mix(char *mix)
{
    char *tok, *save;
    int  i, j;

    memset(weights, 0, sizeof weights);
    for (tok = strtok_r(mix, ",", &save); tok != NULL; tok = strtok_r(NULL, ",", &save))
    {
        char *eq = strchr(tok, '=');

        if (eq != NULL)
            *eq = '\0';
        for (i = 0; i < N_MIX_OPS; i++)
        {
            j = mix_ops[i];
            if (strcmp(tok, lt_op_names[j]) == 0)
            {
                weights[j] = eq != NULL ? (unsigned int) atoi(eq + 1) : 1;
                break;
            }
        }
        if (i == N_MIX_OPS)
        {
            fprintf(stderr, "lt_client: unknown operation %s\n", tok);
            usage();
        }
    }
}

int main(int argc, char *argv[])
{
    worker_t *workers;
    char     *mix = NULL;
    int      c, i, rc;
    double   secs;

#ifdef _WIN32
    setvbuf(stdout, NULL, _IONBF, 0);      /* MSVC has no line buffering */
#else
    setvbuf(stdout, NULL, _IOLBF, 0);
#endif
    client_id = (unsigned32) lt_getpid();

    while ((c = lt_getopt(argc, argv, "h:e:P:t:d:n:r:m:z:T:s:C:a:WkRSQv")) != -1)
    {
        switch (c)
        {
            case 'h': host = lt_optarg; break;
            case 'e': endpoint = lt_optarg; break;
            case 'P':
                if (strcmp(lt_optarg, "tcp") == 0)
                    protseq = "ncacn_ip_tcp";
                else if (strcmp(lt_optarg, "udp") == 0)
                    protseq = "ncadg_ip_udp";
                else
                    usage();
                break;
            case 't': n_threads = atoi(lt_optarg); break;
            case 'd': duration = atoi(lt_optarg); break;
            case 'n': calls_per_thread = atol(lt_optarg); break;
            case 'r': rate = atof(lt_optarg); break;
            case 'm': mix = lt_optarg; break;
            case 'z': size = strtoul(lt_optarg, NULL, 0); break;
            case 'T': slow_ms = strtoul(lt_optarg, NULL, 0); break;
            case 's': seed = strtoull(lt_optarg, NULL, 0); break;
            case 'C': client_id = strtoul(lt_optarg, NULL, 0); break;
            case 'a': spread_first = atol(lt_optarg); break;
            case 'W': flags |= LT_F_WIDE_SWITCH; break;
            case 'k': keep_contexts = 1; break;
            case 'R': recover = 1; break;
            case 'S': server_stats = 1; break;
            case 'Q': query_only = 1; break;
            case 'v': verbose = 1; break;
            default: usage();
        }
    }
    if (host == NULL || lt_optind != argc || n_threads < 1 || n_threads > MAX_THREADS)
        usage();
    if (query_only)
        return print_server_stats();

    if (mix != NULL)
        parse_mix(mix);
    else
        for (i = 0; i < N_MIX_OPS; i++)
            weights[mix_ops[i]] = mix_ops[i] == LT_OP_SLOW ? 0 : 1;
    for (i = 0, weight_sum = 0; i < LT_N_OPS; i++)
        weight_sum += weights[i];
    if (weight_sum == 0)
        usage();

    workers = calloc(n_threads, sizeof *workers);
    start_time = lt_now();
    end_time = start_time + duration;

    for (i = 0; i < n_threads; i++)
    {
        workers[i].id = i;
        if (lt_thread_create(&workers[i].thread, worker, &workers[i]) != 0)
        {
            fprintf(stderr, "lt_client: cannot create thread %d\n", i);
            exit(2);
        }
    }
    for (i = 0; i < n_threads; i++)
        lt_thread_join(workers[i].thread);
    secs = lt_now() - start_time;

    rc = print_results(workers, secs);
    if (server_stats)
        rc |= print_server_stats();
    fflush(stdout);
    if (keep_contexts)
        lt_quick_exit(rc);      /* the server has to run down the contexts */
    for (i = 0; i < n_threads; i++)
        lt_unbind(&workers[i].h);
    free(workers);
    return rc;
}
