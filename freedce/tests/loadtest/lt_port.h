/*
 * lt_port.h: what the load test needs from the platform.
 *
 * The client builds with DCE RPC (dceidl stubs, dcethreads) and with the
 * Microsoft RPC runtime (MIDL stubs, Win32 threads), so that a Windows
 * client can be tested against a DCE server.  The server and lt_data.c only
 * use the type mapping.
 */
#ifndef LT_PORT_H
#define LT_PORT_H

#include <stddef.h>
#include <stdint.h>

#ifdef _WIN32

#include <windows.h>
#include <rpc.h>

/* IDL base types as MIDL maps them (MIDL uses unsigned char for char) */
typedef unsigned char   idl_char;
typedef char            idl_small_int;
typedef unsigned char   idl_usmall_int;
typedef short           idl_short_int;
typedef unsigned short  idl_ushort_int;
typedef long            idl_long_int;
typedef unsigned long   idl_ulong_int;
typedef unsigned char   idl_boolean;
typedef unsigned char   idl_byte;
typedef double          idl_long_float;
typedef float           idl_short_float;
typedef __int64         idl_hyper_int;
typedef unsigned __int64 idl_uhyper_int;
typedef void            *idl_void_p_t;
typedef size_t          idl_size_t;
typedef unsigned long   unsigned32;
typedef char            *lt_pipe_state_t;

#define LT_FORMAT(f, a)
#define LT_CALLBACK     __RPC_USER
#define strtok_r        strtok_s

#else

#include <dce/rpc.h>
#include <dce/pthread_exc.h>

typedef rpc_ss_pipe_state_t lt_pipe_state_t;

#define LT_FORMAT(f, a) __attribute__((format(printf, f, a)))
#define LT_CALLBACK

#endif

/* 64-bit values of IDL hyper types (a struct of two halves in DCE) */
int64_t lt_hyper_get(const idl_hyper_int *v);
void lt_hyper_set(idl_hyper_int *v, int64_t x);
uint64_t lt_uhyper_get(const idl_uhyper_int *v);
void lt_uhyper_set(idl_uhyper_int *v, uint64_t x);

/*
 * Client side only (lt_port.c) -------------------------------------------
 */

/*
 * Use as
 *     LT_TRY
 *     {
 *         ...
 *     }
 *     LT_CATCH(name)
 *         handler statements
 *     LT_ENDTRY
 * name (a char array) receives the name of the exception (DCE) or of the
 * RPC status (Windows).
 */
#ifdef _WIN32
#define LT_TRY          RpcTryExcept
#define LT_CATCH(name)  RpcExcept(1) { lt_status_name(RpcExceptionCode(), name, sizeof name);
#define LT_ENDTRY       } RpcEndExcept
void lt_status_name(unsigned long code, char *name, size_t len);
#else
#define LT_TRY          TRY
#define LT_CATCH(name)  CATCH_ALL { lt_exc_name(THIS_CATCH, name, sizeof name);
#define LT_ENDTRY       } ENDTRY
void lt_exc_name(EXCEPTION *exc, char *name, size_t len);
#endif

/* binding to protseq:host[endpoint] (endpoint may be NULL); 0 on success */
int lt_bind(const char *protseq, const char *host, const char *endpoint, handle_t *h);
void lt_unbind(handle_t *h);
/* remove the endpoint of a binding (the endpoint mapper resolves it again) */
void lt_binding_reset(handle_t h);
/* give up a context handle without a call (the server may not know it) */
void lt_ctx_destroy(void **ctx);

/*
 * Memory of one call: everything the stubs and lt_alloc allocate between
 * lt_call_begin() and lt_call_end() is freed by lt_call_end().
 * lt_call_begin() also points lt_alloc (lt_data.h) to the call's memory.
 */
void lt_call_begin(void);
void lt_call_end(void);

/* threads */
typedef void *(*lt_thread_fn_t)(void *arg);
typedef struct lt_thread_s *lt_thread_t;
int lt_thread_create(lt_thread_t *t, lt_thread_fn_t fn, void *arg);
void lt_thread_join(lt_thread_t t);

/* monotonic time in seconds; sleep until such a time */
double lt_now(void);
void lt_sleep_until(double t);

/* getopt() for Windows */
extern char *lt_optarg;
extern int lt_optind;
int lt_getopt(int argc, char *const argv[], const char *opts);

unsigned long lt_getpid(void);
void lt_quick_exit(int rc);

#endif
