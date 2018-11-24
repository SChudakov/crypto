//
// Created by Semen on 10/21/2018.
//

#include "GCD.h"

BigInteger GCD::calculate_gcd(const BigInteger &a, const BigInteger &b) {
    return b == 0 ? a : calculate_gcd(b, a % b);
}

BigInteger GCD::gcd(const BigInteger &a, const BigInteger &b) {
    if (a < 0 || b < 0) {
        cout << a << " " << b << endl;
        throw std::invalid_argument("a and b should be non-negative");
    }
    return calculate_gcd(a, b);
}
