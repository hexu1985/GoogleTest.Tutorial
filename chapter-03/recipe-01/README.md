### gtest事件机制简介

gtest提供了多种事件机制，非常方便我们在test case之前或之后做一些操作。总结一下gtest的事件一共有3种：

1. 全局的，所有test case执行前后。
2. TestSuite级别的，在某一批test case中第一个case前，及最后一个case执行后。
3. TestCase级别的，每个test case前后。
