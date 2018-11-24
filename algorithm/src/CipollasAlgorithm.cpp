//
// Created by Semen on 10/28/2018.
//

#include "CipollasAlgorithm.h"

tuple<BigInteger, BigInteger, bool> CipollasAlgorithm::square_root(const BigInteger &n, const BigInteger &p) {
    BigInteger zero = BigInteger::value_of(0);
    BigInteger one = BigInteger::value_of(1);
    if (legendre(n, p) != 1) {
        return {zero, zero, false};
    }

    BigInteger a = zero;
    BigInteger squared_value = zero;
    while (true) {
        squared_value = (a * a + p - n) % p;
        if (legendre(squared_value, p) == p - 1) {
            break;
        }
        ++a;
    }
    pair<BigInteger, BigInteger> r = {one, zero};
    pair<BigInteger, BigInteger> s = {a, one};

    BigInteger nn = ((p + 1) / 2) % p;
    while (nn > 0) {
        if (nn % 2 == 1) {
            r = multiply(r, s, squared_value, p);
        }
        s = multiply(s, s, squared_value, p);
        nn = nn / 2;
    }


    if (r.second != 0) {
        return {zero, zero, false};
    }

    if ((r.first * r.first) % p != n) {
        return {zero, zero, false};
    }
    return {r.first, p - r.first, true};
}

BigInteger CipollasAlgorithm::legendre(const BigInteger &a, const BigInteger &p) {
    BigInteger legendre_symbol = legendreSymbol.legendre_symbol(a, p);
    return legendre_symbol == -1 ? p - 1 : legendre_symbol;
}


pair<BigInteger, BigInteger> CipollasAlgorithm::multiply(const pair<BigInteger, BigInteger> &a,
                                                         const pair<BigInteger, BigInteger> &b,
                                                         const BigInteger &squared_value, const BigInteger &p) {
    return {
            (a.first * b.first + a.second * b.second * squared_value) % p,
            (a.first * b.second + a.second * b.first) % p
    };
}