//
// Created by Semen on 11/18/2018.
//

#include "ChineseRemainderProblem.h"


ChineseRemainderProblem::ChineseRemainderProblem() = default;

BigInteger ChineseRemainderProblem::chinese_remainder_problem(vector<pair<uint64_t, uint64_t>> &modulus_remainders) {
    vector<pair<BigInteger, BigInteger>> cp;
    cp.reserve(modulus_remainders.size());
    for (auto &pair  : modulus_remainders) {
        cp.emplace_back(BigInteger::value_of(pair.first), BigInteger::value_of(pair.second));
    }
    return chinese_remainder_problem(cp);
}

BigInteger
ChineseRemainderProblem::chinese_remainder_problem(vector<pair<BigInteger, BigInteger>> &modulus_remainders) {
    assert_pairwise_co_prime(modulus_remainders);

    vector<BigInteger> modulus_values;
    vector<BigInteger> remainders_values;
    for (auto &modulus_remainder : modulus_remainders) {
        modulus_values.push_back(modulus_remainder.first);
        remainders_values.push_back(modulus_remainder.second);
    }

    BigInteger modulus_product = BigInteger::value_of(1);
    for (const auto &modulus_value : modulus_values) {
        modulus_product = modulus_product * modulus_value;
    }
    BigInteger sum = BigInteger::value_of(0);
    for (int i = 0; i < modulus_values.size(); i++) {
        BigInteger mi_coefficient = modulus_product / modulus_values[i];
        sum = sum + remainders_values[i] * inverse(mi_coefficient, modulus_values[i]) * mi_coefficient;
    }

    return sum % modulus_product;
}


void ChineseRemainderProblem::assert_pairwise_co_prime(const vector<pair<BigInteger, BigInteger>> &modulus_remainders) {
    for (int i = 0; i < modulus_remainders.size(); i++) {
        for (int j = 0; j < i; j++) {
            if (gcd.gcd(modulus_remainders[i].first, modulus_remainders[j].first) != 1) {
                throw invalid_argument(
                        modulus_remainders[i].first.to_string() + " and " + modulus_remainders[j].first.to_string() +
                        " are not co-prime");
            }
        }
    }
}

BigInteger ChineseRemainderProblem::inverse(BigInteger a, BigInteger b) {
    BigInteger zero = BigInteger::value_of(0);
    BigInteger one = BigInteger::value_of(1);

    BigInteger b0 = b;
    BigInteger t = zero;
    BigInteger q = zero;
    BigInteger x0 = zero;
    BigInteger x1 = one;
    if (b == one) {
        return one;
    }
    while (a > one) {
        q = a / b;

        t = b;
        b = a % b;
        a = t;

        t = x0;
        x0 = x1 - q * x0;
        x1 = t;
    }
    if (x1 < zero) {
        x1 = x1 + b0;
    }
    return x1;
}


