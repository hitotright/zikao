# CMake 最低版本号要求
cmake_minimum_required (VERSION 2.8)
# 项目信息
project (data_structure)
# 指定生成目标
add_executable(queue queue.cpp)
add_executable(stack stack.cpp)
add_executable(string string.cpp)
add_executable(array array.cpp)
add_executable(list list.cpp)
