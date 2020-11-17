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
  if ((ret = read_config(3, test_args, &conf)) != 0 ||
      strcmp(conf.ip, "123.456.789.1") != 0 || conf.port != 9876) {
    fprintf(stderr, "read_config failed! (%d)\n", ret);
    exit(1);
  }

  exit(0);
}
