//
// Created by Semen on 9/9/2018.
//
#include <BigInteger.h>
#include <gtest/gtest.h>

TEST(value_of, zero) {
    BigInteger zero = BigInteger::value_of(0);
}

TEST(value_of, one_minus_one) {
    BigInteger one = BigInteger::value_of(1);
    BigInteger minus_one = BigInteger::value_of(-1);
}

TEST(value_of, long_limits) {
    BigInteger positive_limit = BigInteger::value_of(4294967295);
    BigInteger negative_limit = BigInteger::value_of(-4294967296);
}
