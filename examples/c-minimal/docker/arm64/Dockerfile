from debian:stable-slim as base

run dpkg --add-architecture armhf \
  && apt-get update \
  && apt-get install -y \
    libconfig-dev:armhf \
    libstdc++6:armhf \
  && rm -rf /var/lib/apt/lists/*

copy libfwlib32-linux-armv7.so.1.0.5 /usr/lib

run ln -s /usr/lib/libfwlib32-linux-armv7.so.1.0.5 /usr/lib/libfwlib32.so && \
  ln -s /usr/lib/libfwlib32-linux-armv7.so.1.0.5 /usr/lib/libfwlib32.so.1 && \
  ln -s /usr/lib/libfwlib32-linux-armv7.so.1.0.5 /usr/lib/libfwlib32.so.1.0.5


from base as builder

run apt-get update \
  && apt-get install -y gcc-arm-linux-gnueabihf \
  && rm -rf /var/lib/apt/lists/*

workdir /usr/src/app

copy examples/c-minimal/main.c fwlib32.h ./

run /usr/bin/arm-linux-gnueabihf-gcc main.c -lfwlib32 -lm -lpthread -o fanuc_minimal


from base

copy --from=builder /usr/src/app/fanuc_minimal /

cmd /fanuc_minimal
