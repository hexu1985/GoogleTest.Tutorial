### 编译项目：通过CMake的find_package

通过find_package查找gtest库，并不需要设置include_directories

```
find_package(GTest REQUIRED)
```

通过target_link_libraries链接gtest库，并不需要设置link_directories

```
target_link_libraries(sample GTest::GTest)
```

编译项目需要设置GTEST_ROOT路径：

```
$ mkdir build
$ cd build
$ cmake -DGTEST_ROOT=~/local \
    ..
$ VERBOSE=1 cmake --build . 
```

或者用更简单的方式，只需两行命令：

```
$ cmake -Bbuild -H. -DGTEST_ROOT=~/local
$ cmake --build build
```

