cmake_minimum_required(VERSION 3.12)
project (crypto)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=gnu++0x")

enable_testing()

add_subdirectory(arithmetic)
add_subdirectory(algorithm)
add_subdirectory(lib/googletest)