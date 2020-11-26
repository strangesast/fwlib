#include "./util.h"

#include <stdint.h>
#include <stdio.h>

#include "./config.h"

int retrieve_id(Config *conf, char *cncID) {
  int ret = 0;
  unsigned short libh;
  uint32_t cnc_ids[4];

  if (cnc_startupprocess(0, "focas.log") != EW_OK) {
    fprintf(stderr, "Failed to create required log file!\n");
    return 1;
  }

  printf("connecting to machine at %s:%d...\n", conf->ip, conf->port);
  if (cnc_allclibhndl3(conf->ip, conf->port, 10, &libh) != EW_OK) {
    fprintf(stderr, "Failed to connect to cnc!\n");
    ret = 1;
    goto cleanup;
  }

  if (cnc_rdcncid(libh, (unsigned long *)cnc_ids) != EW_OK) {
    fprintf(stderr, "Failed to read cnc id!\n");
    ret = 1;
    goto cleanup;
  }

  sprintf(cncID, "%08x-%08x-%08x-%08x", cnc_ids[0], cnc_ids[1], cnc_ids[2],
          cnc_ids[3]);

cleanup:
  if (cnc_freelibhndl(libh) != EW_OK)
    fprintf(stderr, "Failed to free library handle!\n");
  cnc_exitprocess();

  return ret;
}
