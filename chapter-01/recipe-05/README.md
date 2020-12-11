### 编译项目：通过CMake的find_package（使用gtest提供的main函数）

通过find_package查找gtest，并不需要设置include_directories

```
# 可能需要删除cmake自带的FindGTest.cmake
# 路径是/usr/share/cmake-x.y/Modules
find_package(GTest REQUIRED)
```

通过target_link_libraries链接gtest_main库，并不需要设置link_directories

```
target_link_libraries(sample GTest::gtest_main)
```

编译项目需要设置GTest_DIR路径：

```
$ mkdir build
$ cd build
$ cmake -DGTest_DIR=~/local/lib/cmake/GTest \
    ..
$ VERBOSE=1 cmake --build . 
```

