# Python ctypes example

Reads a machine's CNC ID by loading the FOCAS library directly with
[`ctypes`](https://docs.python.org/3/library/ctypes.html): pure Python, nothing to compile. Linux only.

## Usage

1. Make the library available, either:
   - at the root of this repository, e.g. on x86_64:
     `ln -s libfwlib32-linux-x64.so.1.0.5 libfwlib32.so && ln -s libfwlib32-linux-x64.so.1.0.5 libfwlib32.so.1`
   - or system-wide, with `scripts/install.sh`.
2. `MACHINE_IP=<device ip> python3 examples/ctypes/main.py` (can be run from any directory)

| Environment variable | Default     |
|----------------------|-------------|
| `MACHINE_IP`         | `127.0.0.1` |
| `MACHINE_PORT`       | `8193`      |

The exit code is `0` on success, `1` on any error.
