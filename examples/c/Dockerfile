from strangesast/fwlib as base

# the base image is Debian 10 "buster" (EOL): its packages moved to archive.debian.org
run printf '%s\n' \
    'deb http://archive.debian.org/debian buster main' \
    'deb http://archive.debian.org/debian-security buster/updates main' \
    > /etc/apt/sources.list

from base as builder

copy scripts/build-deps.sh /tmp/
run /tmp/build-deps.sh

workdir /usr/src/app

copy examples/c/ .

run mkdir build && \
  cd build && \
  cmake .. && \
  make && \
  make test

from base

run apt-get update && apt-get install -y libconfig-dev
copy --from=builder /usr/src/app/build/bin/fanuc_example /usr/local/bin/

cmd fanuc_example
