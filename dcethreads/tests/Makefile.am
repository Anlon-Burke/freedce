## Process this file with automake to produce Makefile.in

# See src/Makefile.am: no default -I for include/dce.
AUTOMAKE_OPTIONS = nostdinc
AM_CPPFLAGS = -I$(top_builddir)/include -I$(top_srcdir)/include

EXTRA_PROGRAMS = test1 test2 test3 test3var test4 test5 test6 test7
TESTS=test1 test2 test3 test3var test4 invert-test5 test6 test7
EXTRA_DIST=inverttest

DEFS = -DCOMPILING_DCETHREADS# -I. -I$(srcdir)
if TARGET_OS_WIN32
CFLAGS+= $(INCLUDES)
CFLAGS+= -DHAVE_OS_WIN32
endif


CLEANFILES=$(EXTRA_PROGRAMS) $(TESTS)

if TARGET_OS_WIN32
THREADLIB=$(top_builddir)/src/libdcethreads.la
else
THREADLIB=$(top_builddir)/src/libdcethreads.la -ldl
endif

# Create a symlink to our generic result inverting script.
# If it is possible to adjust the command line that "make check" runs, then a
# better way to do this is to just use the shell to invert the result.
invert-test5: test5
	-ln -sf $(srcdir)/inverttest $@

if TARGET_OS_WIN32
bin_PROGRAMS=test1 test2 test3 test4 test5
endif

test1_SOURCES=test1.c
test1_LDADD = $(THREADLIB)

test2_SOURCES=test2.c
test2_LDADD = $(THREADLIB)

test3_SOURCES=test3.c
test3_LDADD = $(THREADLIB)

test3var_SOURCES=test3var.c
test3var_LDADD = $(THREADLIB)


test4_SOURCES=test4.c
test4_LDADD = $(THREADLIB)

test5_SOURCES=test5.c
test5_LDADD = $(THREADLIB)

test6_SOURCES=test6.c
test6_LDADD = $(THREADLIB)

test7_SOURCES=test7.c
test7_LDADD = $(THREADLIB)

#test_atfork1_SOURCES=test_atfork1.c
#test_atfork1_LDADD = $(THREADLIB)
