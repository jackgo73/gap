set(BINARY ${CMAKE_PROJECT_NAME}_tst)

file(GLOB_RECURSE TEST_SOURCES LIST_DIRECTORIES false *.h *.cpp *.c)

#MESSAGE(status "$(TEST_SOURCES)")

# all test in one binary, use filter, adapt to ide.
add_executable(${BINARY} ${TEST_SOURCES})
target_link_libraries(${BINARY} PUBLIC ${CMAKE_PROJECT_NAME} gtest)


#add_test(NAME ${BINARY} COMMAND ${BINARY})

