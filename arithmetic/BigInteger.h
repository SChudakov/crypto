//
// Created by Semen Chudakov on 9/6/2018.
//

#ifndef CRYPTO_BIGINTEGER_H
#define CRYPTO_BIGINTEGER_H


class BigInteger {
public:
    BigInteger &operator+(const BigInteger &other) const;

    BigInteger &operator-(const BigInteger &other) const;

    BigInteger &operator*(const BigInteger &other) const;

    BigInteger &operator/(const BigInteger &other) const;

    BigInteger &operator%(const BigInteger &other) const;

    BigInteger &to_power(int power);


    friend bool operator<(const BigInteger &left, const BigInteger &right);

    friend bool operator>(const BigInteger &left, const BigInteger &right);

    friend bool operator==(const BigInteger &left, const BigInteger &right);


    BigInteger &modulo_addition(const BigInteger &other) const;

    BigInteger &modulo_subtractions(const BigInteger &other) const;

    BigInteger &modulo_multiplication(const BigInteger &other) const;

    BigInteger &modulo_division(const BigInteger &other) const;

    BigInteger &modulo_remainder(const BigInteger &other) const;

    BigInteger &modulo_to_power(const BigInteger &other) const;

    BigInteger &root_quotient(const BigInteger &other) const;
};


#endif //CRYPTO_BIGINTEGER_H
