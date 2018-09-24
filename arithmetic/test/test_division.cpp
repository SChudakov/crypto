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
    vector<int> first_divident_vector;
    first_divident_vector.push_back(987654321);
    first_divident_vector.push_back(1234567);
    BigInteger divident = BigInteger(first_divident_vector, 1);
    vector<int> first_divisor_vector;
    first_divisor_vector.push_back(122333456);
    first_divisor_vector.push_back(12);
    BigInteger divisor = BigInteger(first_divisor_vector, 1);
    BigInteger quotient = BigInteger::value_of(101842);

    ASSERT_EQ(divident / divisor, quotient);
}

TEST(division, long_numbers_2) {
    vector<int> divident_vector;
    divident_vector.push_back(511627776);
    divident_vector.push_back(1099);
    BigInteger divident = BigInteger(divident_vector, 1);

    vector<int> divisor_vector;
    divisor_vector.push_back(73741824);
    divisor_vector.push_back(1);
    BigInteger divisor = BigInteger(divisor_vector, 1);

    BigInteger quotient = BigInteger::value_of(1024);

    ASSERT_EQ(divident / divisor, quotient);
}

TEST(division, long_numbers_3) {

    vector<int> divident_vector;
    divident_vector.push_back(0);
    divident_vector.push_back(1000000);
    BigInteger divident = BigInteger(divident_vector, 1);

    vector<int> divisor_vector;
    divisor_vector.push_back(0);
    divisor_vector.push_back(1);
    BigInteger divisor = BigInteger(divisor_vector, 1);

    BigInteger quotient = BigInteger::value_of(1000000);

    ASSERT_EQ(divident / divisor, quotient);
}

TEST(division, long_numbers_4) {

    vector<int> divident_vector;
    divident_vector.push_back(193484361);
    divident_vector.push_back(92763);
    BigInteger divident = BigInteger(divident_vector, 1);

    vector<int> divisor_vector;
    divisor_vector.push_back(0);
    divisor_vector.push_back(200);
    BigInteger divisor = BigInteger(divisor_vector, 1);

    BigInteger quotient = BigInteger::value_of(463);

    ASSERT_EQ(divident / divisor, quotient);
}

TEST(division, long_numbers_5) {

    vector<int> divident_vector;
    divident_vector.push_back(913481346);
    divident_vector.push_back(193484361);
    divident_vector.push_back(92763);
    BigInteger divident = BigInteger(divident_vector, 1);

    vector<int> divisor_vector;
    divisor_vector.push_back(0);
    divisor_vector.push_back(200);
    BigInteger divisor = BigInteger(divisor_vector, 1);

    vector<int> quotient_vector;
    quotient_vector.push_back(815967421);
    quotient_vector.push_back(463);
    BigInteger quotient = BigInteger(quotient_vector, 1);
    BigInteger tmp = divident / divisor;
    ASSERT_EQ(divident / divisor, quotient);
}

TEST(division, long_numbers_6) {

    vector<int> divident_vector;
    divident_vector.push_back(913481346);
    divident_vector.push_back(193484361);
    divident_vector.push_back(92763);
    BigInteger divident = BigInteger(divident_vector, 1);

    vector<int> divisor_vector;
    divisor_vector.push_back(907983710);
    divisor_vector.push_back(331);
    BigInteger divisor = BigInteger(divisor_vector, 1);

    vector<int> quotient_vector;
    quotient_vector.push_back(484670562);
    quotient_vector.push_back(279);
    BigInteger quotient = BigInteger(quotient_vector, 1);
    BigInteger tmp = divident / divisor;
    ASSERT_EQ(divident / divisor, quotient);
}

TEST(division, long_numbers_7) {

    vector<int> divident_vector;
    divident_vector.push_back(913481346);
    divident_vector.push_back(193484361);
    divident_vector.push_back(92763);
    BigInteger divident = BigInteger(divident_vector, 1);

    vector<int> divisor_vector;
    divisor_vector.push_back(696327136);
    divisor_vector.push_back(305);
    BigInteger divisor = BigInteger(divisor_vector, 1);

    vector<int> quotient_vector;
    quotient_vector.push_back(448832223);
    quotient_vector.push_back(303);
    BigInteger quotient = BigInteger(quotient_vector, 1);
    BigInteger tmp = divident / divisor;
    ASSERT_EQ(divident / divisor, quotient);
}