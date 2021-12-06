cmake_minimum_required(VERSION 3.17)
project(gap VERSION 1.0.0 LANGUAGES C CXX)
set(CMAKE_CXX_STANDARD 14)

option(GAP_BUILD_TESTS "Build gap's unit tests" ON)

include_directories(src)
include_directories(src/include)

add_library(liblt SHARED ${SRC_SOURCES})
target_sources(liblt
        PRIVATE
        src/P_00001_TwoSum.c
        src/slist/P_00023_MergeKLists.c
        )


function(gap_test test_file)
    get_filename_component(test_target_name "${test_file}" NAME_WE)
    add_executable("${test_target_name}" "")
    target_sources("${test_target_name}"
            PRIVATE
            "${test_file}"
            )
    target_link_libraries("${test_target_name}" liblt gmock gtest benchmark)
    add_test(NAME "${test_target_name}" COMMAND "${test_target_name}")
endfunction(gap_test)


if (GAP_BUILD_TESTS)
    enable_testing()
    add_subdirectory("lib/googletest")
    add_subdirectory("lib/benchmark")

    gap_test(tst/base/dimarray.cpp)

    gap_test(tst/include/slist_UT.cpp)

    gap_test("tst/slist/P_00023_MergeKLists_UT.cpp")

    gap_test("tst/P_00001_TwoSum_UT.cpp")


endif (GAP_BUILD_TESTS)
