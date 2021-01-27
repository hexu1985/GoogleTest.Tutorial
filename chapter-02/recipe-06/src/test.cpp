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

TEST(TrivialAssertionTest, Demo)
{
    int m = 5, n = 6;
    EXPECT_TRUE(MutuallyPrime(m, n));
}

TEST(PredicateAssertionTest, Demo)
{
    int m = 5, n = 6;
    EXPECT_PRED2(MutuallyPrime, m, n);
}

#if 0
bool IsEven(int n) 
{
    return (n % 2) == 0;
}
#else
::testing::AssertionResult IsEven(int n) 
{
    if ((n % 2) == 0)
        return ::testing::AssertionSuccess();
    else
        return ::testing::AssertionFailure() << n << " is odd";
}
#endif

int Fib(uint8_t n)
{
    if(n == 0) return 0;
    if(n == 1) return 1;
    uint64_t fn, fn_1 = 1, fn_2 = 0;
    for(uint8_t i = 2; i <= n; i++)
    {
        fn = fn_1 + fn_2;
        fn_2 = fn_1;
        fn_1 = fn;
    }
    return fn;
}

TEST(AssertionResultTest, Demo)
{
    EXPECT_TRUE(IsEven(Fib(4)));
}

