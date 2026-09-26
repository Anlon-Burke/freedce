## Process this file with automake to produce Makefile.in
include $(top_srcdir)/include.mk
include $(top_srcdir)/ncklib/ncklib.mk

AM_CFLAGS+=-I$(IDL_INCLUDE_DIR)/.. -I$(top_builddir)/include 
if PROT_NCADG

idlobjs=conv_cstub.lo convc_cstub.lo convc_sstub.lo


lib_LTLIBRARIES=libprot_ncadg.la

libprot_ncadg_la_LDFLAGS = -version-info $(LT_VERSION)

libprot_ncadg_la_SOURCES= conv.c dg.c dgcall.c dgccall.c \
 dgccallt.c dgcct.c dgclive.c dgclsn.c dgexec.c dgfwd.c \
 dgglob.c dghnd.c dginit.c dglossy.c dglsn.c dgpkt.c dgrq.c \
 dgscall.c dgsct.c dgslive.c dgslsn.c dgsoc.c dgutl.c dgxq.c

libprot_ncadg_la_LIBADD=$(idlobjs)

conv_cstub.lo:	$(IDL_INCLUDE_DIR)/conv.idl
	$(IDL) $(NCK_IDLFLAGS) -cepv -server none $<

# One dceidl run creates both stubs; the stamp makes it run only once, also
# with "make -j" (see "Multiple Outputs" in the automake manual).
convc.stamp: $(IDL_INCLUDE_DIR)/convc.idl
	@rm -f convc.tmp; touch convc.tmp
	$(IDL) $(NCK_IDLFLAGS) -cepv $(IDL_INCLUDE_DIR)/convc.idl
	@mv -f convc.tmp $@
convc_cstub.lo convc_sstub.lo convc_cstub.c convc_sstub.c: convc.stamp
	@test -f $@ || rm -f convc.stamp
	@test -f $@ || $(MAKE) $(AM_MAKEFLAGS) convc.stamp

CLEANFILES=conv.h convc.h convc.stamp
endif
