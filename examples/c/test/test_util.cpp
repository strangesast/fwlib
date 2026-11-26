#define TESTING 1

#include <cstdint>
#include <cstring>

extern "C" {
  #include "../src/config.h"
  #include "../src/util.c"
}

#include "../extern/fff/fff.h"
#include "gtest/gtest.h"

DEFINE_FFF_GLOBALS;
#ifndef _WIN32
FAKE_VALUE_FUNC(short, cnc_startupprocess, long, const char *);
FAKE_VALUE_FUNC(short, cnc_exitprocess);
#endif
FAKE_VALUE_FUNC(short, cnc_allclibhndl3, const char *, unsigned short, long, unsigned short *);
FAKE_VALUE_FUNC(short, cnc_rdcncid, unsigned short, unsigned long *);
FAKE_VALUE_FUNC(short, cnc_freelibhndl, unsigned short);

/*
int retrieve_id(Config *conf, char *cnc_id) {
  int allocated = 0;
  int ret = 0;
  unsigned short libh;
  uint32_t cnc_ids[4];

#ifndef _WIN32
  if (cnc_startupprocess(0, "focas.log") != EW_OK) {
    fprintf(stderr, "Failed to create required log file!\n");
    return 1;
  }
#endif

  printf("connecting to machine at %s:%d...\n", conf->ip, conf->port);
  if (cnc_allclibhndl3(conf->ip, conf->port, 10, &libh) != EW_OK) {
    fprintf(stderr, "Failed to connect to cnc!\n");
    ret = 1;
    goto cleanup;
  }
  allocated = 1;

  if (cnc_rdcncid(libh, (unsigned long *)cnc_ids) != EW_OK) {
    fprintf(stderr, "Failed to read cnc id!\n");
    ret = 1;
    goto cleanup;
  }

  snprintf(cnc_id, 40, "%08x-%08x-%08x-%08x", cnc_ids[0], cnc_ids[1], cnc_ids[2],
          cnc_ids[3]);

cleanup:
  if (allocated && cnc_freelibhndl(libh) != EW_OK)
    fprintf(stderr, "Failed to free library handle!\n");
#ifndef _WIN32
  cnc_exitprocess();
#endif

  return ret;
}
*/

TEST(Util, UtilWorks) {
  char id[36];
  Config c = {"1.2.3.4", 1234};

  ASSERT_EQ(retrieve_id(&c, id), 0);

#ifndef _WIN32
  ASSERT_EQ(cnc_startupprocess_fake.call_count, 1);
#endif
  ASSERT_EQ(cnc_allclibhndl3_fake.call_count, 1);

  EXPECT_STREQ(cnc_allclibhndl3_fake.arg0_val, "1.2.3.4") << "wtf";
  EXPECT_EQ(cnc_allclibhndl3_fake.arg1_val, 1234) << "wtf";

  ASSERT_EQ(cnc_freelibhndl_fake.call_count, 1);
#ifndef _WIN32
  ASSERT_EQ(cnc_exitprocess_fake.call_count, 1);
#endif
}

/*
 * Behaves like the bundled libfwlib32-linux-x64.so.1.0.5: whatever the
 * `unsigned long *` prototype says, cnc_rdcncid stores four 32-bit words
 * (4-byte stores, 4-byte stride). Read back through a buffer of 4 unsigned
 * long (8 bytes each on 64-bit Linux), these words would give
 * 11111111-33333333-00000000-00000000.
 */
static short rdcncid_writes_32bit_words(unsigned short, unsigned long *ids) {
  const uint32_t words[4] = {0x11111111, 0x22222222, 0x33333333, 0x44444444};
  memcpy(ids, words, sizeof(words));
  return EW_OK;
}

TEST(Util, ReadsAllFourIdWords) {
  RESET_FAKE(cnc_allclibhndl3);
  RESET_FAKE(cnc_rdcncid);
  RESET_FAKE(cnc_freelibhndl);
  cnc_rdcncid_fake.custom_fake = rdcncid_writes_32bit_words;

  char id[CNC_ID_SIZE];
  Config c = {"1.2.3.4", 1234};

  ASSERT_EQ(retrieve_id(&c, id), 0);
  ASSERT_EQ(cnc_rdcncid_fake.call_count, 1);
  EXPECT_STREQ(id, "11111111-22222222-33333333-44444444");
}
