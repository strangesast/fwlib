#define _DEFAULT_SOURCE
#include <stdio.h>
#include <stdlib.h>

#include "../src/config.c"

static Config INIT_VALUE = {.ip = "1.2.3.4", .port = 1234};

int main(int argc, char *argv[]) {
  int ret;
  Config conf = INIT_VALUE;

  if (strcmp(conf.ip, "1.2.3.4") != 0 || conf.port != 1234) {
    fprintf(stderr, "unexpected test init values\n");
    exit(1);
  }

  // test valid args
  optind = 1;  // reset global arg index
  char *test_args_1[] = {"test_arg_config", "--port=2345", "--ip=2.3.4.5"};
  if ((ret = read_arg_config(3, test_args_1, &conf)) ||
      strcmp(conf.ip, "2.3.4.5") != 0 || conf.port != 2345) {
    fprintf(stderr, "read_arg_config 1 failed! (%d)\n", ret);
    exit(1);
  }

  // test invalid args
  optind = 1;  // reset global arg index
  conf = INIT_VALUE;
  char *test_args_2[] = {"test_arg_config", "--port", "--ip", "2.3.4.5"};
  if (read_arg_config(4, test_args_2, &conf) == 0 ||
      strcmp(conf.ip, INIT_VALUE.ip) != 0 || conf.port != INIT_VALUE.port) {
    fprintf(stderr, "read_arg_config 2 failed! (%d)\n", ret);
    exit(1);
  }

  exit(0);
}
