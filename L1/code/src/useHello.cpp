#include "hello.h"
#include <gflags/gflags.h>
#include <gtest/gtest.h>
// #include <glog/logging.h>
DEFINE_int32(print_times, 1, "print times");

int main(int argc, char **argv)
{
  gflags::ParseCommandLineFlags(&argc, &argv, true);
  EXPECT_GE(FLAGS_print_times, 1) << "FAILED: EXPECT print_times>=1";

  for (int i = 0; i < FLAGS_print_times; i++)
    sayHello();
}
