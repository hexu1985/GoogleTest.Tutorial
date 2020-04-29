### 运行参数

gtest也为我们提供了一系列的运行参数，使得我们可以对案例的执行进行一些有效的控制。
gtest提供了三种设置的途径：

1. 系统环境变量

2. 命令行参数

3. 代码中指定FLAG

因为提供了三种途径，就会有优先级的问题，有一个原则是，最后设置的那个会生效。

这样，我们就拥有了接收和响应gtest命令行参数的能力。如果需要在代码中指定FLAG，可以使用`testing::GTEST_FLAG`这个宏来设置。
比如相对于命令行参数`--gtest_output`，可以使用`testing::GTEST_FLAG(output) = "xml:"`;来设置。

示例代码如下：

```cpp
int _tmain(int argc, _TCHAR* argv[])
{
    testing::GTEST_FLAG(output) = "xml:";
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
```

最后再来说下第一种设置方式-系统环境变量。如果需要gtest的设置系统环境变量，必须注意的是：

1. 系统环境变量全大写，比如对于`--gtest_output`，响应的系统环境变量为：`GTEST_OUTPUT`

2.  有一个命令行参数例外，那就是`--gtest_list_tests`，它是不接受系统环境变量的。（只是用来罗列测试案例名称）
