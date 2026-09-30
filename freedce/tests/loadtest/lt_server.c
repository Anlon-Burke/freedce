/*
 * lt_server.c: server of the load test.
 *
 * usage: lt_server [-p protseq|all]... [-e endpoint] [-c max_calls] [-f nofile]
 *                  [-i secs]
 *
 * Without -e the server uses dynamic endpoints and registers them with the
 * endpoint mapper (rpcd); with -e it listens on that endpoint for every
 * protocol sequence and does not need rpcd.  "-p all" uses all protocol
 * sequences of the host (rpc_server_use_all_protseqs; not with -e).
 * SIGINT/SIGTERM stop it.
 */
#include <dirent.h>
#include <errno.h>
#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h>
#include <sys/resource.h>
#include <dce/rpc.h>
#include <dce/pthread_exc.h>
#include <dce/dce_error.h>
#include "lt_data.h"

#define CTX_MAGIC   0x4c54434bU     /* "LTCK" */

typedef struct
{
    unsigned32      magic;
    lt_key_t        key;
    unsigned32      calls;
} lt_context_t;

static struct
{
    uint64_t        calls[LT_N_OPS];
    uint64_t        mismatches;
    int64_t         contexts;
    uint64_t        rundowns;
} stats;

static int          max_reports = 20;

#define COUNT(op)   __atomic_fetch_add(&stats.calls[op], 1, __ATOMIC_RELAXED)

static void report(int op, const lt_key_t *key, int bad, const char *err)
{
    if (bad == 0)
        return;
    __atomic_fetch_add(&stats.mismatches, 1, __ATOMIC_RELAXED);
    if (__atomic_fetch_sub(&max_reports, 1, __ATOMIC_RELAXED) > 0)
        fprintf(stderr, "lt_server: MISMATCH %s client %u thread %u call %u: %s\n",
                lt_op_names[op], key->client, key->thread, key->call, err);
}

static void chk_status(const char *what, unsigned32 st)
{
    dce_error_string_t text;
    int                tst;

    if (st == rpc_s_ok)
        return;
    dce_error_inq_text(st, text, &tst);
    fprintf(stderr, "lt_server: %s: %s (0x%x)\n", what, (char *) text, st);
    exit(1);
}

/* managers ----------------------------------------------------------------- */

void lt_null(handle_t h __attribute__((unused)))
{
    COUNT(LT_OP_NULL);
}

void lt_null_idem(handle_t h __attribute__((unused)))
{
    COUNT(LT_OP_NULL_IDEM);
}

idl_long_int lt_struct(handle_t h __attribute__((unused)), lt_key_t *key,
                       lt_rec_t *rec, lt_rec_t *reply)
{
    char err[256] = "";
    int  bad;

    COUNT(LT_OP_STRUCT);
    bad = lt_check_rec(key, LT_REQ, rec, err, sizeof err);
    report(LT_OP_STRUCT, key, bad, err);
    lt_gen_rec(key, LT_REP, reply);
    return bad;
}

idl_long_int lt_array(handle_t h __attribute__((unused)), lt_key_t *key,
                      idl_ulong_int max, idl_ulong_int *len, lt_item_t items[])
{
    char err[256] = "";
    int  bad;

    COUNT(LT_OP_ARRAY);
    if (*len > max)
    {
        lt_errf(err, sizeof err, "len %u > max %u", *len, max);
        report(LT_OP_ARRAY, key, 1, err);
        *len = 0;
        return 1;
    }
    bad = lt_check_items(key, LT_REQ, *len, items, err, sizeof err);
    report(LT_OP_ARRAY, key, bad, err);
    *len = lt_reply_len(key, max);
    lt_gen_items(key, LT_REP, *len, items);
    return bad;
}

idl_long_int lt_union(handle_t h __attribute__((unused)), lt_key_t *key,
                      idl_ulong_int n, lt_var_t vars[], lt_var_t reply[])
{
    char err[256] = "";
    int  bad;

    COUNT(LT_OP_UNION);
    bad = lt_check_vars(key, LT_REQ, n, vars, err, sizeof err);
    report(LT_OP_UNION, key, bad, err);
    lt_gen_vars(key, LT_REP, n, reply);
    return bad;
}

