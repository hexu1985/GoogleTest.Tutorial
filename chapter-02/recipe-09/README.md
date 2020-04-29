### 类型检查

类型检查失败时，直接导致代码编不过，

在C++11中，`testing::StaticAssertTypeEq<T1, T2>`等价于`static_assert(std::is_same<T1, T2>::value, "xxx")`

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
