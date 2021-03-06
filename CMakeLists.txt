
cmake_minimum_required(VERSION 2.8.9)

set(PROJ_NAME "ls-js-value")

set(SEP "/")

set(PROJ_SOURCE_DIR "${CMAKE_BINARY_DIR}/src")
set(PROJ_INCLUDE_DIR "${CMAKE_BINARY_DIR}/include")

file(GLOB SOURCES "${PROJ_SOURCE_DIR}/*.cpp")
file(GLOB HEADERS "${PROJ_INCLUDE_DIR}/*.hpp")

set(PROJ_RUNTIME_DIR ${CMAKE_BINARY_DIR}/bin)

message(STATUS "PROJ_NAME         = ${PROJ_NAME}")
message(STATUS "PROJ_SOURCE_DIR   = ${PROJ_SOURCE_DIR}")
message(STATUS "PROJ_INCLUDE_DIR  = ${PROJ_INCLUDE_DIR}")
message(STATUS "PROJ_RUNTIME_DIR  = ${PROJ_RUNTIME_DIR}")
message(STATUS "SOURCES           = ${SOURCES}")

project(ls-js-value-test)

set(CMAKE_C_COMPILER_ID "GNU")
set(CMAKE_CXX_COMPILER_ID "GNU")
set(CMAKE_COMPILER_IS_GNUCXX TRUE)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -fPIC")
set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -shared")
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${PROJ_RUNTIME_DIR}")
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY "${PROJECT_BINARY_DIR}${SEP}${PROJ_RUNTIME_DIR}")

include_directories("${PROJ_INCLUDE_DIR}")
add_library("${PROJ_NAME}" SHARED "${SOURCES}")



