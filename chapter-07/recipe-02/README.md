### 基于kcov统计测试覆盖率

#### kcov安装

Ubuntu18.04及更新系统, 可以直接apt命令安装:

```
$ sudo apt install kcov
```

源码方式安装lcov请自行网上搜索.

#### 使用方式

Kcov对编译的程序使用DWARF调试信息，以便无需特殊编译器开关即可收集覆盖信息。注：测试程序需要使用Debug模式编译。

- 需要在编译选项中使用`-g`, 例如:
```
$ g++ -o sample -Wall -g -std=c++11 -I/home/hexu/local/googletest/include \
    fun.cpp fun_test.cpp main.cpp MyString.cpp MyStringTest.cpp -lgtest -lpthread -L/home/hexu/local/googletest/lib
```

- 使用kcov生成覆盖率报表: 
```
$ kcov --include-path=. kcov_report ./sample
```

- Kcov选项的更多说明可以通过执行kcov --help来查看

- Kcov版本信息可以通过kcov --version来查看
