#include <stdio.h>
#include <stdlib.h>

#include "gtest/gtest.h"
extern "C" {
  #include "../src/config.h"
}

TEST(Config, ConfigWorks) {
  const char *test_args[] = {"test_arg_config", "--ip=123.456.789.1",
                             "--config=test_config.cfg"};
  Config conf;

  // setenv("", "", 1);
  ASSERT_EQ(read_config(3, (char **)test_args, &conf), 0)
      << "read_config failed";

  EXPECT_STREQ(conf.ip, "123.456.789.1") << "unexpected ip";
  EXPECT_EQ(conf.port, 9876) << "unexpected port";
}
