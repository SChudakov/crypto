//
// Created by Semen on 11/18/2018.
//

#ifndef CRYPTO_CHINESEREMAINDERPROBLEM_H
#define CRYPTO_CHINESEREMAINDERPROBLEM_H

#include <BigInteger.h>
#include "GCD.h"


class ChineseRemainderProblem {
    GCD gcd;

    void assert_pairwise_co_prime(const vector<pair<BigInteger, BigInteger>> &modulus_remainders);

    BigInteger inverse(BigInteger a, BigInteger b);

public:
    ChineseRemainderProblem();

    BigInteger chinese_remainder_problem(vector<pair<uint64_t, uint64_t>> &modulus_remainders);

    BigInteger chinese_remainder_problem(vector<pair<BigInteger, BigInteger>> &modulus_remainders);
};


#endif //CRYPTO_CHINESEREMAINDERPROBLEM_H
