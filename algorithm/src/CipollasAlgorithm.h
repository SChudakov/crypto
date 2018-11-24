//
// Created by Semen on 10/28/2018.
//

#ifndef CRYPTO_CHIPOLLASALGORITHM_H
#define CRYPTO_CHIPOLLASALGORITHM_H


#include "SolovayStrassen.h"
#include "LegendreSymbol.h"
#include "UniformRandomGenerator.h"

using namespace std;


class CipollasAlgorithm {
    static const int MAX_INT = 2147483647;

    LegendreSymbol legendreSymbol;

    BigInteger legendre(const BigInteger &a, const BigInteger &p);

    pair<BigInteger, BigInteger> multiply(const pair<BigInteger, BigInteger> &a, const pair<BigInteger,
            BigInteger> &b, const BigInteger &squared_value, const BigInteger &p);

public:
    tuple<BigInteger, BigInteger, bool> square_root(const BigInteger &n, const BigInteger &p);

};


#endif //CRYPTO_CHIPOLLASALGORITHM_H
