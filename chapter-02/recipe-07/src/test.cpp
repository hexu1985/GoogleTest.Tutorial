#include <gtest/gtest.h>

double sum (double a, double b)
{
    double res = a+b;
    return res;
}

TEST(simpleSum, sumOfFloat)
{
    // EXPECT_EQ(4.56, sum(0.56, 4.0)); // fail
	EXPECT_DOUBLE_EQ(4.56, sum(0.56, 4.0));
}
