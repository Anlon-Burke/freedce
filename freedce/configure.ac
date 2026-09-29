dnl Process this file with autoconf to produce a configure script.
AC_INIT([freedce],[2.0.0])
AC_CONFIG_SRCDIR(uuid/uuid.c)
AC_CANONICAL_TARGET
AC_CONFIG_HEADERS([include/dce/dce_config.h])
AM_INIT_AUTOMAKE
AC_PROG_CC
AC_PREFIX_DEFAULT(/opt/dce)
AC_SUBST([LT_VERSION],[2:0:0])

# determine target system
if test "x$target" = "x"; then
	echo "warning: target not set, building for host system"
	target=${host}
	target_cpu=${host_cpu}
	target_os=${host_os}
	target_vendor=${host_vendor}
fi


# reduce iX86 to i386 for target_cpu
case $target_cpu in
	i?86)	target_cpu="i386";;
esac
# expand linux to linux-gnu
if test "x$target_os" = "xlinux"; then
	target_os="linux-gnu";
fi

case "$target_os" in
    cygwin* | mingw*)
            have_win32=1
	    ;;
esac

dnl there are much better ways to do this...
if test "x$target_cpu" = "xx86_64"; then
	AC_DEFINE(ARCH_WORD_SIZE, 8, [Word Size in bytes])
else
	AC_DEFINE(ARCH_WORD_SIZE, 4, [Word Size in bytes])
fi

if test "x$have_win32" = "x1"; then
	AC_DEFINE(HAVE_OS_WIN32, 1, [Define, if target is win32])
	LIBS="$LIBS -lntdll -lws2_32 -liphlpapi";
	WIN32_PROG_PREFIX=".exe"
	AC_SUBST(WIN32_PROG_PREFIX)
fi

AC_DEFINE(NON_CANCELLABLE_IO, 1, [non-cancellable io])
AC_DEFINE(NON_CANCELLABLE_IO_SELECT, 1, [non-cancellable select])

# show the user what we do
echo "########################################"
echo "# configuring for target: $target"
echo "#   CPU $target_cpu"
echo "#   OS $target_os"
echo "#   VENDOR $target_vendor"
echo "# on host: $host"
echo "#   CPU $host_cpu"
echo "#   OS $host_os"
echo "#   VENDOR $host_vendor"
echo "########################################"

AC_SUBST(target_cpu)
AC_SUBST(target_os)


dnl Checks for programs.
dnl AC_PROG_CC
AC_PROG_CPP
AC_PROG_CXX
# The uuid tool is C++; AC_PROG_CXX settles for "g++" even if there is none.
AC_LANG_PUSH([C++])
AC_COMPILE_IFELSE([AC_LANG_PROGRAM([[]], [[]])], [],
	[AC_MSG_ERROR([a C++ compiler is needed for the uuid tool (package g++ or gcc-c++)])])
AC_LANG_POP([C++])
AC_PROG_AWK
dnl AC_REQUIRE(AC_CANONICAL_HOST)_LT_SET_OPTION([LT_INIT],[win32-dll])
dnl m4_warn([obsolete],[AC_LIBTOOL_WIN32_DLL: Remove this warning and the call to _LT_SET_OPTION when you put the 'win32-dll' option into LT_INITs first parameter.])

AC_LIBTOOL_SETUP
LT_INIT
AC_PROG_INSTALL
AC_PROG_LN_S
AC_PROG_LEX([noyywrap])
AC_PROG_YACC

# Check whether YACC was set to an empty or invalid command
if test "$YACC" = "yacc" || test "$YACC" = ":"; then
  AC_CHECK_PROG([YACC_CHECK], [yacc], [yes], [no])
  if test "$YACC_CHECK" = "no"; then
    AC_MSG_ERROR([Bison, BYacc or Yacc was not found.])
  fi
fi

# The IDL compiler is written in C23 (nullptr, attributes).  Find the
# option that selects C23; it is put in front of CFLAGS, so a -std option
# given in CFLAGS wins and must not select an older standard.
AC_CACHE_CHECK([for the C compiler option for C23], [rpc_cv_c23_cflags],
[rpc_cv_c23_cflags=no
rpc_save_CFLAGS="$CFLAGS"
for rpc_flag in "" -std=gnu23 -std=gnu2x; do
	CFLAGS="$rpc_flag $rpc_save_CFLAGS"
	AC_COMPILE_IFELSE([AC_LANG_PROGRAM([[]],
		[[void *p = nullptr; (void) p;]])],
		[rpc_cv_c23_cflags="${rpc_flag:-none needed}"])
	test "$rpc_cv_c23_cflags" != no && break
done
CFLAGS="$rpc_save_CFLAGS"])
case $rpc_cv_c23_cflags in
no)
	AC_MSG_ERROR([the IDL compiler needs a C23 compiler (e.g. gcc 13 or later); do not select an older -std in CFLAGS]) ;;
"none needed")
	IDL_C23_CFLAGS= ;;
*)
	IDL_C23_CFLAGS=$rpc_cv_c23_cflags ;;
