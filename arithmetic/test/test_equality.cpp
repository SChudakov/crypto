//
// Created by Semen on 9/9/2018.
//
#include "gtest/gtest.h"
#include "BigInteger.h"

TEST(equality, zero_one_minus_one) {
    BigInteger zero = BigInteger::value_of(0);
    BigInteger one = BigInteger::value_of(1);
    BigInteger minus_one = BigInteger::value_of(-1);

    ASSERT_TRUE(zero == zero);
    ASSERT_TRUE(one == one);
    ASSERT_TRUE(minus_one == minus_one);

    ASSERT_FALSE(zero == one);
    ASSERT_FALSE(zero == minus_one);
    ASSERT_FALSE(one == minus_one);
}


