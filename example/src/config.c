#include "./config.h"

extern const char *deviceIP;
extern int devicePort;
const char DEFAULT_IP[] = "127.0.0.1";

static struct option options[] = {{"ip", optional_argument, NULL, 'h'},
                                  {"port", optional_argument, NULL, 'p'},
                                  {"config", optional_argument, NULL, 'c'},
                                  {NULL, 0, NULL, 0}};

int set_config_defaults(struct config *conf) {
  strcpy(conf->ip, "127.0.0.1");
  conf->port = 8193;

  return 0;
}

int read_arg_config(int argc, char *argv[], struct config *conf) {
  int c;
  int i = 0;
  int tmp;

  while ((c = getopt_long(argc, argv, "hp", options, &i)) != -1) {
    switch (c) {
      case 'h':
        strcpy(conf->ip, optarg);
        break;

      case 'p':
        if ((tmp = atoi(optarg)) != 0) {
          conf->port = tmp;
        }
        break;
      case 'c':
        if (read_file_config(optarg, conf)) {
          return 1;
        }
        break;

      case '?':
        /* getopt_long already printed an error message. */
        break;
    }
  }

  return 0;
}

int read_env_config(struct config *conf) {
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

int read_file_config(const char *cfg_file, struct config *conf) {
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

int read_config(int argc, char *argv[], struct config *conf) {
  set_config_defaults(conf);
  read_env_config(conf);
  read_arg_config(argc, argv, conf);

  return 0;
}
