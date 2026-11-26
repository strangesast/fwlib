# Go fwlib example

Connects to a machine through FOCAS (via cgo) and prints its CNC ID.
Linux only.

## Configuration

| Environment variable | Default     |
|----------------------|-------------|
| `MACHINE_IP`         | `localhost` |
| `MACHINE_PORT`       | `8193`      |

The exit code is `0` on success, `1` on any error.

## Docker

From the root of this repository:

```
docker build -t fwlib_go-example -f examples/go/Dockerfile .
docker run --rm --network=host -e MACHINE_IP=<device ip> fwlib_go-example
```

## Local build

1. Install Go and a C compiler (cgo is required).
2. At the root of this repository, link the library for your platform, e.g. on x86_64:
   `ln -s libfwlib32-linux-x64.so.1.0.5 libfwlib32.so && ln -s libfwlib32-linux-x64.so.1.0.5 libfwlib32.so.1`
3. In `examples/go`: `go build -o fwlib_example .`
4. `MACHINE_IP=<device ip> ./fwlib_example`

The binary looks for `libfwlib32.so` at the root of this repository, so it can be run from any directory.
