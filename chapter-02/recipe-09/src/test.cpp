#include <gtest/gtest.h>

template <typename T> class FooType {
public:
    void Bar() { testing::StaticAssertTypeEq<int, T>(); }
};

TEST(TypeAssertionTest, Demo)
{
    FooType<bool> fooType;
    fooType.Bar();
}
