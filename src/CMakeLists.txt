
set(BINARY ${CMAKE_PROJECT_NAME})
file(GLOB_RECURSE SRC_SOURCES LIST_DIRECTORIES true *.h *.cpp *.c)

add_library(${BINARY} STATIC ${SRC_SOURCES})
add_executable(${BINARY}_main main.cpp)
