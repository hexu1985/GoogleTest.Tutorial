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

void no_death_func()
{
    int a = 1;
    int b = 0;
    int c = a*b;
}

TEST(FooDeathTest, DivideByZero)
{
    EXPECT_DEATH(divide_by_zero(),"");
    std::cout << "DeathTest of divide_by_zero........" << std::endl;
}

TEST(FooDeathTest, DereferenceNullPtr)
{
    EXPECT_DEATH(dereference_null_ptr(),"");
    std::cout << "DeathTest of dereference_null_ptr........" << std::endl;
}

#if 0
TEST(FooDeathTest, NoDeathFunc)
{
    EXPECT_DEATH(no_death_func(),"");
    std::cout << "DeathTest of no_death_func........" << std::endl;
}
#endif
