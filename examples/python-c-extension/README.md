# [Python C API](https://docs.python.org/3/c-api/index.html) Example

A Python module written in C that wraps FOCAS. Linux x86_64 only (the Dockerfile uses the x64 library).

```python
from fwlib import Context

with Context(host="192.168.1.10", port=8193, timeout=10) as cnc:
    print(cnc.read_id())
```

- `Context(host="127.0.0.1", port=8193, timeout=10)` connects to the machine; raises `ConnectionError` on failure, `ValueError` on an invalid port or timeout.
- `read_id()` returns the CNC ID as a string; raises `RuntimeError` if the context is closed.
- Leaving the `with` block (or deleting the object) closes the connection. Several contexts can be open at the same time, from several threads: blocking FOCAS calls release the GIL.

## Docker

From the root of this repository:

```
docker run --rm -it --platform=linux/amd64 -e MACHINE_IP=<device ip> $(docker build --platform=linux/amd64 -f examples/python-c-extension/Dockerfile -q .) python3 main.py
```

`main.py` reads `MACHINE_IP` (default `host.docker.internal`, i.e. the Docker host with Docker Desktop) and `MACHINE_PORT` (default `8193`), and exits with code `1` on error.
