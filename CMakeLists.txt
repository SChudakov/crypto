cmake_minimum_required(VERSION 2.6)
project (crypto)

include(GNUInstallDirs)

include(cmake/googletest.cmake)
fetch_googletest(
        ${PROJECT_SOURCE_DIR}/cmake
        ${PROJECT_BINARY_DIR}/googletest
)

add_subdirectory(arithmetic)
add_subdirectory(algorithm)