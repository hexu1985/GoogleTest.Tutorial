### 编译项目：Makefile（使用gtest提供的main函数）

需要指定gtest_main和gtest库，通过-lgtest_main和-lgtest指定，而且可能需要依赖-lpthread（linux平台上）

需要-I指定gtest头文件的安装路径

需要-L指定gtest库的安装路径

