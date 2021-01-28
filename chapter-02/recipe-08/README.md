### 类型检查

```cpp
::testing::StaticAssertTypeEq<T1, T2>();
```

`::testing::StaticAssertTypeEq<T1, T2>()`用来比较T1和T2两个类型是否相同，比如是否同为int。如果相同，这个函数什么也不做，如果不相同，这个函数会产生一个编译错误，错误消息会显示T1和T2的真实类型(具体消息的格式及如何显示取决于编译器)。在使用模板的代码中，这个函数会比较有用。

在C++11中，`testing::StaticAssertTypeEq<T1, T2>`会调用`static_assert(std::is_same<T1, T2>::value, "xxx")`来触发编译错误

示例代码如下：

```cpp
template <typename T> class FooType {
public:
    void Bar() { testing::StaticAssertTypeEq<int, T>(); }
};

TEST(TypeAssertionTest, Demo)
{
    FooType<bool> fooType;
    fooType.Bar();
}
```

编译时会输出如下编译错误：
```
In file included from test.cpp:1:0:
/home/hexu/local/include/gtest/gtest.h: In instantiation of ‘constexpr bool testing::StaticAssertTypeEq() [with T1 = int; T2 = bool]’:
test.cpp:5:53:   required from ‘void FooType<T>::Bar() [with T = bool]’
test.cpp:11:17:   required from here
/home/hexu/local/include/gtest/gtest.h:2313:3: error: static assertion failed: T1 and T2 are not the same type
   static_assert(std::is_same<T1, T2>::value, "T1 and T2 are not the same type");
   ^

```
