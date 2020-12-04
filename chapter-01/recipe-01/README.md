### googletest编译安装

编译googletest项目需要依赖`cmake`：

```
$ git clone https://github.com/google/googletest.git googletest
$ cd googletest
$ mkdir build
$ cd build
$ cmake -DCMAKE_INSTALL_PREFIX=~/local ..
$ cmake --build . --target install
```

或者更简单的方式

```
$ git clone https://github.com/google/googletest.git googletest
$ cd googletest
$ cmake -H. -Bbuild -DCMAKE_INSTALL_PREFIX=~/local
$ cmake --build build --target install
```

CMAKE_INSTALL_PREFIX指定安装目录前缀，可能需要sudo权限执行install命令

CMAKE_BUILD_TYPE指定编译构建类型：例如Release或Debug
对于Visual Studio和Xcode，它们可以同时处理多个配置。可以使用 CMAKE_CONFIGURATION_TYPES 变量可以对这些生成器的可用配置类型进行调整，该变量将接受一个值列表(可从这个链接获得文档:<https://cmake.org/cmake/help/v3.5/variable/CMAKE_CONFIGURATION_TYPES.html>)
对Visual Studio的CMake调用，例如：
```
$ cmake -H. -Bbuild -DCMAKE_CONFIGURATION_TYPES="Release;Debug"
$ cmake --build build --config Release
```
