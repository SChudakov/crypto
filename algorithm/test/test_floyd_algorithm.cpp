//
// Created by Semen on 11/3/2018.
//

#include <gtest/gtest.h>
#include <BigInteger.h>
#include <FloydAlgorithm.h>
#include <functional>

TEST(floyd, floyd_1) {
    FloydsAlgorithm floydsAlgorithm;

    function<BigInteger(const BigInteger &, const BigInteger &)> function =
            [](const BigInteger &x, const BigInteger &mod) { return (x * x + 1) % mod; };
    BigInteger a0 = BigInteger::value_of(2);
    BigInteger mod = BigInteger::value_of(10);

    ASSERT_EQ(floydsAlgorithm.cycle_length(function, a0, mod), BigInteger::value_of(6));
}