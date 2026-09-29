## Process this file with automake to produce Makefile.in
include $(top_srcdir)/include.mk

# "make check": the built-in texts of dce_error_inq_text()
check_PROGRAMS=errtext
errtext_SOURCES=errtext.c
errtext_LDADD=$(top_builddir)/dcelib/libdcerpc.la
TESTS=errtext
