//
// Created by Semen on 10/26/2018.
//

#ifndef CRYPTO_EXTENDEDGCD_H
#define CRYPTO_EXTENDEDGCD_H


#include <BigInteger.h>

class ExtendedGCD {
    tuple<BigInteger, BigInteger, BigInteger> calculate_extended_gcd(const BigInteger &a, const BigInteger &b);
public:
    tuple<BigInteger, BigInteger, BigInteger> extended_gcd(const BigInteger &a, const BigInteger &b);
};


#endif //CRYPTO_EXTENDEDGCD_H
