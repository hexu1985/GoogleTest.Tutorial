### TestCase事件

TestCase事件是挂在每个案例执行前后的，我们需要写一个类，继承testing::Test，然后需要实现的是SetUp方法和TearDown方法(override虚函数)：

1. SetUp()方法在每个TestCase之前执行

2. TearDown()方法在每个TestCase之后执行

示例代码如下：

```cpp
class MyStringTest : public testing::Test {
protected:
    virtual void SetUp()
    {
        std::cout << "MyStringTest SetUp" << std::endl;
        m_count = ++g_count;
    }
    virtual void TearDown()
    {
        std::cout << "MyStringTest TearDown" << std::endl;
    }

    int m_count;
};

// Tests the c'tor that accepts a C string.  
TEST_F(MyStringTest, ConstructorFromCString) {  
    std::cout << __func__ << ", m_count: " << m_count << std::endl;
    const MyString s(kHelloString);  
    EXPECT_EQ(0, strcmp(s.c_string(), kHelloString));  
    EXPECT_EQ(sizeof(kHelloString)/sizeof(kHelloString[0]) - 1,  
        s.Length());  
}  
  
// Tests the copy c'tor.  
TEST_F(MyStringTest, CopyConstructor) {  
    std::cout << __func__ << ", m_count: " << m_count << std::endl;
    const MyString s1(kHelloString);  
    const MyString s2 = s1;  
    EXPECT_EQ(0, strcmp(s2.c_string(), kHelloString));  
}  
```
