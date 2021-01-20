cmake_minimum_required(VERSION 3.0 FATAL_ERROR)
project(examples)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

if(MSVC)
    set(CMAKE_CXX_FLAGS_RELEASE "/MT")
    set(CMAKE_CXX_FLAGS_DEBUG "/MT")
endif()

# cmake自带的FindGTest.cmake
# 路径是/usr/share/cmake-x.y/Modules
find_package(GTest REQUIRED)

aux_source_directory(. SRC_FILE_LIST)
add_executable(sample ${SRC_FILE_LIST})
target_link_libraries(sample GTest::gtest_main)
