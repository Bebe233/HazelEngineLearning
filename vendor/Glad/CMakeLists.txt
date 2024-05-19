cmake_minimum_required (VERSION 3.0)

project (Glad)

set(CMAKE_C_STANDARD 11)
#Debug or Release
set(CMAKE_BUILD_TYPE "Debug")

message(STATUS "source path: ${PROJECT_SOURCE_DIR}")

# parameters

set(SRC_PATH ${PROJECT_SOURCE_DIR}/src )

set(INC_PATH ${PROJECT_SOURCE_DIR}/include)

set(LIBRARY_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/bin)

file(GLOB_RECURSE SRC_LIST ${SRC_PATH}/*.c)

# complier

include_directories(${INC_PATH})

add_library(Glad STATIC ${SRC_LIST})

