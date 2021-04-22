cmake_minimum_required(VERSION 3.16)
project(rotate)

set(CMAKE_CXX_STANDARD 14)
#set(CMAKE_C_STANDARD 99)

include_directories(src)
include_directories(tst)


add_subdirectory(src)
add_subdirectory(tst)
add_subdirectory(lib/googletest)