//
// Created by Semen on 9/20/2018.
//
#include <BigInteger.h>
#include <gtest/gtest.h>

TEST(modulo, zero_one_minus_one) {
    BigInteger one = BigInteger::value_of(1);
    BigInteger zero = BigInteger::value_of(0);

    BigInteger ten = BigInteger::value_of(10);
    BigInteger minus_ten = BigInteger::value_of(-10);
    ASSERT_EQ(ten % one, zero);
    ASSERT_EQ(minus_ten % one, zero);
}

TEST(modulo, short_numbers) {
    BigInteger hundred_twenty_three = BigInteger::value_of(123);
    BigInteger twenty_seven = BigInteger::value_of(27);
    BigInteger fifteen = BigInteger::value_of(15);

    BigInteger million = BigInteger::value_of(1000000);
    BigInteger hundred_twenty_five = BigInteger::value_of(111);
    BigInteger one = BigInteger::value_of(1);

    ASSERT_EQ(hundred_twenty_three % twenty_seven, fifteen);
    ASSERT_EQ(million % hundred_twenty_five, one);
}

TEST(modulo, long_numbers_1) {
    BigInteger divident = BigInteger("1234567987654321");
    BigInteger modulo_base = BigInteger("12122333456");
    BigInteger modulo = BigInteger::value_of(5303828369);
    ASSERT_EQ(divident % modulo_base, modulo);
}

TEST(modulo, long_numbers_2) {
    BigInteger divident = BigInteger("1099511627776");
    BigInteger modulo_base = BigInteger("1073741824");
    BigInteger modulo = BigInteger::value_of(0);
    ASSERT_EQ(divident % modulo_base, modulo);
}

TEST(modulo, long_numbers_3) {
    BigInteger divident = BigInteger("1000000000000000");
    BigInteger modulo_base = BigInteger("1000000000");
    BigInteger modulo = BigInteger::value_of(0);
    ASSERT_EQ(divident % modulo_base, modulo);
}

TEST(modulo, invald_modulo_base) {

    BigInteger ten = BigInteger::value_of(10);
    BigInteger zero = BigInteger::value_of(0);
    BigInteger minus_five = BigInteger::value_of(-5);

    EXPECT_THROW(ten % zero, std::overflow_error);
    EXPECT_THROW(ten % minus_five, std::overflow_error);
}

TEST(modulo, division_test_1) {
    BigInteger divident("92763193484361");
    BigInteger divisor("200000000000");
    BigInteger remainder("163193484361");

    ASSERT_EQ(divident % divisor, remainder);
}
TEST(modulo, division_test_2) {
    BigInteger divident("92763193484361913481346");
    BigInteger divisor("331907983710");
    BigInteger remainder("274900936326");

    ASSERT_EQ(divident % divisor, remainder);
}
TEST(modulo, division_test_3) {
    BigInteger divident("92763193484361913481346");
    BigInteger divisor("305696327136");
    BigInteger remainder("82527378018");

    ASSERT_EQ(divident % divisor, remainder);
}

TEST(modulo, gcd_modulo_1) {
    BigInteger divident("1611623773");
    BigInteger divisor("945636286");
    BigInteger remainder("665987487");

    ASSERT_EQ(divident % divisor, remainder);
}

TEST(modulo, gcd_modulo_2) {
    BigInteger divident("1611623773");
    BigInteger divisor("1913713685");
    BigInteger remainder("1611623773");

    ASSERT_EQ(divident % divisor, remainder);
}
TEST(modulo, gcd_modulo_3) {
    BigInteger divident("100000000000000000000000000001313711692");
    BigInteger divisor("1611623773");
    BigInteger remainder("1464442218");

    ASSERT_EQ(divident % divisor, remainder);
}
