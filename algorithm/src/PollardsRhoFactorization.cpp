//
// Created by Semen on 10/20/2018.
//

#include "PollardsRhoFactorization.h"

PollardsRhoFactorization::PollardsRhoFactorization() {
    gcd = GCD();
}

vector<BigInteger> PollardsRhoFactorization::factorize(const BigInteger &number) {
    if (number <= 0) {
        throw invalid_argument("number should be positive");
    }
    if (number == 1) {
        return {};
    }
    if (number == 2) {
        return {};
    }
    if (number == 3) {
        return {};
    }
    vector<BigInteger> factors;
    factorize(number, factors);
    sort(factors.begin(), factors.end());
    return factors;
}

void PollardsRhoFactorization::factorize(const BigInteger &number, vector<BigInteger> &factors) {
    if (number == 1) {
        return;
    }
    if (solovayStrassen.is_prime(number)) {
        factors.push_back(number);
        return;
    }
    BigInteger factor = get_factor(number);
    BigInteger quotient = number / factor;
//    cout << "factor: " << factor << endl;
//    cout << "quotient: " << quotient << endl;
    cout << endl;
    if (factor != number) { // number is prime
        factorize(quotient, factors);
        factorize(factor, factors);
    }
}

BigInteger PollardsRhoFactorization::get_factor(const BigInteger &number) {
    if (number == 4) {
        return BigInteger::value_of(2);
    }
    BigInteger number_sqrt = number.square_root();

    BigInteger one = BigInteger::value_of(1);
    BigInteger two = BigInteger::value_of(2);

    BigInteger y = BigInteger::value_of(1);

    BigInteger number_minus_one = number - 1;
    for (BigInteger a0 = two; a0 < number_minus_one; ++a0) {
        BigInteger stage = BigInteger::value_of(2);
        BigInteger x = a0;
        BigInteger i = one;
//        cout << "a0: " << a0 << endl;
        for (; i < number_sqrt && x != y && gcd.gcd(number, (x - y).abs()) == one; ++i) {
            if (i == stage) {
                y = x;
//                cout << "stage: " << stage << endl;
                stage = stage * two;
            }
            x = (x * x + one) % number;
        }
        if (x != y && gcd.gcd(number, (x - y).abs()) != one) {
            return gcd.gcd(number, (x - y).abs());
        }
    }
    throw runtime_error("no factor found");
}