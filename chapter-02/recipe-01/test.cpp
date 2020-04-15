#include <gtest/gtest.h>

int Add(int a, int b)  
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

