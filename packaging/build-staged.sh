#!/bin/sh
# Build dcethreads and freedce from an unpacked source tree (e.g. the tarball of
# make-tarball.sh) and install them into a staging directory for the packages:
# prefix /opt/dce, rpcd database in /var/opt/freedce, systemd unit, documentation.
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
     --with-rpcd-dbdir=/var/opt/freedce &&
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
install -D -m 644 "$src/README" "$stage$prefix/share/doc/freedce/README"
install -m 644 "$src/freedce/NEWS" "$stage$prefix/share/doc/freedce/NEWS"
install -m 644 "$src/freedce/COPYING" "$stage$prefix/share/doc/freedce/COPYING"
install -m 644 "$src/dcethreads/COPYING" "$stage$prefix/share/doc/freedce/COPYING.dcethreads"
