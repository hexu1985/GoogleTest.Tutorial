### TestCase事件

TestCase事件是挂在每个案例执行前后的，我们需要写一个类，继承testing::Test，然后需要实现的是SetUp方法和TearDown方法(override虚函数)：

1. SetUp()方法在每个TestCase之前执行

2. TearDown()方法在每个TestCase之后执行

在编写测试案例时，我们需要使用TEST_F这个宏，第一个参数必须是我们上面类的名字，代表一个TestSuite。
