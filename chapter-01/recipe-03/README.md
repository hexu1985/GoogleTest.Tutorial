### 编译项目：CMake，通过find_package

通过find_package查找gtest，并不需要设置include_directories

```
# 可能需要删除cmake自带的FindGTest.cmake
# 路径是/usr/share/cmake-x.y/Modules
find_package(GTest REQUIRED)
```

通过target_link_libraries链接gtest库，并不需要设置link_directories

```
target_link_libraries(sample GTest::gtest)
```

编译项目需要设置GTest_DIR路径：

```
$ mkdir build
$ cd build
$ cmake -DGTest_DIR=~/local/lib/cmake/GTest \
    ..
$ VERBOSE=1 cmake --build . 
```

