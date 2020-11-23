#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "./config.c"
#include "./util.c"
#include "fwlib32.h"

int main(int argc, char *argv[]) {
  char cncID[36];
  Config conf;

  if (read_config(argc, argv, &conf)) {
    fprintf(stderr,
            "usage: %s --config=<path_to_config> --port=<device port> "
            "--ip=<device ip>\n",
            argv[0]);
    return EXIT_FAILURE;
  }

  if (retrieve_id(&conf, cncID)) {
    return EXIT_FAILURE;
  }

  printf("machine id: %s\n", cncID);

  return EXIT_SUCCESS;
}
