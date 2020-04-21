#include <gtest/gtest.h>
#include "fun.h"

class IsPrimeTest : public::testing::TestWithParam<int>
{

};

// 使用参数化测试，只需要：
TEST_P(IsPrimeTest, HandleTrueReturn)
{
    int n =  GetParam();
    EXPECT_TRUE(IsPrime(n));
}

// 定义参数
//INSTANTIATE_TEST_CASE_P(TrueReturn, IsPrimeTest, testing::Values(3, 5, 11, 23, 17));
INSTANTIATE_TEST_SUITE_P(TrueReturn, IsPrimeTest, testing::Values(3, 5, 11, 23, 17));

