#include <gtest/gtest.h>

int Foo(int a, int b)
{
    if (a == 0 || b == 0)
    {
        throw "don't do that";
    }
    int c = a % b;
    if (c == 0)
        return b;
    return Foo(b, c);
}

bool MutuallyPrime(int m, int n)
{
    return Foo(m , n) > 1;
}

TEST(PredicateAssertionTest, Demo)
{
    int m = 5, n = 6;
    EXPECT_PRED2(MutuallyPrime, m, n);
}
