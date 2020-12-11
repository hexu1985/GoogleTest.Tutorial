cmake_minimum_required(VERSION 3.0 FATAL_ERROR)
project(examples)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

if(MSVC)
    set(CMAKE_CXX_FLAGS_RELEASE "/MT")
    set(CMAKE_CXX_FLAGS_DEBUG "/MT")
endif()

include_directories(${gtest_INCLUDE_DIRS})

link_directories(${gtest_LIB_DIRS})

aux_source_directory(. SRC_FILE_LIST)
add_executable(sample ${SRC_FILE_LIST})

if(MSVC)
  target_link_libraries(sample gtest_main gtest)
else()
  target_link_libraries(sample gtest_main gtest pthread)
endif()
