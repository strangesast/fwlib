#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>

#include "../../fwlib32.h"
#define MACHINE_HOST "127.0.0.1"
#define MACHINE_PORT 8193

typedef struct odbdy2_t {
    int16_t  dummy ;     /* not used                */
    int16_t  axis ;      /* axis number             */
    int32_t   alarm ;     /* alarm status            */
    int32_t   prgnum ;    /* current program number  */
    int32_t   prgmnum ;   /* main program number     */
    int32_t   seqnum ;    /* current sequence number */
    int32_t   actf ;      /* actual feedrate         */
    int32_t   acts ;      /* actual spindle speed    */
    union {
        struct {
            int32_t  absolute[MAX_AXIS] ; /* absolute */
            int32_t  machine[MAX_AXIS] ;  /* machine  */
            int32_t  relative[MAX_AXIS] ; /* relative */
            int32_t  distance[MAX_AXIS] ; /* distance to go */
        } faxis ; /* In case of all axes */
        struct {
            int32_t  absolute ; /* absolute */
            int32_t  machine ;  /* machine  */
            int32_t  relative ; /* relative */
            int32_t  distance ; /* distance to go */
        } oaxis ; /* In case of 1 axis */
    } pos ;
} ODBDY2_T ;

int main(int argc, char *argv[]) {
  int allocated = 0;
  int ret = 0;
  unsigned short libh;
  char cnc_id[40] = "";
  uint32_t cnc_ids[4];

#ifndef _WIN32
  if (cnc_startupprocess(0, "focas.log") != EW_OK) {
    fprintf(stderr, "Failed to create required log file!\n");
    return 1;
  }
#endif

  printf("connecting to machine at %s:%d...\n", MACHINE_HOST, MACHINE_PORT);
  if ((ret = cnc_allclibhndl3(MACHINE_HOST, MACHINE_PORT, 10, &libh)) != EW_OK) {
    fprintf(stderr, "Failed to connect to cnc! (%d)\n", ret);
    ret = 1;
    goto cleanup;
  }
  allocated = 1;

  if (cnc_rdcncid(libh, (unsigned long *)cnc_ids) != EW_OK) {
    fprintf(stderr, "Failed to read cnc id!\n");
    ret = 1;
    goto cleanup;
  }

  snprintf(cnc_id, 40, "%08x-%08x-%08x-%08x", cnc_ids[0], cnc_ids[1],
           cnc_ids[2], cnc_ids[3]);
  printf("machine id: %s\n", cnc_id);

  ODBDY2_T buf;
  if (cnc_rddynamic2(libh, -1, sizeof(buf), (ODBDY2 *) &buf) != EW_OK) {
    fprintf(stderr, "Failed to read cnc dynamic info!\n");
    ret = 1;
    goto cleanup;
  }

  printf("Current program = %d\n", buf.prgnum);

  printf("Spindle speed = %d\n", buf.acts);

cleanup:
  if (allocated && cnc_freelibhndl(libh) != EW_OK)
    fprintf(stderr, "Failed to free library handle!\n");
#ifndef _WIN32
  cnc_exitprocess();
#endif

}
