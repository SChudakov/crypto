//
// Created by Semen on 9/9/2018.
//
#include <BigInteger.h>
#include <gtest/gtest.h>

TEST(addition, zero_one_minus_one) {
    BigInteger zero = BigInteger::value_of(0);
    BigInteger one = BigInteger::value_of(1);
    BigInteger minus_one = BigInteger::value_of(-1);

    ASSERT_EQ(zero, zero + zero);
    ASSERT_EQ(one, zero + one);
    ASSERT_EQ(minus_one, zero + minus_one);
    ASSERT_EQ(zero, one + minus_one);
}

TEST(addition, combinations) {
    BigInteger six = BigInteger::value_of(6);
    BigInteger eight = BigInteger::value_of(8);
    BigInteger fourteen = BigInteger::value_of(14);

    BigInteger minus_ten = BigInteger::value_of(-10);
    BigInteger minus_twelve = BigInteger::value_of(-12);
    BigInteger minus_twenty_two = BigInteger::value_of(-22);

    BigInteger two = BigInteger::value_of(2);
    BigInteger minus_two = BigInteger::value_of(-2);

    ASSERT_EQ(six + eight, fourteen);
    ASSERT_EQ(minus_ten + minus_twelve, minus_twenty_two);
    ASSERT_EQ(fourteen + minus_twelve, two);
    ASSERT_EQ(eight + minus_ten, minus_two);


    BigInteger positive_limit_minus_two = BigInteger::value_of(4294967295 - 2);
    BigInteger negative_limit_plus_two = BigInteger::value_of(-4294967296 + 2);

    BigInteger positive_limit = BigInteger::value_of(4294967295);
    BigInteger negative_limit = BigInteger::value_of(-4294967296);

    ASSERT_EQ(positive_limit_minus_two + two, positive_limit);
    ASSERT_EQ(negative_limit + two, negative_limit_plus_two);
}