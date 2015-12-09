cmake_minimum_required(VERSION 3.3)
project(ieee754)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp)
add_executable(ieee754 ${SOURCE_FILES})