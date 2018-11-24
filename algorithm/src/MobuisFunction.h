//
// Created by Semen on 10/26/2018.
//

#ifndef CRYPTO_MOBUISFUNCTION_H
#define CRYPTO_MOBUISFUNCTION_H


#include <BigInteger.h>
#include "SolovayStrassen.h"

class MobuisFunction {
private:
    SolovayStrassen solovayStrassen;
public:
    int mobuidFunction(const BigInteger &n);
};


#endif //CRYPTO_MOBUISFUNCTION_H
