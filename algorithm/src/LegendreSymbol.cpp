//
// Created by Semen on 10/26/2018.
//

#include "LegendreSymbol.h"

const BigInteger LegendreSymbol::MINUS_ONE = BigInteger::value_of(-1);

BigInteger LegendreSymbol::legendre_symbol(const BigInteger &a, const BigInteger &p) {
    if (p == 2 || !solovayStrassen.is_prime(p)) {
        throw std::invalid_argument("p greater than 2 and prime");
    }
    return calculate_legendre_symbol(a, p);
}

BigInteger LegendreSymbol::calculate_legendre_symbol(const BigInteger &a, const BigInteger &p) {
    if (a == 1) {
        return BigInteger::value_of(1);
    }
    if (a % 2 == 0) {
        return calculate_legendre_symbol(a / 2, p) * LegendreSymbol::MINUS_ONE.to_power((p * p - 1) / 8);
    }
    if ((a % 2 == 1) && (a != 1)) {
        return calculate_legendre_symbol(p % a, a) * LegendreSymbol::MINUS_ONE.to_power((a - 1) * (p - 1) / 4);
    }
    return BigInteger::value_of(0);
}

LegendreSymbol::LegendreSymbol() = default;
