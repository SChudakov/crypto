//
// Created by Semen on 10/4/2018.
//
#include <BigInteger.h>
#include <gtest/gtest.h>
#include <ChineseRemainderProblem.h>


TEST(chinese_remainder_problem, chrp_41) {
    ChineseRemainderProblem problem;
    
    vector<pair<uint64_t, uint64_t>> modulus_and_remainders = {{2, 1},
                                                     {3, 2},
                                                     {7, 6}};
    BigInteger expected_number = BigInteger::value_of(41);
    ASSERT_EQ(problem.chinese_remainder_problem(modulus_and_remainders), expected_number);
}

TEST(chinese_remainder_problem, chrp_797) {
    ChineseRemainderProblem problem;

    vector<pair<uint64_t, uint64_t>> modulus_and_remainders = {{5,  2},
                                                     {12, 5},
                                                     {17, 15}};
    BigInteger expected_number = BigInteger::value_of(797);
    ASSERT_EQ(problem.chinese_remainder_problem(modulus_and_remainders), expected_number);
}

TEST(chinese_remainder_problem, chrp_678868) {
    ChineseRemainderProblem problem;

    vector<pair<uint64_t, uint64_t>> modulus_and_remainders = {{5,  3},
                                                     {13, 8},
                                                     {17, 7},
                                                     {23, 0},
                                                     {29, 7}};
    BigInteger expected_number("678868");
    ASSERT_EQ(problem.chinese_remainder_problem(modulus_and_remainders), expected_number);
}

TEST(chinese_remainder_problem, chrp_10125328663) {
    ChineseRemainderProblem problem;

    vector<pair<uint64_t, uint64_t>> modulus_and_remainders = {{5,   3},
                                                     {13,  8},
                                                     {17,  7},
                                                     {23,  0},
                                                     {29,  7},
                                                     {41,  28},
                                                     {997, 51}};
    BigInteger expected_number("10125328663");
    ASSERT_EQ(problem.chinese_remainder_problem(modulus_and_remainders), expected_number);
}

TEST(chinese_remainder_problem, chrp_96298509233883) {
    ChineseRemainderProblem problem;

    vector<pair<uint64_t, uint64_t>> modulus_and_remainders = {{5,    3},
                                                     {13,   8},
                                                     {17,   7},
                                                     {23,   0},
                                                     {29,   7},
                                                     {41,   28},
                                                     {997,  51},
                                                     {3823, 756},};
    BigInteger expected_number("913958719513");
    ASSERT_EQ(problem.chinese_remainder_problem(modulus_and_remainders), expected_number);
}

TEST(chinese_remainder_problem, chrp_913958719513) {
    ChineseRemainderProblem problem;

    vector<pair<uint64_t, uint64_t>> modulus_and_remainders = {{5,    3},
                                                     {13,   8},
                                                     {17,   7},
                                                     {23,   0},
                                                     {29,   7},
                                                     {41,   28},
                                                     {997,  51},
                                                     {3823, 756},
                                                     {4073, 2473},
                                                     {4229, 2635},
                                                     {4493, 1035}};
    BigInteger expected_number("7017114774003040428805078");
    ASSERT_EQ(problem.chinese_remainder_problem(modulus_and_remainders), expected_number);
}
