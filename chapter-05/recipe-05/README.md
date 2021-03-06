### 死亡测试运行方式

1）fast方式（默认的方式）

```cpp
testing::FLAGS_gtest_death_test_style = "fast";
```

2）threadsafe方式

```cpp
testing::FLAGS_gtest_death_test_style = "threadsafe";
```

你可以在 main() 里为所有的死亡测试设置测试形式，也可以为某次测试单独设置。Google Test会在每次测试之前保存这个标记并在测试完成后恢复，所以你不需要去管这部分工作 。

示例代码如下：

```cpp
TEST(MyDeathTest, TestOne) {
    testing::FLAGS_gtest_death_test_style = "threadsafe";
    // This test is run in the "threadsafe" style:
    ASSERT_DEATH(ThisShouldDie(), "");
}

TEST(MyDeathTest, TestTwo) {
    // This test is run in the "fast" style:
    ASSERT_DEATH(ThisShouldDie(), "");
}

int main(int argc, char** argv) {
    testing::InitGoogleTest(&argc, argv);
    testing::FLAGS_gtest_death_test_style = "fast";
    return RUN_ALL_TESTS();
}
```
