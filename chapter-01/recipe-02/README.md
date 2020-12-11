### 编译项目：手动指定链接gtest库

#### Makefile

需要指定gtest库，通过-lgtest指定，而且可能需要依赖-lpthread（linux平台上）

需要-I指定gtest头文件的安装路径

需要-L指定gtest库的安装路径

#### CMakeLists.txt

需要通过`target_link_libraries`指令指定链接gtest库，而且可能需要依赖pthread库（linux平台上），例如:
```
if(MSVC)
  target_link_libraries(sample gtest)
else()
  target_link_libraries(sample gtest pthread)
endif()
```

需要通过`include_directories`指令指定gtest头文件的安装路径，例如:
```
include_directories(${gtest_INCLUDE_DIRS})
```

需要通过`link_directories`指定gtest库的安装路径，例如:
```
link_directories(${gtest_LIB_DIRS})
```

执行cmake命令时需要通过`-D`手动设定`gtest_INCLUDE_DIRS`和`gtest_LIB_DIRS`变量，例如:
```
cmake -Dgtest_INCLUDE_DIRS=~/local/include \
	-Dgtest_LIB_DIRS=~/local/lib ..
```
