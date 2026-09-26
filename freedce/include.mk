include $(top_builddir)/config.mk

# Generated headers (from .idl files, dce_config.h) and the links to the
# OS/CPU specific headers are in the build tree, the other headers in the
# source tree.  <config.h> is include/dce/config.h; in a build in the
# source tree the automake default -I$(top_builddir)/include/dce finds it.
dce_includes=-I$(top_builddir)/include -I$(top_srcdir)/include $(DCETHREADINCLUDES) \
	-I$(top_srcdir)/include/dce

# DRAT.  DO_NOT_CLOBBER (gcc being too smart) no longer works
#CFLAGS= -g -Wall -W -O -pipe -Werror
AM_CFLAGS=-g -Wall -W -pipe

AM_CPPFLAGS=$(dce_includes)

SUFFIXES=.idl

if TARGET_OS_WIN32
# assume cross-compiling for now: hardcode the damn path.  oh well.
IDL=/opt/dce/bin/dceidl
else
IDL=$(top_builddir)/idl/dceidl$(WIN32_PROG_PREFIX)
endif

IDL_INCLUDE_DIR=$(top_srcdir)/include/dce

IDLFLAGS=$(IDL_CFLAGS) -cepv -client none -server none -I$(top_builddir)/include -I$(IDL_INCLUDE_DIR)/..
NCK_IDLFLAGS=-keep object -no_cpp -v -no_mepv -I$(top_builddir)/include -I$(IDL_INCLUDE_DIR)/.. -I$(top_srcdir)/include $(DCETHREADINCLUDES) $(TARGET_OS) -cc_cmd '$(LIBTOOL) --mode=compile $(IDL_CC) -c $(IDL_CFLAGS) '

%.h: %.idl
	$(IDL) $(IDLFLAGS) -no_mepv $<

# Create default message strings from a msg file
#%_defmsg.h:	%.msg
#	echo $(RM) $(RMFLAGS) $@
#	echo $(SED) -e '/^\$$/d;/^$$/d;s/^[^ ]* /"/;s/$$/",/;' $< > $@

#%.cat:	%.msg
#	$(RM) $(RMFLAGS) $@
#	$(GENCAT) $@ $<
