from debian:buster-slim as base

workdir /tmp
copy install.sh fwlib32.h libfwlib32* example/extra-deps.sh ./
run ./install.sh && ./extra-deps.sh

from base as builder

run apt-get update && apt-get install -y \
  build-essential \
  cmake

workdir /usr/src/app

copy example/ .

run mkdir build && \
  cd build && \
  cmake .. && \
  make

from base

copy --from=builder /usr/src/app/build/bin/fanuc_example /usr/local/bin/

cmd fanuc_example
