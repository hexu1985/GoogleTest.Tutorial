### 谓词断言Predicate Assertions 

尽管gtest提供了丰富多样的断言，但它不可能覆盖所有的用户可能需要的使用情况，有时候，用户不得不用EXPECT_TURE去检查一个比较复杂的表达式，因为没有合适的宏可以用，在这种情况下，一旦出错的话，并不能把相关的参数信息打印出来，作为一个workaround，一些用户就自已构造了一些错误信息输出。

针对这种问题， gtest 提供了三种不同的选择来解决

#### 使用一个已经存在的布尔型的函数

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
test.cpp:29: Failure
MutuallyPrime(m, n) evaluates to false, where
m evaluates to 5
n evaluates to 6
```

#### 使用返回值为 AssertionResult 类型的函数

虽然EXPECT_PRED*()能快速处理多个参数的问题，但是这个语法看起来不是很优美，因为不同的参数个数，你得调用不同的宏，如果多于5个目前还没有办法处理。 而类 ::testing::AssertionResult 可以解决这个问题。

一个AssertionResult对象代表了一个断言结果(不管是SUCCESS或者是FAILURE，都有一个消息)。你可以使用这些工厂方法来创建一个AssertionResult对象。
```cpp
namespace testing {

// Returns an AssertionResult object to indicate that an assertion has
// succeeded.
AssertionResult AssertionSuccess();

// Returns an AssertionResult object to indicate that an assertion has
// failed.
AssertionResult AssertionFailure();

}
```

通过AssertionResult对象，可以使用流操作符`<<`来输出一些需要的信息。
在布尔断言中，为了提供更好的更丰富的错误诊断信息，可以构造一个预测函数，返回AssertionResult 代替返回bool：见下例
```cpp
::testing::AssertionResult IsEven(int n) {
    if ((n % 2) == 0)
        return ::testing::AssertionSuccess();
    else
        return ::testing::AssertionFailure() << n << " is odd";
}
```
代替：
```cpp
bool IsEven(int n) {
    return (n % 2) == 0;
}
```
断言`EXPECT_TRUE(IsEven(Fib(4)));`失败的时候，会打印：
```
test.cpp:63: Failure
Value of: IsEven(Fib(4))
  Actual: false (3 is odd)
Expected: true
```
而不是简答的打印：
```
test.cpp:63: Failure
Value of: IsEven(Fib(4))
  Actual: false
Expected: true
```

#### 使用格式化宏

下面的这些宏，可以完全的自定义输出消息的格式

| **Fatal assertion**                            | **Nonfatal assertion**                         | **Verifies**                           |
| :--------------------------------------------- | :--------------------------------------------- | :------------------------------------- |
| ASSERT_PRED_FORMAT1(pred_format1, val1);       | EXPECT_PRED_FORMAT1(pred_format1, val1);       | pred_format1(val1) is successful       |
| ASSERT_PRED_FORMAT2(pred_format2, val1, val2); | EXPECT_PRED_FORMAT2(pred_format2, val1, val2); | pred_format2(val1, val2) is successful |
| ...                                            | ...                                            | ...                                    |

这些宏和上面介绍的宏(ASSERT_PRED*)最大的不同是多了_FORMAT*部分，这些宏一般与下面的函数一起使用：
```cpp
::testing::AssertionResult PredicateFormattern(const char*expr1, const char*expr2, ... const char*exprn, T1val1, T2val2, ... Tnvaln);
```

val1, val2, ..., valn是运行被测试函数需要的参数，这些参数的类型可以是值类型，也可以是引用类型。 expr1, expr2,..., exprn 是对应于 val* 的字符串。

一个 predicate-formatter返回一个::testing::AssertionResult的对象，用来标识SUCCESS或者FAILURE。

示例代码如下：

```cpp
testing::AssertionResult AssertFoo(const char* m_expr, const char* n_expr, const char* k_expr, int m, int n, int k) {
    if (Foo(m, n) == k)
        return testing::AssertionSuccess();
    testing::Message msg;
    msg << m_expr << " and " << n_expr << " 's gcd should be: " << Foo(m, n) << " , not " << k_expr;
    return testing::AssertionFailure(msg);
}

TEST(AssertFooTest, HandleFail)
{
    EXPECT_PRED_FORMAT3(AssertFoo, 3, 6, 2);
}
```

当失败时，返回错误信息：
```
test.cpp:81: Failure
3 and 6 's gcd should be: 3, not: 2
```

在使用(EXPECT|ASSERT)_PRED_FORMAT*时，需要一个predicate-formatter函数来配合使用，配合方式如下：
```cpp
//predicate-formatter
::testing::AssertionResult XXXXXXXXXXX(const char* expr_1,
                                       const char* expr_2,
                                       ... ,
                                       const char* expr_n,
                                       T1 val_1,
                                       T2 val_2,
                                       ... ,
                                       Tn val_n)
{
    //code here
}

//the macro
EXPECT_PRED_FORMATn(XXXXXXXXXXX, val_1,val_2,..., val_n);
```

需要注意的是，代码中XXXXXXXXXXX部分要完全相同，即要有相同的函数名。
