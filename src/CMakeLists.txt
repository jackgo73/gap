
set(BINARY ${CMAKE_PROJECT_NAME})
file(GLOB_RECURSE SOURCES LIST_DIRECTORIES true *.h *.cpp *.c)

include_directories(a_include)

set(SOURCES ${SOURCES})
add_library(lib_${BINARY} STATIC ${SOURCES})

add_executable(exe_main main.cpp)
add_executable(exe_examples_hcreate a_examples/hcreate.c)
add_executable(exe_examples_lfind a_examples/lfind.c)
