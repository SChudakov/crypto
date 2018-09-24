//
// Created by Semen on 9/20/2018.
//
#include "gtest/gtest.h"
#include "BigInteger.h"

TEST(to_power, zero_to_zero) {
    BigInteger zero = BigInteger::value_of(0);

    EXPECT_THROW(zero.to_power(0), std::invalid_argument);
}

TEST(to_power, to_zero_power) {
    BigInteger one = BigInteger::value_of(1);

    BigInteger eleven = BigInteger::value_of(11);
    BigInteger minus_eleven = BigInteger::value_of(-11);

    ASSERT_EQ(eleven.to_power(0), one);
    ASSERT_EQ(minus_eleven.to_power(0), one);
}

TEST(to_power, power_of_two) {

    BigInteger two = BigInteger::value_of(2);
    BigInteger minus_two = BigInteger::value_of(-2);

    BigInteger expected_two_power = BigInteger::value_of(1125899906842624ll);
    BigInteger expected_minus_two_odd_power = BigInteger::value_of(-2251799813685248ll);

    ASSERT_EQ(two.to_power(50), expected_two_power);
    ASSERT_EQ(minus_two.to_power(50), expected_two_power);
    ASSERT_EQ(minus_two.to_power(51), expected_minus_two_odd_power);
}

