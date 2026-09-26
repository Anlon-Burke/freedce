/*
 * lt_port.c: platform layer of the load test client (see lt_port.h).
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lt_data.h"

#ifdef _WIN32
/* Microsoft RPC ------------------------------------------------------------ */

#include <process.h>

void lt_status_name(unsigned long code, char *name, size_t len)
{
    const char *s;

    switch (code)
    {
        case RPC_S_SERVER_UNAVAILABLE:      s = "RPC_S_SERVER_UNAVAILABLE"; break;
        case RPC_S_CALL_FAILED:             s = "RPC_S_CALL_FAILED"; break;
        case RPC_S_CALL_FAILED_DNE:         s = "RPC_S_CALL_FAILED_DNE"; break;
        case RPC_S_PROTOCOL_ERROR:          s = "RPC_S_PROTOCOL_ERROR"; break;
        case RPC_S_UNKNOWN_IF:              s = "RPC_S_UNKNOWN_IF"; break;
        case RPC_S_PROCNUM_OUT_OF_RANGE:    s = "RPC_S_PROCNUM_OUT_OF_RANGE"; break;
        case EPT_S_NOT_REGISTERED:          s = "EPT_S_NOT_REGISTERED"; break;
        case RPC_X_BAD_STUB_DATA:           s = "RPC_X_BAD_STUB_DATA"; break;
        case RPC_S_INVALID_TAG:             s = "RPC_S_INVALID_TAG"; break;
        case RPC_X_SS_CONTEXT_MISMATCH:     s = "RPC_X_SS_CONTEXT_MISMATCH"; break;
        case RPC_X_SS_IN_NULL_CONTEXT:      s = "RPC_X_SS_IN_NULL_CONTEXT"; break;
        case RPC_S_ACCESS_DENIED:           s = "RPC_S_ACCESS_DENIED"; break;
        case RPC_S_OUT_OF_MEMORY:           s = "RPC_S_OUT_OF_MEMORY"; break;
        default:                            s = NULL; break;
    }
    if (s != NULL)
        snprintf(name, len, "%s (%lu)", s, code);
    else
        snprintf(name, len, "RPC status %lu (0x%lx)", code, code);
}

int lt_bind(const char *protseq, const char *host, const char *endpoint, handle_t *h)
{
    RPC_CSTR   s = NULL;
    RPC_STATUS st;

    st = RpcStringBindingComposeA(NULL, (RPC_CSTR) protseq, (RPC_CSTR) host,
                                  (RPC_CSTR) endpoint, NULL, &s);
    if (st == RPC_S_OK)
    {
        st = RpcBindingFromStringBindingA(s, h);
        RpcStringFreeA(&s);
    }
    return st == RPC_S_OK ? 0 : -1;
}

void lt_unbind(handle_t *h)
{
    RpcBindingFree(h);
}

void lt_binding_reset(handle_t h)
{
    RpcBindingReset(h);
}

void lt_ctx_destroy(void **ctx)
{
    RpcSsDestroyClientContext(ctx);
}

/*
 * The stubs allocate with midl_user_allocate(): keep a per-thread list of
 * the blocks of the current call, so that lt_call_end() frees them all
 * (like rpc_ss_disable_allocate() in DCE).
 */
typedef struct block
{
    struct block *prev, *next;
    double       align;
} block_t;

static __declspec(thread) block_t *blocks;
static __declspec(thread) int     in_call;

void __RPC_FAR * __RPC_USER midl_user_allocate(size_t size)
{
    block_t *b = malloc(sizeof *b + size);

    if (b == NULL)
        return NULL;
    b->prev = NULL;
    b->next = NULL;
    if (in_call)
    {
        b->next = blocks;
        if (blocks != NULL)
            blocks->prev = b;
        blocks = b;
    }
    return b + 1;
}

void __RPC_USER midl_user_free(void __RPC_FAR *p)
{
    block_t *b;

    if (p == NULL)
        return;
    b = (block_t *) p - 1;
    if (b->prev != NULL)
        b->prev->next = b->next;
    else if (blocks == b)
        blocks = b->next;
    if (b->next != NULL)
        b->next->prev = b->prev;
    free(b);
}

static idl_void_p_t call_alloc(idl_size_t size)
{
    return midl_user_allocate(size);
}

void lt_call_begin(void)
{
    in_call = 1;
    lt_alloc = call_alloc;
}

void lt_call_end(void)
{
    while (blocks != NULL)
    {
        block_t *b = blocks;

        blocks = b->next;
        free(b);
    }
    in_call = 0;
}

struct lt_thread_s
{
    HANDLE         h;
    lt_thread_fn_t fn;
    void           *arg;
};

static unsigned __stdcall thread_start(void *arg)
{
    struct lt_thread_s *t = arg;

    t->fn(t->arg);
    return 0;
}

