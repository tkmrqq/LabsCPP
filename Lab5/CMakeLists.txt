cmake_minimum_required(VERSION 3.26)
project(Lab5)

set(CMAKE_CXX_STANDARD 17)

project(exp LANGUAGES CXX)
add_library(exp INTERFACE exp.h)
target_include_directories(exp INTERFACE ${CMAKE_CURRENT_SOURCE_DIR})
