## Process this file with automake to produce Makefile.in
include $(top_srcdir)/include.mk

IDL_FLAGS=-I$(IDL_INCLUDE_DIR)/.. -I$(top_builddir)/include $(DCETHREADINCLUDES)
IDLCC=-I../include -no_mepv -cc_cmd "$(CC) -D_BSD $(IDL_FLAGS) $(IDL_CFLAGS) -c" $(IDL_INCS)

libs=$(top_builddir)/dcelib/libdcerpc.la \
	$(top_builddir)/uuid/libuuid.la -lstdc++ -lm

all-local: client server

EXTRA_PROGRAMS=client server
# "make check" runs the suite against a local server (see run_tests.sh);
# client and server are built by "all", which "check" depends on.
TESTS=run_tests.sh
EXTRA_DIST=run_tests.sh perf_tcp.sh perf_udp.sh

client_SOURCES=client.c 
server_SOURCES=server.c perf.c

client_LDADD=perf_cstub.o perfb_cstub.o perfc_sstub.o perfg.o perfg_cstub.o util.o $(libs)
server_LDADD=perf_sstub.o perfb_sstub.o perfc_cstub.o perfg.o perfg_sstub.o perfb.o util.o $(libs)

# All sources include the generated headers.
BUILT_SOURCES=perf.h perfb.h perfc.h perfg.h
CLEANFILES=perf.h perfb.h perfc.h perfg.h server client \
           perf_sstub.o perfb_sstub.o perfc_sstub.o perfg_sstub.o \
           perf_cstub.o perfb_cstub.o perfc_cstub.o perfg_cstub.o \
           perf.stamp perfb.stamp perfc.stamp perfg.stamp server.log

# Each dceidl run creates a header and two stub objects.  The stamp files
# make sure that it runs only once per IDL file, also with "make -j"
# (see "Multiple Outputs" in the automake manual).
perf.stamp: perf.idl perf.acf
	@rm -f perf.tmp; touch perf.tmp
	$(IDL) $(IDLCC) perf.idl
	@mv -f perf.tmp $@
perf_cstub.o perf_sstub.o perf.h: perf.stamp
	@test -f $@ || rm -f perf.stamp
	@test -f $@ || $(MAKE) $(AM_MAKEFLAGS) perf.stamp

perfb.stamp: perfb.idl
	@rm -f perfb.tmp; touch perfb.tmp
	$(IDL) $(IDLCC) perfb.idl
	@mv -f perfb.tmp $@
perfb_cstub.o perfb_sstub.o perfb.h: perfb.stamp
	@test -f $@ || rm -f perfb.stamp
	@test -f $@ || $(MAKE) $(AM_MAKEFLAGS) perfb.stamp

perfc.stamp: perfc.idl
	@rm -f perfc.tmp; touch perfc.tmp
	$(IDL) $(IDLCC) perfc.idl
	@mv -f perfc.tmp $@
perfc_cstub.o perfc_sstub.o perfc.h: perfc.stamp
	@test -f $@ || rm -f perfc.stamp
	@test -f $@ || $(MAKE) $(AM_MAKEFLAGS) perfc.stamp

perfg.stamp: perfg.idl
	@rm -f perfg.tmp; touch perfg.tmp
	$(IDL) $(IDLCC) perfg.idl
	@mv -f perfg.tmp $@
perfg_cstub.o perfg_sstub.o perfg.h: perfg.stamp
	@test -f $@ || rm -f perfg.stamp
	@test -f $@ || $(MAKE) $(AM_MAKEFLAGS) perfg.stamp