int lt_thread_create(lt_thread_t *tp, lt_thread_fn_t fn, void *arg)
{
    struct lt_thread_s *t = malloc(sizeof *t);

    t->fn = fn;
    t->arg = arg;
    t->h = (HANDLE) _beginthreadex(NULL, 0, thread_start, t, 0, NULL);
    if (t->h == 0)
    {
        free(t);
        return -1;
    }
    *tp = t;
    return 0;
}

void lt_thread_join(lt_thread_t t)
{
    WaitForSingleObject(t->h, INFINITE);
    CloseHandle(t->h);
    free(t);
}

double lt_now(void)
{
    static LARGE_INTEGER freq;
    LARGE_INTEGER        now;

    if (freq.QuadPart == 0)
        QueryPerformanceFrequency(&freq);
    QueryPerformanceCounter(&now);
    return (double) now.QuadPart / (double) freq.QuadPart;
}

void lt_sleep_until(double t)
{
    double d = t - lt_now();

    if (d > 0)
        Sleep((DWORD) (d * 1000));
}

char *lt_optarg;
int  lt_optind = 1;

int lt_getopt(int argc, char *const argv[], const char *opts)
{
    const char *o;
    char       c;

    if (lt_optind >= argc || argv[lt_optind][0] != '-' || argv[lt_optind][1] == '\0')
        return -1;
    c = argv[lt_optind][1];
    o = strchr(opts, c);
    if (o == NULL || argv[lt_optind][2] != '\0')
        return '?';
    lt_optind++;
    if (o[1] == ':')
    {
        if (lt_optind >= argc)
            return '?';
        lt_optarg = argv[lt_optind++];
    }
    return c;
}

unsigned long lt_getpid(void)
{
    return GetCurrentProcessId();
}

void lt_quick_exit(int rc)
{
    ExitProcess(rc);    /* no cleanup: the server must run down the contexts */
}

#else
/* DCE RPC ------------------------------------------------------------------ */

#include <time.h>
#include <unistd.h>
#include <dce/dce_error.h>

void lt_exc_name(EXCEPTION *exc, char *name, size_t len)
{
    long int           status;
    dce_error_string_t text;
    int                st;

    /* an exception for a status without its own exception: show the status */
    if (exc_get_status(exc, &status) == 0)
    {
        dce_error_inq_text((unsigned32) status, text, &st);
        snprintf(name, len, "%s (0x%lx)", st == 0 ? (char *) text : exc->printable_name,
                 (unsigned long) status);
    }
    else
        snprintf(name, len, "%s", exc->printable_name);
}

int lt_bind(const char *protseq, const char *host, const char *endpoint, handle_t *h)
{
    char       sb[512];
    unsigned32 st;

    snprintf(sb, sizeof sb, "%s:%s%s%s%s", protseq, host,
             endpoint ? "[" : "", endpoint ? endpoint : "", endpoint ? "]" : "");
    rpc_binding_from_string_binding((unsigned_char_p_t) sb, h, &st);
    return st == rpc_s_ok ? 0 : -1;
}

void lt_unbind(handle_t *h)
{
    unsigned32 st;

    rpc_binding_free(h, &st);
}

void lt_binding_reset(handle_t h)
{
    unsigned32 st;

    rpc_binding_reset(h, &st);
}

void lt_ctx_destroy(void **ctx)
{
    rpc_ss_destroy_client_context(ctx);
}

void lt_call_begin(void)
{
    rpc_ss_enable_allocate();
    lt_alloc = rpc_ss_allocate;
}

void lt_call_end(void)
{
    rpc_ss_disable_allocate();
}

struct lt_thread_s
{
    pthread_t t;
};

int lt_thread_create(lt_thread_t *tp, lt_thread_fn_t fn, void *arg)
{
    struct lt_thread_s *t = malloc(sizeof *t);

    if (pthread_create(&t->t, &pthread_attr_default, fn, arg) != 0)
    {
        free(t);
        return -1;
    }
    *tp = t;
    return 0;
}

void lt_thread_join(lt_thread_t t)
{
    pthread_join(t->t, NULL);
    free(t);
}

double lt_now(void)
{
    struct timespec now;

    clock_gettime(CLOCK_MONOTONIC, &now);
    return now.tv_sec + now.tv_nsec / 1e9;
}

void lt_sleep_until(double t)
{
    struct timespec ts;

    ts.tv_sec = (time_t) t;
    ts.tv_nsec = (long) ((t - (double) ts.tv_sec) * 1e9);
    clock_nanosleep(CLOCK_MONOTONIC, TIMER_ABSTIME, &ts, NULL);
}

char *lt_optarg;
int  lt_optind = 1;

int lt_getopt(int argc, char *const argv[], const char *opts)
{
    int c = getopt(argc, argv, opts);

    lt_optarg = optarg;
    lt_optind = optind;
    return c;
}

unsigned long lt_getpid(void)
{
    return (unsigned long) getpid();
}

void lt_quick_exit(int rc)
{
    _exit(rc);          /* no cleanup: the server must run down the contexts */
}

#endif
