cmake_minimum_required(VERSION 3.1)

project(cpputil-library)

set(CPPUTIL_DIR "${CMAKE_SOURCE_DIR}/cpputil")

include_directories(
    ${CPPUTIL_DIR}/algorithm
    ${CPPUTIL_DIR}/functional
    ${CPPUTIL_DIR}/iterator
    ${CPPUTIL_DIR}/thread
    ${CPPUTIL_DIR}/traits
    ${CPPUTIL_DIR}/utility
)

file(GLOB_RECURSE CPPUTIL_HEADERS "*.hpp")
file(GLOB_RECURSE CPPUTIL_SOURCES "*.cpp")

if ("${CMAKE_CXX_COMPILER_ID}" STREQUAL "MSVC")
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /W4 /Za /permissive-")
else("${CMAKE_CXX_COMPILER_ID}" STREQUAL "GNU" OR "${CMAKE_CXX_COMPILER_ID}" STREQUAL "Clang")
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra -Wshadow")
endif()

add_library(cpputil STATIC ${CPPUTIL_HEADERS} ${CPPUTIL_SOURCES})

set_property(TARGET cpputil PROPERTY CXX_STANDARD 17)