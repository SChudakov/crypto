//
// Created by Semen on 10/26/2018.
//

#ifndef CRYPTO_POLLARDSRHODISCRETELOGARITHM_H
#define CRYPTO_POLLARDSRHODISCRETELOGARITHM_H


#include <BigInteger.h>
#include "EulerFunction.h"
#include "ExtendedGCD.h"

class BabyStepGiantStepDiscreteLogarithm {
public:
    BabyStepGiantStepDiscreteLogarithm();

    BigInteger discreteLogarithm(const BigInteger &g, const BigInteger &h, const BigInteger &mod);
};


#endif //CRYPTO_POLLARDSRHODISCRETELOGARITHM_H
