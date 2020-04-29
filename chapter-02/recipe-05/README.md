### 异常检查

| **Fatal assertion**                      | **Nonfatal assertion**                   | **Verifies**                                    |
| :--------------------------------------- | :--------------------------------------- | :---------------------------------------------- |
| ASSERT_THROW(statement, exception_type); | EXPECT_THROW(statement, exception_type); | statement throws an exception of the given type |
| ASSERT_ANY_THROW(statement);             | EXPECT_ANY_THROW(statement);             | statement throws an exception of any type       |
| ASSERT_NO_THROW(statement);              | EXPECT_NO_THROW(statement);              | statement doesn't throw any exception           |

示例代码如下：

```cpp
int Foo(int a, int b)
{
    if (a == 0 || b == 0) {
        throw "don't do that";
    }

    int c = a % b;
    if (c == 0)
        return b;

    return Foo(b, c);
}


TEST(FooTest, HandleZeroInput)
{
    EXPECT_ANY_THROW(Foo(10, 0));
    EXPECT_THROW(Foo(0, 5), const char*);
}
```
