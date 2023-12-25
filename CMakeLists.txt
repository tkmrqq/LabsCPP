cmake_minimum_required(VERSION 3.26)
project(LabsCPP)

set(CMAKE_CXX_STANDARD 14)

include_directories(Lab1-2)
include_directories(Lab3)
include_directories(Lab4)
include_directories(Lab5)
include_directories(Lab6)
include_directories(Lab7)

add_subdirectory(Lab1-2)
add_subdirectory(Lab3)
add_subdirectory(Lab4)
add_subdirectory(Lab5)
add_subdirectory(Lab6)
add_subdirectory(Lab7)

target_link_libraries(Lab6 exp)

add_executable(CW codewars.cpp)


