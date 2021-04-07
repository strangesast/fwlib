from strangesast/fwlib as base

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
