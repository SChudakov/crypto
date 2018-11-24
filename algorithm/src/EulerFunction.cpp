//
// Created by Semen on 10/26/2018.
//

#include "EulerFunction.h"

BigInteger EulerFunction::eulerFunction(const BigInteger &number) {
    if (number <= 0) {
        throw invalid_argument("number should be positive");
    }

    BigInteger input = number;

    BigInteger result = BigInteger::value_of(1);
    BigInteger i = BigInteger::value_of(2);
    while (i * i <= input) {
        BigInteger p = BigInteger::value_of(1);
        while (input % i == 0) {
            input = input / i;
            p = p * i;
        }
        p = p / i;
        if (p != 0) {
            result = result * p * (i - 1);
        }
        i = i + 1;
    }
    BigInteger n = input - 1;
    if (n == 0) {
        return result;
    } else {
        return n * result;
    }
}
