cmake_minimum_required(VERSION 3.26)
project(Lab4)

set(CMAKE_CXX_STANDARD 17)

add_executable(Lab4 Lab4.cpp myStack.h)
target_link_libraries(Lab4 exp)
