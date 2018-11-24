//
// Created by Semen on 10/21/2018.
//

#ifndef CRYPTO_GCD_H
#define CRYPTO_GCD_H


#include <BigInteger.h>

class GCD {
    BigInteger calculate_gcd(const BigInteger &a, const BigInteger &b);

public:
    BigInteger gcd(const BigInteger &a, const BigInteger &b);
};


#endif //CRYPTO_GCD_H
