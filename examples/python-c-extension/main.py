from fwlib import Context


# Use the context manager to connect and retrieve the CNC ID
with Context(host="host.docker.internal", port=8193) as cnc:
    cnc_id = cnc.read_id()
    print(f"CNC ID: {cnc_id}")
