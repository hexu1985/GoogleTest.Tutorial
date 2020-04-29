### gtest断言简介

gtest 提供了TEST()宏，用来定义测试函数：

```cpp
TEST(test_suite_name, test_case_name) 
{
    // test body ...
}
```

在测试函数中gtest提供了断言，断言的宏可以理解为分为两类，一类是ASSERT系列，一类是EXPECT系列。一个直观的解释就是：

1. `ASSERT_*` 系列的断言，当检查点失败时，退出当前函数（注意：并非退出当前案例）。

2. `EXPECT_*` 系列的断言，当检查点失败时，继续往下执行。

```cpp
TEST(MyTest, Add) 
{
    EXPECT_EQ(1 + 1, 2);
    ASSERT_EQ(1 + 1, 2);
}
```
