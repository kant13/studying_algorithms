cmake_minimum_required(VERSION 3.10.1)

set(TEST_RUNNER test_runner)
file(GLOB_RECURSE TEST_SRC_LIST "${CMAKE_CURRENT_LIST_DIR}/*.cpp")
add_executable(${TEST_RUNNER} ${TEST_SRC_LIST} ${SRC_LIST})
add_test(NAME ${TEST_RUNNER} COMMAND ./${TEST_RUNNER})
add_custom_target(unit_test ${TEST_RUNNER} COMMENT "Running unit test\n\n" VERBATIM)

# Running all unit test from root directory:
# make unit_test
