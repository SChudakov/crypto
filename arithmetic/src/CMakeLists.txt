add_library(arithmetic "")

target_sources(arithmetic
        PRIVATE
            BigInteger.cpp
        PUBLIC
            ${CMAKE_CURRENT_LIST_DIR}/BigInteger.h
        )
target_include_directories(arithmetic
        PUBLIC
            ${CMAKE_CURRENT_LIST_DIR}
        )