cmake_minimum_required(VERSION 3.3)
project(uva)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp)
add_executable(uva ${SOURCE_FILES})
add_executable(100 100.cpp)
add_executable(10189 10189.cpp)