cmake_minimum_required(VERSION 3.26)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

project(euler_review)
include(cmake/submodule.cmake)
include(CTest)

add_subdirectory(src)
add_subdirectory(external)
add_subdirectory(tests)

