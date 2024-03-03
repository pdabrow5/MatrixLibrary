cmake_minimum_required(VERSION 3.18.4)

project(MatrixLibrary)

set (CMAKE_CXX_STANDARD 14)
SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -pthread")

add_subdirectory(lib)
add_subdirectory(tests)