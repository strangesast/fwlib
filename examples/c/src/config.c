#include "./config.h"

#ifndef _WIN32
#include <getopt.h>
#endif
#include "../extern/libconfig/lib/libconfig.h"
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#ifdef _WIN32
enum ARG_KEY{CONFIG, PORT, IP};
const char *V_CONFIG = "--config=";
const char *V_PORT = "--port=";
const char *V_IP = "--ip=";

int read_arg_config(int argc, char *argv[], Config *conf) {
  char ip[100] = "";
  char config_filename[100] = "";
  int tmp;
  int port = 0;
  int i;
  int j = 0;
  size_t l;
  char *arg;
  char v[100] = "";
  // ip port config
  for (i = 1; j = 0, arg=argv[i], i < argc; i++) {
    enum ARG_KEY key;
    if (strncmp(arg, V_CONFIG, l = strlen(V_CONFIG)) == 0) {
      key = CONFIG;
    } else if (strncmp(arg, V_PORT, l = strlen(V_PORT)) == 0) {
      key = PORT;
    } else if (strncmp(arg, V_IP, l = strlen(V_IP)) == 0) {
      key = IP;
    } else {
      fprintf(stderr, "unrecognized argument: \"%s\"\n", arg);
      return 1;
    }
    for (char *c = arg+l; *c != '\0' && j < 100; j++, c++) {
      v[j] = *c;
    }
    v[j] = '\0';
    switch (key) {
      case CONFIG: {
        if (read_file_config(v, conf)) {
          return 1;
        }
        break;
      }
      case PORT: {
        if ((tmp = atoi(v)) < 1 || tmp > 65535) { 
          // invalid port
          fprintf(stderr, "Invalid port argument: \"%s\"\n", v);
          return 1;
        }
        port = tmp;
        break;
      }
      case IP: {
        snprintf(ip, 100, "%s", v);
        break;
      }
    }
  }
  if (port != 0) {
    conf->port = port;
  }
  if (*ip != '\0') {
    strncpy_s(conf->ip, 100, ip, 100);
  }
  return 0;
}
#else
static struct option options[] = {{"ip", required_argument, NULL, 'h'},
                                  {"port", required_argument, NULL, 'p'},
                                  {"config", required_argument, NULL, 'c'},
                                  {NULL, 0, NULL, 0}};

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
        snprintf(ip, 100, "%s", optarg);
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

  if (ip_flag) {
    snprintf(conf->ip, 100, "%s", ip);
  }
  if (port != 0) {
    conf->port = port;
  }

  return 0;
}
#endif

#ifdef _WIN32
int read_env_config(Config *conf) {
  int iTmp;
  char buf[100] = "";
  char *pTmp = (char *)buf;
  size_t n;

  n = 100;
  if (_dupenv_s(&pTmp, &n, "DEVICE_IP") == 0 && pTmp != NULL) {
    snprintf(conf->ip, 100, "%s", pTmp);
  }
  n = 100;
  if (_dupenv_s(&pTmp, &n, "DEVICE_PORT") == 0 && pTmp != NULL) {
    if ((iTmp = atoi(pTmp)) > 0 && iTmp < 65535) {
      conf->port = iTmp;
    }
  }

  return 0;
}
#else
int read_env_config(Config *conf) {
  int iTmp;
  char *pTmp;

  if ((pTmp = getenv("DEVICE_IP")) != NULL) {
    snprintf(conf->ip, 100, "%s", pTmp);
  }

  if (((pTmp = getenv("DEVICE_PORT")) != NULL) && (iTmp = atoi(pTmp)) > 0) {
    conf->port = iTmp;
  }

  return 0;
}
#endif

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
    snprintf(conf->ip, 100, "%s", tmp);
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
