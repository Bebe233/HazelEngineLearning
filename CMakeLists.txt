cmake_minimum_required (VERSION 3.0)

project (HazelEngine)

set(CMAKE_CXX_STANDARD 17)

message(STATUS "source path: ${PROJECT_SOURCE_DIR}")

# parameters

set(SRC_PATH ${PROJECT_SOURCE_DIR}/src )

set(INC_PATH ${PROJECT_SOURCE_DIR}/src ${PROJECT_SOURCE_DIR}/vendor/spdlog/include)

set(PCH ${PROJECT_SOURCE_DIR}/src/hzpch.h)

set(LIBRARY_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/bin)

file(GLOB_RECURSE SRC_LIST ${SRC_PATH}/*.cpp)

# complier

include_directories(${INC_PATH})

add_library(Hazel STATIC ${SRC_LIST})

target_precompile_headers(Hazel PUBLIC ${PCH})

