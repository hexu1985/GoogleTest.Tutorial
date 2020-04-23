### \*\_DEATH(statement, regex)

1）statement是被测试的代码语句

2）regex是一个正则表达式，用来匹配异常时在stderr中输出的内容

3）编写死亡测试案例时，TEST的第一个参数，即testcase_name，请使用DeathTest后缀。原因是gtest会优先运行死亡测试案例，应该是为线程安全考虑。
