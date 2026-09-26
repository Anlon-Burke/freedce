/*
 * lt_client.c: client of the load test.
 *
 * usage: lt_client -h host [options]
 *   -h host      server host (name or address)
 *   -e endpoint  server endpoint; without it rpcd on the host resolves it
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
 *   -W           use union discriminants that do not fit into 16 bits
 *   -k           keep the contexts: exit without closing them (rundown test)
 *   -S           print the server statistics at the end
 *   -Q           only print the server statistics
 *   -v           print every error (default: the first 10)
 *
 * The exit status is 0 if every call succeeded and all data was correct.
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h>
#include <dce/rpc.h>
#include <dce/pthread_exc.h>
#include <dce/dce_error.h>
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
    pthread_t   thread;
    handle_t    h;
    lt_ctx_t    ctx;
    lt_rng_t    rng;
    lt_key_t    key;
    op_stats_t  ops[LT_N_OPS];
    struct { char name[65]; uint64_t count; } exc[MAX_EXC_NAMES];
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
static int          keep_contexts, server_stats, query_only;

static struct timespec start_time, end_time;
static int          reports_left = 10;

static double elapsed(const struct timespec *from)
{
    struct timespec now;

    clock_gettime(CLOCK_MONOTONIC, &now);
    return (now.tv_sec - from->tv_sec) + (now.tv_nsec - from->tv_nsec) / 1e9;
}

static void add_ns(struct timespec *t, double secs)
{
    long ns = (long) (secs * 1e9);

    t->tv_sec += ns / 1000000000L;
    t->tv_nsec += ns % 1000000000L;
    if (t->tv_nsec >= 1000000000L)
    {
        t->tv_sec++;
        t->tv_nsec -= 1000000000L;
    }
}

static int before(const struct timespec *a, const struct timespec *b)
{
    return a->tv_sec < b->tv_sec || (a->tv_sec == b->tv_sec && a->tv_nsec < b->tv_nsec);
}

static void report(worker_t *w, int op, const char *fmt, const char *text)
{
    if (verbose || __atomic_fetch_sub(&reports_left, 1, __ATOMIC_RELAXED) > 0)
        fprintf(stderr, "lt_client %u thread %d call %u %s: %s%s\n", client_id, w->id,
                w->key.call, lt_op_names[op], fmt, text);
}

static void count_exception(worker_t *w, const char *name)
{
    int i;

    for (i = 0; i < MAX_EXC_NAMES; i++)
    {
        if (w->exc[i].count == 0)
        {
            strncpy(w->exc[i].name, name, 64);
            w->exc[i].count = 1;
            return;
        }
        if (strcmp(w->exc[i].name, name) == 0)
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

static void pipe_pull(rpc_ss_pipe_state_t state, idl_ulong_int *buf,
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

static void pipe_alloc(rpc_ss_pipe_state_t state, idl_ulong_int bsize __attribute__((unused)),
                       idl_ulong_int **buf, idl_ulong_int *bcount)
{
    pipe_state_t *ps = (pipe_state_t *) state;

    *buf = ps->buf;
    *bcount = sizeof ps->buf;
}

static void pipe_push(rpc_ss_pipe_state_t state, idl_ulong_int *buf, idl_ulong_int ecount)
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
            lt_item_t     *items = rpc_ss_allocate(max * sizeof *items + 1);

            lt_gen_items(key, LT_REQ, len, items);
            sbad = lt_array(w->h, (lt_key_t *) key, max, &len, items);
            if (len != lt_reply_len(key, max))
            {
                lt_errf(err, sizeof err, "reply length %u, expected %u",
                        len, lt_reply_len(key, max));
                bad = 1;
            }
            else
                bad = lt_check_items(key, LT_REP, len, items, err, sizeof err);
            break;
        }

        case LT_OP_UNION:
        {
            unsigned32 n = 1 + lt_rng_below(&r, size);
            lt_var_t   *vars = rpc_ss_allocate(n * sizeof *vars);
            lt_var_t   *reply = rpc_ss_allocate(n * sizeof *reply);

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
            lt_gnode_t   *nodes = rpc_ss_allocate(lt_graph_nodes(n) * sizeof *nodes);
            lt_gnode_p_t *slots = rpc_ss_allocate(n * sizeof *slots);

            lt_gen_graph(key, n, nodes, slots);
            sbad = lt_graph(w->h, (lt_key_t *) key, n, slots);
            bad = lt_check_graph(key, n, slots, 1, err, sizeof err);
            break;
        }

        case LT_OP_PIPE_IN:
        case LT_OP_PIPE_OUT:
        {
            pipe_state_t *ps = rpc_ss_allocate(sizeof *ps);
            lt_pipe_t    p;

            ps->key = key;
            ps->count = lt_rng_below(&r, 64 * size + 1);
            ps->done = 0;
            ps->bad = 0;
            p.pull = pipe_pull;
            p.push = pipe_push;
            p.alloc = pipe_alloc;
            p.state = (rpc_ss_pipe_state_t) ps;
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
                    lt_errf(err, sizeof err, "pipe had %u elements, expected %u",
                            ps->done, ps->count);
                    bad = 1;
                }
            }
            break;
        }

        case LT_OP_CTX_OP:
        {
            idl_ulong_int n = lt_ctx_op(w->ctx);

            (void) n;
            break;
        }

        case LT_OP_SLOW:
            lt_slow(w->h, slow_ms, false);
            break;
    }

    if (sbad != 0)
        report(w, op, "server found differences", "");
    if (bad != 0)
        report(w, op, "", err);
    return sbad + bad;
}

static void run_op(worker_t *w, int op)
{
    op_stats_t      *s = &w->ops[op];
    struct timespec t0;
    uint64_t        us;
    int             b;

    clock_gettime(CLOCK_MONOTONIC, &t0);
    rpc_ss_enable_allocate();
    TRY
    {
        if (call_op(w, op) != 0)
            s->mismatches++;
    }
    CATCH_ALL
    {
        s->errors++;
        count_exception(w, THIS_CATCH->printable_name);
        report(w, op, "exception ", THIS_CATCH->printable_name);
    }
    ENDTRY
    rpc_ss_disable_allocate();

    us = (uint64_t) (elapsed(&t0) * 1e6);
    s->calls++;
    s->sum_us += us;
    if (us > s->max_us)
        s->max_us = us;
    for (b = 0; b < N_BUCKETS - 1 && (1ULL << b) <= us; b++)
        ;
    s->hist[b]++;
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
    worker_t        *w = arg;
    char            sb[512];
    unsigned32      st;
    struct timespec next;
    volatile double interval = rate > 0 ? n_threads / rate : 0;
    lt_key_t        rkey;

    snprintf(sb, sizeof sb, "%s:%s%s%s%s", protseq, host,
             endpoint ? "[" : "", endpoint ? endpoint : "", endpoint ? "]" : "");
    rpc_binding_from_string_binding((unsigned_char_p_t) sb, &w->h, &st);
    if (st != rpc_s_ok)
    {
        fprintf(stderr, "lt_client: bad binding %s\n", sb);
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
        TRY
        {
            lt_open(w->h, &w->key, &w->ctx);
            w->ops[LT_OP_OPEN].calls++;
        }
        CATCH_ALL
        {
            w->ops[LT_OP_OPEN].errors++;
            count_exception(w, THIS_CATCH->printable_name);
            report(w, LT_OP_OPEN, "exception ", THIS_CATCH->printable_name);
        }
        ENDTRY
    }

    /* spread the first calls over one interval */
    clock_gettime(CLOCK_MONOTONIC, &next);
    add_ns(&next, interval * lt_rng_below(&w->rng, 1000) / 1000.0);

    for (w->key.call = 1; ; w->key.call++)
    {
        int op;

        if (calls_per_thread > 0 ? (long) w->key.call > calls_per_thread
                                 : !before(&next, &end_time))
            break;
        op = pick_op(w);
        if (op == LT_OP_CTX_OP && w->ctx == NULL)
            op = LT_OP_NULL;
        if (interval > 0)
        {
            struct timespec now;

            clock_gettime(CLOCK_MONOTONIC, &now);
            if (before(&now, &next))
                clock_nanosleep(CLOCK_MONOTONIC, TIMER_ABSTIME, &next, NULL);
            add_ns(&next, interval);
        }
        else
            clock_gettime(CLOCK_MONOTONIC, &next);
        run_op(w, op);
    }

    if (w->ctx != NULL && !keep_contexts)
    {
        TRY
        {
            lt_close(&w->ctx);
            w->ops[LT_OP_CLOSE].calls++;
        }
        CATCH_ALL
        {
            w->ops[LT_OP_CLOSE].errors++;
            count_exception(w, THIS_CATCH->printable_name);
            report(w, LT_OP_CLOSE, "exception ", THIS_CATCH->printable_name);
        }
        ENDTRY
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

    for (i = 0; i < n_threads; i++)
        for (k = 0; k < MAX_EXC_NAMES && workers[i].exc[k].count > 0; k++)
        {
            /* merge by name into thread 0's table for printing */
            if (i > 0)
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
        }
    for (k = 0; k < MAX_EXC_NAMES && workers[0].exc[k].count > 0; k++)
        printf("exception %s: %llu\n", workers[0].exc[k].name,
               (unsigned long long) workers[0].exc[k].count);

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
    char       sb[512];
    unsigned32 st;
    handle_t   h;
    lt_stats_t s;
    uint64_t   total = 0;
    int        i;
    volatile int rc = 0;     /* set in CATCH */

    snprintf(sb, sizeof sb, "%s:%s%s%s%s", protseq, host,
             endpoint ? "[" : "", endpoint ? endpoint : "", endpoint ? "]" : "");
    rpc_binding_from_string_binding((unsigned_char_p_t) sb, &h, &st);
    TRY
    {
        lt_stats(h, &s);
        for (i = 0; i < LT_N_OPS; i++)
            total += lt_uhyper_get(&s.calls[i]);
        printf("server calls %llu mismatches %llu contexts %u rundowns %llu "
               "threads %u fds %u rss %llu kB\n",
               (unsigned long long) total,
               (unsigned long long) lt_uhyper_get(&s.mismatches), s.contexts,
               (unsigned long long) lt_uhyper_get(&s.rundowns), s.threads, s.fds,
               (unsigned long long) lt_uhyper_get(&s.rss_kb));
    }
    CATCH_ALL
    {
        printf("server statistics: exception %s\n", THIS_CATCH->printable_name);
        rc = 1;
    }
    ENDTRY
    rpc_binding_free(&h, &st);
    return rc;
}

