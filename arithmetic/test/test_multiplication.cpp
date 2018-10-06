//
// Created by Semen on 9/16/2018.
//
#include "gtest/gtest.h"
#include "BigInteger.h"

TEST(multiplication, zero_one_minus_one) {
    BigInteger zero = BigInteger::value_of(0);
    BigInteger one = BigInteger::value_of(1);
    BigInteger minus_one = BigInteger::value_of(-1);

    ASSERT_EQ(zero * zero, zero);
    ASSERT_EQ(one * zero, zero);
    ASSERT_EQ(minus_one * zero, zero);
    ASSERT_EQ(minus_one * one, minus_one);
    ASSERT_EQ(one * minus_one, minus_one);
}

TEST(multiplication, int_numbers) {
    BigInteger six = BigInteger::value_of(6);
    BigInteger eight = BigInteger::value_of(8);
    BigInteger minus_ten = BigInteger::value_of(-10);
    BigInteger minus_twelve = BigInteger::value_of(-12);

    BigInteger forty_eight = BigInteger::value_of(48);
    BigInteger minus_sixty = BigInteger::value_of(-60);
    BigInteger hundred = BigInteger::value_of(100);
    BigInteger minus_eighty = BigInteger::value_of(-80);
    BigInteger one_hundred_and_twenty = BigInteger::value_of(120);

    ASSERT_EQ(six * eight, forty_eight);
    ASSERT_EQ(six * minus_ten, minus_sixty);
    ASSERT_EQ(minus_ten * minus_ten, hundred);
    ASSERT_EQ(eight * minus_ten, minus_eighty);
    ASSERT_EQ(minus_twelve * minus_ten, one_hundred_and_twenty);


    BigInteger one = BigInteger::value_of(1);
    BigInteger minus_one = BigInteger::value_of(-1);
    BigInteger positive_max_of_length_one = BigInteger::value_of(999999999);
    BigInteger negative_max_of_length_one = BigInteger::value_of(-999999999);

    ASSERT_EQ(positive_max_of_length_one * one, positive_max_of_length_one);
    ASSERT_EQ(one * negative_max_of_length_one, negative_max_of_length_one);
    ASSERT_EQ(positive_max_of_length_one * minus_one, negative_max_of_length_one);
    ASSERT_EQ(minus_one * negative_max_of_length_one, positive_max_of_length_one);
}

TEST(multiplication, long_numbers_1) {
    BigInteger billion = BigInteger::value_of(1000000000l);
    BigInteger billion_times_billion("1000000000000000000");
    BigInteger expected_billion_times_billion = billion * billion;
    ASSERT_EQ(expected_billion_times_billion, billion_times_billion);
}

TEST(multiplication, long_numbers_2) {
    BigInteger positive_max = BigInteger::value_of(999999999);
    BigInteger positive_max_square("999999998000000001");
    BigInteger expected_positive_max_square = positive_max * positive_max;
    ASSERT_EQ(expected_positive_max_square, positive_max_square);
}

TEST(multiplication, long_numbers_3) {
    BigInteger two = BigInteger::value_of(2);
    BigInteger power_of_two = BigInteger::value_of(1);
    int exponent = 100;
    for (int i = 0; i < exponent; i++) {
        power_of_two = power_of_two * two;
    }
    vector<int> expected_power_of_two_vector;
    BigInteger expected_power_of_two("1267650600228229401496703205376");
    ASSERT_EQ(expected_power_of_two, power_of_two);
}

TEST(multiplication, long_numbers_4) {
    BigInteger multiplier_1 = BigInteger("331907983710");
    BigInteger multiplier_2 = BigInteger("100000000000");
    BigInteger product = BigInteger("33190798371000000000000");
    ASSERT_EQ(multiplier_1 * multiplier_2, product);
}