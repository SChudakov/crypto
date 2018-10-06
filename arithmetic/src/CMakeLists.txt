add_library(biginteger)

target_sources(biginteger
        PRIVATE
            BigInteger.cpp
        PUBLIC
            ${CMAKE_CURRENT_LIST_DIR}/BigInteger.h
        )
target_include_directories(biginteger
        PUBLIC
            ${CMAKE_CURRENT_LIST_DIR}
        )