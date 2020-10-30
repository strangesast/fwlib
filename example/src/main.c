#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "fwlib32.h"

unsigned short libh;

void cleanup() {
  if (cnc_freelibhndl(libh) != EW_OK)
    fprintf(stderr, "Failed to free library handle!\n");
  cnc_exitprocess();
}

int main(int argc, char *argv[]) {
  char ip[100] = "127.0.0.1";
  int port = 8193;
  unsigned long cncIDs[4];
  char cncID[36];

  if (argc > 1) {
    if (strlen(argv[1]) >= sizeof(ip)) {
      printf("ip too long: %s\n", argv[1]);
      exit(EXIT_FAILURE);
      return 1;
    }
    strcpy(ip, argv[1]);
  }

  if (argc > 2) {
    int tmp;
    tmp = atoi(argv[2]);
    if (tmp > 0 && tmp < 65535) {
      port = tmp;
    }
  }

  if (cnc_startupprocess(0, "focas.log") != EW_OK) {
    fprintf(stderr, "Failed to create required log file!\n");
    exit(EXIT_FAILURE);
    return 1;
  }

  printf("connecting to machine at %s:%d...\n", ip, port);
  if (cnc_allclibhndl3(ip, port, 10, &libh) != EW_OK) {
    fprintf(stderr, "Failed to connect to cnc!\n");
    exit(EXIT_FAILURE);
    return 1;
  }
  atexit(cleanup);

  if (cnc_rdcncid(libh, cncIDs) != EW_OK) {
    fprintf(stderr, "Failed to read cnc id!\n");
    exit(EXIT_FAILURE);
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
  printf("machine id: %s\n", cncID);

  exit(EXIT_SUCCESS);
}
