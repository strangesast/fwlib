#define TESTING 1
extern "C" {
#include "../src/config.h"
#include "../src/util.h"
}

#include "../extern/fff/fff.h"
#include "gtest/gtest.h"

DEFINE_FFF_GLOBALS;
FAKE_VALUE_FUNC(short, cnc_startupprocess, long, const char *);
FAKE_VALUE_FUNC(short, cnc_allclibhndl3, const char *, unsigned short, long,
                unsigned short *);
FAKE_VALUE_FUNC(short, cnc_rdcncid, unsigned short, unsigned long *);
FAKE_VALUE_FUNC(short, cnc_freelibhndl, unsigned short);
FAKE_VALUE_FUNC(short, cnc_exitprocess);

TEST(Util, UtilWorks) {
  char id[36];
  Config c = {"1.2.3.4", 1234};

  ASSERT_EQ(retrieve_id(&c, id), 0);

  ASSERT_EQ(cnc_startupprocess_fake.call_count, 1);
  ASSERT_EQ(cnc_allclibhndl3_fake.call_count, 1);

  EXPECT_STREQ(cnc_allclibhndl3_fake.arg0_val, "1.2.3.4") << "wtf";
  EXPECT_EQ(cnc_allclibhndl3_fake.arg1_val, 1234) << "wtf";

  ASSERT_EQ(cnc_freelibhndl_fake.call_count, 1);
  ASSERT_EQ(cnc_exitprocess_fake.call_count, 1);
}
