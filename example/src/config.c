#include <libconfig.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

extern const char *deviceIP;
extern int devicePort;
const char DEFAULT_IP[] = "127.0.0.1";

int read_config(const char *cfg_file) {
  int iTmp;
  char *pTmp;
  bool config_avail = true;
  config_t cfg;

  config_init(&cfg);

  if (!config_read_file(&cfg, cfg_file)) {
    config_avail = false;
    fprintf(stderr, "unable to read config file \"%s\"\n", cfg_file);
  }

  if ((pTmp = getenv("DEVICE_IP")) != NULL) {
    deviceIP = pTmp;
  } else if (config_avail && config_lookup_string(&cfg, "ip", &deviceIP)) {
    // set by libconfig
  } else {
    // use default
    deviceIP = DEFAULT_IP;
  }

  if (((pTmp = getenv("DEVICE_PORT")) != NULL) && (iTmp = atoi(pTmp)) > 0) {
    devicePort = iTmp;
  } else if (config_avail && config_lookup_int(&cfg, "port", &devicePort)) {
    // set by libconfig
  } else {
    // use default
    devicePort = 8193;
  }

  config_destroy(&cfg);

  return 0;
}
