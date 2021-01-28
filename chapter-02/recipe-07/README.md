### 浮点型断言

浮点数存在截断误差，两个浮点数之间一般不能精确的相等，所以之前的比较宏(ASSERT|EXPECT_EQ)都不能用于浮点数的比较，而且浮点数(float, double)表示的范围很大，远比占据同样字节数的定点数(int, long)表示的范围大，而且分辨率也是浮动的(数之间的间隔随着数的大小的增加而增大）。所以最好使用相对误差来进行比较，除了跟0相比。

一般来说，对于浮点数的比较，用户需要自已指定误差范围，如果不想指定或是对这个不关心的话，gtest也提供了使用默认误差范围的相应的断言。

浮点数比较的宏：

| **Fatal assertion**                 | **Nonfatal assertion**              | **Verifies**                           |
| :---------------------------------- | :---------------------------------- | :------------------------------------- |
| ASSERT_FLOAT_EQ(expected, actual);  | EXPECT_FLOAT_EQ(expected, actual);  | the two float values are almost equal  |
| ASSERT_DOUBLE_EQ(expected, actual); | EXPECT_DOUBLE_EQ(expected, actual); | the two double values are almost equal |

对于浮点数比较下的默认相等，默认的误差范围为4个[ULP(Units in the Last Place)](https://zh.wikipedia.org/wiki/%E6%9C%80%E5%90%8E%E4%B8%80%E4%BD%8D%E4%B8%8A%E7%9A%84%E5%8D%95%E4%BD%8D%E5%80%BC)


下面的宏允许用户自己指定一个精度来进行比较：

| **Fatal assertion**                 | **Nonfatal assertion**              | **Verifies**                                                                 |
| :---------------------------------- | :---------------------------------- | :--------------------------------------------------------------------------- |
| ASSERT_NEAR(val1, val2, abs_error); | EXPECT_NEAR(val1, val2, abs_error); | the difference between val1 and val2 doesn't exceed the given absolute error |
 

虽然一些浮点数的操作很有用，但是却不怎么常用，为了避免定义大量的浮点数相关的宏，这里定义了 predicate-format宏来：
```cpp
EXPECT_PRED_FORMAT2(testing::FloatLE, val1, val2);
EXPECT_PRED_FORMAT2(testing::DoubleLE, val1, val2);
```
