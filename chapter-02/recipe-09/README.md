### 类型检查

类型检查失败时，直接导致代码编不过，

在C++11中，`testing::StaticAssertTypeEq<T1, T2>`等价于`static_assert(std::is_same<T1, T2>::value, "xxx")`
