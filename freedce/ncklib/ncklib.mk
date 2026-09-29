AM_CPPFLAGS+=-I$(top_srcdir)/ncklib/include -I$(top_srcdir)/ncklib/include/$(target_os)
AM_CFLAGS+=-DNCK -D_POSIX_C_SOURCE=1
AM_CPPFLAGS+=-DRPC_C_UXD_DIR=\"$(NCALRPC_DIR)\"
