cmake_minimum_required(VERSION 2.8.9)
project(to-endian)

set(CMAKE_C_COMPILER_ID "GNU")
set(CMAKE_CXX_COMPILER_ID "GNU")
set(CMAKE_COMPILER_IS_GNUCXX TRUE)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${PROJECT_BINARY_DIR}/bin)
set(SOURCE_DIR ${CMAKE_BINARY_DIR}/src)
set(INCLUDE_DIR ${CMAKE_BINARY_DIR}/include)
include_directories("${INCLUDE_DIR}")
file(GLOB COMMON_HDRS "${INCLUDE_DIR}/*.hpp" "${INCLUDE_DIR}/*.cpp")
file(GLOB SOURCES "${SOURCE_DIR}/*.cpp")
string(REGEX REPLACE "${SOURCE_DIR}/([a-z-]+)\\.cpp" "\\1" BINARIES "${SOURCES}")

message(STATUS "SOURCE_DIR=${SOURCE_DIR}")
message(STATUS "INCLUDE_DIR=${INCLUDE_DIR}")
message(STATUS "COMMON_HDRS=${COMMON_HDRS}")
message(STATUS "SOURCES=${SOURCES}")
message(STATUS "BINARIES=${BINARIES}")

#
# loop foreach target
#

foreach(MAIN_EXE IN LISTS BINARIES)

set(MAIN_SRC "${SOURCE_DIR}/${MAIN_EXE}.cpp")

message(STATUS "${MAIN_EXE}: ${MAIN_SRC} ${COMMON_HDRS}")

add_executable("${MAIN_EXE}" "${MAIN_SRC}")

endforeach(MAIN_EXE)



