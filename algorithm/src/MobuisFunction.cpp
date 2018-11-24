//
// Created by Semen on 10/26/2018.
//

#include "MobuisFunction.h"

int MobuisFunction::mobuidFunction(const BigInteger &n) {
    if (n < 1) {
        throw std::invalid_argument("n should be positive");
    }

    if (n == 1) {
        return 1;
    }

    BigInteger p = BigInteger::value_of(0);
    for (BigInteger i = BigInteger::value_of(1); i <= n; i = i + 1) {
        if (n % i == 0 && solovayStrassen.is_prime(i)) {
            if (n % (i * i) == 0) {
                return 0;

            } else {
                p = p + 1;
            }
        }
    }

    return (p % 2 != 0) ? -1 : 1;
}
