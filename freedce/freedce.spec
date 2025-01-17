Summary: A free implementation of the DCE RPC API
Name: FreeDCE
Version: 1.0.1
Release: 1mdk
Copyright: GPL
Group: System/Libraries
Packager: Paul-Andre Panon <ppanon@sierrasys.com>
BuildArchitectures: i386
Source: http://ftp1.sourceforge.net/freedce/freedce-1.0.1.tgz

BuildRoot: %{_tmppath}/%{name}-root
#Prereq: 
Requires: DCEthreads libstdc++
BuildPrereq: egcs libstdc++-devel bison flex DCEthreads-devel

%description
FreeDCE is a freely distributable implementation of the DCE RPC APIs.

Install FreeDCE if you need to run some packages that use the DCE APIs

%package devel
Summary: Header files and libraries for developing apps which will use freedce.
Group: Development/C
Requires: FreeDCE

%description devel
The FreeDCE-devel package contains the header files and libraries needed
to develop programs that use the FreeDCE remote procedure call libraries.

%prep
%setup -n freedce-1.0.1

%build
CFLAGS="$RPM_OPT_FLAGS" ./configure --prefix=/usr \
   --exec_prefix=/usr --bindir=/usr/sbin --libexecdir=/usr/lib \
   --localstatedir=/var --sysconfdir=/etc \
   
make -f Makefile


%install
rm -rf $RPM_BUILD_ROOT
make install  \
	DESTDIR=$RPM_BUILD_ROOT \
	prefix=/usr \
	sysconfdir=/etc/freedce \
	localstatedir=/var \
	bindir=/usr/sbin \
	libexecdir=/usr/lib/freedce

%clean
rm -rf $RPM_BUILD_ROOT

%files
%defattr(-,root,root)
%dir /usr/sbin/
/usr/sbin/uuid
/usr/sbin/rpcd
/usr/sbin/echo_server
/usr/sbin/echo_client
%dir /usr/lib/
/usr/lib/lib*.so
/usr/lib/lib*.so.*

%files devel
%defattr(-,root,root)
%dir /usr/sbin
/usr/sbin/dceidl
%dir /usr/lib/
/usr/lib/libuuid.la
/usr/lib/libuuid.a
/usr/lib/libdcerpc.la
/usr/lib/libdcerpc.a
%dir /usr/include/dce/
/usr/include/dce/*.h
/usr/include/dce/*.idl

%post -p /sbin/ldconfig

%postun -p /sbin/ldconfig

%changelog
* Wed Mar  7 2001 Paul-Andre Panon <ppanon@sierrasys.com> 1.1.0.6pl1-1mdk
- built from latest cvs extract, plus change to freedce/uuid/Makefile.in

