### gtest死亡测试简介

死亡测试是为了判断一段逻辑是否会导致进程退出而设计的。
gtest的死亡测试能做到在一个安全的环境下执行崩溃的测试案例，同时又对崩溃结果进行验证。

#### 使用的宏

| Fatal assertion                           | Nonfatal assertion                        | Verifies |
| ----------------------------------------- | ----------------------------------------- | -------- |
| ASSERT_DEATH(statement, regex);           | EXPECT_DEATH(statement, regex);           | statement crashes with the given error |
| ASSERT_EXIT(statement, predicate, regex); | EXPECT_EXIT(statement, predicate, regex); | statement exits with the given error and its exit code matches predicate |

示例代码如下：

```cpp
void Foo()
{
    int *pInt = nullptr;
    *pInt = 42 ;
}

TEST(FooDeathTest, Demo)
{
    EXPECT_DEATH(Foo(), "");
}
```
