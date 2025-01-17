/*
 * (c) Copyright 1993 OPEN SOFTWARE FOUNDATION, INC.
 * (c) Copyright 1993 HEWLETT-PACKARD COMPANY
 * (c) Copyright 1993 DIGITAL EQUIPMENT CORPORATION
 * To anyone who acknowledges that this file is provided "AS IS"
 * without any express or implied warranty:
 *                 permission to use, copy, modify, and distribute this
 * file for any purpose is hereby granted without fee, provided that
 * the above copyright notices and this notice appears in all source
 * code copies, and that none of the names of Open Software
 * Foundation, Inc., Hewlett-Packard Company, or Digital Equipment
 * Corporation be used in advertising or publicity pertaining to
 * distribution of the software without specific, written prior
 * permission.  Neither Open Software Foundation, Inc., Hewlett-
 * Packard Company, nor Digital Equipment Corporation makes any
 * representations about the suitability of this software for any
 * purpose.
 */

/*
 *  OSF DCE Version 1.0
 */

#ifndef sysdep_incl
#define sysdep_incl

/*
**
**  NAME
**
**      SYSDEP.H
**
**  FACILITY:
**
**      Interface Definition Language (IDL) Compiler
**
**  ABSTRACT:
**
**      Operating system and compiler dependencies.
**
**  VERSION: DCE 1.0
**
*/

#if defined(__VMS) && !defined(VMS)
#define VMS
#define vms
#endif

/*
 *  exit status codes
 */
#ifdef VMS
#   define pgm_warning 0x10000000  /* 0 % 8 == warning */
#   define pgm_ok      0x00000001  /* 1 % 8 == success */
#   define pgm_error   0x10000002  /* 2 % 8 == error   */
#else
#   define pgm_ok      0
#   define pgm_warning 2
#   define pgm_error   3
#endif

/*
** Macro to test a system-specific status code for failure status.
*/
#ifdef VMS
#define ERROR_STATUS(s) (((s) & 1) != 1)
#else
#define ERROR_STATUS(s) ((s) != 0)
#endif

/*
** define HASDIRTREE if OS has foo/widget/bar file system.
** if HASDIRTREE, define BRANCHCHAR and BRANCHSTRING appropriately
** define HASPOPEN if system can do popen()
** define HASINODES if system has real inodes returned by stat()
*/

/* MSDOS */
#ifdef _MSDOS
#ifndef __STDC__
#define __STDC__ 1
#endif
#define BRANCHCHAR '\\'
#define BRANCHSTRING "\\"
#define HASPOPEN
#define HASDIRTREE
#define DEFAULT_IDIR     "\\mstools\\h"
#define DEFAULT_H_IDIR   "\\mstools\\h"
#define INCLUDE_TEMPLATE "#include <dce\\%s>\n"
#define USER_INCLUDE_TEMPLATE "#include \"%s\"\n"
#define USER_INCLUDE_H_TEMPLATE "#include \"%s.h\"\n"
#define MESSAGE_CATALOG_DIR "\\bin"
#define CD_IDIR "."
#define unlink _unlink
#define getcwd _getcwd
#define chdir _chdir
#define stat _stat
#define popen _popen
#define pclose _pclose
#define S_IFMT _S_IFMT
#define S_IFDIR _S_IFDIR
#define S_IFREG _S_IFREG
#define NO_TRY_CATCH_FINALLY
#ifdef TURBOC
#define stat(a,b) turboc_stat(a,b)
#endif
#endif


/* VAX VMS  */
#ifdef VMS
#define HASDIRTREE
#define BRANCHCHAR ']'
#define BRANCHSTRING "]"
/* VMS model is that system .IDL and .H files are in the same directory. */
#define DEFAULT_IDIR    "DCE:"
#define DEFAULT_H_IDIR  "DCE:"
#define INCLUDE_TEMPLATE "#include <dce/%s>\n"
#define USER_INCLUDE_TEMPLATE "#include <%s>\n"
#define USER_INCLUDE_H_TEMPLATE "#include <%s.h>\n"
#define CD_IDIR "[]"
#endif


#if defined(__OSF__) || defined(__OSF1__) || defined(__osf__) || defined(BSD) || defined(SYS5) || defined(ultrix) || defined(_AIX) || defined(__ultrix) || defined(_BSD) || defined(__linux__)
#define UNIX
#define HASDIRTREE
#define HASPOPEN
#define HASINODES
#define BRANCHCHAR '/'
#define BRANCHSTRING "/"
#define CD_IDIR "."
#endif

#ifndef CD_IDIR
Porting Message:  You must provide definitions for the symbols
    describing the directory structure available on your platform.  
#endif

/*
 * Default DCE include directory
 */
#ifndef DEFAULT_IDIR
# define DEFAULT_IDIR "/usr/include"
#endif
#define DEFAULT_H_IDIR DEFAULT_IDIR
#define INCLUDE_TEMPLATE "#include <dce/%s>\n"
#define USER_INCLUDE_TEMPLATE "#include <%s>\n"
#define USER_INCLUDE_H_TEMPLATE "#include <%s.h>\n"

/*
 * Default DCE auto import path
 */
#ifndef AUTO_IMPORT_FILE
# define AUTO_IMPORT_FILE "dce/nbase.idl"
#endif

/*
** Default filetype names.
*/
#if defined(VMS) || defined(_MSDOS)
#define OBJ_FILETYPE ".OBJ"
#else
#define OBJ_FILETYPE ".o"
#endif

