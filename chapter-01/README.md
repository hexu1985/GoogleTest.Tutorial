### ubuntu下编译googletest

编译googletest项目需要依赖`cmake`，`g++`：

```
$ git clone https://github.com/google/googletest.git googletest
$ cd googletest
$ mkdir build
$ cd build
$ cmake -DCMAKE_INSTALL_PREFIX=~/local ..
$ cmake --build . --target install
```

CMAKE_INSTALL_PREFIX指定安装目录前缀，可能需要sudo权限执行install命令
