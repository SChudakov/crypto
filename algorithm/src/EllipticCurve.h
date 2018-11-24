//
// Created by Semen on 11/19/2018.
//

#ifndef CRYPTO_ELIPTICCURVE_H
#define CRYPTO_ELIPTICCURVE_H


#include <BigInteger.h>

class EllipticCurve {
    BigInteger p;
    BigInteger a;
    BigInteger b;
    pair<BigInteger, BigInteger> G;
    BigInteger n;
    BigInteger h;
public:
    const BigInteger &getP() const;

    const pair<BigInteger, BigInteger> &getG() const;

    const BigInteger &getA() const;

    const BigInteger &getB() const;

    const BigInteger &getN() const;

    const BigInteger &getH() const;

public:
    EllipticCurve(const BigInteger &p, const BigInteger &a, const BigInteger &b, pair<BigInteger, BigInteger> G,
                  const BigInteger &n, const BigInteger &h);
};


#endif //CRYPTO_ELIPTICCURVE_H
