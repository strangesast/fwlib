#!/bin/sh
arch=$(arch)
if [ "$arch" = "x86_64" ]; then
  dpkg --add-architecture i386 && apt-get update && apt-get install -y gcc-multilib
fi
