#include <stdio.h>
#include <stdlib.h>

#include "../src/config.c"

int add(int a, int b) { return a + b; }

int main(int argc, char *argv[]) {
  int ret;
  Config conf = {.ip = "0.0.0.0", .port = 1234};
  char config_file[] = "./test_config.cfg";

  if (strcmp(conf.ip, "0.0.0.0") != 0) {
    fprintf(stderr, "unexpected null value for deviceIP\n");
    exit(1);
  }

  if (conf.port != 1234) {
    fprintf(stderr, "unexpected null value for devicePort\n");
    exit(1);
  }

  ret = read_file_config(config_file, &conf);
  if (ret != 0) {
    fprintf(stderr, "read_config failed!\n");
    exit(1);
  }

  if (strcmp(conf.ip, "9.8.7.6") != 0) {
    fprintf(stderr, "unexpected device ip \"%s\"\n", conf.ip);
    exit(1);
  }

  if (conf.port != 9876) {
    fprintf(stderr, "unexpected device port \"%d\"\n", conf.port);
    exit(1);
  }

  exit(0);
}
