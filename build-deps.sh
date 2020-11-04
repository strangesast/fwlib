#!/bin/sh
_arch=$(arch)
_set=true
if [ -z "${TARGETPLATFORM}" ]; then _unset=false; fi

echo "arch! $_arch"
apt-get update
if [ "$_set" = true ] && [ "$TARGETPLATFORM" = "aarch64" ] || [ "$_arch" = "aarch64" ]; then
  apt-get install -y \
    cmake \
    gcc-arm-linux-gnueabihf \
    g++-arm-linux-gnueabihf \
    libconfig-dev
  update-alternatives --remove-all cc
  update-alternatives --remove-all g++
  update-alternatives --install /usr/bin/cc cc /usr/bin/arm-linux-gnueabihf-gcc 50
  update-alternatives --install /usr/bin/g++ g++ /usr/bin/arm-linux-gnueabihf-g++ 50

elif [ "$_set" = true ] && [ "$TARGETPLATFORM" = "linux/amd64" ] || [ "$_arch" = "x86_64" ]; then
  apt-get install -y \
    cmake \
    gcc-multilib \
    g++-multilib \
    libconfig-dev

elif [ "$_set" = true ] && [ "$TARGETPLATFORM" = "linux/arm/v7" ] || [ "$_arch" = "armhf" ] || [ "$_arch" = "armv7l" ]; then
  apt-get install -y \
    cmake \
    build-essential \
    libconfig-dev

else
  apt-get install -y \
    cmake \
    build-essential \
    libconfig-dev

fi
