### Predicate Assertions 

在使用EXPECT_TRUE或ASSERT_TRUE时，有时希望能够输出更加详细的信息，比如检查一个函数的返回值TRUE还是FALSE时，希望能够输出传入的参数是什么，以便失败后好跟踪。因此提供了如下的断言：

| **Fatal assertion**              | **Nonfatal assertion**           | **Verifies**                   |
| :------------------------------- | :------------------------------- | :----------------------------- |
| ASSERT_PRED1(pred1, val1);       | EXPECT_PRED1(pred1, val1);       | pred1(val1) returns true       |
| ASSERT_PRED2(pred2, val1, val2); | EXPECT_PRED2(pred2, val1, val2); | pred2(val1, val2) returns true |
| ...                              | ...                              | ...                            |

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
