//
// Created by Semen on 10/21/2018.
//
#include <BigInteger.h>
#include <gtest/gtest.h>
#include <PollardsRhoFactorization.h>


TEST(factorization, not_positive) {
    PollardsRhoFactorization factorization;

    BigInteger minus_one = BigInteger::value_of(-1);
    BigInteger zero = BigInteger::value_of(0);

    ASSERT_THROW(factorization.factorize(minus_one), std::invalid_argument);
    ASSERT_THROW(factorization.factorize(zero), std::invalid_argument);
}

TEST(factorization, one_two_three) {
    PollardsRhoFactorization factorization;

    BigInteger one = BigInteger::value_of(1);
    vector<BigInteger> one_factors = {};

    BigInteger two = BigInteger::value_of(2);
    vector<BigInteger> two_factors = {};

    BigInteger three = BigInteger::value_of(3);
    vector<BigInteger> three_factors = {};


    ASSERT_EQ(factorization.factorize(one), one_factors);
    ASSERT_EQ(factorization.factorize(two), two_factors);
    ASSERT_EQ(factorization.factorize(three), three_factors);
}

TEST(factorization, small_numbers) {
    PollardsRhoFactorization factorization;

    BigInteger four = BigInteger::value_of(4);
    vector<BigInteger> four_factors = {BigInteger::value_of(2),
                                       BigInteger::value_of(2)};
    ASSERT_EQ(factorization.factorize(four), four_factors);

    BigInteger six = BigInteger::value_of(6);
    vector<BigInteger> six_factors = {BigInteger::value_of(2),
                                      BigInteger::value_of(3)};
    ASSERT_EQ(factorization.factorize(six), six_factors);

    BigInteger eight = BigInteger::value_of(8);
    vector<BigInteger> eight_factors = {BigInteger::value_of(2),
                                        BigInteger::value_of(2),
                                        BigInteger::value_of(2)};
    ASSERT_EQ(factorization.factorize(eight), eight_factors);

    BigInteger nine = BigInteger::value_of(9);
    vector<BigInteger> nine_factors = {BigInteger::value_of(3),
                                       BigInteger::value_of(3)};

    ASSERT_EQ(factorization.factorize(nine), nine_factors);

    BigInteger ten = BigInteger::value_of(10);
    vector<BigInteger> ten_factors = {BigInteger::value_of(2),
                                      BigInteger::value_of(5)};
    ASSERT_EQ(factorization.factorize(ten), ten_factors);

    BigInteger twelve = BigInteger::value_of(12);
    vector<BigInteger> twelve_factors = {BigInteger::value_of(2),
                                         BigInteger::value_of(2),
                                         BigInteger::value_of(3)};
    ASSERT_EQ(factorization.factorize(twelve), twelve_factors);
}

TEST(factorization, numbers) {
    PollardsRhoFactorization factorization;

    BigInteger number_1 = BigInteger::value_of(221);
    vector<BigInteger> number_1_factors = {BigInteger::value_of(13),
                                           BigInteger::value_of(17)};

    ASSERT_EQ(factorization.factorize(number_1), number_1_factors);

    BigInteger number_2 = BigInteger::value_of(33263);
    vector<BigInteger> prime_2_factors = {BigInteger::value_of(29),
                                          BigInteger::value_of(31),
                                          BigInteger::value_of(37)};

    ASSERT_EQ(factorization.factorize(number_2), prime_2_factors);

    BigInteger number_3 = BigInteger::value_of(62615533);
    vector<BigInteger> prime_3_factors = {BigInteger::value_of(7907),
                                          BigInteger::value_of(7919)};

    ASSERT_EQ(factorization.factorize(number_3), prime_3_factors);

    BigInteger number_4 = BigInteger::value_of(10967535067);
    vector<BigInteger> prime_4_factors = {BigInteger::value_of(104723),
                                          BigInteger::value_of(104729)};

    ASSERT_EQ(factorization.factorize(number_4), prime_4_factors);


    BigInteger number_5 = BigInteger::value_of(1689217490501);
    vector<BigInteger> prime_5_factors = {BigInteger::value_of(1299689),
                                          BigInteger::value_of(1299709)};

    ASSERT_EQ(factorization.factorize(number_5), prime_5_factors);
}

TEST(factorization, large_number_1) {
    PollardsRhoFactorization factorization;

    BigInteger number_1("178747004981223949");
    vector<BigInteger> number_1_factors = {BigInteger("224737"),
                                           BigInteger("611953"),
                                           BigInteger("1299709")};

    ASSERT_EQ(factorization.factorize(number_1), number_1_factors);

    BigInteger number_2("8465650336748518079455230673");
    vector<BigInteger> number_2_factors = {BigInteger("2038074743"),
                                           BigInteger("2038074751"),
                                           BigInteger("2038074761")};

    ASSERT_EQ(factorization.factorize(number_2), number_2_factors);
}
