//
// Created by Semen on 9/20/2018.
//
#include "gtest/gtest.h"
#include "BigInteger.h"

TEST(modulo, zero_one_minus_one) {
    BigInteger one = BigInteger::value_of(1);
    BigInteger zero = BigInteger::value_of(0);

    BigInteger ten = BigInteger::value_of(10);
    BigInteger minus_ten = BigInteger::value_of(-10);
    BigInteger expected = minus_ten % one;
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
    vector<int> first_divident_vector;
    first_divident_vector.push_back(987654321);
    first_divident_vector.push_back(1234567);
    BigInteger divident = BigInteger(first_divident_vector, 1);
    vector<int> first_divisor_vector;
    first_divisor_vector.push_back(122333456);
    first_divisor_vector.push_back(12);
    BigInteger modulo_base = BigInteger(first_divisor_vector, 1);
    BigInteger modulo = BigInteger::value_of(5303828369);

    ASSERT_EQ(divident % modulo_base, modulo);


}

TEST(modulo, long_numbers_2) {
    vector<int> divident_vector;
    divident_vector.push_back(511627776);
        divident_vector.push_back(1099);
    BigInteger divident = BigInteger(divident_vector, 1);

    vector<int> divisor_vector;
    divisor_vector.push_back(73741824);
    divisor_vector.push_back(1);
    BigInteger modulo_base = BigInteger(divisor_vector, 1);

    BigInteger modulo = BigInteger::value_of(0);

    ASSERT_EQ(divident % modulo_base, modulo);
}

TEST(modulo, long_numbers_3) {

    vector<int> divident_vector;
    divident_vector.push_back(0);
    divident_vector.push_back(1000000);
    BigInteger divident = BigInteger(divident_vector, 1);

    vector<int> divisor_vector;
    divisor_vector.push_back(0);
    divisor_vector.push_back(1);
    BigInteger modulo_base = BigInteger(divisor_vector, 1);

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
