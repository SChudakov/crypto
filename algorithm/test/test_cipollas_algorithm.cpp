//
// Created by Semen on 10/28/2018.
//
#include <gtest/gtest.h>
#include <BigInteger.h>
#include <CipollasAlgorithm.h>
#include <tuple>

using namespace std;


TEST(euler_function, cipolla_1) {
    CipollasAlgorithm cipollasAlgorithm;

    tuple<BigInteger, BigInteger, bool> t1 = {BigInteger::value_of(6), BigInteger::value_of(7), true};
    tuple<BigInteger, BigInteger, bool> t2 = {BigInteger::value_of(37), BigInteger::value_of(64), true};
    tuple<BigInteger, BigInteger, bool> t3 = {BigInteger::value_of(9872), BigInteger::value_of(135), true};
    tuple<BigInteger, BigInteger, bool> t4 = {BigInteger::value_of(0), BigInteger::value_of(0), false};
    tuple<BigInteger, BigInteger, bool> t5 = {BigInteger::value_of(855842), BigInteger::value_of(144161), true};
    tuple<BigInteger, BigInteger, bool> t6 = {BigInteger::value_of(475131702), BigInteger::value_of(524868305), true};
    tuple<BigInteger, BigInteger, bool> t7 = {BigInteger::value_of(791399408049), BigInteger::value_of(208600591990),
                                              true};

    ASSERT_EQ(cipollasAlgorithm.square_root(BigInteger::value_of(10), BigInteger::value_of(13)), t1);
    ASSERT_EQ(cipollasAlgorithm.square_root(BigInteger::value_of(56), BigInteger::value_of(101)), t2);
    ASSERT_EQ(cipollasAlgorithm.square_root(BigInteger::value_of(8218), BigInteger::value_of(10007)), t3);
    ASSERT_EQ(cipollasAlgorithm.square_root(BigInteger::value_of(8219), BigInteger::value_of(10007)), t4);
    ASSERT_EQ(cipollasAlgorithm.square_root(BigInteger::value_of(331575), BigInteger::value_of(1000003)), t5);
    ASSERT_EQ(cipollasAlgorithm.square_root(BigInteger("665165880"), BigInteger("1000000007")), t6);
    ASSERT_EQ(cipollasAlgorithm.square_root(BigInteger("881398088036"), BigInteger("1000000000039")), t7);
}


