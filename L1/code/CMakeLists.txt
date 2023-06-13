cmake_minimum_required(VERSION 3.16)
PROJECT(HELLO)
set(HELLO_INCLUDE_DIR ${PROJECT_SOURCE_DIR}/include)
# set(CMAKE_MODULE_PATH ${PROJECT_SOURCE_DIR}/src)
ADD_SUBDIRECTORY(src bin)
#添加测试用例
enable_testing()
add_subdirectory(gtest bin/gtest)
