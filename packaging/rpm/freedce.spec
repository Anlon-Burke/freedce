# FreeDCE 2.0.0 (64-bit port) for Fedora, RHEL/AlmaLinux/Rocky 9 and 10 and openSUSE,
# installed below /opt/dce.  Build: put freedce-%%{version}.tar.gz (packaging/make-tarball.sh)
# into the SOURCES directory, then
#   rpmbuild -bb freedce.spec
# openSUSE has no dist tag: add e.g. --define "dist .tw".
# The build is packaging/build-staged.sh, shared with the .deb and Arch packages; it builds
# and installs in one step, so it runs in %%install (rpm empties the buildroot there).

%global debug_package %{nil}
%global _lto_cflags %{nil}
%if 0%{?rhel} == 9
# the annobin plugin of EL9 belongs to its gcc 11, not to gcc-toolset-14
%undefine _annotated_build
%endif

Name:           freedce
Version:        2.0.0
Release:        3%{?dist}
Summary:        DCE RPC runtime and endpoint mapper (FreeDCE, 64-bit)
# Per package (details: packaging/debian/copyright, /opt/dce/share/doc/freedce/licenses):
# libdcerpc, protocol modules, rpcd: OSF notice (+ UCB notice in rpcdbg.c); libdcethreads: GPL
# without version number (any version) with LGPL-2.0-or-later parts; uuid tool: LGPL-2.0-or-later;
# rpcd links the stub of objex.idl (derived from the COM specification, no license notice);
# files without a notice: the statement in README.
License:        LicenseRef-OSF-DCE AND LicenseRef-UCB-1988 AND GPL-1.0-or-later AND LGPL-2.0-or-later AND LicenseRef-Microsoft-COM-Spec AND LicenseRef-FreeDCE-README
URL:            https://sourceforge.net/projects/freedce/
Source0:        freedce-%{version}.tar.gz
ExclusiveArch:  x86_64

BuildRequires:  gcc gcc-c++ make autoconf automake libtool flex bison
BuildRequires:  systemd-rpm-macros
%if 0%{?rhel} == 9
# the IDL compiler needs C23; EL9's gcc 11 has no nullptr
BuildRequires:  gcc-toolset-14-gcc gcc-toolset-14-gcc-c++
%endif

%description
FreeDCE is the OSF DCE 1.1 RPC runtime for Linux, interoperable with other
DCE RPC and Microsoft RPC implementations (ncacn_ip_tcp, ncadg_ip_udp).
This package contains the runtime libraries (libdcerpc, libdcethreads and
the protocol modules), the endpoint mapper rpcd with a systemd unit
(freedce-rpcd.service, not enabled by default) and the uuid tool, all
below /opt/dce.

%package devel
Summary:        DCE RPC development files and IDL compiler (FreeDCE, 64-bit)
# dceidl and headers: OSF notice; winnt.idl: PADL notice; obase/objex/remact.idl: derived from
# the COM specification, no license notice; nt/lsarpc.h, nt/ntsec.h: GPL-2.0-or-later;
# libdcethreads headers: GPL with LGPL-2.0-or-later parts; files without a notice: README
License:        LicenseRef-OSF-DCE AND LicenseRef-PADL AND LicenseRef-Microsoft-COM-Spec AND GPL-2.0-or-later AND GPL-1.0-or-later AND LGPL-2.0-or-later AND LicenseRef-FreeDCE-README
Requires:       %{name} = %{version}-%{release}
Requires:       cpp

%description devel
The IDL compiler dceidl (also as idl), the headers and IDL files and the
development links of libdcerpc and libdcethreads, below /opt/dce.

%package examples
Summary:        DCE RPC example clients and servers (FreeDCE, 64-bit)
# echo and samr demos: no license notice (README statement); liblsarpc: GPL-2.0-or-later
License:        LicenseRef-FreeDCE-README AND GPL-2.0-or-later
Requires:       %{name} = %{version}-%{release}

