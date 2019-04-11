cmake_minimum_required(VERSION 3.1)

project(cpputil-test)

# Handle Google Test Framework

configure_file(CMakeLists.txt.in googletest-download/CMakeLists.txt)

execute_process(COMMAND ${CMAKE_COMMAND} -G "${CMAKE_GENERATOR}" .
    RESULT_VARIABLE result
    WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}/googletest-download)
if(result)
    message(FATAL_ERROR "CMake step for googletest failed: ${result}")
endif()

execute_process(COMMAND ${CMAKE_COMMAND} --build .
    RESULT_VARIABLE result
    WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}/googletest-download)
if(result)
    message(FATAL_ERROR "Build step for googletest failed: ${result}")
endif()

set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)

add_subdirectory(${CMAKE_CURRENT_BINARY_DIR}/googletest-src
                 ${CMAKE_CURRENT_BINARY_DIR}/googletest-build
                 EXCLUDE_FROM_ALL)

# Project Setup

set(CPPUTIL_DIR "${CMAKE_SOURCE_DIR}/cpputil")

include_directories(
    ${CPPUTIL_DIR}/algorithm
    ${CPPUTIL_DIR}/functional
    ${CPPUTIL_DIR}/iterator
    ${CPPUTIL_DIR}/memory
    ${CPPUTIL_DIR}/traits
    ${CPPUTIL_DIR}/thread
    ${CPPUTIL_DIR}/utility
    ${CMAKE_SOURCE_DIR}/test/algorithm
    ${CMAKE_SOURCE_DIR}/test/functional
    ${CMAKE_SOURCE_DIR}/test/iterator
    ${CMAKE_SOURCE_DIR}/test/memory
    ${CMAKE_SOURCE_DIR}/test/traits
    ${CMAKE_SOURCE_DIR}/test/thread
    ${CMAKE_SOURCE_DIR}/test/utility
    ${CMAKE_SOURCE_DIR}/test/test
)

file(GLOB_RECURSE TEST_HEADERS "*.hpp")
file(GLOB_RECURSE TEST_SOURCES "*.cpp")

if ("${CMAKE_CXX_COMPILER_ID}" STREQUAL "MSVC")
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /W4 /Za /permissive-")
else("${CMAKE_CXX_COMPILER_ID}" STREQUAL "GNU" OR "${CMAKE_CXX_COMPILER_ID}" STREQUAL "Clang")
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra -Wshadow")
endif()

add_executable(cpputil-test ${TEST_SOURCES} ${TEST_HEADERS})
target_link_libraries(cpputil-test cpputil gtest_main)

set_property(TARGET cpputil-test PROPERTY CXX_STANDARD 17)