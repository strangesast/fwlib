#define _DEFAULT_SOURCE
#include <stdio.h>
#include <stdlib.h>

#include "../src/config.c"

int main(int argc, char *argv[]) {
  Config conf = {.ip = "0.0.0.0", .port = 1234};

  unsetenv("DEVICE_IP");
  unsetenv("DEVICE_PORT");

  if (read_env_config(&conf) || strcmp(conf.ip, "0.0.0.0") != 0 ||
      conf.port != 1234) {
    fprintf(stderr, "unexpected test init values\n");
    exit(1);
  }

  setenv("DEVICE_IP", "127.0.0.1", 1);
  setenv("DEVICE_PORT", "8193", 1);

  if (read_env_config(&conf) || strcmp(conf.ip, "127.0.0.1") != 0 ||
      conf.port != 8193) {
    fprintf(stderr, "read_env_config failed\n");
    exit(1);
  }

  exit(0);
}
