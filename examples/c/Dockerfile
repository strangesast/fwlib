from strangesast/fwlib as base

# the strangesast/fwlib image on Docker Hub is still Debian 10 "buster" (EOL):
# its packages moved to archive.debian.org. Newer bases are left untouched.
run if grep -q '^10\.' /etc/debian_version; then \
      printf '%s\n' \
        'deb http://archive.debian.org/debian buster main' \
        'deb http://archive.debian.org/debian-security buster/updates main' \
        > /etc/apt/sources.list; \
    fi

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
