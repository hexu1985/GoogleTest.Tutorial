#include <gtest/gtest.h>

inline int Add(int a, int b)  
{  
    return a + b;  
}  

TEST(fun, Add)  
{  
    EXPECT_EQ(1, Add(2,-1));

    EXPECT_EQ(5, Add(2,3));  

    EXPECT_EQ(4, Add(2,4)); // 运算结果不等于期望值

    ASSERT_EQ(6, Add(10,4)) << "assert test failure!"; // 运算结果不等于期望值, 使用ASSERT_EQ

    EXPECT_EQ(7, Add(2,4)) << "expect test failure!"; // 不会运行到这
}  

#if 0
void test_add1()
{
    std::cout << "test_add1" << std::endl;
    EXPECT_EQ(1, Add(2,-1));

    EXPECT_EQ(5, Add(2,3));  

    EXPECT_EQ(4, Add(2,4)); // 运算结果不等于期望值

    ASSERT_EQ(6, Add(10,4)) << "assert test failure!"; // 运算结果不等于期望值, 使用ASSERT_EQ

    EXPECT_EQ(7, Add(2,4)) << "expect test failure!"; // 不会运行到这
}

void test_add2()
{
    std::cout << "test_add2" << std::endl;
    EXPECT_EQ(1, Add(2,-1));

    EXPECT_EQ(5, Add(2,3));  

    EXPECT_EQ(4, Add(2,4)); // 运算结果不等于期望值

    ASSERT_EQ(6, Add(10,4)) << "assert test failure!"; // 运算结果不等于期望值, 使用ASSERT_EQ

    EXPECT_EQ(7, Add(2,4)) << "expect test failure!"; // 不会运行到这
}

void test_add3()
{
    std::cout << "test_add3" << std::endl;
    EXPECT_EQ(1, Add(2,-1));

    EXPECT_EQ(5, Add(2,3));  

    EXPECT_EQ(4, Add(2,4)); // 运算结果不等于期望值

    ASSERT_EQ(6, Add(10,4)) << "assert test failure!"; // 运算结果不等于期望值, 使用ASSERT_EQ

    EXPECT_EQ(7, Add(2,4)) << "expect test failure!"; // 不会运行到这
}

TEST(fun, Addfuncs)
{
    test_add1();
    test_add2();
    test_add3();
}
#endif

inline int Sub(int a, int b)
{
    return a - b;
}

TEST(fun, Sub)  
{  
    EXPECT_EQ(3, Sub(2,-1));

    EXPECT_EQ(-1, Sub(2,3));  
}  

