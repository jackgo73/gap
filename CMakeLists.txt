cmake_minimum_required(VERSION 3.16)
project(rotate)

set(CMAKE_CXX_STANDARD 14)

include_directories(problems)

add_subdirectory(problems)
add_subdirectory(tst)
add_subdirectory(lib/googletest)