#include <getopt.h>
#include <libconfig.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct config {
  char ip[100];
  int port;
} Config;

int set_config_defaults(struct config *conf);
int read_config(int argc, char *argv[], struct config *conf);
int read_arg_config(int argc, char *argv[], struct config *conf);
int read_env_config(struct config *conf);
int read_file_config(const char *cfg_file, struct config *conf);
