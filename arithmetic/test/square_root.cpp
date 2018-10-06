//
// Created by Semen on 9/21/2018.
//
#include "gtest/gtest.h"
#include "BigInteger.h"


TEST(square_root, negative_number) {
    BigInteger minus_one = BigInteger::value_of(-1);

    EXPECT_THROW(minus_one.square_root(), std::runtime_error);
}

TEST(square_root, short_numbers) {
    BigInteger one = BigInteger::value_of(1);

    BigInteger ten = BigInteger::value_of(10);
    BigInteger three = BigInteger::value_of(3);


    BigInteger hundred_twenty_two = BigInteger::value_of(122);
    BigInteger eleven = BigInteger::value_of(11);


    ASSERT_EQ(one.square_root(), one);
    ASSERT_EQ(ten.square_root(), three);
    ASSERT_EQ(hundred_twenty_two.square_root(), eleven);
}

TEST(square_root, long_numbers_1) {
    BigInteger number = BigInteger("1000000000");
    BigInteger square_root = BigInteger::value_of(31622);
    ASSERT_EQ(number.square_root(), square_root);
}

TEST(square_root, long_numbers_2) {
    BigInteger number = BigInteger("10000000000");
    BigInteger square_root = BigInteger::value_of(100000);
    ASSERT_EQ(number.square_root(), square_root);
}

TEST(square_root, long_numbers_3) {
    BigInteger number = BigInteger("92763193484361913481346");
    BigInteger square_root = BigInteger("304570506589");
    ASSERT_EQ(number.square_root(), square_root);
}

TEST(square_root, long_numbers_4) {
    BigInteger number = BigInteger("1847568147658716457");
    BigInteger square_root = BigInteger("1359252790");
    ASSERT_EQ(number.square_root(), square_root);
}

TEST(square_root, long_numbers_5) {
    BigInteger number = BigInteger("6572465876527952345720986992586027756720867327506827");
    BigInteger square_root = BigInteger("81070746120459211829693569");
    ASSERT_EQ(number.square_root(), square_root);
}

TEST(square_root, long_numbers_6) {
    BigInteger number = BigInteger("17561874187581658716478165165");
    BigInteger square_root = BigInteger("132521221649898");
    ASSERT_EQ(number.square_root(), square_root);
}
