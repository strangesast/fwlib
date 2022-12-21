from debian:stable-slim as base

run apt-get update \
  && apt-get install -y \
    libconfig-dev \
#    libstdc++6 \
  && rm -rf /var/lib/apt/lists/*

copy libfwlib32-linux-armv7.so.1.0.5 /usr/lib

run ln -s /usr/lib/libfwlib32-linux-armv7.so.1.0.5 /usr/lib/libfwlib32.so && \
  ln -s /usr/lib/libfwlib32-linux-armv7.so.1.0.5 /usr/lib/libfwlib32.so.1 && \
  ln -s /usr/lib/libfwlib32-linux-armv7.so.1.0.5 /usr/lib/libfwlib32.so.1.0.5


from base as builder

run apt-get update \
  && apt-get install -y \
    build-essential \
    cmake \
  && rm -rf /var/lib/apt/lists/*

workdir /usr/src/app

copy examples/c/ fwlib32.h ./

run mkdir build \
  && cd build \
  && cmake .. \
  && cmake --build . \
  && ctest


from base

copy --from=builder /usr/src/app/build/bin/fanuc_example /

cmd /fanuc_example
