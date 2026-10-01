#!/bin/sh
# Build dcethreads and freedce from an unpacked source tree (e.g. the tarball of
# make-tarball.sh) and install them into a staging directory for the packages:
# prefix /opt/dce, rpcd database in /var/opt/freedce, ncalrpc sockets in /run/freedce/ncalrpc
# (created at boot by tmpfiles.d), systemd unit, documentation.
# CFLAGS/LDFLAGS from the environment (dpkg-buildflags, makepkg) are used.
# Usage: packaging/build-staged.sh <stage dir> [make jobs]
set -e
src=$(cd "$(dirname "$0")/.." && pwd)
mkdir -p "$1"
stage=$(cd "$1" && pwd)
jobs=${2:-$(nproc)}
prefix=/opt/dce
build=$src/_build

rm -rf "$build"
mkdir -p "$build/dcethreads" "$build/freedce"

# dcethreads first, into the stage
(cd "$src/dcethreads" && ./buildconf)
(cd "$build/dcethreads" &&
 "$src/dcethreads/configure" --prefix=$prefix &&
 make -j"$jobs" &&
 make install DESTDIR="$stage")
# link freedce with -L against the staged library, not through the .la file
# (which would name /opt/dce/lib, where nothing is installed yet)
rm -f "$stage$prefix/lib/libdcethreads.la"

# freedce against the staged dcethreads; the debug information shall name the
# installed headers (/opt/dce/include), not the stage
map="-ffile-prefix-map=$stage="
(cd "$src/freedce" && ./buildconf)
(cd "$build/freedce" &&
 CFLAGS="${CFLAGS--g -O2} $map" CXXFLAGS="${CXXFLAGS--g -O2} $map" \
 "$src/freedce/configure" --prefix=$prefix \
     --with-dcethreads-dir="$stage$prefix" \
     --with-rpcd-dbdir=/var/opt/freedce \
     --with-ncalrpc-dir=/run/freedce/ncalrpc &&
 make -j"$jobs" &&
 make install DESTDIR="$stage")

# no libtool archives and static libraries in the packages
rm -f "$stage$prefix"/lib/*.la "$stage$prefix"/lib/*.a

# the stage path must not end up in any installed file (run paths, debug information,
# generated headers), as rpm's check-buildroot also requires
bad=$(grep -rl -a -F "$stage" "$stage$prefix" 2>/dev/null || true)
if [ -n "$bad" ]; then
    echo "build-staged.sh: the stage directory $stage is named in:" >&2
    echo "$bad" >&2
    exit 1
fi

install -D -m 644 "$src/freedce/rpcd/freedce-rpcd.service" \
    "$stage/usr/lib/systemd/system/freedce-rpcd.service"
install -d -m 755 "$stage/var/opt/freedce"
# /run is empty after a boot: systemd-tmpfiles creates the ncalrpc directory (mode 1777,
# like /tmp/.X11-unix; not below /tmp, where Fedora and Arch remove old files)
install -d -m 755 "$stage/usr/lib/tmpfiles.d"
echo "d /run/freedce/ncalrpc 1777 root root -" > "$stage/usr/lib/tmpfiles.d/freedce.conf"
chmod 644 "$stage/usr/lib/tmpfiles.d/freedce.conf"
install -D -m 644 "$src/README" "$stage$prefix/share/doc/freedce/README"
install -m 644 "$src/freedce/NEWS" "$stage$prefix/share/doc/freedce/NEWS"
install -m 644 "$src/freedce/COPYING" "$stage$prefix/share/doc/freedce/COPYING"
install -m 644 "$src/dcethreads/COPYING" "$stage$prefix/share/doc/freedce/COPYING.dcethreads"
install -d -m 755 "$stage$prefix/share/doc/freedce/licenses"
install -m 644 "$src"/LICENSES/*.txt "$stage$prefix/share/doc/freedce/licenses/"
