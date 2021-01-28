#### 字符串断言

| **Fatal assertion**                         | **Nonfatal assertion**                      | **Verifies**                                            |
| :------------------------------------------ | :------------------------------------------ | :------------------------------------------------------ |
| ASSERT_STREQ(expected_str, actual_str);     | EXPECT_STREQ(expected_str, actual_str);     | the two C strings have the same content                 |
| ASSERT_STRNE(str1, str2);                   | EXPECT_STRNE(str1, str2);                   | the two C strings have different content                |
| ASSERT_STRCASEEQ(expected_str, actual_str); | EXPECT_STRCASEEQ(expected_str, actual_str); | the two C strings have the same content, ignoring case  |
| ASSERT_STRCASENE(str1, str2);               | EXPECT_STRCASENE(str1, str2);               | the two C strings have different content, ignoring case |

示例代码如下：
```cpp
TEST(StringCmpTest, Demo)
{
    char* pszCoderZh = "CoderZh";

    EXPECT_STREQ("CoderZh", pszCoderZh);
    EXPECT_STRNE("CnBlogs", pszCoderZh);
    EXPECT_STRCASEEQ("coderzh", pszCoderZh);  // Succeed
    EXPECT_STREQ("coderzh", pszCoderZh);      // Failure
}
```