idl_long_int lt_list(handle_t h __attribute__((unused)), lt_key_t *key,
                     lt_node_t *list, lt_node_t **reply)
{
    char err[256] = "";
    int  bad;

    COUNT(LT_OP_LIST);
    bad = lt_check_list(key, LT_REQ, list, err, sizeof err);
    report(LT_OP_LIST, key, bad, err);
    *reply = lt_gen_list(key, LT_REP);
    return bad;
}

idl_long_int lt_graph(handle_t h __attribute__((unused)), lt_key_t *key,
                      idl_ulong_int n, lt_gnode_p_t slots[])
{
    char       err[256] = "";
    int        bad;
    unsigned32 i;

    COUNT(LT_OP_GRAPH);
    bad = lt_check_graph(key, n, slots, 0, err, sizeof err);
    report(LT_OP_GRAPH, key, bad, err);
    for (i = 0; i < n; i++)
        if (slots[i] != NULL)
            slots[i]->visits++;
    return bad;
}

idl_long_int lt_pipe_in(handle_t h __attribute__((unused)), lt_key_t *key,
                        idl_ulong_int count, lt_pipe_t data)
{
    idl_ulong_int buf[1024], n, i;
    unsigned32    total = 0;
    char          err[256] = "";
    int           bad = 0;

    COUNT(LT_OP_PIPE_IN);
    do
    {
        (*data.pull)(data.state, buf, 1024, &n);
        for (i = 0; i < n; i++, total++)
            if (buf[i] != lt_pipe_elt(key, LT_REQ, total) && bad++ == 0)
                lt_errf(err, sizeof err, "pipe element %u differs", total);
    } while (n > 0);
    if (total != count && bad++ == 0)
        lt_errf(err, sizeof err, "pipe had %u elements, expected %u", total, count);
    report(LT_OP_PIPE_IN, key, bad, err);
    return bad;
}

idl_long_int lt_pipe_out(handle_t h __attribute__((unused)), lt_key_t *key,
                         idl_ulong_int count, lt_pipe_t data)
{
    idl_ulong_int buf[1024], n, i;
    unsigned32    sent = 0;

    COUNT(LT_OP_PIPE_OUT);
    while (sent < count)
    {
        n = count - sent < 1024 ? count - sent : 1024;
        for (i = 0; i < n; i++)
            buf[i] = lt_pipe_elt(key, LT_REP, sent + i);
        (*data.push)(data.state, buf, n);
        sent += n;
    }
    (*data.push)(data.state, buf, 0);
    return 0;
}

void lt_open(handle_t h __attribute__((unused)), lt_key_t *key, lt_ctx_t *ctx)
{
    lt_context_t *c = malloc(sizeof *c);

    COUNT(LT_OP_OPEN);
    c->magic = CTX_MAGIC;
    c->key = *key;
    c->calls = 0;
    __atomic_fetch_add(&stats.contexts, 1, __ATOMIC_RELAXED);
    *ctx = c;
}

idl_ulong_int lt_ctx_op(lt_ctx_t ctx)
{
    lt_context_t *c = ctx;

    COUNT(LT_OP_CTX_OP);
    if (c->magic != CTX_MAGIC)
    {
        report(LT_OP_CTX_OP, &c->key, 1, "bad context magic");
        return 0;
    }
    return ++c->calls;
}

static void free_context(lt_context_t *c)
{
    c->magic = 0;
    free(c);
    __atomic_fetch_sub(&stats.contexts, 1, __ATOMIC_RELAXED);
}

void lt_close(lt_ctx_t *ctx)
{
    COUNT(LT_OP_CLOSE);
    free_context(*ctx);
    *ctx = NULL;
}

void lt_ctx_t_rundown(rpc_ss_context_t ctx)
{
    __atomic_fetch_add(&stats.rundowns, 1, __ATOMIC_RELAXED);
    free_context(ctx);
}

void lt_slow(handle_t h __attribute__((unused)), idl_ulong_int ms, idl_boolean spin)
{
    struct timespec ts, end;

    COUNT(LT_OP_SLOW);
    if (!spin)
    {
        ts.tv_sec = ms / 1000;
        ts.tv_nsec = (ms % 1000) * 1000000L;
        nanosleep(&ts, NULL);
        return;
    }
    clock_gettime(CLOCK_MONOTONIC, &end);
    end.tv_sec += ms / 1000;
    end.tv_nsec += (ms % 1000) * 1000000L;
    if (end.tv_nsec >= 1000000000L)
    {
        end.tv_sec++;
        end.tv_nsec -= 1000000000L;
    }
    do
        clock_gettime(CLOCK_MONOTONIC, &ts);
    while (ts.tv_sec < end.tv_sec || (ts.tv_sec == end.tv_sec && ts.tv_nsec < end.tv_nsec));
}

