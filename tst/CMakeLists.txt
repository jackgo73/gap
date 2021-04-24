set(BINARY ${CMAKE_PROJECT_NAME}_tst)

file(GLOB_RECURSE TEST_SOURCES LIST_DIRECTORIES false *.h *.cpp *.c)

#MESSAGE(status "$(TEST_SOURCES)")

add_executable(${BINARY} ${TEST_SOURCES})
target_link_libraries(${BINARY} PUBLIC ${CMAKE_PROJECT_NAME} gtest)

#add_executable(p_00002_add_two_numbers p_00002_add_two_numbers/add_two_numbers_tst.cpp)
#target_link_libraries(p_00002_add_two_numbers PUBLIC ${CMAKE_PROJECT_NAME} gtest)



#add_test(NAME ${BINARY} COMMAND ${BINARY})

