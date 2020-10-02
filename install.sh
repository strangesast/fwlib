#!/bin/sh
libinstall()
{
  cp "$base/libfwlib32-$platform-$arch.so.$version" "$libdir/libfwlib32.so.$version"
  ln -sf "$libdir/libfwlib32.so.$version" "$libdir/libfwlib32.so"
}

version=1.0.5
platform=linux
arch=$(arch)
base="$(dirname "$(realpath "$0")")"
libdir=/usr/local/lib
if [ "$arch" = "x86_64" ]; then
  arch=x64
  libinstall
elif [ "$arch" = "armv7l" ]; then
  arch=armv7
  libinstall
else
  arch=x86
  libinstall
fi
cp "$base/fwlib32.h" /usr/include/
ldconfig
