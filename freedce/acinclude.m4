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
AC_DEFUN([RPC_CHECK_LIBDIR],
dnl RPC_CHECK_LIBDIR(func, library, dirs,action-present,action-notpresent)
[AC_PREREQ([2.13])
AC_CACHE_CHECK([for -l$2 in one of $3], [rpc_cv_libdir_$2],
	[
	rpc_func_save_LIBS="$LIBS"
	rpc_func_save_LDFLAGS="$LDFLAGS"
	rpc_cv_libdir_$2="no"
	AC_LINK_IFELSE([AC_LANG_CALL([], [$1])], [rpc_cv_libdir_$2="none required"], [])
	if test "$rpc_cv_libdir_$2" = "no"; then
		LIBS="-l$2 $rpc_func_save_LIBS"
		AC_LINK_IFELSE([AC_LANG_CALL([], [$1])], [rpc_cv_libdir_$2="none required"], [])
		if test "$rpc_cv_libdir_$2" = "no"; then
			dnl the lib not found in default location also iterate
			for i in $3; do
				LDFLAGS="-L$i $rpc_func_save_LDFLAG"
				AC_LINK_IFELSE([AC_LANG_CALL([], [$1])], [rpc_cv_libdir_$2="$i"], [])
				if test "$rpc_cv_libdir_$2" != "no"; then
					break
				fi
			done
		fi
	fi
	LDFLASG=rpc_func_save_LDFLAGS
	LIBS=rpc_func_save_LIBS
if test "$rpc_cv_libdir_$2" != "no"; then
	AC_MSG_NOTICE([XXX-REGULAR-MNE checking for $1 in <$2> LIBS=<$LIBS>])
	LIBS="-l$2 $LIBS"
	test "$rpc_cv_libdir_$2" = "none required" || {
		LDFLAGS="-L$rpc_cv_libdir_$2 $LDFLAGS"
		AC_MSG_RESULT([found in $rpc_cv_libdir_$2])
	}
	$4
else	:
	$5
fi])])

dnl Find out where the dcethreads includes has been installed
AC_DEFUN([RPC_CHECK_INCDIR],
dnl RPC_CHECK_LIBDIR(header, desc, dirs, action-present, action-notpresent)
[AC_PREREQ([2.13])
AC_CACHE_CHECK([for $2 header in one of $3], [rpc_cv_incdir_$2],
[rpc_cv_incdir_$2="no"
AC_MSG_NOTICE([.])
AC_MSG_NOTICE([MNE CHKI ARG1=<$1>, ARG2=<$2>, ARG3=<$3>])
AC_CHECK_HEADER($1, [rpc_cv_incdir_$2="none required"])
test "$rpc_cv_incdir_$2" = "no" && for i in $3; do
AC_MSG_NOTICE([MNE CHKI i=<$i>, KETTE=<$i/$1>])
	AC_CHECK_HEADER($i/$1,
		[rpc_cv_incdir_$2="$i/$1"
		break])
done])
if test "$rpc_cv_incdir_$2" = "no"; then
	unset rpc_cv_incdir_$2
	$5
else
	test "$rpc_cv_incdir_$2" = "none required" || {
		AC_MSG_RESULT([found in $rpc_cv_incdir_$2])
	}
	test "$rpc_cv_incdir_$2" = "none required" && unset rpc_cv_incdir_$2
	$4
fi])
