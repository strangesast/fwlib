#define _GNU_SOURCE
#define _BSD_SOURCE
#define _DEFAULT_SOURCE

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// #include "../../fwlib32.h"
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
  short ret;
  unsigned long tt;
  struct timespec t0, t1;

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

  char program_path[241] = "";
  if (cnc_exeprgname2(libh, program_path) != EW_OK) {
    fprintf(stderr, "Failed to get exec path!\n");
    exit(EXIT_FAILURE);
    return 1;
  }
  printf("current program path: %s\n", program_path);

  char buf[2048];
  long chunk = 1280;  // must be multiple of 256
  long len;
  short type = 0;  // NC Program

  char *prog = NULL;
  long offset = 0;

  clock_gettime(CLOCK_MONOTONIC_RAW, &t0);
  ret = cnc_upstart4(libh, type, program_path);

  if (ret != EW_OK) {
    fprintf(stderr, "upstart4 failed\n");
    exit(EXIT_FAILURE);
    return 1;
  }

  do {
    len = chunk;
    ret = cnc_upload4(libh, &len, buf);

    if (ret == EW_BUFFER) {
      continue;
    }
    if (ret == EW_OK) {
      if (len > 0) {
        size_t s = offset + len;
        if (prog == NULL) {
          prog = (char *)malloc(s + 1);
        } else {
          prog = (char *)realloc(prog, s + 1);
        }
        prog[s] = 0;
        memcpy(&prog[offset], &buf[0], len);
        offset += len;
      }
    }
  } while (ret == EW_OK || ret == EW_BUFFER);

  clock_gettime(CLOCK_MONOTONIC_RAW, &t1);
  tt = (t1.tv_sec - t0.tv_sec) * 1000000 + (t1.tv_nsec - t0.tv_nsec) / 1000;

  // printf("%s\n", prog);
  printf("program read took %.2fs (%ld bytes)\n", (double)tt / 1e6,
         strlen(prog));
  free(prog);

  ret = cnc_upend4(libh);
  if (ret != EW_OK) {
    fprintf(stderr, "upend4 failed!\n");
    exit(EXIT_FAILURE);
    return 1;
  }

  IODBPSD param;

  if (cnc_rdparam(libh, 6711, ALL_AXES, 8, &param) != EW_OK) {
    fprintf(stderr, "Failed to read part parameter!\n");
    return 1;
  }

  printf("part count: %ld\n", param.u.ldata);

  exit(EXIT_SUCCESS);
}
