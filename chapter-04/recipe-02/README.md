### 参数化测试

例如原先的测试代码如下：

```cpp
// 不使用参数化测试，就需要像这样写五次
TEST(IsPrimeTest, HandleTrueReturn)
{
    EXPECT_TRUE(IsPrime(3));
    EXPECT_TRUE(IsPrime(5));
    EXPECT_TRUE(IsPrime(11));
    EXPECT_TRUE(IsPrime(23));
    EXPECT_TRUE(IsPrime(17));
}
```

我们需要做如下几步，将测试转成gtest的参数化测试。

#### 1. 告诉gtest你的参数类型是什么

你必须添加一个类，继承testing::TestWithParam<T>，其中T就是你需要参数化的参数类型。

示例代码如下：

```cpp
class IsPrimeTest : public::testing::TestWithParam<int>
{

};
```

#### 2. 告诉gtest你拿到参数的值后，具体做些什么样的测试

这里，我们要使用一个新的宏：`TEST_P`，
在`TEST_P`宏里，使用GetParam()获取当前的参数的具体值。

示例代码如下：

```cpp
// 使用参数化测试，只需要：
TEST_P(IsPrimeTest, HandleTrueReturn)
{
    int n =  GetParam();
    EXPECT_TRUE(IsPrime(n));
}
```

#### 3. 告诉gtest你想要测试的参数范围是什么

使用`INSTANTIATE_TEST_SUITE_P`（在旧版本中使用`INSTANTIATE_TEST_CASE_P`宏，不过已经废弃）这宏来告诉gtest你要测试的参数范围：
`INSTANTIATE_TEST_SUITE_P`(InstantiationName, FooTest, Values("meeny", "miny", "moe"));

第一个参数是testsuite的前缀，可以任意取。

第二个参数是testsuite的名称，需要和之前定义的参数化的类的名称相同。

第三个参数是可以理解为参数生成器，上面的例子使用test::Values表示使用括号内的参数。

示例代码如下：

```cpp
// 定义参数
//INSTANTIATE_TEST_CASE_P(TrueReturn, IsPrimeTest, testing::Values(3, 5, 11, 23, 17));
INSTANTIATE_TEST_SUITE_P(TrueReturn, IsPrimeTest, testing::Values(3, 5, 11, 23, 17));
```

#### 4. Google提供了一系列的参数生成的函数：

| generator                                    | 说明                                           |
| -------------------------------------------- | ---------------------------------------------- |
| Range(begin, end[, step])                    | 范围在begin~end之间，步长为step，不包括end     |
| Values(v1, v2, ..., vN)                      | v1,v2到vN的值                                  |
| ValuesIn(container) and ValuesIn(begin, end) | 从一个C类型的数组或是STL容器，或是迭代器中取值 |
| Bool()                                       | 取false 和 true 两个值                         |
| Combine(g1, g2, ..., gN)                     | 这个比较强悍，它将g1,g2,...gN进行排列组合，g1,g2,...gN本身是一个参数生成器，每次分别从g1,g2,..gN中各取出一个值，组合成一个元组(Tuple)作为一个参数。 |
