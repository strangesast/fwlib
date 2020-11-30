#ifndef FW_UTIL_H
#define FW_UTIL_H

#include "./config.h"

/* unclear why this is required (else "error: overloaded function with no
 * contextual type information")*/
#ifndef TESTING
#include "fwlib32.h"
#else
#define EW_OK 0
#ifndef _WIN32
short cnc_startupprocess(long, const char *);
short cnc_exitprocess();
#endif
short cnc_rdcncid(unsigned short, unsigned long *);
short cnc_allclibhndl3(const char *, unsigned short, long, unsigned short *);
short cnc_freelibhndl(unsigned short);
#endif

int retrieve_id(Config *, char *);
#endif
