#include "./util.h"

#include <stdint.h>
#include <stdio.h>

#include "./config.h"

int retrieve_id(Config *conf, char *cnc_id) {
  int allocated = 0;
  int ret = 0;
  unsigned short libh;
  /* cnc_rdcncid writes four 32-bit words, whatever the `unsigned long *` in
   * its prototype suggests (unsigned long is 8 bytes on 64-bit Linux, but the
   * x64 library still stores 4-byte words): keep a uint32_t[4] buffer. */
  uint32_t cnc_ids[4] = {0, 0, 0, 0};

#ifndef _WIN32
  if (cnc_startupprocess(0, "focas.log") != EW_OK) {
    fprintf(stderr, "Failed to create required log file!\n");
    return 1;
  }
#endif

  printf("connecting to machine at %s:%d...\n", conf->ip, conf->port);
  if ((ret = cnc_allclibhndl3(conf->ip, conf->port, 10, &libh)) != EW_OK) {
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

  snprintf(cnc_id, CNC_ID_SIZE, "%08x-%08x-%08x-%08x", cnc_ids[0],
           cnc_ids[1], cnc_ids[2], cnc_ids[3]);

cleanup:
  if (allocated && cnc_freelibhndl(libh) != EW_OK)
    fprintf(stderr, "Failed to free library handle!\n");
#ifndef _WIN32
  cnc_exitprocess();
#endif

  return ret;
}
