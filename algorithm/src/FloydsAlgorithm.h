//
// Created by Semen on 11/3/2018.
//

#ifndef CRYPTO_FLOYDSALGORITHM_H
#define CRYPTO_FLOYDSALGORITHM_H


#include <BigInteger.h>
#include <functional>

class FloydsAlgorithm {
public:
    BigInteger cycle_length(function<BigInteger(const BigInteger &, const BigInteger &)> func,
                            BigInteger a0, const BigInteger &mod);
};


#endif //CRYPTO_FLOYDSALGORITHM_H
