### 显示返回成功或失败

直接返回成功：SUCCEED();

返回失败：

| **Fatal assertion** | **Nonfatal assertion** |
| :------------------ | :--------------------- |
| FAIL();             | ADD_FAILURE();         |

示例代码如下：

```cpp
TEST(ExplicitTest, Demo)
{
    ADD_FAILURE() << "Sorry"; // None Fatal Asserton，继续往下执行。

    //FAIL(); // Fatal Assertion，不往下执行该test case。

    SUCCEED();
}
```
