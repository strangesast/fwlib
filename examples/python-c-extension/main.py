import os
import sys

from fwlib import Context

host = os.environ.get("MACHINE_IP", "host.docker.internal")

# Use the context manager to connect and retrieve the CNC ID
try:
    port = int(os.environ.get("MACHINE_PORT", "8193"))
    with Context(host=host, port=port) as cnc:
        cnc_id = cnc.read_id()
        print(f"CNC ID: {cnc_id}")
except (ConnectionError, RuntimeError, ValueError) as e:
    print(f"error: {e}", file=sys.stderr)
    sys.exit(1)