/* statistics ---------------------------------------------------------------- */

static unsigned long proc_status(const char *field)
{
    char          line[256];
    size_t        len = strlen(field);
    unsigned long v = 0;
    FILE          *f = fopen("/proc/self/status", "r");

    if (f == NULL)
        return 0;
    while (fgets(line, sizeof line, f) != NULL)
        if (strncmp(line, field, len) == 0 && line[len] == ':')
        {
            v = strtoul(line + len + 1, NULL, 10);
            break;
        }
    fclose(f);
    return v;
}

static unsigned long open_fds(void)
{
    unsigned long n = 0;
    DIR           *d = opendir("/proc/self/fd");
    struct dirent *e;

    if (d == NULL)
        return 0;
    while ((e = readdir(d)) != NULL)
        if (e->d_name[0] != '.')
            n++;
    closedir(d);
    return n > 0 ? n - 1 : 0;       /* without the directory's own fd */
}

static void get_stats(lt_stats_t *s)
{
    int i;

    memset(s, 0, sizeof *s);
    for (i = 0; i < LT_N_OPS; i++)
        lt_uhyper_set(&s->calls[i], __atomic_load_n(&stats.calls[i], __ATOMIC_RELAXED));
    lt_uhyper_set(&s->mismatches, __atomic_load_n(&stats.mismatches, __ATOMIC_RELAXED));
    s->contexts = (idl_ulong_int) __atomic_load_n(&stats.contexts, __ATOMIC_RELAXED);
    lt_uhyper_set(&s->rundowns, __atomic_load_n(&stats.rundowns, __ATOMIC_RELAXED));
    s->threads = proc_status("Threads");
    s->fds = open_fds();
    lt_uhyper_set(&s->rss_kb, proc_status("VmRSS"));
}

void lt_stats(handle_t h __attribute__((unused)), lt_stats_t *s)
{
    COUNT(LT_OP_STATS);
    get_stats(s);
}

void lt_maybe(handle_t h __attribute__((unused)), lt_key_t *key,
              idl_ulong_int len, lt_item_t items[])
{
    char err[256] = "";
    int  bad;

    COUNT(LT_OP_MAYBE);
    bad = lt_check_items(key, LT_REQ, len, items, err, sizeof err);
    report(LT_OP_MAYBE, key, bad, err);
}

idl_long_int lt_ptrarr(handle_t h __attribute__((unused)),
                       lt_key_t *key __attribute__((unused)),
                       idl_ulong_int n, lt_item_t *p)
{
    volatile idl_ulong_int sum = 0;
    idl_ulong_int          i;

    COUNT(LT_OP_PTRARR);
    /* Trust the declared count: read all n elements (see size_is(n)). */
    if (p != NULL)
        for (i = 0; i < n; i++)
            sum += p[i].id;
    return (idl_long_int) sum;
}

static void print_stats(void)
{
    lt_stats_t s;
    uint64_t   total = 0;
    int        i;

    get_stats(&s);
    for (i = 0; i < LT_N_OPS; i++)
        total += lt_uhyper_get(&s.calls[i]);
    printf("stats: calls %llu mismatches %llu contexts %u rundowns %llu "
           "threads %u fds %u rss %llu kB\n",
           (unsigned long long) total,
           (unsigned long long) lt_uhyper_get(&s.mismatches), s.contexts,
           (unsigned long long) lt_uhyper_get(&s.rundowns), s.threads, s.fds,
           (unsigned long long) lt_uhyper_get(&s.rss_kb));
}

static int stats_interval;

static void *stats_thread(void *arg __attribute__((unused)))
{
    for (;;)
    {
        sleep(stats_interval);
        print_stats();
    }
    return NULL;
}

static sigset_t stop_signals;

static void *signal_thread(void *arg __attribute__((unused)))
{
    unsigned32 st;
    int        sig;

    sigwait(&stop_signals, &sig);
    printf("signal %d: stopping\n", sig);
    rpc_mgmt_stop_server_listening(NULL, &st);
    return NULL;
}

