### 自定义格式的Predicate Assertions

| **Fatal assertion**                            | **Nonfatal assertion**                         | **Verifies**                           |
| :--------------------------------------------- | :--------------------------------------------- | :------------------------------------- |
| ASSERT_PRED_FORMAT1(pred_format1, val1);       | EXPECT_PRED_FORMAT1(pred_format1, val1);       | pred_format1(val1) is successful       |
| ASSERT_PRED_FORMAT2(pred_format2, val1, val2); | EXPECT_PRED_FORMAT2(pred_format2, val1, val2); | pred_format2(val1, val2) is successful |
| ...                                            | ...                                            | ...                                    |

示例代码如下：

```cpp
testing::AssertionResult AssertFoo(const char* m_expr, const char* n_expr, const char* k_expr, int m, int n, int k) {
    if (Foo(m, n) == k)
        return testing::AssertionSuccess();
    testing::Message msg;
    msg << m_expr << " 和 " << n_expr << " 的最大公约数应该是：" << Foo(m, n) << " 而不是：" << k_expr;
    return testing::AssertionFailure(msg);
}

TEST(AssertFooTest, HandleFail)
{
    EXPECT_PRED_FORMAT3(AssertFoo, 3, 6, 2);
}
```
