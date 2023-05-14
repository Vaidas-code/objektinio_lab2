cmake_minimum_required(VERSION 3.0.0)
project(2.0Vector VERSION 0.1.0)
set(CMAKE_CXX_STANDARD 17)

add_executable(2.0vec_obj 2.0Vector.cpp)

#include_directories(${CMAKE_CURRENT_SOURCE_DIR}/headers)

 add_executable(tests tests.cpp)
