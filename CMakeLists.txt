cmake_minimum_required(VERSION 3.6)
project(Project_3)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp Dictionary.cpp Dictionary.h d_except.h d_matrix.h)
add_executable(Project_3 ${SOURCE_FILES})