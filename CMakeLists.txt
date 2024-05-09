cmake_minimum_required(VERSION 3.15)

# 项目名称  ${PROJECT_NAME}
# set(PROJECT_NAME Algorithm)

# 项目名称及版本
project(Algorithm VERSION 1.0)

# C++20
set(CMAKE_CXX_STANDARD 20)

# 头文件目录
include_directories(include)

# 添加源文件
set(SRC_LIST src/main.cpp src/MySort.cpp tests/MySortUnitTest.cpp)

# 创建
add_executable(Algorithm ${SRC_LIST})


target_precompile_headers(Algorithm PRIVATE include/stdafx.h)