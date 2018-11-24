//
// Created by Semen on 10/26/2018.
//

#include "ExtendedGCD.h"


tuple<BigInteger, BigInteger, BigInteger> ExtendedGCD::extended_gcd(const BigInteger &a, const BigInteger &b) {
    if (a < 0 || b < 0) {
        throw std::invalid_argument("a and b must be non-negative");
    }
    return calculate_extended_gcd(a, b);
}
/*
 * <d,x,y>
 * d = GCD(a,b)
 */
tuple<BigInteger, BigInteger, BigInteger> ExtendedGCD::calculate_extended_gcd(const BigInteger &a, const BigInteger &b) {
    if (b == 0) {
        return {a, BigInteger::value_of(1), BigInteger::value_of(0)};
    } else {
        tuple<BigInteger, BigInteger, BigInteger> gcd = extended_gcd(b, a % b);
        return {get<0>(gcd), get<2>(gcd), get<1>(gcd) - (a / b) * get<2>(gcd)};
    }
}
