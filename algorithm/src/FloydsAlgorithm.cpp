//
// Created by Semen on 11/3/2018.
//

#include "FloydsAlgorithm.h"

BigInteger FloydsAlgorithm::cycle_length(function<BigInteger(const BigInteger &, const BigInteger &)> func, BigInteger a0,
                                         const BigInteger &mod) {
    BigInteger a = a0;
    BigInteger b = func(a0, mod);
    while (a != b) {
        a = func(a, mod);
        b = func(func(b, mod), mod);
    }
    b = func(a, mod);
    BigInteger r = BigInteger::value_of(1);
    while (a != b) {
        b = func(b, mod);
        ++r;
    }
    return r;
}
