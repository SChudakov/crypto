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

    vector<int> number;
    int signum;

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
    digit_taken_digits(const vector<int> &divident, const vector<int> &divisor, int divident_decade,
                       int divisor_decades, bool ctt);


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


    static void assert_legal_power(const BigInteger &number, const BigInteger &power);

    static void assert_legal_mod(const BigInteger &mod);


    static void normalize(vector<int> &number);

    static pair<int, int> quotient_and_remainder_by_base(long long number);

    static pair<int, int> numbers_and_decade(int decade_position);

    static string to_string(int number);

    static vector<int> to_vector(const string &s);

    BigInteger negate() const;

public:
    BigInteger();

    explicit BigInteger(const string &s);


    friend BigInteger operator+(const BigInteger &left, const BigInteger &right);

    friend BigInteger operator+(const BigInteger &left, long long right);

    friend BigInteger operator+(long long left, const BigInteger &right);


    friend BigInteger operator-(const BigInteger &a);


    friend BigInteger operator-(const BigInteger &left, const BigInteger &right);

    friend BigInteger operator-(const BigInteger &left, long long right);

    friend BigInteger operator-(long long left, const BigInteger &right);


    friend BigInteger operator*(const BigInteger &left, const BigInteger &right);

    friend BigInteger operator*(const BigInteger &left, long long right);

    friend BigInteger operator*(long long left, const BigInteger &right);


    friend BigInteger operator/(const BigInteger &left, const BigInteger &right);

    friend BigInteger operator/(const BigInteger &left, long long right);

    friend BigInteger operator/(long long left, const BigInteger &right);


    friend BigInteger operator%(const BigInteger &left, const BigInteger &right);

    friend BigInteger operator%(const BigInteger &left, long long right);

    friend BigInteger operator%(long long left, const BigInteger &right);


    friend BigInteger operator++(BigInteger &a);

    BigInteger &operator=(const BigInteger &other);


    friend bool operator<(const BigInteger &left, const BigInteger &right);

    friend bool operator<(const BigInteger &left, long long right);

    friend bool operator<(long long left, const BigInteger &right);


    friend bool operator<=(const BigInteger &left, const BigInteger &right);

    friend bool operator<=(const BigInteger &left, long long right);

    friend bool operator<=(long long left, const BigInteger &right);


    friend bool operator>(const BigInteger &left, const BigInteger &right);

    friend bool operator>(const BigInteger &left, long long right);

    friend bool operator>(long long left, const BigInteger &right);


    friend bool operator>=(const BigInteger &left, const BigInteger &right);

    friend bool operator>=(const BigInteger &left, long long right);

    friend bool operator>=(long long left, const BigInteger &right);


    friend bool operator==(const BigInteger &left, const BigInteger &right);

    friend bool operator==(const BigInteger &left, long long right);

    friend bool operator==(long long left, const BigInteger &right);


    friend bool operator!=(const BigInteger &left, const BigInteger &right);

    friend bool operator!=(const BigInteger &left, long long right);

    friend bool operator!=(long long left, const BigInteger &right);


    friend ostream &operator<<(ostream &os, const BigInteger &dt);


    BigInteger to_power(const BigInteger &power) const;

    BigInteger to_power(unsigned long long power) const;

    BigInteger to_power(const BigInteger &power, const BigInteger &mod) const;

    BigInteger to_power(unsigned long long power, const BigInteger &mod) const;

    BigInteger square_root() const;


    BigInteger modulo_addition(const BigInteger &other, const BigInteger &modulo) const;

    BigInteger modulo_addition(const BigInteger &other, long long modulo) const;

    BigInteger modulo_addition(long long other, const BigInteger &modulo) const;

    BigInteger modulo_subtraction(const BigInteger &other, const BigInteger &modulo) const;

    BigInteger modulo_subtraction(long long other, const BigInteger &modulo) const;

    BigInteger modulo_subtraction(const BigInteger &other, long long modulo) const;

    BigInteger modulo_multiplication(const BigInteger &other, const BigInteger &modulo) const;

    BigInteger modulo_multiplication(long long other, const BigInteger &modulo) const;

    BigInteger modulo_multiplication(const BigInteger &other, long long modulo) const;

    BigInteger modulo_division(const BigInteger &other, const BigInteger &modulo) const;

    BigInteger modulo_division(long long other, const BigInteger &modulo) const;

    BigInteger modulo_division(const BigInteger &other, long long modulo) const;


    BigInteger abs() const;

    static BigInteger value_of(long long number);

    string to_string() const;

    static BigInteger random(const BigInteger &mod);

    int operator[](int idx)const ;

    uint64_t size();
};


#endif //CRYPTO_BIGINTEGER_H
