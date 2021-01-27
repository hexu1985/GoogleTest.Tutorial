### 谓词断言Predicate Assertions 

尽管gtest提供了丰富多样的断言，但它不可能覆盖所有的用户可能需要的使用情况，有时候，用户不得不用EXPECT_TURE去检查一个比较复杂的表达式，因为没有合适的宏可以用，在这种情况下，一旦出错的话，并不能把相关的参数信息打印出来，作为一个workaround，一些用户就自已构造了一些错误信息输出。

针对这种问题， gtest 提供了三种不同的选择来解决

####使用一个已经存在的布尔型的函数

如果你已经有一个返回布尔的函数，那么你可以使用下面的函数：

| **Fatal assertion**                         | **Nonfatal assertion**                      | **Verifies**                              |
| :------------------------------------------ | :------------------------------------------ | :---------------------------------------- |
| ASSERT_PRED1(pred1, val1);                  | EXPECT_PRED1(pred1, val1);                  | pred1(val1) returns true                  |
| ASSERT_PRED2(pred2, val1, val2);            | EXPECT_PRED2(pred2, val1, val2);            | pred2(val1, val2) returns true            |
| ...                                         | ...                                         | ...                                       |
| ASSERT_PREDn(pred2, val1, val2, ..., valn); | EXPECT_PREDn(pred2, val1, val2, ..., valn); | predn(val1, val2, ..., valn) returns true |

predn 的 n，可以是0,1,2,3,4,5(据说目前只支持5个), 表示了后面有几个值，如果这个宏失败了的话，就会打印出所有的表达式的结果(val)，这些参数表达式只会被计算一次。

示例代码如下：

```cpp
bool MutuallyPrime(int m, int n)
{
    return Foo(m , n) > 1;
}

TEST(PredicateAssertionTest, Demo)
{
    int m = 5, n = 6;
    EXPECT_PRED2(MutuallyPrime, m, n);
}
```

当失败时，返回错误信息：
```
test.cpp:23: Failure
MutuallyPrime(m, n) evaluates to false, where
m evaluates to 5
n evaluates to 6
```

