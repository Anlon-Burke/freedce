AC_OUTPUT(include/Makefile)
AC_OUTPUT(include/dce/Makefile)

# Create symlinks for os and cpu dependent files

if test "x$target_os" = x; then
	echo "error: target_os not set $target_os"
	exit 1;
fi
AC_MSG_RESULT([Generating os dependent symlinks for $target_os])
if test ! -d $ac_abs_confdir/include/dce/$target_os; then
	echo "error: operating system $target_os not supported"
	exit 1;
fi
if test ! -d $ac_pwd/include; then
	mkdir "include"
fi
if test ! -d $ac_pwd/include/dce; then
	mkdir "include/dce"
fi
osdepheaders=`cd $ac_abs_confdir/include/dce/$target_os && echo *.h`
for header in $osdepheaders ; do
	# in a build in the source tree the link must not replace a source header
	# (a copy of the linked file, where ln made one, is fine)
	if test -f include/dce/$header && test ! -h include/dce/$header \
	   && ! cmp -s include/dce/$header $ac_abs_confdir/include/dce/$target_os/$header; then
		AC_MSG_ERROR([include/dce/$header is a file: the link to $target_os/$header would replace it])
	else
		ln -sf $ac_abs_confdir/include/dce/$target_os/$header include/dce/$header
	fi
done;
unset osdepheaders

if test "x$target_cpu" = x; then
	echo "error target_cpu not set $target_cpu"
	exit 1;
fi
AC_MSG_RESULT([Generating cpu dependent symlinks for $target_cpu])
if test ! -d $ac_abs_confdir/include/dce/$target_cpu; then
	echo "error: architecture $target_cpu not supported"
	exit 1;
fi
cpudepheaders=`cd $ac_abs_confdir/include/dce/$target_cpu && echo *.h`
for header in $cpudepheaders ; do
	if test -f include/dce/$header && test ! -h include/dce/$header \
	   && ! cmp -s include/dce/$header $ac_abs_confdir/include/dce/$target_cpu/$header; then
		AC_MSG_ERROR([include/dce/$header is a file: the link to $target_cpu/$header would replace it])
	else
		ln -sf $ac_abs_confdir/include/dce/$target_cpu/$header include/dce/$header
	fi
done;
unset cpudepheaders

