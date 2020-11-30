#include <stdio.h>
#include <stdlib.h>

#include "gtest/gtest.h"
extern "C" {
  #include "../src/config.h"
}

#ifdef _WIN32
#define unset_env(k) _putenv_s(k, "");
#define set_env(k, v) _putenv_s(k, v);
#else
#define unset_env(k) unsetenv(k);
#define set_env(k, v) setenv(k, v, 1);
#endif

TEST(Config, EnvConfigWorks) {
  Config conf = {"0.0.0.0", 1234};

  unset_env("DEVICE_IP");
  unset_env("DEVICE_PORT");

  ASSERT_EQ(read_env_config(&conf), 0);
  EXPECT_STREQ(conf.ip, "0.0.0.0");
  EXPECT_EQ(conf.port, 1234);

  set_env("DEVICE_IP", "127.0.0.1");
  set_env("DEVICE_PORT", "8193");

  ASSERT_EQ(read_env_config(&conf), 0);
  EXPECT_STREQ(conf.ip, "127.0.0.1");
  EXPECT_EQ(conf.port, 8193);
}
