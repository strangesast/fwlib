/*
 * Stand-in for libfwlib32, used only by test_lifecycle.py: no network, a slow
 * cnc_rdcncid, and every other call records whether it ran while a read was
 * in progress. Built as libfwlib32.so by the Dockerfile `test` target.
 */
#include <stdatomic.h>
#include <stdint.h>
#include <string.h>
#include <time.h>

#define EW_OK 0

static atomic_int reading, overlaps, reads, frees, exits;

static void check_overlap(void) {
  if (atomic_load(&reading)) atomic_fetch_add(&overlaps, 1);
}

short cnc_startupprocess(long level, const char *filename) {
  (void)level;
  (void)filename;
  check_overlap();
  return EW_OK;
}

short cnc_exitprocess(void) {
  check_overlap();
  atomic_fetch_add(&exits, 1);
  return EW_OK;
}

short cnc_allclibhndl3(const char *ip, unsigned short port, long timeout,
                       unsigned short *libh) {
  (void)ip;
  (void)port;
  (void)timeout;
  check_overlap();
  *libh = 1;
  return EW_OK;
}

short cnc_freelibhndl(unsigned short libh) {
  (void)libh;
  check_overlap();
  atomic_fetch_add(&frees, 1);
  return EW_OK;
}

/* like the real x64 library: four 32-bit words, despite the prototype */
short cnc_rdcncid(unsigned short libh, unsigned long *ids) {
  const uint32_t words[4] = {0x11111111, 0x22222222, 0x33333333, 0x44444444};
  const struct timespec duration = {0, 300 * 1000 * 1000}; /* 300 ms */
  (void)libh;
  atomic_store(&reading, 1);
  atomic_fetch_add(&reads, 1);
  nanosleep(&duration, NULL);
  memcpy(ids, words, sizeof(words));
  atomic_store(&reading, 0);
  return EW_OK;
}

/* introspection, called from the test through ctypes */
void stub_reset(void) {
  atomic_store(&overlaps, 0);
  atomic_store(&reads, 0);
  atomic_store(&frees, 0);
  atomic_store(&exits, 0);
}
int stub_reads(void) { return atomic_load(&reads); }
int stub_overlaps(void) { return atomic_load(&overlaps); }
int stub_frees(void) { return atomic_load(&frees); }
int stub_exits(void) { return atomic_load(&exits); }
