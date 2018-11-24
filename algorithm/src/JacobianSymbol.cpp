//
// Created by Semen on 10/26/2018.
//

#include "JacobianSymbol.h"

BigInteger JacobianSymbol::jacobian_symbol(BigInteger a, BigInteger p) {
    if (p % 2 == 0) {
        throw std::invalid_argument("p should be odd");
    }
    if (a == 0) {
        return BigInteger::value_of(0);
    }
    // (0/n) = 0

    BigInteger ans = BigInteger::value_of(1);
    if (a < 0) {
        a = -a; // (a/n) = (-a/n)*(-1/n)
        if (p % 4 == 3) {
            ans = -ans; // (-1/n) = -1 if n = 3 (mod 4)
        }
    }

    if (a == 1) {
        return ans;// (1/n) = 1
    }

    while (a != 0) {
        if (a < 0) {
            a = -a;// (a/n) = (-a/n)*(-1/n)
            if (p % 4 == 3) {
                ans = -ans;// (-1/n) = -1 if n = 3 (mod 4)
            }
        }

        while (a % 2 == 0) {
            a = a / 2;
            if (p % 8 == 3 || p % 8 == 5) {
                ans = -ans;
            }
        }

        swap(a, p);

        if (a % 4 == 3 && p % 4 == 3) {
            ans = -ans;
        }
        a = a % p;

        if (a > p / 2) {
            a = a - p;
        }
    }

    if (p == 1) {
        return ans;
    }
    return BigInteger::value_of(0);
}
