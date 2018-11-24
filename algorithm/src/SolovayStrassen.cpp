//
// Created by Semen on 10/26/2018.
//

#include "SolovayStrassen.h"

const BigInteger SolovayStrassen::DEFAULT_ITERATION = BigInteger::value_of(10);

bool SolovayStrassen::is_prime(const BigInteger &p) {
    return is_prime(p, DEFAULT_ITERATION);
}

bool SolovayStrassen::is_prime(const BigInteger &p, const BigInteger &iterations) {
    if (p < 2) {
        return false;
    }
    if (p == 2) {
        return true;
    }
    if (p % 2 == 0) {
        return false;
    }
    for (BigInteger i = BigInteger::value_of(0); i < iterations; ++i) {
        BigInteger a = rand() % (p - 1) + 1;
        BigInteger jacobian_symbol = jacobiSymbol.jacobian_symbol(a, p);
        BigInteger jacobian = (p + jacobian_symbol) % p;
        BigInteger mod = modulo(a, (p - 1) / 2, p);

        if (jacobian == 0 || mod != jacobian) {
            return false;
        }
    }
    return true;
}

BigInteger SolovayStrassen::modulo(const BigInteger &base, BigInteger exponent, const BigInteger &mod) {
    BigInteger x = BigInteger::value_of(1);
    BigInteger y = base;
    while (exponent > 0) {
        if (exponent % 2 == 1) {
            x = (x * y) % mod;
        }

        y = (y * y) % mod;
        exponent = exponent / 2;
    }

    return x % mod;
}

SolovayStrassen::SolovayStrassen() = default;

