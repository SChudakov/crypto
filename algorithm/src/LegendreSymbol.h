//
// Created by Semen on 10/26/2018.
//

#ifndef CRYPTO_LEGENDRESYMBOL_H
#define CRYPTO_LEGENDRESYMBOL_H


#include <BigInteger.h>
#include "SolovayStrassen.h"

class LegendreSymbol {
    static const BigInteger MINUS_ONE;

    SolovayStrassen solovayStrassen;

    BigInteger calculate_legendre_symbol(const BigInteger &a, const BigInteger &p);

public:
    LegendreSymbol();

    BigInteger legendre_symbol(const BigInteger &a, const BigInteger &p);
};


#endif //CRYPTO_LEGENDRESYMBOL_H
