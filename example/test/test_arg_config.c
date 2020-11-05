#define _DEFAULT_SOURCE
#include <stdio.h>
#include <stdlib.h>

#include "../src/config.c"

int add(int a, int b) { return a + b; }

int main(int argc, char *argv[]) {
  char *test_args[] = {"test_arg_config", "--port=8193", "--ip=127.0.0.1"};
  int ret;
  Config conf = {.ip = "0.0.0.0", .port = 1234};

  if (strcmp(conf.ip, "0.0.0.0") != 0) {
    fprintf(stderr, "unexpected null value for deviceIP\n");
    exit(1);
  }

  if (conf.port != 1234) {
    fprintf(stderr, "unexpected null value for devicePort\n");
    exit(1);
  }

  ret = read_arg_config(3, test_args, &conf);
  if (ret != 0) {
    fprintf(stderr, "read_arg_config failed!\n");
    exit(1);
  }

  if (strcmp(conf.ip, "127.0.0.1") != 0) {
    fprintf(stderr, "unexpected device ip \"%s\"\n", conf.ip);
    exit(1);
  }

  if (conf.port != 8193) {
    fprintf(stderr, "unexpected device port \"%d\"\n", conf.port);
    exit(1);
  }

  exit(0);
}
