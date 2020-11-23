#include "./util.h"

#include <stdio.h>

#include "./config.h"

int retrieve_id(Config *conf, char *cncID) {
  int ret;
  unsigned short libh;
  unsigned long cncIDs[4];

  if (cnc_startupprocess(0, "focas.log") != EW_OK) {
    fprintf(stderr, "Failed to create required log file!\n");
    ret = 1;
    return ret;
  }

  printf("connecting to machine at %s:%d...\n", conf->ip, conf->port);
  if (cnc_allclibhndl3(conf->ip, conf->port, 10, &libh) != EW_OK) {
    fprintf(stderr, "Failed to connect to cnc!\n");
    ret = 1;
    return ret;
  }

  if (cnc_rdcncid(libh, cncIDs) != EW_OK) {
    fprintf(stderr, "Failed to read cnc id!\n");
    ret = 1;
    goto cleanup;
    return 1;
  }

#if __SIZEOF_LONG__ == 4
  sprintf(cncID, "%08lx-%08lx-%08lx-%08lx", cncIDs[0] & 0xffffffff,
          cncIDs[1] & 0xffffffff, cncIDs[2] & 0xffffffff,
          cncIDs[3] & 0xffffffff);
#else
  sprintf(cncID, "%08lx-%08lx-%08lx-%08lx", cncIDs[0] & 0xffffffff,
          cncIDs[0] >> 32 & 0xffffffff, cncIDs[1] & 0xffffffff,
          cncIDs[1] >> 32 & 0xffffffff);
#endif
  ret = 0;

cleanup:
  if (cnc_freelibhndl(libh) != EW_OK)
    fprintf(stderr, "Failed to free library handle!\n");
  cnc_exitprocess();

  return ret;
}
