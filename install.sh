#!/bin/sh
version=1.0.5
platform=linux
arch=$(arch)
base="$(dirname "$(realpath "$0")")"
if [ "$arch" = "x86_64" ] || [ "$arch" = "x86" ]; then
  arch=x86
elif [ "$arch" = "armv7l" ]; then
  arch=armv7
else
  echo "unsupported arch"
  exit 1
fi
cp fwlib32.h /usr/include/
cp "$base/libfwlib32-$platform-$arch.so.$version" "/usr/local/lib/libfwlib32.so.$version"
ln -sf /usr/local/lib/libfwlib32.so.$version /usr/local/lib/libfwlib32.so
ldconfig