/* main ---------------------------------------------------------------------- */

static void usage(void)
{
    fprintf(stderr,
        "usage: lt_client -h host [-e endpoint] [-P tcp|udp] [-t threads]\n"
        "                 [-d secs | -n calls] [-r rate] [-m mix] [-z size] [-T ms]\n"
        "                 [-s seed] [-C id] [-W] [-k] [-S] [-Q] [-v]\n");
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

    setvbuf(stdout, NULL, _IOLBF, 0);
    lt_alloc = rpc_ss_allocate;
    client_id = (unsigned32) getpid();

    while ((c = getopt(argc, argv, "h:e:P:t:d:n:r:m:z:T:s:C:WkSQv")) != -1)
    {
        switch (c)
        {
            case 'h': host = optarg; break;
            case 'e': endpoint = optarg; break;
            case 'P':
                if (strcmp(optarg, "tcp") == 0)
                    protseq = "ncacn_ip_tcp";
                else if (strcmp(optarg, "udp") == 0)
                    protseq = "ncadg_ip_udp";
                else
                    usage();
                break;
            case 't': n_threads = atoi(optarg); break;
            case 'd': duration = atoi(optarg); break;
            case 'n': calls_per_thread = atol(optarg); break;
            case 'r': rate = atof(optarg); break;
            case 'm': mix = optarg; break;
            case 'z': size = strtoul(optarg, NULL, 0); break;
            case 'T': slow_ms = strtoul(optarg, NULL, 0); break;
            case 's': seed = strtoull(optarg, NULL, 0); break;
            case 'C': client_id = strtoul(optarg, NULL, 0); break;
            case 'W': flags |= LT_F_WIDE_SWITCH; break;
            case 'k': keep_contexts = 1; break;
            case 'S': server_stats = 1; break;
            case 'Q': query_only = 1; break;
            case 'v': verbose = 1; break;
            default: usage();
        }
    }
    if (host == NULL || optind != argc || n_threads < 1 || n_threads > MAX_THREADS)
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
    clock_gettime(CLOCK_MONOTONIC, &start_time);
    end_time = start_time;
    end_time.tv_sec += duration;

    for (i = 0; i < n_threads; i++)
    {
        workers[i].id = i;
        if (pthread_create(&workers[i].thread, &pthread_attr_default, worker, &workers[i]) != 0)
        {
            perror("lt_client: pthread_create");
            exit(2);
        }
    }
    for (i = 0; i < n_threads; i++)
        pthread_join(workers[i].thread, NULL);
    secs = elapsed(&start_time);

    rc = print_results(workers, secs);
    if (server_stats)
        rc |= print_server_stats();
    if (keep_contexts)
        _exit(rc);      /* the server has to run down the contexts */
    for (i = 0; i < n_threads; i++)
    {
        unsigned32 st;

        rpc_binding_free(&workers[i].h, &st);
    }
    return rc;
}
