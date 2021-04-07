#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>

#include "../../fwlib32.h"
#define MACHINE_HOST "127.0.0.1"
#define MACHINE_PORT 8193

int main(int argc, char *argv[]) {
  int allocated = 0;
  int ret = 0;
  unsigned short libh;
  char cnc_id[40] = "";
  uint32_t cnc_ids[4];

#ifndef _WIN32
  if (cnc_startupprocess(0, "focas.log") != EW_OK) {
    fprintf(stderr, "Failed to create required log file!\n");
    return 1;
  }
#endif

  printf("connecting to machine at %s:%d...\n", MACHINE_HOST, MACHINE_PORT);
  if ((ret = cnc_allclibhndl3(MACHINE_HOST, MACHINE_PORT, 10, &libh)) != EW_OK) {
    fprintf(stderr, "Failed to connect to cnc! (%d)\n", ret);
    ret = 1;
    goto cleanup;
  }
  allocated = 1;

  if (cnc_rdcncid(libh, (unsigned long *)cnc_ids) != EW_OK) {
    fprintf(stderr, "Failed to read cnc id!\n");
    ret = 1;
    goto cleanup;
  }

  snprintf(cnc_id, 40, "%08x-%08x-%08x-%08x", cnc_ids[0], cnc_ids[1],
           cnc_ids[2], cnc_ids[3]);

cleanup:
  if (allocated && cnc_freelibhndl(libh) != EW_OK)
    fprintf(stderr, "Failed to free library handle!\n");
#ifndef _WIN32
  cnc_exitprocess();
#endif

  printf("machine id: %s\n", cnc_id);
}