/* main ---------------------------------------------------------------------- */

static void usage(void)
{
    fprintf(stderr, "usage: lt_server [-p protseq|all]... [-e endpoint] [-c max_calls] "
                    "[-f nofile] [-i secs]\n");
    exit(2);
}

int main(int argc, char *argv[])
{
    const char         *protseqs[8];
    int                n_protseqs = 0, i, c;
    const char * volatile endpoint = NULL;      /* used after TRY */
    volatile unsigned32 max_calls = rpc_c_listen_max_calls_default;
    unsigned32         st;
    rpc_binding_vector_p_t bindings;
    pthread_t          t;

    setvbuf(stdout, NULL, _IOLBF, 0);
    lt_alloc = rpc_ss_allocate;

    while ((c = getopt(argc, argv, "p:e:c:f:i:")) != -1)
    {
        switch (c)
        {
            case 'p':
                if (n_protseqs == 8)
                    usage();
                protseqs[n_protseqs++] = optarg;
                break;
            case 'e':
                endpoint = optarg;
                break;
            case 'c':
                max_calls = strtoul(optarg, NULL, 0);
                break;
            case 'f':
            {
                struct rlimit rl;

                getrlimit(RLIMIT_NOFILE, &rl);
                rl.rlim_cur = strtoul(optarg, NULL, 0);
                if (rl.rlim_cur > rl.rlim_max)
                    rl.rlim_max = rl.rlim_cur;
                if (setrlimit(RLIMIT_NOFILE, &rl) != 0)
                    fprintf(stderr, "lt_server: setrlimit(%s): %s\n", optarg, strerror(errno));
                break;
            }
            case 'i':
                stats_interval = atoi(optarg);
                break;
            default:
                usage();
        }
    }
    if (optind != argc)
        usage();
    if (n_protseqs == 0)
        protseqs[n_protseqs++] = "ncacn_ip_tcp";

    /* the signal thread and all runtime threads inherit the blocked signals */
    sigemptyset(&stop_signals);
    sigaddset(&stop_signals, SIGINT);
    sigaddset(&stop_signals, SIGTERM);
    pthread_sigmask(SIG_BLOCK, &stop_signals, NULL);

    rpc_server_register_if(loadtest_v1_0_s_ifspec, NULL, NULL, &st);
    chk_status("rpc_server_register_if", st);

    for (i = 0; i < n_protseqs; i++)
    {
        if (strcmp(protseqs[i], "all") == 0)
        {
            if (endpoint != NULL)
                usage();
            rpc_server_use_all_protseqs(max_calls, &st);
        }
        else if (endpoint != NULL)
            rpc_server_use_protseq_ep((unsigned_char_p_t) protseqs[i], max_calls,
                                      (unsigned_char_p_t) endpoint, &st);
        else
            rpc_server_use_protseq((unsigned_char_p_t) protseqs[i], max_calls, &st);
        chk_status(protseqs[i], st);
    }

    rpc_server_inq_bindings(&bindings, &st);
    chk_status("rpc_server_inq_bindings", st);
    for (i = 0; i < (int) bindings->count; i++)
    {
        unsigned_char_p_t s;

        rpc_binding_to_string_binding(bindings->binding_h[i], &s, &st);
        if (st == rpc_s_ok)
        {
            printf("listening on %s\n", (char *) s);
            rpc_string_free(&s, &st);
        }
    }
    if (endpoint == NULL)
    {
        rpc_ep_register(loadtest_v1_0_s_ifspec, bindings, NULL,
                        (unsigned_char_p_t) "load test server", &st);
        chk_status("rpc_ep_register", st);
    }

    pthread_create(&t, &pthread_attr_default, signal_thread, NULL);
    if (stats_interval > 0)
        pthread_create(&t, &pthread_attr_default, stats_thread, NULL);

    printf("ready\n");
    TRY
    {
        rpc_server_listen(max_calls, &st);
        chk_status("rpc_server_listen", st);
    }
    CATCH_ALL
    {
        fprintf(stderr, "lt_server: rpc_server_listen raised %s\n", THIS_CATCH->printable_name);
    }
    ENDTRY

    if (endpoint == NULL)
        rpc_ep_unregister(loadtest_v1_0_s_ifspec, bindings, NULL, &st);
    rpc_binding_vector_free(&bindings, &st);
    print_stats();
    return 0;
}
