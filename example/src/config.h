#ifndef FW_CONFIG_H
#define FW_CONFIG_H

typedef struct config {
  char ip[100];
  int port;
} Config;

extern const Config default_config;

int read_config(int argc, char *argv[], Config *conf);
int read_arg_config(int argc, char *argv[], Config *conf);
int read_env_config(Config *conf);
int read_file_config(const char *cfg_file, Config *conf);

#endif
