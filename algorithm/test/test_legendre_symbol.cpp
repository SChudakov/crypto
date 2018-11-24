//
// Created by Semen on 10/27/2018.
//

#include <BigInteger.h>
#include <gtest/gtest.h>
#include <PollardsRhoFactorization.h>
#include <LegendreSymbol.h>


TEST(legendre_symbol, p_not_prime) {
    LegendreSymbol legendreSymbol;

    ASSERT_THROW(legendreSymbol.legendre_symbol(BigInteger::value_of(1), BigInteger::value_of(1)),
                 std::invalid_argument);
    ASSERT_THROW(legendreSymbol.legendre_symbol(BigInteger::value_of(10), BigInteger::value_of(8)),
                 std::invalid_argument);
}

TEST(legendre_symbol, legendre_symbol_1) {
    LegendreSymbol legendreSymbol;

    ASSERT_EQ(legendreSymbol.legendre_symbol(BigInteger::value_of(7), BigInteger::value_of(3)),
              BigInteger::value_of(1));
    ASSERT_EQ(legendreSymbol.legendre_symbol(BigInteger::value_of(7), BigInteger::value_of(17)),
              BigInteger::value_of(-1));
    ASSERT_EQ(legendreSymbol.legendre_symbol(BigInteger::value_of(32), BigInteger::value_of(97)),
              BigInteger::value_of(1));
    ASSERT_EQ(legendreSymbol.legendre_symbol(BigInteger::value_of(141364816849), BigInteger::value_of(252097800623)),
              BigInteger::value_of(-1));
//    ASSERT_EQ(legendreSymbol.legendre_symbol(BigInteger("34035243914635549601583369544560650254325084643201"),
//                                             BigInteger("100000000000000000000000000000000000000000000000151")),
//              BigInteger::value_of(1));
}