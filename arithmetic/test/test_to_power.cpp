//
// Created by Semen on 9/20/2018.
//
#include <BigInteger.h>
#include <gtest/gtest.h>

TEST(to_power, error_combinations) {
    BigInteger zero = BigInteger::value_of(0);
    BigInteger one = BigInteger::value_of(1);
    BigInteger minus_one = BigInteger::value_of(-1);
    EXPECT_THROW(zero.to_power(zero), std::invalid_argument);
    EXPECT_THROW(one.to_power(minus_one), std::invalid_argument);
}

TEST(to_power, zero_to_zero_bigint_power) {
    BigInteger zero = BigInteger::value_of(0);

    EXPECT_THROW(zero.to_power(0), std::invalid_argument);
}

TEST(to_power, to_zero_power_int_power) {
    BigInteger one = BigInteger::value_of(1);

    BigInteger eleven = BigInteger::value_of(11);
    BigInteger minus_eleven = BigInteger::value_of(-11);

    ASSERT_EQ(eleven.to_power(0), one);
    ASSERT_EQ(minus_eleven.to_power(0), one);
}

TEST(to_power, to_zero_power_bigint_power) {
    BigInteger zero = BigInteger::value_of(0);
    BigInteger one = BigInteger::value_of(1);

    BigInteger eleven = BigInteger::value_of(11);
    BigInteger minus_eleven = BigInteger::value_of(-11);

    ASSERT_EQ(eleven.to_power(zero), one);
    ASSERT_EQ(minus_eleven.to_power(zero), one);
}

TEST(to_power, power_of_two_int_power) {

    BigInteger two = BigInteger::value_of(2);
    BigInteger minus_two = BigInteger::value_of(-2);

    BigInteger expected_two_power = BigInteger::value_of(1125899906842624ll);
    BigInteger expected_minus_two_odd_power = BigInteger::value_of(-2251799813685248ll);

    ASSERT_EQ(two.to_power(50), expected_two_power);
    ASSERT_EQ(minus_two.to_power(50), expected_two_power);
    ASSERT_EQ(minus_two.to_power(51), expected_minus_two_odd_power);
}

TEST(to_power, power_of_two_bigint_power) {
    BigInteger two = BigInteger::value_of(2);
    BigInteger minus_two = BigInteger::value_of(-2);

    BigInteger fifty = BigInteger::value_of(50);
    BigInteger fifty_one = BigInteger::value_of(51);

    BigInteger expected_two_power = BigInteger::value_of(1125899906842624ll);
    BigInteger expected_minus_two_odd_power = BigInteger::value_of(-2251799813685248ll);

    ASSERT_EQ(two.to_power(fifty), expected_two_power);
    ASSERT_EQ(minus_two.to_power(fifty), expected_two_power);
    ASSERT_EQ(minus_two.to_power(fifty_one), expected_minus_two_odd_power);
}