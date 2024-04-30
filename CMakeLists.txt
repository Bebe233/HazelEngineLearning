cmake_minimum_required (VERSION 3.0)

project (HazelEngineLearning)

set(CMAKE_CXX_STANDARD 11)

set(SRC_PATH ${PROJECT_SOURCE_DIR}/src)

set(LIBRARY_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/bin)

file(GLOB_RECURSE SRC_LIST ${SRC_PATH}/*.cpp)

include_directories(${SRC_PATH})

add_library(Hazel SHARED ${SRC_LIST})

