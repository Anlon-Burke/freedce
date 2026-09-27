## Process this file with automake to produce Makefile.in

# The config header lives in include/dce, next to the DCE pthread.h; the
# default -I for it would hide the system pthread.h in an in-tree build.
AUTOMAKE_OPTIONS = nostdinc
AM_CFLAGS= -Wall -W -Werror -pipe
DEFS = -DCOMPILING_DCETHREADS -D_GNU_SOURCE -D_REENTRANT
AM_CPPFLAGS = -I$(top_builddir)/include -I$(top_srcdir)/include

#  Build the exception/thread library
lib_LTLIBRARIES = libdcethreads.la
#libdcethreads_la_LDFLAGS = -version-info 2:1:0 -Wl,--version-script,./RELEASE
libdcethreads_la_LDFLAGS = -version-info $(LT_VERSION)
libdcethreads_la_SOURCES = \
    exc_handling.c \
    pthread_dce.c \
    pthread_dceexc.c

if TARGET_OS_LINUX
    libdcethreads_la_SOURCES+=pthread_dce_atfork.c \
                              pthd4_cancel.c \
                              pthd4_libc_wrapers.c

endif

noinst_HEADERS = pthread_dce_atfork.h pthd4_cancel.h

#EXTRA_DIST = Versions
