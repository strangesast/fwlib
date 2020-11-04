#include <libconfig.h>
#include <stdio.h>
#include <stdlib.h>

#include "../src/config.c"

int devicePort;
const char *deviceIP = NULL;

int add(int a, int b) { return a + b; }

int main(int argc, char *argv[]) {
  int ret;
  char config_file[] = "test_config.cfg";

  if (deviceIP != NULL) {
    fprintf(stderr, "unexpected null value for deviceIP\n");
    exit(1);
  }

  if (devicePort != 0) {
    fprintf(stderr, "unexpected null value for devicePort\n");
    exit(1);
  }

  ret = read_config(config_file);
  if (ret != 0) {
    fprintf(stderr, "read_config failed!\n");
    exit(1);
  }

  if (strcmp(deviceIP, "127.0.0.1") != 0) {
    fprintf(stderr, "unexpected device ip\n");
    exit(1);
  }

  if (devicePort != 8193) {
    fprintf(stderr, "unexpected device port");
  }

  exit(0);
}
