cmake_minimum_required(VERSION 3.10)

project(cpputil-test)

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

include_directories(
    ${CMAKE_SOURCE_DIR}/include/cpputil/functional
    ${CMAKE_SOURCE_DIR}/include/cpputil/traits
    ${CMAKE_SOURCE_DIR}/include/cpputil/utility
    ${CMAKE_SOURCE_DIR}/test
)

# Include all cpputil library header files
file(GLOB_RECURSE CPPUTIL_HEADERS "${CMAKE_SOURCE_DIR}/include/*.hpp")
# Include all header and sources files for the cpputil-test project
file(GLOB TEST_HEADERS "*.hpp")
file(GLOB TEST_SOURCES "*.cpp")

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /W4 /Za /permissive-")

add_executable(cpputil-test ${TEST_SOURCES} ${TEST_HEADERS} ${CPPUTIL_HEADERS})

set_property(TARGET cpputil-test PROPERTY CXX_STANDARD 17)

target_link_libraries(cpputil-test gtest_main)