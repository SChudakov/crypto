//
// Created by Semen on 10/26/2018.
//

#ifndef CRYPTO_SOLOVAYSTRASSEN_H
#define CRYPTO_SOLOVAYSTRASSEN_H


#include <BigInteger.h>
#include "JacobianSymbol.h"

class SolovayStrassen {
    static const BigInteger DEFAULT_ITERATION;

    JacobianSymbol jacobiSymbol;

    BigInteger modulo(const BigInteger &base, BigInteger exponent, const BigInteger &mod);

public:
    bool is_prime(const BigInteger &p);

    bool is_prime(const BigInteger &p, const BigInteger &iterations);

    SolovayStrassen();
};


#endif //CRYPTO_SOLOVAYSTRASSEN_H
