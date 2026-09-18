dnl Process this file with autoconf to produce a configure script.
AC_INIT([dcethreads],[2.0.2])
AC_CONFIG_SRCDIR(src/exc_handling.c)
AC_CANONICAL_TARGET
AC_CONFIG_HEADERS([include/dce/dcethreads_conf.h])
AM_INIT_AUTOMAKE
AC_PREFIX_DEFAULT(/opt/dce)
AC_SUBST([LT_VERSION],[2:2:0])

AC_USE_SYSTEM_EXTENSIONS

AC_DEFINE([_POSIX_SOURCE], [1], [internally posix is needed])
AC_DEFINE([_POSIX_C_SOURCE], [200809L], [internally posix is needed])

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
        i?86)   target_cpu="i386";;
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

AM_CONDITIONAL(TARGET_OS_LINUX, test x$target_os = xlinux-gnu)
AM_CONDITIONAL(TARGET_OS_WIN32, test x$have_win32 = x1)

if test "x$have_win32" = "x1"; then
        AC_DEFINE(HAVE_OS_WIN32, 1, [Define, if target is win32])
        dnl LIBS="$LIBS -lntdll ";
        WIN32_PROG_PREFIX=".exe"
        dnl AC_SUBST(WIN32_PROG_PREFIX)
        dnl AC_DEFINE(PTW32_STATIC_LIB, 1, [Define, if using static pthreadwin32])
        dnl AC_SUBST(PTW32_STATIC_LIB)
fi
dnl Checks for programs.
LT_INIT
AC_PROG_AWK
AC_PROG_CC
AC_PROG_CPP
AC_PROG_INSTALL
AC_PROG_LN_S

dnl Checks for libraries.
if test "x$have_win32" = "x1"; then
AC_CHECK_LIB(ws2_32, main)
AC_CHECK_LIB(pthreadGC2, pthread_create)
#AC_CHECK_LIB(iphlpapi, main)
#AC_CHECK_LIB(ws2_32, main)
else
AC_CHECK_LIB(pthread, pthread_create)
fi


dnl Checks for header files.
dnl m4_warn([obsolete],
dnl [The preprocessor macro 'STDC_HEADERS' is obsolete.
dnl   Except in unusual embedded environments, you can safely include all
dnl   C89 headers unconditionally.])dnl
# Autoupdate added the next two lines to ensure that your configure
# script's behavior did not change.  They are probably safe to remove.
AC_CHECK_INCLUDES_DEFAULT
AC_PROG_EGREP

AC_HEADER_SYS_WAIT
AC_CHECK_HEADERS(fcntl.h malloc.h sys/time.h unistd.h features.h sys/cdefs.h)

dnl Checks for typedefs, structures, and compiler characteristics.
AC_C_CONST
AC_C_INLINE
AC_TYPE_MODE_T
AC_TYPE_OFF_T
AC_TYPE_SIZE_T
dnl m4_warn([obsolete],
dnl [Update your code to rely only on HAVE_SYS_TIME_H,
dnl then remove this warning and the obsolete code below it.
dnl All current systems provide time.h; it need not be checked for.
dnl Not all systems provide sys/time.h, but those that do, all allow
dnl you to include it and time.h simultaneously.])dnl
AC_CHECK_HEADERS_ONCE([sys/time.h])
# Obsolete code to be removed.
# if test $ac_cv_header_sys_time_h = yes; then
#   AC_DEFINE([TIME_WITH_SYS_TIME],[1],[Define to 1 if you can safely include both <sys/time.h>
# 	     and <time.h>.  This macro is obsolete.])
# fi
# End of obsolete code.

AC_CHECK_TYPES(ssize_t)

dnl Checks for library functions.
dnl m4_warn([obsolete],
dnl [AC_PROG_GCC_TRADITIONAL is obsolete; use AC_PROG_CC
dnl ])dnl
dnl AC_REQUIRE(AC_PROG_CC)
AC_FUNC_MEMCMP
AC_CHECK_FUNCS(gettimeofday)

AC_DEFINE(YIELD_AFTER_PTHREAD_CREATE, 1)

AC_DEFINE(USE_CANCELATION_WRAPPER, 1)

AC_MSG_CHECKING([sighandler signature]); 
AC_COMPILE_IFELSE([AC_LANG_SOURCE([[
#include <signal.h>

extern void mne_sig_act(int, int);

void mne_setup()
{

struct sigaction sa = {0};
sa.sa_handler = &mne_sig_act;
}

]])],
[AC_MSG_RESULT([SIG 2]) AC_DEFINE(HAVE_SIGHANDLER, 2, [void(*)(int, int)])],
[
	AC_COMPILE_IFELSE([AC_LANG_SOURCE([[
#include <signal.h>

extern void mne_sig_act(int);

void mne_setup()
{

struct sigaction sa = {0};
sa.sa_handler = &mne_sig_act;
}

]])])

	AC_MSG_RESULT([SIG 1]) AC_DEFINE(HAVE_SIGHANDLER, 1, [void(*)(int)], AC_MSG_ERROR([no signal handler]))
]	
)

dnl check if glibc functions are true cancellation points
dnl

dnl  if test "x$have_win32" == "x1"; then
dnl  AC_DEFINE(USE_CANCELATION_WRAPPER, 1)
dnl  else
dnl  
dnl  AC_MSG_CHECKING([POSIX cancellation point]); 
dnl  AC_RUN_IFELSE([AC_LANG_SOURCE([[
dnl  #include <pthread.h>
dnl  #include <unistd.h>
dnl  #include <errno.h>
dnl  #include <time.h>
dnl  #include <stdlib.h>
dnl  #include <assert.h>
dnl  
dnl  int eintr=0; 
dnl  
dnl  void*
dnl  thread(void* unused)
dnl  {
dnl    struct timespec req={5,0}, rem; 
dnl    int    status; 
dnl  
dnl    do {
dnl      status = nanosleep(&req, &rem);
dnl    }
dnl    while (status!=-1);
dnl    
dnl    eintr = (errno==EINTR);
dnl    pthread_exit (NULL);
dnl  }
dnl  
dnl  int
dnl  main()
dnl  {
dnl    pthread_t thrid; 
dnl  
dnl    assert (pthread_create(&thrid, NULL, thread, NULL)==0);
dnl    sleep(1);
dnl    assert (pthread_cancel (thrid)==0);
dnl    sleep(1);
dnl    exit (eintr);
dnl  }
dnl  ]])],
dnl  	[AC_MSG_RESULT([yes]) ],
dnl  	[AC_MSG_RESULT([no]) AC_DEFINE(USE_CANCELATION_WRAPPER, 1)]	
dnl  )
dnl  fi # have_win32

AC_CONFIG_FILES([Makefile include/Makefile include/dce/Makefile src/Makefile tests/Makefile])
AC_OUTPUT
