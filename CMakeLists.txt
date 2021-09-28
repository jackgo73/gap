cmake_minimum_required(VERSION 3.17)
project(gap VERSION 1.0.0 LANGUAGES C CXX)
set(CMAKE_CXX_STANDARD 14)

#option(GAP_BUILD_TESTS "Build gap's unit tests" ON)

include_directories(src/include)

add_subdirectory(lib/googletest)
add_subdirectory(src)
add_subdirectory(tst)

#set_property(TARGET gap PROPERTY C_STANDARD 99)