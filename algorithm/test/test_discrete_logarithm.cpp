//
// Created by Semen on 10/26/2018.
//

#include <BigInteger.h>
#include <gtest/gtest.h>
#include <PollardsRhoFactorization.h>
#include <BabyStepGiantStepDiscreteLogarithm.h>


TEST(discrete_logarithm, no_logarithm) {
    BabyStepGiantStepDiscreteLogarithm logarithm;

    ASSERT_EQ(logarithm.discreteLogarithm(BigInteger::value_of(7),
                                          BigInteger::value_of(3),
                                          BigInteger::value_of(8)), BigInteger::value_of(-1));

    ASSERT_EQ(logarithm.discreteLogarithm(BigInteger::value_of(4),
                                          BigInteger::value_of(3),
                                          BigInteger::value_of(7)), BigInteger::value_of(-1));
}

TEST(discrete_logarithm, simple) {
    BabyStepGiantStepDiscreteLogarithm logarithm;
    ASSERT_EQ(logarithm.discreteLogarithm(BigInteger::value_of(3),
                                          BigInteger::value_of(13),
                                          BigInteger::value_of(25)), BigInteger::value_of(17));

    ASSERT_EQ(logarithm.discreteLogarithm(BigInteger::value_of(3),
                                          BigInteger::value_of(16),
                                          BigInteger::value_of(23)), BigInteger::value_of(17));

    ASSERT_EQ(logarithm.discreteLogarithm(BigInteger::value_of(33),
                                          BigInteger::value_of(44),
                                          BigInteger::value_of(97)), BigInteger::value_of(-1));

    ASSERT_EQ(logarithm.discreteLogarithm(BigInteger::value_of(31),
                                          BigInteger::value_of(10),
                                          BigInteger::value_of(103)), BigInteger::value_of(33));
}
