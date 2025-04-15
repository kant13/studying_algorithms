cmake_minimum_required(VERSION 3.30.4)

# Define variables
set(TEST_RUNNER test_runner)
file(GLOB_RECURSE TEST_SRC_LIST "*.cxx")

# Configure test target
add_executable(${TEST_RUNNER} ${TEST_SRC_LIST})
target_link_libraries(${TEST_RUNNER} ${CMAKE_PROJECT_NAME})

# Run tests
add_test(NAME ${TEST_RUNNER} COMMAND ./${TEST_RUNNER} -d yes)
