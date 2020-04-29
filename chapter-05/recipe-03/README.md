### \*\_EXIT(statement, predicate, regex)

1）statement是被测试的代码语句

2）predicate 在这里必须是一个委托，接收int型参数，并返回bool。只有当返回值为true时，死亡测试案例才算通过。gtest提供了一些常用的predicate：

```cpp
testing::ExitedWithCode(exit_code)
```
如果程序正常退出并且退出码与exit_code相同则返回 true

```cpp
testing::KilledBySignal(signal_number)  // Windows下不支持
```
如果程序被signal_number信号kill的话就返回true

3）regex是一个正则表达式，用来匹配异常时在stderr中输出的内容

这里， 要说明的是，\*\_DEATH其实是对\*\_EXIT进行的一次包装，\*\_DEATH的predicate判断进程是否以非0退出码退出或被一个信号杀死。

示例代码如下：

```cpp
TEST(ExitDeathTest, Demo)
{
    EXPECT_EXIT(_exit(1),  testing::ExitedWithCode(1),  "");
}
```
