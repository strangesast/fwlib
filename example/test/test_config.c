#define _DEFAULT_SOURCE
#include <stdio.h>
#include <stdlib.h>

#include "../src/config.c"

int main(int argc, char *argv[]) {
  char *test_args[] = {"test_arg_config", "--ip=123.456.789.1",
                       "--config=test_config.cfg"};
  int ret;
  Config conf;

  // setenv("", "", 1);
  ret = read_config(2, test_args, &conf);
  if (ret != 0) {
    fprintf(stderr, "read_config failed!\n");
    exit(1);
  }

  if (strcmp(conf.ip, "123.456.789.1") != 0) {
    fprintf(stderr, "unexpected null value for deviceIP\n");
    exit(1);
  }

  if (conf.port != 8193) {
    fprintf(stderr, "unexpected null value for devicePort\n");
    exit(1);
  }

  exit(0);
}
