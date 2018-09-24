//
// Created by Semen on 9/9/2018.
//
#include "gtest/gtest.h"
#include "BigInteger.h"

TEST(subtraction, zero_one_minus_one) {
    BigInteger zero = BigInteger::value_of(0);
    BigInteger one = BigInteger::value_of(1);
    BigInteger minus_one = BigInteger::value_of(-1);

    ASSERT_EQ(zero, zero - zero);
    ASSERT_EQ(minus_one, zero - one);
    ASSERT_EQ(one, zero - minus_one);
    ASSERT_EQ(zero, minus_one - minus_one);
}

TEST(subtraction, combinations) {
    BigInteger six = BigInteger::value_of(6);
    BigInteger eight = BigInteger::value_of(8);
    BigInteger eighteen = BigInteger::value_of(18);

    BigInteger minus_ten = BigInteger::value_of(-10);
    BigInteger minus_twelve = BigInteger::value_of(-12);
    BigInteger minus_twenty = BigInteger::value_of(-20);

    BigInteger two = BigInteger::value_of(2);
    BigInteger minus_two = BigInteger::value_of(-2);

    ASSERT_EQ(eighteen, eight - minus_ten);
    ASSERT_EQ(two, minus_ten - minus_twelve);
    ASSERT_EQ(minus_ten, eight - eighteen);
    ASSERT_EQ(minus_twenty, minus_twelve - eight);


    BigInteger positive_limit_minus_two = BigInteger::value_of(4294967295 - 2);
    BigInteger negative_limit_plus_two = BigInteger::value_of(-4294967296 + 2);

    BigInteger positive_limit = BigInteger::value_of(4294967295);
    BigInteger negative_limit = BigInteger::value_of(-4294967296);

    ASSERT_EQ(positive_limit, positive_limit_minus_two - minus_two);
    ASSERT_EQ(negative_limit, negative_limit_plus_two - two);
}