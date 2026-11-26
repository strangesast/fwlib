"""Read a CNC's ID through FOCAS using ctypes (no compilation needed). Linux only."""

import ctypes
import os
import sys
from pathlib import Path

EW_OK = 0


class FocasError(Exception):
    pass


def load_focas():
    # prefer libfwlib32.so at the root of this repository (see README),
    # otherwise use the system-wide library (e.g. installed by scripts/install.sh)
    local = Path(__file__).resolve().parents[2] / "libfwlib32.so"
    focas = ctypes.CDLL(str(local) if local.exists() else "libfwlib32.so")

    # Declaring argtypes makes ctypes convert and check every argument; without
    # it, a Python str is passed as wchar_t* and every int as a 32-bit C int.
    focas.cnc_startupprocess.argtypes = [ctypes.c_long, ctypes.c_char_p]
    focas.cnc_startupprocess.restype = ctypes.c_short
    focas.cnc_exitprocess.argtypes = []
    focas.cnc_exitprocess.restype = ctypes.c_short
    focas.cnc_allclibhndl3.argtypes = [
        ctypes.c_char_p,
        ctypes.c_ushort,
        ctypes.c_long,
        ctypes.POINTER(ctypes.c_ushort),
    ]
    focas.cnc_allclibhndl3.restype = ctypes.c_short
    focas.cnc_freelibhndl.argtypes = [ctypes.c_ushort]
    focas.cnc_freelibhndl.restype = ctypes.c_short
    # the C prototype says `unsigned long *`, but the library writes 32-bit
    # words (see read_machine_id)
    focas.cnc_rdcncid.argtypes = [ctypes.c_ushort, ctypes.POINTER(ctypes.c_uint32)]
    focas.cnc_rdcncid.restype = ctypes.c_short
    return focas


def read_machine_id(focas, ip, port, timeout=10):
    ret = focas.cnc_startupprocess(0, b"focas.log")
    if ret != EW_OK:
        raise FocasError(f"failed to create required log file ({ret})")
    try:
        libh = ctypes.c_ushort(0)
        ret = focas.cnc_allclibhndl3(ip.encode(), port, timeout, ctypes.byref(libh))
        if ret != EW_OK:
            raise FocasError(f"failed to connect to {ip}:{port} ({ret})")
        try:
            # cnc_rdcncid writes four 32-bit words, whatever the `unsigned long *`
            # in its prototype suggests (c_ulong is 8 bytes on 64-bit Linux, but
            # the x64 library still stores 4-byte words): keep a c_uint32 array.
            cnc_ids = (ctypes.c_uint32 * 4)()
            ret = focas.cnc_rdcncid(libh, cnc_ids)
            if ret != EW_OK:
                raise FocasError(f"failed to read cnc id ({ret})")
            return "-".join(f"{v:08x}" for v in cnc_ids)
        finally:
            ret = focas.cnc_freelibhndl(libh)
            if ret != EW_OK:
                print(f"warning: failed to free library handle ({ret})", file=sys.stderr)
    finally:
        focas.cnc_exitprocess()


def main():
    ip = os.environ.get("MACHINE_IP", "127.0.0.1")
    value = os.environ.get("MACHINE_PORT", "8193")
    try:
        port = int(value)
        if not 1 <= port <= 65535:
            raise ValueError
    except ValueError:
        print(f"error: invalid MACHINE_PORT: {value!r}", file=sys.stderr)
        return 1

    try:
        focas = load_focas()
    except OSError as e:
        print(f"error: cannot load libfwlib32.so ({e})", file=sys.stderr)
        return 1

    print(f"connecting to machine at {ip}:{port}...")
    try:
        machine_id = read_machine_id(focas, ip, port)
    except FocasError as e:
        print(f"error: {e}", file=sys.stderr)
        return 1

    print(f"machine_id={machine_id}")
    return 0


if __name__ == "__main__":
    sys.exit(main())
