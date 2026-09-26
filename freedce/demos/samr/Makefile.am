## Process this file with automake to produce Makefile.in
include $(top_srcdir)/include.mk

IDL_FLAGS= -I$(IDL_INCLUDE_DIR)/.. -I$(top_builddir)/include $(DCETHREADINCLUDES)

install-strip:	install

bin_PROGRAMS=samr_server samr_client

samr_server_SOURCES=misc.c samr_server.c
samr_client_SOURCES=misc.c samr_client.c

noinst_HEADERS=misc.h samr.idl samr.acf

BUILT_SOURCES=samr.h
CLEANFILES=samr.h samr_sstub.o samr_cstub.o samr.stamp

libs=$(top_builddir)/dcelib/libdcerpc.la

samr_server_LDADD=samr_sstub.o $(libs)
samr_client_LDADD=samr_cstub.o $(libs)

# One dceidl run creates the header and both stubs; the stamp makes it run
# only once, also with "make -j" (see "Multiple Outputs" in the automake
# manual).
samr.stamp: samr.idl samr.acf
	@rm -f samr.tmp; touch samr.tmp
	$(IDL) $(IDL_FLAGS) $(top_srcdir)/demos/samr/samr.idl
	@mv -f samr.tmp $@
samr.h samr_sstub.o samr_cstub.o: samr.stamp
	@test -f $@ || rm -f samr.stamp
	@test -f $@ || $(MAKE) $(AM_MAKEFLAGS) samr.stamp

