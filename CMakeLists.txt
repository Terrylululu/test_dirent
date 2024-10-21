cmake_minimum_required(VERSION 3.10)  # 指定CMake的最低版本要求

# 项目名称和语言
project(TestDirent CXX)

# 设置C++标准
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# 包含目录
include_directories(include)

# 添加可执行文件
add_executable(test_dirent test_dirent.cpp)

# 如果你的项目依赖于特定的库，你可以在这里添加它们
# target_link_libraries(test_dirent <library_name>)