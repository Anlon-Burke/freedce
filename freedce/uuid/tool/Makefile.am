## Process this file with automake to produce Makefile.in
# Makefile for the UUID generation tool

include $(top_srcdir)/include.mk

bin_PROGRAMS = uuid
uuid_SOURCES = uuidtool.cpp uuid-cpp.cpp
uuid_LDADD = $(top_builddir)/dcelib/libdcerpc.la -lstdc++

noinst_HEADERS = uuid.hpp
