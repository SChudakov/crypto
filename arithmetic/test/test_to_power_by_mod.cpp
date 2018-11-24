//
// Created by Semen on 11/18/2018.
//
#include <BigInteger.h>
#include <gtest/gtest.h>

TEST(to_power_by_mod, power_error_combinations) {
    BigInteger zero = BigInteger::value_of(0);
    BigInteger one = BigInteger::value_of(1);
    BigInteger minus_one = BigInteger::value_of(-1);
    BigInteger modulo = BigInteger::value_of(2);

    EXPECT_THROW(zero.to_power(zero, modulo), std::invalid_argument);
    EXPECT_THROW(one.to_power(minus_one, modulo), std::invalid_argument);
}

TEST(to_power_by_mod, modulo_error_combinations) {
    BigInteger one = BigInteger::value_of(1);

    EXPECT_THROW(one.to_power(one, one), std::invalid_argument);
    EXPECT_THROW(one.to_power(one, -one), std::invalid_argument);
}

TEST(to_power_by_mod, simple) {
    ASSERT_EQ(BigInteger::value_of(5).to_power(320, BigInteger::value_of(7)), BigInteger::value_of(4));
    ASSERT_EQ(BigInteger::value_of(9).to_power(119, BigInteger::value_of(713)), BigInteger::value_of(255));
}