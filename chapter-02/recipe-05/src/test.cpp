#include <gtest/gtest.h>
#include <string>

int Foo(int a, int b)
{
    if (a == 0 || b == 0) {
        throw "don't do that";
    }

    int c = a % b;
    if (c == 0)
        return b;

    return Foo(b, c);
}


TEST(FooTest, HandleZeroInput)
{
    EXPECT_ANY_THROW(Foo(10, 0));
    EXPECT_THROW(Foo(0, 5), const char*);
}