/*
** Commands to invoke C-Preprocessor, C-Compiler etc.
*/
#define CPP            "gcc -E -x c-header "
#define CC_DEF_CMD     "gcc -c -D_GNU_SOURCE -D_REENTRANT"

/*
** Default suffixes for IDL-generated files.
*/
#ifdef UNIX
# ifndef ENABLE_DCOM
#  define CSTUB_SUFFIX   	"_cstub.c"
#  define SSTUB_SUFFIX   	"_sstub.c"
#  define CAUX_SUFFIX    	"_caux.c"
#  define SAUX_SUFFIX    	"_saux.c"
# else
#  define CSTUB_SUFFIX	"_cstub.cxx"
#  define SSTUB_SUFFIX 	"_sstub.cxx"
#  define SAUX_SUFFIX    "_saux.cxx"
#  define CAUX_SUFFIX    "_caux.cxx"
# endif
# define HEADER_SUFFIX  	".h"
#endif

#ifdef _MSDOS
# define CSTUB_SUFFIX   "_c.c"
# define SSTUB_SUFFIX   "_s.c"
# define HEADER_SUFFIX  ".h"
# define CAUX_SUFFIX    "_x.c"
# define SAUX_SUFFIX    "_y.c"
#endif

#ifdef VMS
# define CSTUB_SUFFIX   "_cstub.c"
# define SSTUB_SUFFIX   "_sstub.c"
# define HEADER_SUFFIX  ".h"
# define CAUX_SUFFIX    "_caux.c"
# define SAUX_SUFFIX    "_saux.c"
#endif

#ifndef CSTUB_SUFFIX
Porting Message:  You must provide definitions for the files suffixes to
    be used on your platform.
#endif

/*
 * Template for IDL version text emitted as comment into generated files.
 */
#ifndef IDL_VERSION_TEXT 
# if ENABLE_DCOM
#  define IDL_VERSION_TEXT "FreeDCE/DCOM " VERSION " with GNU Flex/Bison"
# else
#  define IDL_VERSION_TEXT "FreeDCE 1.0.1 64-bit with GNU Flex/Bison"
# endif
#endif
#define IDL_VERSION_TEMPLATE "/* Generated by IDL compiler version FreeDCE 1.0.1 64-bit with GNU Flex/Bison */\n"

/*
** PASS_I_DIRS_TO_CC determines whether the list of import directories, with
** the system IDL directory replaced by the system H directory if present,
** gets passed as command option(s) to the C compiler when compiling stubs.
*/
#ifndef apollo
# define PASS_I_DIRS_TO_CC
#endif

/*
** Environment variables for IDL system include directories
** on supported platforms.
*/
#ifdef DUMPERS
# define NIDL_LIBRARY_EV "NIDL_LIBRARY"
#endif

/*
** Maximum length of IDL identifiers.  Architecturally specified as 31, but
** on platforms whose C (or other) compilers have more stringent lengths,
** this value might have to be less.
*/
#define MAX_ID 128

/*
** Estimation of available stack size in a server stub.  Under DCE threads
** stack overflow by large amounts can result in indeterminant behavior.  If
** the estimated stack requirements for stack surrogates exceeds the value
** below, objects are allocated via malloc instead of on the stack.
*/
#define AUTO_HEAP_STACK_THRESHOLD 7000

/*
** Symbol for 'audible bell' character.  A workaround for the problem that
** some non-stdc compilers incorrectly map '\a' to 'a'.  Might need work
** on a non-stdc EBCDIC platform.
*/
#if defined(__STDC__)
#define AUDIBLE_BELL '\a'
#define AUDIBLE_BELL_CSTR "\\a"
#else
#define AUDIBLE_BELL '\007'
#define AUDIBLE_BELL_CSTR "\\007"
#endif

/*
** Data type of memory returned by malloc.  In ANSI standard compilers, this
** is a void *, but default to char * for others.
*/
#if defined(__STDC__) || defined(vaxc)
#define heap_mem void
#else
#define heap_mem char
#endif

/*
**  Maximum number of characters in a directory path name for a file.  Used
**  to allocate buffer space for manipulating the path name string.
*/
#ifndef PATH_MAX
# ifdef VMS
# define PATH_MAX  256
# else
# define PATH_MAX 1024
# endif
#endif

/*
** Define PROTO if the system compiler supports ANSI prototypes
*/
#ifndef PROTO
#if defined __STDC__ || defined VAXC || defined mips || defined _AIX || defined __alpha
#define PROTO
#endif
#endif

/*
** Define macros for NLS entry points used only in message.c
*/
#if defined(_AIX)
#       define NL_SPRINTF NLsprintf
#       define NL_VFPRINTF NLvfprintf
#else
#       define NL_SPRINTF sprintf
#       define NL_VFPRINTF vfprintf
#endif


/*
** To avoid passing the VMS C compiler lines of more than 255 characters, we
** redirect fprintf through a special routine, use on other Digital platforms
** also for consistancy in testing of compiler output.
*/
#if defined(vms) || defined(ultrix) || defined(__osf__)
#define IDL_USE_OUTPUT_LINE
#ifdef fprintf
#undef fprintf
#endif
#define fprintf output_line

/*
** Functions exported by sysdep.c
*/
extern int output_line(
#ifdef PROTO
    FILE * fid,                 /* [in] File handle */
    char *format,               /* [in] Format string */
    ...                         /* [in] 0-N format arguments */
#endif
);

extern void flush_output_line(
#ifdef PROTO
    FILE * fid                  /* [in] File handle */
#endif
);
#endif
#endif
