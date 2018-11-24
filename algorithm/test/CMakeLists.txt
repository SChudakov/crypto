project(algorithm_test)

include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})

add_executable(algorithm_test
        main.cpp
        test_pollards_factorization.cpp
        test_gcd.cpp
        test_discrete_logarithm.cpp
        test_extended_gcd.cpp
        test_euler_function.cpp
        test_jacobian_symbol.cpp
        test_mobius_function.cpp
        test_legendre_symbol.cpp
        test_solovay_strassen.cpp
        test_cipollas_algorithm.cpp
        test_floyds_algorithm.cpp
        test_chinese_remainder_problem.cpp
        test_el_gamal.cpp)

target_link_libraries(algorithm_test gtest gtest_main)
target_link_libraries(algorithm_test algorithm)