### TestSuite事件

我们需要写一个类，继承testing::Test，然后实现两个静态方法

1. SetUpTestCase() 方法在第一个TestCase之前执行

2. TearDownTestCase() 方法在最后一个TestCase之后执行

示例代码如下：

```cpp
class MyStringTest : public testing::Test {
protected:
    static void SetUpTestCase() {
        std::cout << "MyStringTest SetUpTestCase" << std::endl;
        s_count++; 
    }

    static void TearDownTestCase() {
        std::cout << "MyStringTest TearDownTestCase" << std::endl;
    }

    // Some expensive resource shared by all tests.
    static int s_count;
};

int MyStringTest::s_count = 0; 
```

在编写测试案例时，我们需要使用TEST_F这个宏，第一个参数必须是我们上面类的名字，代表一个TestSuite。

示例代码如下：

```cpp
// Tests the c'tor that accepts a C string.  
TEST_F(MyStringTest, ConstructorFromCString) {  
    std::cout << __func__ << ", s_count: " << s_count << std::endl;
    const MyString s(kHelloString);  
    EXPECT_EQ(0, strcmp(s.c_string(), kHelloString));  
    EXPECT_EQ(sizeof(kHelloString)/sizeof(kHelloString[0]) - 1,  
        s.Length());  
}  
  
// Tests the copy c'tor.  
TEST_F(MyStringTest, CopyConstructor) {  
    std::cout << __func__ << ", s_count: " << s_count << std::endl;
    const MyString s1(kHelloString);  
    const MyString s2 = s1;  
    EXPECT_EQ(0, strcmp(s2.c_string(), kHelloString));  
}  
```
