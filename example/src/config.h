#ifndef FW_CONFIG_H
#define FW_CONFIG_H

const struct config {
  char ip[100];
  int port;
} default_config = {"127.0.0.1", 8193};

typedef struct config Config;

int read_config(int argc, char *argv[], Config *conf);
int read_arg_config(int argc, char *argv[], Config *conf);
int read_env_config(Config *conf);
int read_file_config(const char *cfg_file, Config *conf);

#endif
