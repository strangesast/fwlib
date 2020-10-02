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
libdir=/lib
if [ "$arch" = "x86_64" ] || [ "$arch" = "x86" ]; then
  arch=x86
  libdir=/lib
  libinstall
  arch=x64
  libdir=/lib64
  libinstall
elif [ "$arch" = "armv7l" ]; then
  arch=armv7
  libdir=/lib
  libinstall
else
  echo "unsupported arch"
  exit 1
fi
cp fwlib32.h /usr/include/
ldconfig
