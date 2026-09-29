## Process this file with automake to produce Makefile.in
include $(top_srcdir)/include.mk
include $(top_srcdir)/ncklib/ncklib.mk

noinst_LTLIBRARIES=librpc.la

librpc_la_SOURCES=dce_error.c rpcclock.c rpcdbg.c rpclist.c \
 rpclog.c rpcmem.c rpcmutex.c rpcrand.c rpctimer.c

# Built-in texts of dce_error_inq_text(), generated from the status IDLs
ERRTAB_INPUTS=$(srcdir)/dce_error_texts.txt $(top_srcdir)/include/dce/rpcsts.idl \
 $(top_srcdir)/include/dce/ncastat.idl
BUILT_SOURCES=dce_error_table.h
CLEANFILES=dce_error_table.h
EXTRA_DIST=mkerrtab.awk dce_error_texts.txt

dce_error_table.h: $(srcdir)/mkerrtab.awk $(ERRTAB_INPUTS)
	$(AWK) -f $(srcdir)/mkerrtab.awk $(ERRTAB_INPUTS) > $@.tmp
	mv -f $@.tmp $@

