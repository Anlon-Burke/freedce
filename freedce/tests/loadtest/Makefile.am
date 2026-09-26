## Process this file with automake to produce Makefile.in
include $(top_srcdir)/include.mk

IDL_FLAGS=-I$(IDL_INCLUDE_DIR)/.. -I$(top_builddir)/include $(DCETHREADINCLUDES)
IDLCC=-I$(top_builddir)/include -I$(IDL_INCLUDE_DIR)/.. \
	-cc_cmd "$(CC) -D_BSD $(IDL_FLAGS) $(IDL_CFLAGS) -c"

libs=$(top_builddir)/dcelib/libdcerpc.la \
	$(top_builddir)/uuid/libuuid.la -lstdc++

noinst_PROGRAMS=lt_server lt_client

lt_server_SOURCES=lt_server.c lt_data.c lt_data.h lt_port.h
lt_client_SOURCES=lt_client.c lt_data.c lt_data.h lt_port.c lt_port.h

lt_server_LDADD=loadtest_sstub.o $(libs)
lt_client_LDADD=loadtest_cstub.o $(libs)

# "make check" runs a short load test against a local server (run_check.sh).
TESTS=run_check.sh
EXTRA_DIST=loadtest.idl run_check.sh README build_win.cmd

BUILT_SOURCES=loadtest.h
CLEANFILES=loadtest.h loadtest_sstub.o loadtest_cstub.o loadtest.stamp lt_server.log

# One dceidl run creates the header and both stubs; the stamp makes it run
# only once, also with "make -j" (see "Multiple Outputs" in the automake
# manual).
loadtest.stamp: loadtest.idl
	@rm -f loadtest.tmp; touch loadtest.tmp
	$(IDL) $(IDLCC) $(srcdir)/loadtest.idl
	@mv -f loadtest.tmp $@
loadtest_cstub.o loadtest_sstub.o loadtest.h: loadtest.stamp
	@test -f $@ || rm -f loadtest.stamp
	@test -f $@ || $(MAKE) $(AM_MAKEFLAGS) loadtest.stamp
