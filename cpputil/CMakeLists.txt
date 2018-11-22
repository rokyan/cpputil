cmake_minimum_required(VERSION 3.10)

project(cpputil-library)

set(CPPUTIL_DIR "${CMAKE_SOURCE_DIR}/cpputil")
set(CPPUTIL_SRC_DIR "${CPPUTIL_DIR}/src")

include_directories(
    ${CPPUTIL_SRC_DIR}/algorithm
    ${CPPUTIL_SRC_DIR}/functional
    ${CPPUTIL_SRC_DIR}/iterator
    ${CPPUTIL_SRC_DIR}/thread
    ${CPPUTIL_SRC_DIR}/traits
    ${CPPUTIL_SRC_DIR}/utility
)

file(GLOB_RECURSE CPPUTIL_HEADERS "*.hpp")
file(GLOB_RECURSE CPPUTIL_SOURCES "*.cpp")

add_library(cpputil STATIC ${CPPUTIL_HEADERS} ${CPPUTIL_SOURCES})