

function(gap_test test_file)
    get_filename_component(test_target_name "${test_file}" NAME_WE)
    add_executable("${test_target_name}" "")
    target_sources("${test_target_name}"
            PRIVATE
            "${test_file}"
            )
    target_link_libraries("${test_target_name}" ${CMAKE_PROJECT_NAME} gtest)
    add_test(NAME "${test_target_name}" COMMAND "${test_target_name}")
endfunction(gap_test)


#if (GAP_BUILD_TESTS)
#endif (GAP_BUILD_TESTS)

enable_testing()


gap_test(utils/slist_UT.cpp)
gap_test("slist/P_00019_RemoveNthFromEnd_UT.cpp")
gap_test("slist/P_00023_MergeKLists_UT.cpp")

gap_test("slist/P_00876_MiddleNode_UT.cpp")
gap_test("slist/P_00021_MergeTwoLists_UT.cpp")
