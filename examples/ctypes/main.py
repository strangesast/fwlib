import ctypes
from pathlib import Path

# must rename libfwlib32-$plat-$arch.so.$version to libfwlib32.so
libpath = (
    # ../../libfwlib32.so
    Path.cwd().parents[1] / "libfwlib32.so"
)
focas = ctypes.cdll.LoadLibrary(libpath)
focas.cnc_startupprocess.restype = ctypes.c_short
focas.cnc_exitprocess.restype = ctypes.c_short
focas.cnc_allclibhndl3.restype = ctypes.c_short
focas.cnc_freelibhndl.restype = ctypes.c_short
focas.cnc_rdcncid.restype = ctypes.c_short

ret = focas.cnc_startupprocess(0, "focas.log")
if ret != 0:
    raise Exception(f"Failed to create required log file! ({ret})")

ip = "127.0.0.1"
port = 8193
timeout = 10
libh = ctypes.c_ushort(0)

print(f"connecting to machine at {ip}:{port}...")
ret = focas.cnc_allclibhndl3(
    ip.encode(),
    port,
    timeout,
    ctypes.byref(libh),
)
if ret != 0:
    raise Exception(f"Failed to connect to cnc! ({ret})")

try:
    cnc_ids = (ctypes.c_uint32 * 4)()
    ret = focas.cnc_rdcncid(libh, cnc_ids)
    if ret != 0:
        raise Exception(f"Failed to read cnc id! ({ret})")

    machine_id = "-".join([f"{cnc_ids[i]:08x}" for i in range(4)])
    print(f"machine_id={machine_id}")

finally:
    ret = focas.cnc_freelibhndl(libh)
    if ret != 0:
        raise Exception(f"Failed to free library handle! ({ret})")

focas.cnc_exitprocess()
