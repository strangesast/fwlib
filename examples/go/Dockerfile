from golang:bullseye as base

workdir /tmp/
copy libfwlib32* fwlib32.h scripts/install.sh ./

run ./install.sh

workdir /usr/src/app

from base as builder

copy . .

# specific for building on aarch64 targeting armhf
run cd examples/go && GOARCH=arm GOARM=7 CGO_ENABLED=1 GOOS=linux CC=arm-linux-gnueabihf-gcc go build -o fwlib_example .

from base


copy --from=builder /usr/src/app/examples/go/fwlib_example .

cmd ["./fwlib_example"]
