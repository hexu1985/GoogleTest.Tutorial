### 类型参数化 

gtest还提供了应付各种不同类型的数据时的方案，以及参数化类型的方案。

1. 首先定义一个模版类，继承testing::Test，然后使用TYPED_TEST_SUITE_P（在旧版本中使用TYPED_TEST_CASE_P宏，不过已经废弃）
宏来这个模板类转换成支持类型参数化的testsuite

2. 使用宏TYPED_TEST_P定义我们的测试用例，在声明模版的数据类型时，使用TypeParam 

3. 接着，我们需要注册我们的测试用例，使用REGISTER_TYPED_TEST_SUITE_P（在旧版本中使用REGISTER_TYPED_TEST_CASE_P宏，不过已经废弃）宏，
第一个参数是testsuite的名称，后面的参数是test的名称列表

4. 接着指定需要的类型列表：通过typedef testing::Types指定类型参数列表，并通过使用INSTANTIATE_TYPED_TEST_SUITE_P
（在旧版本中使用INSTANTIATE_TYPED_TEST_CASE_P，不过已经废弃）宏，第一个参数是testsuite的前缀，可以任意取。 
第二个参数是testsuite的名称，需要和之前定义的参数化的类的名称相同。第三个参数是通过typedef testing::Types指定类型参数列表。

#### 参考

<http://anadoxin.org/blog/type-parametrized-unit-testing-in-gtest.html>
