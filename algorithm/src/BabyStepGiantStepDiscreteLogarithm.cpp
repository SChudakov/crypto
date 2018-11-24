//
// Created by Semen on 10/26/2018.
//

#include <map>
#include "BabyStepGiantStepDiscreteLogarithm.h"

BigInteger
BabyStepGiantStepDiscreteLogarithm::discreteLogarithm(const BigInteger &a, const BigInteger &b, const BigInteger &m) {
    if (a >= m) {
        throw invalid_argument("a should be less than modulo");
    }
    if (b >= m) {
        throw invalid_argument("b should be less than modulo");
    }


    BigInteger n = m.square_root() + 1;

    BigInteger an = BigInteger::value_of(1);
    for (int i = 0; i < n; ++i) {
        an = (an * a) % m;
    }

    map<BigInteger, BigInteger> values;
    BigInteger cur = an;
    for (BigInteger i = BigInteger::value_of(1); i <= n; ++i) {
        if (values.find(cur) == values.end()) {
            values[cur] = i;
        }
        cur = (cur * an) % m;
    }

    cur = b;
    for (int i = 0; i <= n; ++i) {
        if (values.find(cur) != values.end()) {
            BigInteger ans = values[cur] * n - i;
            if (ans < m) {
                return ans;
            }
        }
        cur = (cur * a) % m;
    }
    return BigInteger::value_of(-1);
}

BabyStepGiantStepDiscreteLogarithm::BabyStepGiantStepDiscreteLogarithm() = default;