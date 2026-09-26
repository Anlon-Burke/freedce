## Process this file with automake to produce Makefile.in
include $(top_srcdir)/include.mk

SUBDIRS=idl include idllib uuid ncklib dcelib uuid/tool rpcd dcom demos . perf tests

EXTRA_DIST=include.mk 

dist-hook:
	-chmod -R a+r $(distdir)
	$(TAR) choIf $(distdir).tar.bz2 $(distdir)

