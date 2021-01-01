#include <stdio.h>
#include <stdlib.h>

#include "gtest/gtest.h"
extern "C" {
  #include "../src/config.h"
}

static Config INIT_VALUE = {"1.2.3.4", 1234};

TEST(Config, ArgConfigWorks) {
  Config conf = INIT_VALUE;

  EXPECT_STREQ(conf.ip, "1.2.3.4") << "unexpected ip";
  EXPECT_EQ(conf.port, 1234) << "unexpected ip";

#ifdef _WIN32
#else
  // test valid args
  optind = 1;  // reset global arg index
  const char *test_args_1[] = {"test_arg_config", "--port=2345", "--ip=2.3.4.5"};
  ASSERT_EQ(read_arg_config(3, (char **)test_args_1, &conf), 0) << "read_arg_config failed";

  EXPECT_STREQ(conf.ip, "2.3.4.5") << "ip not set correctly";
  EXPECT_EQ(conf.port, 2345) << "port not set correctly";

  // test invalid args
  optind = 1;  // reset global arg index
  conf = INIT_VALUE;
  const char *test_args_2[] = {"test_arg_config", "--port", "--ip", "2.3.4.5"};
  ASSERT_NE(read_arg_config(4, (char **) test_args_2, &conf), 0) << "read_arg_config should fail";

  EXPECT_STREQ(conf.ip, INIT_VALUE.ip) << "ip should be unmodified";
  EXPECT_EQ(conf.port, INIT_VALUE.port) << "port should be unmodified";
#endif
}
