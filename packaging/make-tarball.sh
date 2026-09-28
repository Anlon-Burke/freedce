#!/bin/sh
# Create the source tarball freedce-<version>.tar.gz (+ .sha256) of a committed git revision.
# The version is taken from freedce/configure.ac.
# Usage: packaging/make-tarball.sh [output dir] [revision]   (defaults: ., HEAD)
set -e
top=$(git rev-parse --show-toplevel)
rev=${2:-HEAD}
version=$(git -C "$top" show "$rev:freedce/configure.ac" |
          sed -n 's/^AC_INIT(\[freedce\],\[\([^]]*\)\])/\1/p')
[ -n "$version" ] || { echo "no version in freedce/configure.ac" >&2; exit 1; }
out=${1:-.}
mkdir -p "$out"
name=freedce-$version
git -C "$top" archive --format=tar.gz --prefix="$name/" -o "$(cd "$out" && pwd)/$name.tar.gz" "$rev"
(cd "$out" && sha256sum "$name.tar.gz" > "$name.tar.gz.sha256" && cat "$name.tar.gz.sha256")
