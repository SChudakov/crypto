//
// Created by Semen on 10/26/2018.
//

#ifndef CRYPTO_JACOBIANSYMBOL_H
#define CRYPTO_JACOBIANSYMBOL_H


#include <BigInteger.h>

class JacobianSymbol {
public:
    BigInteger jacobian_symbol(BigInteger a, BigInteger p);
};


#endif //CRYPTO_JACOBIANSYMBOL_H
