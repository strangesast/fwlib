#include "./util.h"

#include <stdint.h>
#include <stdio.h>

#include "./config.h"

int retrieve_id(Config *conf, char *cnc_id) {
  int allocated = 0;
  int ret = 0;
  unsigned short libh;
  /* FOCAS expects an array of 4 `unsigned long` (8 bytes each on 64-bit
   * Linux); a uint32_t[4] buffer would be overrun there. */
  unsigned long cnc_ids[4] = {0, 0, 0, 0};

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

  if (cnc_rdcncid(libh, cnc_ids) != EW_OK) {
    fprintf(stderr, "Failed to read cnc id!\n");
    ret = 1;
    goto cleanup;
  }

  snprintf(cnc_id, CNC_ID_SIZE, "%08x-%08x-%08x-%08x",
           (uint32_t)cnc_ids[0], (uint32_t)cnc_ids[1], (uint32_t)cnc_ids[2],
           (uint32_t)cnc_ids[3]);

cleanup:
  if (allocated && cnc_freelibhndl(libh) != EW_OK)
    fprintf(stderr, "Failed to free library handle!\n");
#ifndef _WIN32
  cnc_exitprocess();
#endif

  return ret;
}
