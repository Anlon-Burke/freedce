/* include/dce/dce_config.h.  Generated by configure.  */
/* include/dce/dce_config.h.in.  Generated from configure.in by autoheader.  */

/* Word Size in bytes */
#define ARCH_WORD_SIZE 8

/* Include the DCE dummy auth service */
/* #undef AUTH_DUMMY */

/* Include GSS-API authentication */
/* #undef AUTH_GSS */

/* Include NTMLSSP auth */
/* #undef AUTH_NTLMSSP */

/* Support for the codeset registry (untested) */
/* #undef BUILD_CODESET */

/* Compile with debugging support */
#define DEBUG 1

/* Build demo programs */
#define DEMO_PROGS 1

/* Enable DUMPERS for debugging dceidl */
/* #undef DUMPERS */

/* Enable experimental DCOM support */
/* #undef ENABLE_DCOM */

/* Enable pthreads: experimental */
/* #undef ENABLE_PTHREADS */

/* Define to 1 if you have the <dlfcn.h> header file. */
#define HAVE_DLFCN_H 1

/* Define to 1 if you have the <features.h> header file. */
#define HAVE_FEATURES_H 1

/* Define to 1 if you have the `gettimeofday' function. */
#define HAVE_GETTIMEOFDAY 1

/* Define to 1 if you have the <inttypes.h> header file. */
#define HAVE_INTTYPES_H 1

/* Define to 1 if you have the `dl' library (-ldl). */
#define HAVE_LIBDL 1

/* Define to 1 if you have the `pthread' library (-lpthread). */
#define HAVE_LIBPTHREAD 1

/* Define to 1 if you have the `pthreadGC2' library (-lpthreadGC2). */
/* #undef HAVE_LIBPTHREADGC2 */

/* Define to 1 if you have the <memory.h> header file. */
#define HAVE_MEMORY_H 1

/* Define, if target is win32 */
/* #undef HAVE_OS_WIN32 */

/* Define to 1 if you have the `socket' function. */
#define HAVE_SOCKET 1

/* Define to 1 if you have the <stdint.h> header file. */
#define HAVE_STDINT_H 1

/* Define to 1 if you have the <stdlib.h> header file. */
#define HAVE_STDLIB_H 1

/* Define to 1 if you have the <strings.h> header file. */
#define HAVE_STRINGS_H 1

/* Define to 1 if you have the <string.h> header file. */
#define HAVE_STRING_H 1

/* Define to 1 if you have the <sys/cdefs.h> header file. */
#define HAVE_SYS_CDEFS_H 1

/* Define to 1 if you have the <sys/stat.h> header file. */
#define HAVE_SYS_STAT_H 1

/* Define to 1 if you have the <sys/types.h> header file. */
#define HAVE_SYS_TYPES_H 1

/* Define to 1 if you have the <unistd.h> header file. */
#define HAVE_UNISTD_H 1

/* IP network address family support */
#define NAF_IP 1

/* Unix Domain Socket network address family support */
#define NAF_UXD 1

/* non-cancellable io */
#define NON_CANCELLABLE_IO 1

/* non-cancellable select */
#define NON_CANCELLABLE_IO_SELECT 1

/* Name of package */
#define PACKAGE "freedce"

/* Define to the address where bug reports for this package should be sent. */
#define PACKAGE_BUGREPORT ""

/* Define to the full name of this package. */
#define PACKAGE_NAME "freedce"

/* Define to the full name and version of this package. */
#define PACKAGE_STRING "freedce 1.0.1"

/* Define to the one symbol short name of this package. */
#define PACKAGE_TARNAME "freedce"

/* Define to the version of this package. */
#define PACKAGE_VERSION "1.0.1"

/* Support connection based transports */
#define PROT_NCACN 1

/* Support connectionless transports */
#define PROT_NCADG 1

/* Define to 1 if you have the ANSI C header files. */
#define STDC_HEADERS 1

/* Include loopback interface support */
#define USE_LOOPBACK 1

/* Version number of package */
#define VERSION "1.0.1"

/* Define to 1 if `lex' declares `yytext' as a `char *' by default, not a
   `char[]'. */
#define YYTEXT_POINTER 1

/* Description */
#define _BSD 

/* Description */
#define _GNU_SOURCE 

/* Description */
#define _REENTRANT 

/* Define to `__inline__' or `__inline' if that's what the C compiler
   calls it, or to nothing if 'inline' is not supported under any name.  */
#ifndef __cplusplus
/* #undef inline */
#endif
