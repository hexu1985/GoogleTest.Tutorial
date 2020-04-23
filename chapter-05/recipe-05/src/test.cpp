#include <gtest/gtest.h>
#include <iostream>

void divide_by_zero()
{
    int a = 1;
    int b = 0;
    int c = a/b;
}

void dereference_null_ptr()
{
    int *pInt = nullptr;
    *pInt = 42 ;
}

TEST(FooDeathTest, DivideByZero)
{
    testing::FLAGS_gtest_death_test_style = "threadsafe";
    EXPECT_DEATH(divide_by_zero(),"");
    std::cout << "DeathTest of divide_by_zero........" << std::endl;
}

TEST(FooDeathTest, DereferenceNullPtr)
{
    EXPECT_DEATH(dereference_null_ptr(),"");
    std::cout << "DeathTest of dereference_null_ptr........" << std::endl;
}

