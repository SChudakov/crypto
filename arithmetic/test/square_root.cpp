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
    vector<int> number_vector;
    number_vector.push_back(0);
    number_vector.push_back(1);
    BigInteger number = BigInteger(number_vector, 1);
    BigInteger square_root = BigInteger::value_of(31622);

    ASSERT_EQ(number.square_root(), square_root);
}

TEST(square_root, long_numbers_2) {
    vector<int> number_vector;
    number_vector.push_back(0);
    number_vector.push_back(10);
    BigInteger number = BigInteger(number_vector, 1);
    BigInteger square_root = BigInteger::value_of(100000);

    ASSERT_EQ(number.square_root(), square_root);
}

TEST(square_root, long_numbers_3) {
    vector<int> number_vector;
    number_vector.push_back(913481346);
    number_vector.push_back(193484361);
    number_vector.push_back(92763);
    BigInteger number = BigInteger(number_vector, 1);

    vector<int> square_root_vector;
    square_root_vector.push_back(570506589);
    square_root_vector.push_back(304);
    BigInteger square_root = BigInteger(square_root_vector, 1);

    ASSERT_EQ(number.square_root(), square_root);
}

TEST(square_root, long_numbers_4) {
    vector<int> number_vector;
    number_vector.push_back(658716457);
    number_vector.push_back(847568147);
    number_vector.push_back(1);
    BigInteger number = BigInteger(number_vector, 1);

    vector<int> square_root_vector;
    square_root_vector.push_back(359252790);
    square_root_vector.push_back(1);
    BigInteger square_root = BigInteger(square_root_vector, 1);

    ASSERT_EQ(number.square_root(), square_root);
}

TEST(square_root, long_numbers_5) {
    vector<int> number_vector;
    number_vector.push_back(327506827);
    number_vector.push_back(756720867);
    number_vector.push_back(992586027);
    number_vector.push_back(345720986);
    number_vector.push_back(876527952);
    number_vector.push_back(6572465);
    BigInteger number = BigInteger(number_vector, 1);

    vector<int> square_root_vector;
    square_root_vector.push_back(829693569);
    square_root_vector.push_back(120459211);
    square_root_vector.push_back(81070746);
    BigInteger square_root = BigInteger(square_root_vector, 1);

    ASSERT_EQ(number.square_root(), square_root);
}

TEST(square_root, long_numbers_6) {
    vector<int> number_vector;
    number_vector.push_back(478165165);
    number_vector.push_back(581658716);
    number_vector.push_back(561874187);
    number_vector.push_back(17);
    BigInteger number = BigInteger(number_vector, 1);

    vector<int> square_root_vector;
    square_root_vector.push_back(221649898);
    square_root_vector.push_back(132521);
    BigInteger square_root = BigInteger(square_root_vector, 1);

    ASSERT_EQ(number.square_root(), square_root);
}
