
cmake_minimum_required(VERSION 2.8.9)

set(PROJ_NAME "ls-js-value-test")
set(SEP "/")

set(PROJ_SOURCE_DIR "${CMAKE_BINARY_DIR}${SEP}src")
set(PROJ_INCLUDE_DIR "${CMAKE_BINARY_DIR}${SEP}include")

get_filename_component(BASE_DIR "${CMAKE_BINARY_DIR}${SEP}.." REALPATH)
set(BASE_SOURCE_DIR "${BASE_DIR}${SEP}src")
set(BASE_INCLUDE_DIR "${BASE_DIR}${SEP}include")

file(GLOB SOURCES "${PROJ_SOURCE_DIR}${SEP}*.cpp" "${BASE_SOURCE_DIR}${SEP}*.cpp")
file(GLOB HEADERS "${PROJ_INCLUDE_DIR}${SEP}*.hpp" "${BASE_INCLUDE_DIR}${SEP}*.hpp")

set(RUNTIME_DIR "${CMAKE_BINARY_DIR}${SEP}bin")

message(STATUS "PROJ_NAME         = ${PROJ_NAME}")
message(STATUS "PROJ_SOURCE_DIR   = ${PROJ_SOURCE_DIR}")
message(STATUS "PROJ_INCLUDE_DIR  = ${PROJ_INCLUDE_DIR}")
message(STATUS "BASE_DIR          = ${BASE_DIR}")
message(STATUS "BASE_SOURCE_DIR   = ${BASE_SOURCE_DIR}")
message(STATUS "BASE_INCLUDE_DIR  = ${BASE_INCLUDE_DIR}")
message(STATUS "RUNTIME_DIR       = ${RUNTIME_DIR}")

message(STATUS "SOURCES           = ${SOURCES}")
message(STATUS "HEADERS           = ${HEADERS}")

project(ls-js-value-test)

set(CMAKE_C_COMPILER_ID "GNU")
set(CMAKE_CXX_COMPILER_ID "GNU")
set(CMAKE_COMPILER_IS_GNUCXX TRUE)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -g")
set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS}")
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${RUNTIME_DIR}")

add_executable("${PROJ_NAME}" "${SOURCES}")
include_directories("${PROJ_INCLUDE_DIR}")
include_directories("${BASE_INCLUDE_DIR}")