esac
AC_SUBST(IDL_C23_CFLAGS)

# The OSF code keeps its K&R function definitions; gcc 16 warns about each
# of them with -W.  Turn that warning off if the compiler knows it (the
# positive form is tested: gcc accepts any unknown -Wno- option).  It comes
# before CFLAGS, so -Wold-style-definition given in CFLAGS still wins.
AC_CACHE_CHECK([whether the C compiler knows -Wold-style-definition],
	[rpc_cv_old_style_definition],
[rpc_save_CFLAGS="$CFLAGS"
CFLAGS="$CFLAGS -Werror -Wold-style-definition"
AC_COMPILE_IFELSE([AC_LANG_PROGRAM([[]], [[]])],
	[rpc_cv_old_style_definition=yes], [rpc_cv_old_style_definition=no])
CFLAGS="$rpc_save_CFLAGS"])
DCE_WARN_CFLAGS=
if test "$rpc_cv_old_style_definition" = yes; then
	DCE_WARN_CFLAGS=-Wno-old-style-definition
fi
AC_SUBST(DCE_WARN_CFLAGS)

AC_PATH_PROG(GENCAT, gencat)
AC_PATH_PROG(SED, sed)
AC_SUBST(GENCAT)
AC_SUBST(SED)
AC_OBJEXT
AC_C_INLINE

RPC_ARG_DEFINE(pthreads, ENABLE_PTHREADS, no,Enable pthreads: experimental)
AM_CONDITIONAL(ENABLE_PTHREADS, test x$rpc_arg_pthreads = yes)

dnl AC_CHECK_HEADERS(windows.h)
dnl Checks for libraries.
if test "x$have_win32" = "x1"; then
AC_CHECK_LIB(pthreadGC2, pthread_create)
dnl ENABLE_PTHREADS="yes"
else
AC_CHECK_LIB(pthread, pthread_create)
fi
AC_CHECK_LIB(dl, dlopen)

SAMBA_TNG_DIRS="/usr/local/samba"
AC_ARG_WITH(samba-tng-dir, [  --with-samba-tng-dir   Specify where you have installed Samba (The Next Generation)],
[SAMBA_TNG_DIRS="$withval $SAMBA_TNG_DIRS"])

if test "x$have_win32" = "x1"; then
THREADS_DIRS="/opt/dce-win32"
else
THREADS_DIRS="/opt/dce"
fi

AC_ARG_WITH(dcethreads-dir, [  --with-dcethreads-dir   Specify where you have installed dcethreads],
[THREADS_DIRS="$withval $THREADS_DIRS"])

dnl directory of the rpcd endpoint database (rpcdep.dat)
RPCD_DBDIR="/tmp/"
AC_ARG_WITH(rpcd-dbdir, [  --with-rpcd-dbdir=DIR   Directory of the rpcd endpoint database (default /tmp/)],
[RPCD_DBDIR="$withval"])
case "$RPCD_DBDIR" in
*/) ;;
*) RPCD_DBDIR="$RPCD_DBDIR/" ;;
esac
AC_SUBST(RPCD_DBDIR)

dnl directory of the ncalrpc sockets: endpoint "foo" is the socket <dir>/foo
NCALRPC_DIR="/tmp/.ncalrpc"
AC_ARG_WITH(ncalrpc-dir, [  --with-ncalrpc-dir=DIR  Directory of the ncalrpc sockets (default /tmp/.ncalrpc)],
[NCALRPC_DIR="$withval"])
NCALRPC_DIR=`echo "$NCALRPC_DIR" | sed 's,//*$,,'`
case "$NCALRPC_DIR" in
/?*) ;;
*) AC_MSG_ERROR([--with-ncalrpc-dir needs an absolute directory]) ;;
esac
dnl sun_path has 108 bytes: leave room for "/" and a UUID endpoint (36)
if test `expr "$NCALRPC_DIR" : '.*'` -gt 64; then
    AC_MSG_ERROR([--with-ncalrpc-dir: at most 64 characters])
fi
AC_SUBST(NCALRPC_DIR)

dnl the libraries and headers are searched in <dir>/lib and <dir>/include
THREADS_LIB_DIRS=
THREADS_INC_DIRS=
for i in $THREADS_DIRS; do
	THREADS_LIB_DIRS="$THREADS_LIB_DIRS $i/lib"
	THREADS_INC_DIRS="$THREADS_INC_DIRS $i/include"
done

echo "enable_pthreads: " $ENABLE_PTHREADS

if test "x$ENABLE_PTHREADS" != "xyes"; then
RPC_CHECK_LIBDIR(pthd4exc_create, dcethreads, $THREADS_LIB_DIRS,,
AC_MSG_ERROR([freedce requires libdcethreads!]))
else
RPC_CHECK_LIBDIR(dcethreads_exc_lib_init, dcethreads, $THREADS_LIB_DIRS,,
AC_MSG_ERROR([freedce requires libdcethreads!]))
fi

