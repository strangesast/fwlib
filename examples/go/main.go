package main

/*
#cgo LDFLAGS: -L${SRCDIR}/../.. -lfwlib32 -Wl,-rpath,${SRCDIR}/../..
#include <stdlib.h>
#include "../../fwlib32.h"
*/
import "C"

import (
	"fmt"
	"os"
	"strconv"
	"unsafe"
)

func main() {
	os.Exit(run())
}

// run returns the process exit code; it is separate from main so that the
// deferred cleanup calls still run before os.Exit.
func run() int {
	ip := "localhost"
	if value, ok := os.LookupEnv("MACHINE_IP"); ok {
		ip = value
	}
	port := 8193
	if value, ok := os.LookupEnv("MACHINE_PORT"); ok {
		d, err := strconv.Atoi(value)
		if err != nil || d < 1 || d > 65535 {
			fmt.Fprintf(os.Stderr, "invalid MACHINE_PORT: %q\n", value)
			return 1
		}
		port = d
	}

	logLevel := 0
	logFname := C.CString("focas.log")
	defer C.free(unsafe.Pointer(logFname))
	if ret := C.cnc_startupprocess(C.long(logLevel), logFname); ret != C.EW_OK {
		fmt.Fprintf(os.Stderr, "cnc_startupprocess failed (%d)\n", ret)
		return 1
	}
	defer func() {
		if ret := C.cnc_exitprocess(); ret != C.EW_OK {
			fmt.Fprintf(os.Stderr, "cnc_exitprocess failed (%d)\n", ret)
		}
	}()

	cIP := C.CString(ip)
	defer C.free(unsafe.Pointer(cIP))

	var libh C.ushort
	fmt.Printf("connecting to %s:%d...\n", ip, port)
	if ret := C.cnc_allclibhndl3(cIP, C.ushort(port), 10, &libh); ret != C.EW_OK {
		fmt.Fprintf(os.Stderr, "cnc_allclibhndl3 failed (%d)\n", ret)
		return 1
	}
	defer func() {
		if ret := C.cnc_freelibhndl(libh); ret != C.EW_OK {
			fmt.Fprintf(os.Stderr, "cnc_freelibhndl failed (%d)\n", ret)
		}
	}()

	// cnc_rdcncid writes four 32-bit words, whatever the `unsigned long *` in
	// its prototype suggests (C.ulong is 8 bytes on 64-bit Linux, but the x64
	// library still stores 4-byte words): keep a [4]uint32 buffer.
	var cncIDs [4]uint32
	if ret := C.cnc_rdcncid(libh, (*C.ulong)(unsafe.Pointer(&cncIDs[0]))); ret != C.EW_OK {
		fmt.Fprintf(os.Stderr, "cnc_rdcncid failed (%d)\n", ret)
		return 1
	}
	machineID := fmt.Sprintf("%08x-%08x-%08x-%08x",
		cncIDs[0], cncIDs[1], cncIDs[2], cncIDs[3])

	fmt.Printf("machine_id: %s\n", machineID)
	return 0
}
