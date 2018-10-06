//
// Created by Semen on 9/16/2018.
//
#include "gtest/gtest.h"
#include "BigInteger.h"


TEST(division, zero_division) {

    BigInteger one = BigInteger::value_of(1);
    BigInteger zero = BigInteger::value_of(0);

    EXPECT_THROW(one / zero, std::overflow_error);
}

TEST(division, zero_one_minus_one) {
    BigInteger one = BigInteger::value_of(1);
    BigInteger zero = BigInteger::value_of(0);
    BigInteger minus_one = BigInteger::value_of(-1);

    BigInteger ten = BigInteger::value_of(10);
    BigInteger minus_ten = BigInteger::value_of(-10);

    ASSERT_EQ(ten / one, ten);
    ASSERT_EQ(ten / minus_one, minus_ten);
    ASSERT_EQ(minus_ten / one, minus_ten);
    ASSERT_EQ(minus_ten / minus_one, ten);
}

TEST(division, short_numbers) {
    BigInteger hundred_twenty_three = BigInteger::value_of(123);
    BigInteger twenty_seven = BigInteger::value_of(27);
    BigInteger four = BigInteger::value_of(4);

    BigInteger million = BigInteger::value_of(1000000);
    BigInteger hundred_twenty_five = BigInteger::value_of(125);
    BigInteger eight_thousands = BigInteger::value_of(8000);

    ASSERT_EQ(hundred_twenty_three / twenty_seven, four);
    ASSERT_EQ(million / hundred_twenty_five, eight_thousands);
}

TEST(division, long_numbers_1) {
    BigInteger divident = BigInteger("1234567987654321");
    BigInteger divisor = BigInteger("12122333456");
    BigInteger quotient = BigInteger::value_of(101842);
    ASSERT_EQ(divident / divisor, quotient);
}

TEST(division, long_numbers_2) {
    BigInteger divident = BigInteger("1099511627776");
    BigInteger divisor = BigInteger("1073741824");
    BigInteger quotient = BigInteger::value_of(1024);
    ASSERT_EQ(divident / divisor, quotient);
}

TEST(division, long_numbers_3) {
    BigInteger divident = BigInteger("1000000000000000");
    BigInteger divisor = BigInteger("1000000000");
    BigInteger quotient = BigInteger::value_of(1000000);
    ASSERT_EQ(divident / divisor, quotient);
}

TEST(division, long_numbers_4) {
    BigInteger divident = BigInteger("92763193484361");
    BigInteger divisor = BigInteger("200000000000");
    BigInteger quotient = BigInteger::value_of(463);
    ASSERT_EQ(divident / divisor, quotient);
}

TEST(division, long_numbers_5) {
    BigInteger divident = BigInteger("92763193484361913481346");
    BigInteger divisor = BigInteger("200000000000");
    BigInteger quotient = BigInteger("463815967421");
    BigInteger tmp = divident / divisor;
    ASSERT_EQ(divident / divisor, quotient);
}

TEST(division, long_numbers_6) {
    BigInteger divident = BigInteger("92763193484361913481346");
    BigInteger divisor = BigInteger("331907983710");
    BigInteger quotient = BigInteger("279484670562");
    BigInteger tmp = divident / divisor;
    ASSERT_EQ(divident / divisor, quotient);
}

TEST(division, long_numbers_7) {
    BigInteger divident = BigInteger("92763193484361913481346");
    BigInteger divisor = BigInteger("305696327136");
    BigInteger quotient = BigInteger("303448832223");
    ASSERT_EQ(divident / divisor, quotient);
}