dnl Checks for header files.
AC_CHECK_HEADERS(features.h sys/cdefs.h dlfcn.h)
RPC_CHECK_INCDIR(dce/pthread_exc.h, dcethreads, $THREADS_INC_DIRS,,
AC_MSG_ERROR([freedce requires dcethreads include files!]))
DCETHREADINCLUDES=
if test "x$rpc_cv_incdir_dcethreads" != "xnone required"; then
	DCETHREADINCLUDES="-I$rpc_cv_incdir_dcethreads"
fi
AC_SUBST(DCETHREADINCLUDES)


dnl Checks for typedefs, structures, and compiler characteristics.

dnl Checks for library functions.
dnl AC_REQUIRE(AC_PROG_CC)
AC_PROG_CC
AC_FUNC_MEMCMP

dnl _GNU_SOURCE pulls in the definition of _pthread_push_defer
AC_DEFINE([_BSD], [], [Description])
AC_DEFINE([_GNU_SOURCE], [], [Description])
AC_DEFINE([_REENTRANT], [], [Description])


dnl This allows us to re-use AC_OUTPUT which makes things more maintainable
dnl and helps us to use automake nicely.
dnl it is defined here and not in acinclude.m4 because acgeneral.m4 gets
dnl parsed AFTER acinclude.m4
pushdef([AC_OUTPUT], 
[define([RPC_OUTPUT_FILES], ifdef([RPC_OUTPUT_FILES], RPC_OUTPUT_FILES ,)[$1])]
)

RPC_ARG_DEFINE(debug, DEBUG, yes,Compile with debugging support)

RPC_ARG_DEFINE(dcom, ENABLE_DCOM, no,Enable experimental DCOM support)
AM_CONDITIONAL(ENABLE_DCOM, test x$rpc_arg_dcom = yes)
AM_CONDITIONAL(TARGET_OS_LINUX, test x$target_os = xlinux-gnu)
AM_CONDITIONAL(TARGET_OS_WIN32, test x$have_win32 = x1)

dnl ============= include subdirs here
sinclude(uuid/config.m4)
sinclude(include/config.m4)
sinclude(idl/config.m4)
sinclude(idllib/config.m4)
sinclude(ncklib/config.m4)
sinclude(ncklib/transport/config.m4)
sinclude(ncklib/auth/config.m4)
sinclude(ncklib/rpc/config.m4)
sinclude(ncklib/codeset/config.m4)
sinclude(ncklib/com/config.m4)
sinclude(ncklib/naf/config.m4)
sinclude(dcelib/config.m4)
sinclude(rpcd/config.m4)
sinclude(demos/config.m4)
sinclude(demos/echo_server/config.m4)
sinclude(dcom/config.m4)
sinclude(perf/config.m4)


AC_CONFIG_FILES(Makefile)
AC_CONFIG_FILES(dcelib/Makefile)
AC_CONFIG_FILES(idl/Makefile)
AC_CONFIG_FILES(idl/sysdep.h)
AC_CONFIG_FILES(perf/Makefile)
AC_CONFIG_FILES(tests/Makefile)
AC_CONFIG_FILES(tests/loadtest/Makefile)
AC_CONFIG_FILES(tests/errtext/Makefile)
AC_CONFIG_FILES(uuid/Makefile)
AC_CONFIG_FILES(uuid/tool/Makefile)
AC_CONFIG_FILES(include/dce/Makefile)
AC_CONFIG_FILES(include/Makefile)
AC_CONFIG_FILES(ncklib/com/Makefile)
AC_CONFIG_FILES(ncklib/rpc/Makefile)
AC_CONFIG_FILES(ncklib/transport/dg/Makefile)
AC_CONFIG_FILES(ncklib/transport/cn/Makefile)
AC_CONFIG_FILES(ncklib/transport/Makefile)
AC_CONFIG_FILES(ncklib/codeset/Makefile)
AC_CONFIG_FILES(ncklib/auth/Makefile)
AC_CONFIG_FILES(ncklib/naf/Makefile)
AC_CONFIG_FILES(ncklib/Makefile)
AC_CONFIG_FILES(demos/lsa/Makefile)
AC_CONFIG_FILES(demos/ntsec/Makefile)
AC_CONFIG_FILES(demos/Makefile)
AC_CONFIG_FILES(demos/samr/Makefile)
AC_CONFIG_FILES(demos/echo_server/Makefile)
AC_CONFIG_FILES(dcom/Makefile)
AC_CONFIG_FILES(idllib/Makefile)
AC_CONFIG_FILES(rpcd/Makefile)
AC_CONFIG_FILES(config.mk)
#AC_CONFIG_FILES([Makefile ild/Makefile config.mk])
AC_OUTPUT

dnl restore original AC_OUTPUT definition
popdef([AC_OUTPUT])

dnl call AC_OUTPUT with the list of files we accumulated.
dnl automake will complain about RPC_OUTPUT_FILES.in, so
dnl we include a dummy file to keep it quiet.
AC_CONFIG_FILES([RPC_OUTPUT_FILES])
AC_OUTPUT

