### 显式的(explicit)成功或失败

SUCCEED()宏：生成一个success消息，但是，它并不能表明这一条测试是成功的，只有当一个测试的所有断言都是成功的，这个测试才是成功的。(注意：目前，SUCCEED()并不能产生一个用户可见的输出)

显式失败的宏：

| **Fatal assertion** | **Nonfatal assertion** | **Nonfatal assertion**                  |
| :------------------ | :--------------------- | :-------------------------------------- |
| FAIL();             | ADD_FAILURE();         | ADD_FAILURE_AT("file_path",line_number);|

FAIL()产生一个fatal failure，而ADD_FAILURE()和ADD_FAILURE_AT()产生一个nonfatal failure。 在一些控制流程中，它们会比一些布尔表达式更有用，比如有一些分支是不能走的，见下例：

```cpp
switch(expression) {
  case 1: ... some checks ...
  case 2: ... some other checks
  ...
  default: FAIL() << "We shouldn't get here.";
}
```

示例代码如下：

```cpp
TEST(ExplicitTest, Demo)
{
    ADD_FAILURE() << "Sorry"; // None Fatal Asserton，继续往下执行。

    //FAIL(); // Fatal Assertion，不往下执行该test case。

    ADD_FAILURE_AT("test_file.cpp", 19) << "Sorry again"; // None Fatal Asserton，继续往下执行。

    SUCCEED();
}
```