%description examples
The echo and samr demonstration clients and servers, below /opt/dce.

%prep
%setup -q

%build
# see %%install

%install
%if 0%{?rhel} == 9
. /opt/rh/gcc-toolset-14/enable
%endif
%if 0%{?suse_version}
export CFLAGS="%{optflags}" CXXFLAGS="%{optflags}"
%else
%{?set_build_flags}
%endif
sh packaging/build-staged.sh %{buildroot} %{?_smp_build_ncpus}%{!?_smp_build_ncpus:4}
# the programs and libraries find their libraries in /opt/dce/lib through RUNPATH, on
# purpose (no ld.so.conf entry): tell check-rpaths that this non-system path is intended
export QA_RPATHS=$(( 0x0002 ))

%if 0%{?suse_version}
%pre
%service_add_pre freedce-rpcd.service

%post
%service_add_post freedce-rpcd.service
%tmpfiles_create freedce.conf

%preun
%service_del_preun freedce-rpcd.service

%postun
%service_del_postun_without_restart freedce-rpcd.service
%else
%post
%systemd_post freedce-rpcd.service
%tmpfiles_create freedce.conf

%preun
%systemd_preun freedce-rpcd.service

%postun
%systemd_postun freedce-rpcd.service
%endif

%files
%dir /opt/dce
%dir /opt/dce/bin
%dir /opt/dce/lib
%dir /opt/dce/share
%dir /opt/dce/share/doc
/opt/dce/lib/libdcerpc.so.*
/opt/dce/lib/libdcethreads.so.*
/opt/dce/lib/libnaf_*.so*
/opt/dce/lib/libprot_*.so*
/opt/dce/bin/rpcd
/opt/dce/bin/uuid
%dir /opt/dce/share/doc/freedce
%doc /opt/dce/share/doc/freedce/README
%doc /opt/dce/share/doc/freedce/NEWS
%license /opt/dce/share/doc/freedce/COPYING
%license /opt/dce/share/doc/freedce/COPYING.dcethreads
%license /opt/dce/share/doc/freedce/licenses
%{_unitdir}/freedce-rpcd.service
%{_tmpfilesdir}/freedce.conf
%dir /var/opt/freedce

%files devel
/opt/dce/bin/dceidl
/opt/dce/bin/idl
/opt/dce/include
/opt/dce/lib/libdcerpc.so
/opt/dce/lib/libdcethreads.so
/opt/dce/share/freedce

%files examples
/opt/dce/bin/echo_client
/opt/dce/bin/echo_server
/opt/dce/bin/samr_client
/opt/dce/bin/samr_server
/opt/dce/lib/liblsarpc.so*

%changelog
* Fri Oct 02 2026 Anlon-Burke <Anlon-Burke@users.noreply.github.com> - 2.0.0-3
- Release: network input checked before use (CN and DG packets, NDR
  unmarshaling, protocol towers, rpcd endpoint map requests; fixes a
  stack buffer overflow and an unbounded allocation in rpcd reachable
  over the network), ncalrpc sockets in /run/freedce/ncalrpc without
  leftover files, a cancel ends a call whose send is blocked by a
  stalled server, timers no longer expire early, maybe call fixes,
  complete license metadata and license texts.

* Tue Sep 29 2026 Anlon-Burke <Anlon-Burke@users.noreply.github.com> - 2.0.0-2
- Second preview: built-in texts for the status codes, fixes found with
  ASan/UBSan, zeroed pad bytes in bind_ack, rpc_ep_register with
  rpc_server_use_all_protseqs, configurable dcethreads wake-up signal,
  uuid tool fixes, more robust parallel and cross builds.

* Tue Sep 29 2026 Anlon-Burke <Anlon-Burke@users.noreply.github.com> - 2.0.0-1
- First packages of FreeDCE 2.0.0 (64-bit port), below /opt/dce.
