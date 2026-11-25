from golang:bookworm as base

workdir /tmp/
copy libfwlib32* fwlib32.h scripts/install.sh ./

run ./install.sh

workdir /usr/src/app

from base as builder

copy . .

# on aarch64, cross-compile for armhf (there is no arm64 build of libfwlib32,
# install.sh sets up the armhf toolchain); elsewhere, build natively
run cd examples/go && \
  if [ "$(arch)" = "aarch64" ]; then \
    export GOARCH=arm GOARM=7 CC=arm-linux-gnueabihf-gcc; \
  fi && \
  CGO_ENABLED=1 GOOS=linux go build -o fwlib_example .

from base


copy --from=builder /usr/src/app/examples/go/fwlib_example .

cmd ["./fwlib_example"]
