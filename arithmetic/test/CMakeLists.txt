project(arithmetic_tests)

include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})

add_executable(arithmetic_tests
        main.cpp
        test_value_of.cpp
        test_additioin.cpp
        test_subtraction.cpp
        test_equality.cpp
        test_multiplication.cpp
        test_division.cpp test_modulo.cpp test_to_power.cpp square_root.cpp test_chinese_remainder_problem.cpp)


add_subdirectory(lib/googletest)

target_link_libraries(arithmetic_tests gtest gtest_main)
target_link_libraries(arithmetic_tests biginteger)


