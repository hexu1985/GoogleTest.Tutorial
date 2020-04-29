### 类型参数化 

gtest还提供了应付各种不同类型的数据时的方案，以及参数化类型的方案。

假如有一个IContainer的接口类，我们需要自己实现基于vector和list的子类，那么我们的测试代码就要翻倍。

示例代码如下：

```cpp

class IContainer {
public:
    virtual void add(size_t num) = 0;
    virtual size_t count() const = 0;
    virtual void forEach(IteratorFuncT closure) const = 0;
};

class VectorContainer: public IContainer {
private:
    std::vector<size_t> items;

public:
    void add(size_t num) override {
        items.push_back(num);
    }

    size_t count() const override {
        return items.size();
    }

    void forEach(IteratorFuncT closure) const override {
        for(const size_t item: items) {
            closure(item);
        }
    }
};

class ListContainer: public IContainer {
private:
    std::list<size_t> items;

public:
    void add(size_t num) override {
        items.push_back(num);
    }

    size_t count() const override {
        return items.size();
    }

    void forEach(IteratorFuncT closure) const override {
        for(const size_t item: items) {
            closure(item);
        }
    }
};

TEST(VectorContainerTest, ShouldBeEmptyOnStartup) {
    VectorContainer container;
    ASSERT_EQ(container.count(), 0);
}

TEST(VectorContainerTest, ShouldAdd1) {
    VectorContainer container;
    container.add(1);
    ASSERT_EQ(container.count(), 1);
}

TEST(ListContainerTest, ShouldBeEmptyOnStartup) {
    ListContainer container;
    ASSERT_EQ(container.count(), 0);
}

TEST(ListContainerTest, ShouldAdd1) {
    ListContainer container;
    container.add(1);
    ASSERT_EQ(container.count(), 1);
}

```

我们需要做如下几步，将测试转成gtest的参数化类型的测试。

1. 首先定义一个模版类，继承testing::Test，然后使用TYPED_TEST_SUITE_P（在旧版本中使用TYPED_TEST_CASE_P宏，不过已经废弃）宏来这个模板类转换成支持类型参数化的testsuite

示例代码如下：

```cpp
template <typename T>
class ContainerTest: public ::testing::Test { };
//TYPED_TEST_CASE_P(ContainerTest);
TYPED_TEST_SUITE_P(ContainerTest);
```

2. 使用宏TYPED_TEST_P定义我们的测试用例，在声明模版的数据类型时，使用TypeParam 

示例代码如下：

```cpp
TYPED_TEST_P(ContainerTest, ShouldBeEmptyOnStartup) {
    TypeParam container;
    ASSERT_EQ(container.count(), 0);
}

TYPED_TEST_P(ContainerTest, ShouldAdd1) {
    TypeParam container;
    container.add(1);
    ASSERT_EQ(container.count(), 1);
}
```

之前的4个测试用例就减少到2个。

3. 接着，我们需要注册我们的测试用例，使用REGISTER_TYPED_TEST_SUITE_P（在旧版本中使用REGISTER_TYPED_TEST_CASE_P宏，不过已经废弃）宏，第一个参数是testsuite的名称，后面的参数是test的名称列表

示例代码如下：

```cpp
//REGISTER_TYPED_TEST_CASE_P(ContainerTest,
REGISTER_TYPED_TEST_SUITE_P(ContainerTest,
    ShouldBeEmptyOnStartup,
    ShouldAdd1
);
```
4. 接着指定需要的类型列表：通过typedef testing::Types指定类型参数列表，并通过使用INSTANTIATE_TYPED_TEST_SUITE_P（在旧版本中使用INSTANTIATE_TYPED_TEST_CASE_P，不过已经废弃）宏，
第一个参数是testsuite的前缀，可以任意取。 
第二个参数是testsuite的名称，需要和之前定义的参数化的类的名称相同。第三个参数是通过typedef testing::Types指定类型参数列表。

```cpp
typedef ::testing::Types<VectorContainer, ListContainer> ContainerTypes;
//INSTANTIATE_TYPED_TEST_CASE_P(ContainerTypesInstantiation, ContainerTest, ContainerTypes);
INSTANTIATE_TYPED_TEST_SUITE_P(ContainerTypesInstantiation, ContainerTest, ContainerTypes);
```

#### 参考

<http://anadoxin.org/blog/type-parametrized-unit-testing-in-gtest.html>
