package main

/*
#cgo CFLAGS: -I./src
#cgo LDFLAGS: -L./../../ -lfwlib32 -Wl,-rpath=./../../
#include <stdlib.h>
#include "../../fwlib32.h"
*/
import "C"

import (
	"fmt"
	"unsafe"
)

func main() {
	var libh C.ushort

	log_level := 0
	log_fname := C.CString("focas.log")
	defer C.free(unsafe.Pointer(log_fname))
	if ret := C.cnc_startupprocess(C.long(log_level), log_fname); ret != C.EW_OK {
		fmt.Printf("cnc_startupprocess failed (%d)\n", ret)
		return
	}

	ip := "localhost"
	port := 8193
	_ip := C.CString(ip)
	defer C.free(unsafe.Pointer(_ip))

	fmt.Printf("connecting to %s:%d...\n", ip, port)
	if ret := C.cnc_allclibhndl3(_ip, C.ushort(port), 10, &libh); ret != C.EW_OK {
		fmt.Printf("cnc_allclibhndl3 failed (%d)\n", ret)
		return
	}

	var cnc_ids [4]uint32
	if ret := C.cnc_rdcncid(libh, (*C.ulong)(unsafe.Pointer(&cnc_ids[0]))); ret != C.EW_OK {
		fmt.Printf("cnc_rdcncid failed (%d)\n", ret)
		return
	}
	machine_id := fmt.Sprintf("%08x-%08x-%08x-%08x", cnc_ids[0], cnc_ids[1], cnc_ids[2], cnc_ids[3])

	fmt.Printf("machine_id: %s\n", machine_id)

	if ret := C.cnc_freelibhndl(libh); ret != C.EW_OK {
		fmt.Printf("cnc_freelibhndl failed (%d)\n", ret)
	}

	if ret := C.cnc_exitprocess(); ret != C.EW_OK {
		fmt.Printf("cnc_exitprocess failed (%d)\n", ret)
	}
}
