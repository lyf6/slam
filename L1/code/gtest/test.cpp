#include <gtest/gtest.h>
#include <hello.h>

/*
使用gtest测试用例定义宏来定义测试用例：
TEST(TestSuiteName, TestName) {
  ... test body ...
}
*/

TEST(Test_Addint, test_add_int_1)
{
    int res = add_int(4, 5);
    EXPECT_EQ(res, 9);
};

TEST(Test_Addint, test_add_int_2)
{
    int res = add_int(4, 0);
    EXPECT_EQ(res, 4);
}