#include "./config.h"

#include <getopt.h>
#include <libconfig.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

static struct option options[] = {{"ip", required_argument, NULL, 'h'},
                                  {"port", required_argument, NULL, 'p'},
                                  {"config", required_argument, NULL, 'c'},
                                  {NULL, 0, NULL, 0}};

const Config default_config = {.ip = "127.0.0.1", .port = 8193};

int read_arg_config(int argc, char *argv[], Config *conf) {
  int c;
  int i = 0;
  int tmp;
  int port = 0;
  bool ip_flag = false;
  char ip[100] = "";

  while ((c = getopt_long(argc, argv, "hpc", options, &i)) != -1) {
    switch (c) {
      case 'h':
        ip_flag = true;
        strncpy(ip, optarg, 100);
        break;

      case 'p':
        if ((tmp = atoi(optarg)) != 0 && tmp > 0 && tmp < 65535) {
          port = tmp;
        } else {
          fprintf(stderr, "invalid port: \"%s\"\n", optarg);
          return 1;
        }
        break;
      case 'c':
        if (read_file_config(optarg, conf)) {
          return 1;
        }
        break;

      case '?':
        /* getopt_long already printed an error message. */
        return 1;
    }
  }
  printf("START %d\n", c);
  if (ip_flag) {
    strncpy(conf->ip, ip, 100);
  }
  if (port != 0) {
    conf->port = port;
  }

  return 0;
}

int read_env_config(Config *conf) {
  int iTmp;
  char *pTmp;

  if ((pTmp = getenv("DEVICE_IP")) != NULL) {
    strcpy(conf->ip, pTmp);
  }

  if (((pTmp = getenv("DEVICE_PORT")) != NULL) && (iTmp = atoi(pTmp)) > 0) {
    conf->port = iTmp;
  }

  return 0;
}

int read_file_config(const char *cfg_file, Config *conf) {
  config_t cfg;

  config_init(&cfg);
  const char *tmp;

  if (config_read_file(&cfg, cfg_file) != CONFIG_TRUE) {
    fprintf(stderr, "unable to read config file \"%s\"\n", cfg_file);
    config_destroy(&cfg);
    return 1;
  }

  if (config_lookup_string(&cfg, "ip", &tmp) == CONFIG_TRUE) {
    strcpy(conf->ip, tmp);
  }
  config_lookup_int(&cfg, "port", &conf->port);

  config_destroy(&cfg);

  return 0;
}

int read_config(int argc, char *argv[], Config *conf) {
  Config a = default_config;
  if (read_env_config(&a) || read_arg_config(argc, argv, &a)) {
    return 1;
  }
  *conf = a;
  return 0;
}
