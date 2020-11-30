#include <stdio.h>
#include <stdlib.h>

#include "../src/config.h"
#include "gtest/gtest.h"

TEST(Config, DefaultConfigWorks) {
  Config conf = {"0.0.0.0", 1234};

  EXPECT_STREQ(conf.ip, "0.0.0.0");
  EXPECT_EQ(conf.port, 1234);

  conf = default_config;

  EXPECT_STREQ(conf.ip, "127.0.0.1");
  EXPECT_EQ(conf.port, 8193);
}
