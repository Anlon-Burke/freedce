dnl $Revision: 1.7 $
AC_DEFUN([RPC_ARG_DEFINE],
[
AC_ARG_ENABLE($1,
dnl $1=option name
dnl $2=symbol name
dnl $3=if yes, then enable by default
dnl $4=help string
[  --enable-$1		$4 (default=$3)],
[
 case "${enableval}" in
	yes)
		AC_DEFINE($2, 1, [$4])
		rpc_arg_$1=yes
		;;
	no)
		;;
	*)
		AC_MSG_ERROR(bad value ${enableval} for --enable-$1)
		;;
	esac
],
if test "x$3" = "xyes" ; then
	rpc_arg_$1=yes;
	AC_DEFINE($2, 1, [$4])
fi
)
])

dnl Find out where the dcethreads library has been installed
dnl RPC_CHECK_LIBDIR(func, library, dirs, action-present, action-notpresent)
dnl On success -l<library> is added to LIBS and, if the library was found
dnl in one of <dirs>, -L<dir> to LDFLAGS.
AC_DEFUN([RPC_CHECK_LIBDIR],
[AC_CACHE_CHECK([for -l$2 in one of $3], [rpc_cv_libdir_$2],
[rpc_func_save_LIBS="$LIBS"
rpc_func_save_LDFLAGS="$LDFLAGS"
rpc_cv_libdir_$2="no"
LIBS="-l$2 $rpc_func_save_LIBS"
AC_LINK_IFELSE([AC_LANG_CALL([], [$1])], [rpc_cv_libdir_$2="none required"])
if test "$rpc_cv_libdir_$2" = "no"; then
	for i in $3; do
		LDFLAGS="-L$i $rpc_func_save_LDFLAGS"
		AC_LINK_IFELSE([AC_LANG_CALL([], [$1])], [rpc_cv_libdir_$2="$i"])
		test "$rpc_cv_libdir_$2" != "no" && break
	done
fi
LIBS="$rpc_func_save_LIBS"
LDFLAGS="$rpc_func_save_LDFLAGS"])
if test "$rpc_cv_libdir_$2" != "no"; then
	LIBS="-l$2 $LIBS"
	test "$rpc_cv_libdir_$2" = "none required" || LDFLAGS="-L$rpc_cv_libdir_$2 $LDFLAGS"
	$4
else	:
	$5
fi])

dnl Find out where the dcethreads includes have been installed
dnl RPC_CHECK_INCDIR(header, desc, dirs, action-present, action-notpresent)
dnl The cache variable rpc_cv_incdir_<desc> is set to "none required" or to
dnl the directory that has to be added with -I.
AC_DEFUN([RPC_CHECK_INCDIR],
[AC_CACHE_CHECK([for $2 headers in one of $3], [rpc_cv_incdir_$2],
[rpc_func_save_CPPFLAGS="$CPPFLAGS"
rpc_cv_incdir_$2="no"
AC_PREPROC_IFELSE([AC_LANG_SOURCE([[#include <$1>]])], [rpc_cv_incdir_$2="none required"])
if test "$rpc_cv_incdir_$2" = "no"; then
	for i in $3; do
		CPPFLAGS="-I$i $rpc_func_save_CPPFLAGS"
		AC_PREPROC_IFELSE([AC_LANG_SOURCE([[#include <$1>]])], [rpc_cv_incdir_$2="$i"])
		test "$rpc_cv_incdir_$2" != "no" && break
	done
fi
CPPFLAGS="$rpc_func_save_CPPFLAGS"])
if test "$rpc_cv_incdir_$2" != "no"; then
	$4
else	:
	$5
fi])
