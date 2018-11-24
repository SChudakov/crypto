//
// Created by Semen on 10/27/2018.
//
#include <BigInteger.h>
#include <gtest/gtest.h>
#include <PollardsRhoFactorization.h>
#include <MobuisFunction.h>


TEST(mobuis_function, negative_n) {
    MobuisFunction mobuisFunction;

    ASSERT_THROW(mobuisFunction.mobuidFunction(BigInteger::value_of(0)), std::invalid_argument);
    ASSERT_THROW(mobuisFunction.mobuidFunction(BigInteger::value_of(-1)), std::invalid_argument);
}


TEST(mobuis_function, mobuis_function_1) {
    MobuisFunction mobuisFunction;

    ASSERT_EQ(mobuisFunction.mobuidFunction(BigInteger::value_of(6)), BigInteger::value_of(1));
    ASSERT_EQ(mobuisFunction.mobuidFunction(BigInteger::value_of(49)), BigInteger::value_of(0));
    ASSERT_EQ(mobuisFunction.mobuidFunction(BigInteger::value_of(3)), BigInteger::value_of(-1));
    ASSERT_EQ(mobuisFunction.mobuidFunction(BigInteger::value_of(78)), BigInteger::value_of(-1));
}