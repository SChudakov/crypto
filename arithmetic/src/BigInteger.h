//
// Created by Semen Chudakov on 9/6/2018.
//

#ifndef CRYPTO_BIGINTEGER_H
#define CRYPTO_BIGINTEGER_H

#include <vector>
#include <algorithm>
#include <stdlib.h>
#include <iostream>
#include <stdexcept>
#include <tuple>
#include <cmath>
#include <string>
#include <sstream>


using namespace std;


class BigInteger {
private:
    static const int BASE = 1000 * 1000 * 1000;
    static const BigInteger ZERO;
    static const BigInteger ONE;

    vector<int> number;
    int signum;

    BigInteger();

    BigInteger(const vector<int> &number, int signum);

    static int compare(const vector<int> &first, const vector<int> &second);


    static vector<int> add(const vector<int> &first, const vector<int> &second);

    static vector<int> subtract(const vector<int> &first, const vector<int> &second);

    static void mutating_subtract_with_no_normalization(vector<int> &first, const vector<int> &second);


    static vector<int> multiply(const vector<int> &first, const vector<int> &second);


    static pair<vector<int>, vector<int>> quotient_and_remainder(const vector<int> &first, const vector<int> &second);

    static pair<vector<int>, vector<int>> short_division(const vector<int> &divident, int divisor);

    static pair<vector<int>, vector<int>> long_division(const vector<int> &divident, const vector<int> &divisor);


    static tuple<int, int, vector<int>>
    digit_taken_digits_multiplied(const vector<int> &first, const vector<int> &second, int divident_decade_pointer,
                                  int divisor_decades, bool ctt);

    static pair<int, int>
    digit_taken_digits(const vector<int> &divident, const vector<int> &divisor, const int divident_decade,
                       const int divisor_decades, const bool ctt);


    static vector<int> vector_with_one_in_decade(int decade_position);

    static int power_of_ten(int power);

    static int decade_value(vector<int> number, int decade_position);

    static int decade_value(int number, int decade_position);

    static int non_zero_decades(int number);

    static int non_zero_decades(const vector<int> &number);


    static vector<int> short_square_root(vector<int> number);

    static vector<int> long_square_root(vector<int> number);

    static vector<int> square_root_initial_approximation(vector<int> number);

    static vector<int>
    square_root_next_approximation(const vector<int> &number, const vector<int> &approximation, vector<int> two);


    static void assert_pairwise_co_prime(const vector<pair<int, int>> &modulus_remainders);

    static int gcd(int a, int b);


    static BigInteger inverse(BigInteger a, BigInteger b);


    static void normalize(vector<int> &number);

    static pair<int, int> quotient_and_remainder_by_base(long long number);

    static pair<int, int> numbers_and_decade(int decade_position);

    static string to_string(int number);

    static vector<int> to_vector(const string &s);

public:
    explicit BigInteger(const string &s);


    friend BigInteger operator+(const BigInteger &first, const BigInteger &second);

    friend BigInteger operator-(const BigInteger &first, const BigInteger &second);

    friend BigInteger operator*(const BigInteger &first, const BigInteger &second);

    friend BigInteger operator/(const BigInteger &first, const BigInteger &second);

    friend BigInteger operator%(const BigInteger &first, const BigInteger &second);


    friend bool operator<(const BigInteger &left, const BigInteger &right);

    friend bool operator>(const BigInteger &left, const BigInteger &right);

    friend bool operator==(const BigInteger &left, const BigInteger &right);


    friend ostream &operator<<(ostream &os, const BigInteger &dt);


    BigInteger to_power(unsigned int power) const;

    BigInteger square_root() const;


    BigInteger modulo_addition(const BigInteger &other, const BigInteger &modulo) const;

    BigInteger modulo_subtractions(const BigInteger &other, const BigInteger &modulo) const;

    BigInteger modulo_multiplication(const BigInteger &other, const BigInteger &modulo) const;

    BigInteger modulo_division(const BigInteger &other, const BigInteger &modulo) const;

    BigInteger modulo_remainder(const BigInteger &other, const BigInteger &modulo) const;

    BigInteger modulo_to_power(unsigned int power, const BigInteger &modulo) const;

    BigInteger root_quotient(const BigInteger &modulo) const;


    BigInteger negate() const;

    static BigInteger value_of(long long number);

    static BigInteger chinese_remainder_problem(vector<pair<int, int>> &modulus_remainders);
};


#endif //CRYPTO_BIGINTEGER_H
