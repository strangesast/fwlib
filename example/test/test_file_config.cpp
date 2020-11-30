#include <stdio.h>
#include <stdlib.h>

#include "gtest/gtest.h"
extern "C" {
  #include "../src/config.h"
}

TEST(Config, FileConfigWorks) {
  Config conf = {"0.0.0.0", 1234};
  const char config_file[] = "./test_config.cfg";

  EXPECT_STREQ(conf.ip, "0.0.0.0");
  EXPECT_EQ(conf.port, 1234);

  ASSERT_EQ(read_file_config(config_file, &conf), 0);
  EXPECT_STREQ(conf.ip, "9.8.7.6");
  EXPECT_EQ(conf.port, 9876);
}
