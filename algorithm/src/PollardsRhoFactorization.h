//
// Created by Semen on 10/20/2018.
//

#ifndef CRYPTO_POLLARDSRPOALGORITHM_H
#define CRYPTO_POLLARDSRPOALGORITHM_H

#include "GCD.h"
#include "FloydAlgorithm.h"
#include "CipollasAlgorithm.h"

using namespace std;

class PollardsRhoFactorization {
private:
    GCD gcd;
    SolovayStrassen solovayStrassen;
    function<BigInteger(const BigInteger &, const BigInteger &)> func =
            [](const BigInteger &x, const BigInteger &mod) { return (x * x + 1) % mod; };

    void factorize(const BigInteger &number, vector<BigInteger> &factors);

    BigInteger get_factor(const BigInteger &number);

public:
    PollardsRhoFactorization();

    vector<BigInteger> factorize(const BigInteger &number);
};


#endif //CRYPTO_POLLARDSRPOALGORITHM_H
