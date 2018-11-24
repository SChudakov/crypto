//
// Created by Semen on 10/27/2018.
//
#include <BigInteger.h>
#include <gtest/gtest.h>
#include <PollardsRhoFactorization.h>
#include <JacobianSymbol.h>


TEST(jacobian_symbol, even_p) {
    JacobianSymbol jacobianSymbol;

    BigInteger a = BigInteger::value_of(2);
    BigInteger p = BigInteger::value_of(4);

    ASSERT_THROW(jacobianSymbol.jacobian_symbol(a, p), std::invalid_argument);
    ASSERT_THROW(jacobianSymbol.jacobian_symbol(p, a), std::invalid_argument);
}

TEST(jacobian_symbol, jacobian_symbol_1) {
    JacobianSymbol jacobianSymbol;

    BigInteger a = BigInteger::value_of(2);
    BigInteger p = BigInteger::value_of(15);

    ASSERT_EQ(jacobianSymbol.jacobian_symbol(a, p), BigInteger::value_of(1));
}

TEST(jacobian_symbol, jacobian_symbol_2) {
    JacobianSymbol jacobianSymbol;

    BigInteger a = BigInteger::value_of(7);
    BigInteger p = BigInteger::value_of(15);

    ASSERT_EQ(jacobianSymbol.jacobian_symbol(a, p), BigInteger::value_of(-1));
}

TEST(jacobian_symbol, jacobian_symbol_3) {
    JacobianSymbol jacobianSymbol;

    BigInteger a = BigInteger::value_of(14);
    BigInteger p = BigInteger::value_of(15);

    ASSERT_EQ(jacobianSymbol.jacobian_symbol(a, p), BigInteger::value_of(-1));
}

TEST(jacobian_symbol, jacobian_symbol_4) {
    JacobianSymbol jacobianSymbol;

    BigInteger a = BigInteger::value_of(4 * 7);
    BigInteger p = BigInteger::value_of(15);

    ASSERT_EQ(jacobianSymbol.jacobian_symbol(a, p), BigInteger::value_of(-1));
}

TEST(jacobian_symbol, jacobian_symbol_5) {
    JacobianSymbol jacobianSymbol;

    BigInteger a = BigInteger::value_of(1236);
    BigInteger p = BigInteger::value_of(20003);

    ASSERT_EQ(jacobianSymbol.jacobian_symbol(a, p), BigInteger::value_of(1));
}
