cmake_minimum_required (VERSION 3.10)

project("raytracing")

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)


# Here, gsl/gsl should be whatever X you want to write as `#include <X>`
find_path(GSL_INCLUDE_DIR gsl/gsl)
if(GSL_INCLUDE_DIR STREQUAL "GSL_INCLUDE_DIR-NOTFOUND")
  message(FATAL_ERROR "Could not find Guidelines Support Library.")
endif()
include_directories(${GSL_INCLUDE_DIR})

set(SOURCE_DIR "${CMAKE_CURRENT_LIST_DIR}/src")
set(TEST_DIR "${CMAKE_CURRENT_LIST_DIR}/test")

add_subdirectory(${SOURCE_DIR})

include(CTest)
if(BUILD_TESTING)
	add_subdirectory(${TEST_DIR})
endif()
