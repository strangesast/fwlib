#include "./config.h"

/* unclear why this is required */
#ifndef TESTING
#include "fwlib32.h"
#else
#define EW_OK 0
short cnc_rdcncid(unsigned short, unsigned long *);
short cnc_startupprocess(long, const char *);
short cnc_allclibhndl3(const char *, unsigned short, long, unsigned short *);
short cnc_freelibhndl(unsigned short);
short cnc_exitprocess();
#endif

int retrieve_id(Config *conf, char *cncID);
