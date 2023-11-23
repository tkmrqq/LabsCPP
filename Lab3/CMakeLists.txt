cmake_minimum_required(VERSION 3.25)
project(Lab3)

set(CMAKE_CXX_STANDARD 17)

add_executable(Lab3_2 variant8.cpp inheritance.h)
target_link_libraries(Lab3_2 exp)