cmake_minimum_required(VERSION 3.12)
project(crypto)

add_executable(arithmetic
        main.cpp
        )

add_subdirectory(src)
add_subdirectory(test)