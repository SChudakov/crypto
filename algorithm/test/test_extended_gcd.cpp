//
// Created by Semen on 10/27/2018.
//
#include <BigInteger.h>
#include <gtest/gtest.h>
#include <PollardsRhoFactorization.h>
#include <ExtendedGCD.h>


TEST(extended_gcd, extended_gcd_1) {
    ExtendedGCD gcd;

    BigInteger one = BigInteger::value_of(1);

    tuple<BigInteger, BigInteger, BigInteger> result = {BigInteger::value_of(1), BigInteger::value_of(0),
                                                        BigInteger::value_of(1)};
    ASSERT_EQ(gcd.extended_gcd(one, one), result);
}

TEST(extended_gcd, extended_gcd_2) {
    ExtendedGCD gcd;

    BigInteger three = BigInteger::value_of(3);
    BigInteger five = BigInteger::value_of(5);

    tuple<BigInteger, BigInteger, BigInteger> result = {BigInteger::value_of(1), BigInteger::value_of(2),
                                                        BigInteger::value_of(-1)};
    ASSERT_EQ(gcd.extended_gcd(three, five), result);
}

TEST(extended_gcd, extended_gcd_3) {
    ExtendedGCD gcd;

    BigInteger three = BigInteger::value_of(12);
    BigInteger five = BigInteger::value_of(6);

    tuple<BigInteger, BigInteger, BigInteger> result = {BigInteger::value_of(6), BigInteger::value_of(0),
                                                        BigInteger::value_of(1)};
    ASSERT_EQ(gcd.extended_gcd(three, five), result);
}

TEST(extended_gcd, extended_gcd_4) {
    ExtendedGCD gcd;

    BigInteger a = BigInteger::value_of(7);
    BigInteger b = BigInteger::value_of(1200);

    tuple<BigInteger, BigInteger, BigInteger> result = {BigInteger::value_of(1), BigInteger::value_of(343),
                                                        BigInteger::value_of(-2)};
    ASSERT_EQ(gcd.extended_gcd(a, b), result);
}
