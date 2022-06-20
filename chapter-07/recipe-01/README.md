### 基于lcov统计测试覆盖率

#### lcov安装

Ubuntu18.04及更新系统, 可以直接apt命令安装:

```
$ sudo apt install lcov
```

源码方式安装lcov请自行网上搜索.

#### 使用方式

- 需要在编译选项中新增`-fprofile-arcs -ftest-coverage`, 编译完成才能生成覆盖率相关的*.gcda文件, 例如:
```
$ g++ -o sample -Wall -g -std=c++11 -fprofile-arcs -ftest-coverage -I/home/hexu/local/googletest/include \
    fun.cpp fun_test.cpp main.cpp MyString.cpp MyStringTest.cpp -lgtest -lpthread -L/home/hexu/local/googletest/lib
```

- 运行测试用例的目标文件, 本例中:`./sample`. 运行成功在对应的源码目录会生成与gcda对应的gcno文件.
```
$ ls
fun.cpp   fun.h         fun_test.gcno  main.cpp   Makefile      MyString.gcno  MyStringTest.cpp   README.md
fun.gcno  fun_test.cpp  gen_cov.sh     main.gcno  MyString.cpp  MyString.h     MyStringTest.gcno  sample
```

- 使用lcov生成覆盖率统计文件: `lcov -d . -t 'sample' -o 'sample.info' -b . -c`, 命令含义如下:
    + `-d src_dir`: 待覆盖率测试的源码目录，此处为`.`当前目录
    + `-t sample`: 目标的名称，可不带引号，此处为sample
    + `-o sample.info`: 生成的覆盖率文件，可自定义，可不带引号
    + `-b .`: 相对目录的起始位置
    + `-c`: capture，采集覆盖率

- 使用genhtml生成覆盖率报表: `genhtml -o cov_report sample.info`
    + `-o cov_report`: 输出的目标文件夹，可带路径，此处为当前目录下的cov_report目录
    + `sample.info`: 覆盖率的统计文件

- 使用浏览器打开cov_report/index.html文件

