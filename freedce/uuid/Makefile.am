## Process this file with automake to produce Makefile.in
# Makefile for the UUID functions.  They are part of libdcerpc (a separate
# libuuid.so.1 would clash with the util-linux library of the same name);
# the uuid tool is built in tool/, after libdcerpc.

include $(top_srcdir)/include.mk

if TARGET_OS_WIN32
LIBS += -lkernel32 -lrpcrt4
endif

noinst_LTLIBRARIES = libdceuuid.la
if TARGET_OS_WIN32
libdceuuid_la_SOURCES = uuid.c uuidsys.c get_ether_addr.c win32timeofday.c win32uuid.c win32mem.c
else
libdceuuid_la_SOURCES = uuid.c uuidsys.c get_ether_addr.c 
endif

noinst_HEADERS= uuid_i.h
