cmake_minimum_required(VERSION 3.30.4)

project(binary_tree VERSION 0.0.1 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

set(ENABLE_TESTING ON CACHE BOOL "Enable unit tests")

add_library(${CMAKE_PROJECT_NAME} INTERFACE)
target_include_directories(${CMAKE_PROJECT_NAME} INTERFACE include)

if (ENABLE_TESTING)
    enable_testing()
    add_subdirectory(tests)
endif (ENABLE_TESTING)

install(TARGETS ${CMAKE_PROJECT_NAME} RUNTIME DESTINATION ${INSTALL_BIN_DIR_NAME})
