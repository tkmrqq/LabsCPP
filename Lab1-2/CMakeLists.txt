cmake_minimum_required(VERSION 3.25)
project(Lab1)

set(CMAKE_CXX_STANDARD 17)

add_executable(Lab1 main.cpp radius.h)
add_executable(LabTest libTest.cpp strlib.h strlib.cpp)
