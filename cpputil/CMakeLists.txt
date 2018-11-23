cmake_minimum_required(VERSION 3.10)

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

add_library(cpputil STATIC ${CPPUTIL_HEADERS} ${CPPUTIL_SOURCES})