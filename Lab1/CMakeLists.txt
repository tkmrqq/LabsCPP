cmake_minimum_required(VERSION 3.25)
project(Lab1)

set(CMAKE_CXX_STANDARD 17)

add_executable(Lab1 main.cpp header.h)

add_executable(Lab2 strlib.cpp strlib.h)
add_executable(LabTest libTest.cpp strlib.h strlib.cpp)
