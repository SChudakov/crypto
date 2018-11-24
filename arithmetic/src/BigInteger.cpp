//
// Created by Semen on 9/6/2018.
//

#include "BigInteger.h"

const BigInteger BigInteger::ZERO = BigInteger();


BigInteger::BigInteger() {
    this->number = vector<int>();
    this->number.push_back(0);
    this->signum = 0;
}

BigInteger::BigInteger(const vector<int> &number, int signum) : number(number), signum(signum) {}

BigInteger::BigInteger(const string &s) {
    vector<int> parsed_number;
    int parsed_signum = 1;
    if (s[0] == '-') {
        parsed_number = to_vector(s.substr(1));
        parsed_signum = -1;
    } else {
        parsed_number = to_vector(s);
        signum = 1;
        if (parsed_number.size() == 1 && parsed_number[0] == 0) {
            signum = 0;
        }
    }
    number = parsed_number;
    signum = parsed_signum;
}

vector<int> BigInteger::to_vector(const string &s) {
    vector<int> result;
    int j = s.size();
    while (j > 0) {
        int i = j - 9 >= 0 ? j - 9 : 0;
        result.push_back(stoi(s.substr((unsigned int) (i), (unsigned int) (j - i))));
        j = i;
    }
    return result;
}


BigInteger operator++(BigInteger &a) {
    return a = a + 1;
}


BigInteger operator+(const BigInteger &left, const BigInteger &right) {
    if (left.signum == 0) {
        return right;
    }
    if (right.signum == 0) {
        return left;
    }
    if (left.signum == right.signum) {
        return BigInteger(BigInteger::add(left.number, right.number), left.signum);
    }

    int compared = BigInteger::compare(left.number, right.number);
    if (compared == 0) {
        return BigInteger::ZERO;
    }
    vector<int> result_number;
    int result_signum = 0;
    if (compared > 0) {
        result_number = BigInteger::subtract(left.number, right.number);
        result_signum = left.signum;
    } else {
        result_number = BigInteger::subtract(right.number, left.number);
        result_signum = right.signum;
    }
    return BigInteger(result_number, result_signum);
}

BigInteger operator+(const BigInteger &left, long long right) {
    return left + BigInteger::value_of(right);
}

BigInteger operator+(long long left, const BigInteger &right) {
    return right + left;
}


BigInteger operator-(const BigInteger &a) {
    return a.negate();
}


BigInteger operator-(const BigInteger &left, const BigInteger &right) {
    if (left.signum == 0) {
        return right.negate();
    }
    if (right.signum == 0) {
        return left;
    }
    if (left.signum != right.signum) {
        return BigInteger(BigInteger::add(left.number, right.number), left.signum);
    }

    int compared = BigInteger::compare(left.number, right.number);
    if (compared == 0) {
        return BigInteger::ZERO;
    }
    vector<int> result_number;
    int result_signum = 0;
    if (compared > 0) {
        result_number = BigInteger::subtract(left.number, right.number);
        result_signum = left.signum == 1 ? 1 : -1;
    } else {
        result_number = BigInteger::subtract(right.number, left.number);
        result_signum = left.signum == 1 ? -1 : 1;
    }
    return BigInteger(result_number, result_signum);
}

BigInteger operator-(const BigInteger &left, long long right) {
    return left - BigInteger::value_of(right);
}

BigInteger operator-(long long left, const BigInteger &right) {
    return right - left;
}

vector<int> BigInteger::add(const vector<int> &first, const vector<int> &second) {
    vector<int> result;

    int carry = 0;
    pair<int, int> quotient_and_remainder_by_base;
    for (unsigned int i = 0; i < max(first.size(), second.size()); ++i) {
        if (i == result.size()) {
            result.push_back(0);
        }
        int current_sum = 0;
        if (i < first.size() && i < second.size()) {
            current_sum = first[i] + second[i];
        } else {
            if (i < first.size()) {
                current_sum = first[i];
            } else {
                current_sum = second[i];
            }
        }
        quotient_and_remainder_by_base = BigInteger::quotient_and_remainder_by_base(carry + current_sum);
        result[i] = quotient_and_remainder_by_base.second;
        carry = quotient_and_remainder_by_base.first;
    }
    if (quotient_and_remainder_by_base.first != 0) {
        result.push_back(quotient_and_remainder_by_base.first);
    }
    normalize(result);
    return result;
}

vector<int> BigInteger::subtract(const vector<int> &first, const vector<int> &second) {
    vector<int> result(first);
    BigInteger::mutating_subtract_with_no_normalization(result, second);
    normalize(result);
    return result;
}

void BigInteger::mutating_subtract_with_no_normalization(vector<int> &first, const vector<int> &second) {
    int carry = 0;
    for (unsigned int i = 0; i < second.size(); ++i) {
        first[i] -= carry + second[i];
        if (first[i] < 0) {
            carry = 1;
            first[i] += BigInteger::BASE;
        } else {
            carry = 0;
        }
    }
    if (carry != 0) {
        first[second.size()] -= carry;
    }
}

void BigInteger::normalize(vector<int> &number) {
    while (number.size() > 1 && number.back() == 0) {
        number.pop_back();
    }
}

BigInteger operator*(const BigInteger &left, const BigInteger &right) {
    if (left.signum == 0 || right.signum == 0) {
        return BigInteger::ZERO;
    }
    return BigInteger(BigInteger::multiply(left.number, right.number), left.signum == right.signum ? 1 : -1);
}

BigInteger operator*(const BigInteger &left, long long right) {
    return left * BigInteger::value_of(right);
}

BigInteger operator*(long long left, const BigInteger &right) {
    return right * left;
}

vector<int> BigInteger::multiply(const vector<int> &first, const vector<int> &second) {
    vector<int> result(first.size() + second.size());
    int carry = 0;
    int i = 0;
    int j = 0;
    for (i = 0; i < first.size(); ++i) {
        for (j = 0; j < second.size(); ++j) {
            long long cur = result[i + j] + first[i] * 1ll * second[j] + carry;
            pair<int, int> quotient_and_remainder = BigInteger::quotient_and_remainder_by_base(cur);
            result[i + j] = quotient_and_remainder.second;
            carry = quotient_and_remainder.first;
        }
        result[i + j] += carry;
        carry = 0;
    }
    result[i + j - 1] += carry;
    while (result.size() > 1 && result.back() == 0) {
        result.pop_back();
    }
    return result;
}

BigInteger operator/(const BigInteger &left, const BigInteger &right) {
    if (right == BigInteger::ZERO) {
        throw overflow_error("Division by zero");
    }
    if (BigInteger::compare(left.number, right.number) < 0) {
        return BigInteger::ZERO;
    }
    return BigInteger(BigInteger::quotient_and_remainder(left.number, right.number).first,
                      left.signum == right.signum ? 1 : -1);
}

BigInteger operator/(const BigInteger &left, long long right) {
    return left / BigInteger::value_of(right);
}

BigInteger operator/(long long left, const BigInteger &right) {
    return right / left;
}

pair<vector<int>, vector<int>>
BigInteger::quotient_and_remainder(const vector<int> &first, const vector<int> &second) {
    pair<vector<int>, vector<int>> result;
    if (second.size() == 1) {
        return short_division(first, second[0]);
    } else {
        return long_division(first, second);
    }
}

pair<vector<int>, vector<int>>
BigInteger::short_division(const vector<int> &divident, const int divisor) {
    vector<int> quotient;
    vector<int> remainder;
    int carry = 0;
    for (int i = divident.size() - 1; i >= 0; --i) {
        long long cur = divident[i] + carry * 1ll * BASE;
        quotient.push_back(int(cur / divisor));
        carry = int(cur % divisor);
    }
    reverse(quotient.begin(), quotient.end());
    remainder.push_back(carry);
    normalize(quotient);
    normalize(remainder);
    return {quotient, remainder};
}

pair<vector<int>, vector<int>> BigInteger::long_division(const vector<int> &divident, const vector<int> &divisor) {
    if (BigInteger::compare(divident, divisor) < 0) {
        return {{0}, divident};
    }
    string quotient_digits;
    vector<int> remainder(divident);

    int divident_decades = non_zero_decades(remainder);
    int divisor_decades = non_zero_decades(divisor);
    int remainder_decade_pointer = divident_decades;
    int dw = divisor_decades + 1;
    for (int i = 0; i < divident_decades - divisor_decades + 1; i++) {
        tuple<int, int, vector<int>> digit_taken_digits_multiplied = BigInteger::digit_taken_digits_multiplied(
                remainder, divisor, remainder_decade_pointer, divisor_decades, dw == divisor_decades + 1);
        if (i == 0) {
            if (get<1>(digit_taken_digits_multiplied) == 2) {
                dw--;
            } else {
                i++;
            }
        }
        quotient_digits += std::to_string(get<0>(digit_taken_digits_multiplied));

        mutating_subtract_with_no_normalization(remainder, get<2>(digit_taken_digits_multiplied));
        if (get<1>(digit_taken_digits_multiplied) == 2) {
            if (decade_value(remainder, remainder_decade_pointer) == 0) {
                remainder_decade_pointer -= 1;
            } else {
                dw++;
            }
        } else {
            remainder_decade_pointer -= 1;
        }
    }
    normalize(remainder);
    return {to_vector(quotient_digits), remainder};
}


tuple<int, int, vector<int>> BigInteger::digit_taken_digits_multiplied(const vector<int> &divident,
                                                                       const vector<int> &divisor,
                                                                       const int divident_decade_pointer,
                                                                       const int divisor_decades,
                                                                       const bool ctt) {

    pair<int, int> digit_taken_digits = BigInteger::digit_taken_digits(divident, divisor,
                                                                       divident_decade_pointer,
                                                                       divisor_decades, ctt);

    int digit = digit_taken_digits.first;
    int taken_digits = digit_taken_digits.second;
    int decades_difference = divident_decade_pointer - divisor_decades;

    if (taken_digits == 3) {
        decades_difference -= 1;
    }

    vector<int> digit_vector;
    digit_vector.push_back(digit);
    vector<int> tmp_1 = multiply(divisor, vector_with_one_in_decade(decades_difference + 1));
    vector<int> multiplied = multiply(multiply(divisor, vector_with_one_in_decade(decades_difference + 1)),
                                      digit_vector);
    if (BigInteger::compare(multiplied, divident) > 0) {
        digit -= 1;
        digit_vector[0] -= 1;
        multiplied = multiply(multiply(divisor, vector_with_one_in_decade(decades_difference + 1)), digit_vector);
    }

    return {digit, taken_digits, multiplied};
}

pair<int, int> BigInteger::digit_taken_digits(const vector<int> &divident,
                                              const vector<int> &divisor,
                                              const int divident_decade,
                                              const int divisor_decades,
                                              const bool ctt) {
    int decades_difference = divident_decade - divisor_decades;
    int taken_digits = 2;

    int divident_digits = decade_value(divident, divident_decade) * 10 +
                          decade_value(divident, divident_decade - 1);
    int divisor_digits = decade_value(divisor, divisor_decades) * 10 +
                         decade_value(divisor, divisor_decades - 1);

    int ratio = divident_digits / divisor_digits;
    vector<int> ratio_vector;
    ratio_vector.push_back(ratio);
    if (ratio == 0 && ctt) {
        divident_digits *= 10;
        divident_digits += decade_value(divident, divident_decade - 2);
        taken_digits = 3;
        ratio = divident_digits / divisor_digits;
    }
    int compared = compare(multiply(divisor, BigInteger::multiply(
            vector_with_one_in_decade(decades_difference + 1), ratio_vector)), divident);
    if (ctt && ratio == 1 && compared > 0) {
        divident_digits *= 10;
        divident_digits += decade_value(divident, divident_decade - 2);
        taken_digits = 3;
        ratio = divident_digits / divisor_digits;
    }
    if (!ctt && ratio == 1 && compared > 0) {
        ratio--;
    }


    return {ratio, taken_digits};
}

vector<int> BigInteger::vector_with_one_in_decade(const int decade_position) {
    vector<int> result;
    pair<int, int> numbers_and_decade = BigInteger::numbers_and_decade(decade_position);

    result.reserve(static_cast<unsigned int>(numbers_and_decade.first));
    for (int i = 0; i < numbers_and_decade.first; i++) {
        result.push_back(0);
    }
    result.push_back(power_of_ten(numbers_and_decade.second - 1));
    return result;
}

int BigInteger::power_of_ten(int power) {
    int result = 1;
    for (int i = 0; i < power; i++) {
        result *= 10;
    }
    return result;
}

int BigInteger::decade_value(vector<int> number, int decade_position) {
    pair<int, int> numbers_and_decade = BigInteger::numbers_and_decade(decade_position);
    return decade_value(number[numbers_and_decade.first], numbers_and_decade.second);
}

int BigInteger::decade_value(const int number, const int decade_position) {
    return (number / BigInteger::power_of_ten(decade_position - 1) % 10);
}

int BigInteger::non_zero_decades(const vector<int> &number) {
    return static_cast<int>((number.size() - 1) * 9 + non_zero_decades(number[number.size() - 1]));
}

int BigInteger::non_zero_decades(const int number) {
    int result = 0;
    int copy = number;
    while (copy != 0) {
        copy /= 10;
        result++;
    }
    return result;
}


BigInteger operator%(const BigInteger &left, const BigInteger &right) {
    if (right.signum == -1 || right.signum == 0) {
        throw overflow_error("Modulo base should be a positive number");
    }
    if (left.signum == 0 || left == right) {
        return BigInteger::ZERO;
    }
    if (BigInteger::compare(left.number, right.number) < 0) {
        if (left.signum == 1) {
            return left;
        }
        if (left.signum == -1) {
            return BigInteger(BigInteger::subtract(right.number, left.number), 1);
        }
    }
    vector<int> remainder = BigInteger::quotient_and_remainder(
            BigInteger::add(BigInteger::quotient_and_remainder(left.number, right.number).second, right.number),
            right.number).second;
    int sg = 1;
    if (remainder.size() == 1 && remainder[0] == 0) {
        sg = 0;
    }
    return BigInteger(remainder, sg);
}

BigInteger operator%(const BigInteger &left, long long right) {
    return left % BigInteger::value_of(right);
}

BigInteger operator%(long long left, const BigInteger &right) {
    return BigInteger::value_of(left) % right;
}


BigInteger &BigInteger::operator=(const BigInteger &other) = default;


bool operator<(const BigInteger &left, const BigInteger &right) {
    if (left.signum == 0) {
        return right.signum > 0;
    }
    if (right.signum == 0) {
        return left.signum < 0;
    }
    if (left.signum != right.signum) {
        return left.signum == -1;
    }
    int compared = BigInteger::compare(left.number, right.number);
    if (left.signum == 1) {
        return compared == -1;
    } else {
        return compared == 1;
    }
}

bool operator<(const BigInteger &left, long long right) {
    return left < BigInteger::value_of(right);;
}

bool operator<(long long left, const BigInteger &right) {
    return BigInteger::value_of(left) < right;
}


bool operator<=(const BigInteger &left, const BigInteger &right) {
    return (left < right) || (left == right);
}

bool operator<=(const BigInteger &left, long long right) {
    return left <= BigInteger::value_of(right);
}

bool operator<=(long long left, const BigInteger &right) {
    return BigInteger::value_of(left) <= right;
}


bool operator>(const BigInteger &left, const BigInteger &right) {
    if (left.signum == 0) {
        return right.signum < 0;
    }
    if (right.signum == 0) {
        return left.signum > 0;
    }
    if (left.signum != right.signum) {
        return left.signum == 1;
    }
    int compared = BigInteger::compare(left.number, right.number);
    if (left.signum == 1) {
        return compared == 1;
    } else {
        return compared == -1;
    }
}

bool operator>(const BigInteger &left, long long right) {
    return left > BigInteger::value_of(right);;
}

bool operator>(long long left, const BigInteger &right) {
    return BigInteger::value_of(left) > right;
}


bool operator>=(const BigInteger &left, const BigInteger &right) {
    return (left > right) || (left == right);
}

bool operator>=(const BigInteger &left, long long right) {
    return left >= BigInteger::value_of(right);
}

bool operator>=(long long left, const BigInteger &right) {
    return BigInteger::value_of(left) >= right;
}


bool operator==(const BigInteger &left, const BigInteger &right) {
    if (left.signum != right.signum) {
        return false;
    }
    return BigInteger::compare(left.number, right.number) == 0;
}

bool operator==(const BigInteger &left, long long right) {
    return left == BigInteger::value_of(right);;
}

bool operator==(long long left, const BigInteger &right) {
    return right == left;
}


bool operator!=(const BigInteger &left, const BigInteger &right) {
    return !(left == right);
}

bool operator!=(const BigInteger &left, const long long right) {
    return left != BigInteger::value_of(right);;
}

bool operator!=(long long left, const BigInteger &right) {
    return right != left;
}


int BigInteger::compare(const vector<int> &first, const vector<int> &second) {
    int i = static_cast<int>(first.size() - 1);
    int j = static_cast<int>(second.size() - 1);
    while (first[i] == 0) {
        i--;
    }
    while (second[j] == 0) {
        j--;
    }
    if (i < 0 && j < 0) {
        return 0;
    } else {
        if (i < 0) {
            return -1;
        }
        if (j < 0) {
            return 1;
        }
    }

    if (i != j) {
        if (i > j) {
            return 1;
        } else {
            return -1;
        }
    }
    for (; i >= 0; i--) {
        if (first[i] != second[i]) {
            break;
        }
    }
    if (i < 0) {
        return 0;
    } else {
        return first[i] > second[i] ? 1 : -1;
    }
}


ostream &operator<<(ostream &stream, const BigInteger &number) {
    stream << number.to_string();
    return stream;
}

string BigInteger::to_string() const {
    stringstream stream;
    if (signum == -1) {
        stream << "-";
    }
    if (number.size() == 1 && number[0] == 0) {
        stream << "0";
    } else {
        int i = 1;
        for (auto rit = number.rbegin(); rit != number.rend(); ++rit) {
            if (i == 1) {
                if (*rit != 0) {
                    stream << *rit;
                }
            } else {
                stream << BigInteger::to_string(*rit);
            }
            i++;
        }
    }
    return stream.str();
}

string BigInteger::to_string(int number) {
    stringstream stream;
    int non_zero_decades = BigInteger::non_zero_decades(number);
    for (int i = 0; i < 9 - non_zero_decades; i++) {
        stream << 0;
    }
    stream << number;
    return stream.str();
}


BigInteger BigInteger::to_power(const BigInteger &power) const {
    BigInteger::assert_legal_power(*this, power);

    BigInteger power_copy = power;
    bool even_power = !(power_copy % 2 == 1);
    vector<int> result;
    result.push_back(1);
    vector<int> copy(number);
    while (power_copy > 0) {
        if (power_copy % 2 == 1) {
            result = multiply(result, copy);
        }
        copy = multiply(copy, copy);
        power_copy = power_copy / 2;
    }
    return BigInteger(result, (signum == -1 && !even_power) ? -1 : 1);
}

BigInteger BigInteger::to_power(unsigned long long power) const {
    return to_power(BigInteger::value_of(power));
}

BigInteger BigInteger::to_power(const BigInteger &power, const BigInteger &mod) const {
    BigInteger::assert_legal_power(*this, power);
    BigInteger::assert_legal_mod(mod);

    BigInteger power_copy = power;
    bool even_power = !(power_copy % 2 == 1);
    vector<int> result;
    result.push_back(1);
    vector<int> copy(number);
    while (power_copy > 0) {
        if (power_copy % 2 == 1) {
            result = quotient_and_remainder(multiply(result, copy), mod.number).second;
        }
        copy = quotient_and_remainder(multiply(copy, copy), mod.number).second;
        power_copy = power_copy / 2;
    }
    return BigInteger(result, (signum == -1 && !even_power) ? -1 : 1);
}

BigInteger BigInteger::to_power(unsigned long long power, const BigInteger &mod) const {
    return to_power(BigInteger::value_of(power), mod);
}

void BigInteger::assert_legal_power(const BigInteger &number, const BigInteger &power) {
    if (number.signum == 0 && power == 0) {
        throw invalid_argument("Indeterminateness of type 0 to power of 0");
    }
    if (power.signum == -1) {
        throw invalid_argument("Power cannot be negative");
    }
}

void BigInteger::assert_legal_mod(const BigInteger &mod) {
    if (mod < 2) {
        throw invalid_argument("Mod cannot be less than 2");
    }
}


BigInteger BigInteger::square_root() const {
    if (signum == -1) {
        throw runtime_error("Square root of negative number");
    }
    if (signum == 0) {
        return ZERO;
    }
    if (number.size() == 1) {
        return BigInteger(short_square_root(number), 1);
    } else {
        return BigInteger(long_square_root(number), 1);
    }
}

vector<int> BigInteger::short_square_root(vector<int> number) {
    vector<int> result;
    result.push_back(static_cast<int>(sqrt(number[0])));
    return result;
}

vector<int> BigInteger::long_square_root(vector<int> number) {
    vector<int> two_vector;
    two_vector.push_back(2);
    vector<int> approximation = square_root_initial_approximation(number);
    vector<int> next_approximation = square_root_next_approximation(number, approximation, two_vector);
    while (compare(approximation, next_approximation) != 0) {
        approximation = next_approximation;
        next_approximation = square_root_next_approximation(number, approximation, two_vector);
    }
    return approximation;
}

vector<int> BigInteger::square_root_initial_approximation(const vector<int> number) {
    vector<int> result;

    int non_zero_decades = BigInteger::non_zero_decades(number);
    int zero_decades = 0;
    int number_digits = 0;

    if (non_zero_decades & 1) {
        zero_decades = (non_zero_decades - 1) / 2;
        number_digits = decade_value(zero_decades, non_zero_decades);
    } else {
        zero_decades = non_zero_decades / 2 - 1;
        number_digits = 10;
    }

    int approximation_digit = number_digits < 10 ? 2 : 6;
    int zero_numbers = zero_decades / 9;
    int additional_zeros = zero_decades % 9;
    result.reserve(static_cast<unsigned int>(zero_numbers));
    for (int i = 0; i < zero_numbers; i++) {
        result.push_back(0);
    }
    result.push_back(approximation_digit * power_of_ten(additional_zeros));
    return result;
}

vector<int> BigInteger::square_root_next_approximation(const vector<int> &number, const vector<int> &approximation,
                                                       const vector<int> two) {
    return quotient_and_remainder(add(approximation, quotient_and_remainder(number, approximation).first), two).first;
}


BigInteger BigInteger::modulo_addition(const BigInteger &other, const BigInteger &modulo) const {
    return (*this + other) % modulo;
}

BigInteger BigInteger::modulo_addition(const BigInteger &other, long long modulo) const {
    return (*this + other) % modulo;
}

BigInteger BigInteger::modulo_addition(long long other, const BigInteger &modulo) const {
    return (*this + other) % modulo;
}


BigInteger BigInteger::modulo_subtraction(const BigInteger &other, const BigInteger &modulo) const {
    return (*this - other) % modulo;
}

BigInteger BigInteger::modulo_subtraction(long long other, const BigInteger &modulo) const {
    return (*this - other) % modulo;
}

BigInteger BigInteger::modulo_subtraction(const BigInteger &other, long long modulo) const {
    return (*this - other) % modulo;
}


BigInteger BigInteger::modulo_multiplication(const BigInteger &other, const BigInteger &modulo) const {
    return (*this * other) % modulo;
}

BigInteger BigInteger::modulo_multiplication(long long other, const BigInteger &modulo) const {
    return (*this * other) % modulo;
}

BigInteger BigInteger::modulo_multiplication(const BigInteger &other, long long modulo) const {
    return (*this * other) % modulo;
}


BigInteger BigInteger::modulo_division(const BigInteger &other, const BigInteger &modulo) const {
    return (*this / other) % modulo;
}

BigInteger BigInteger::modulo_division(long long other, const BigInteger &modulo) const {
    return (*this / other) % modulo;
}

BigInteger BigInteger::modulo_division(const BigInteger &other, long long modulo) const {
    return (*this / other) % modulo;
}


pair<int, int> BigInteger::numbers_and_decade(int decade_position) {
    if (decade_position % 9 == 0) {
        return {decade_position / 9 - 1, 9};
    } else {
        return {decade_position / 9, decade_position % 9};
    }
}

pair<int, int> BigInteger::quotient_and_remainder_by_base(long long number) {
    return {static_cast<const int &>(number / BigInteger::BASE), static_cast<const int &>(number % BigInteger::BASE)};
}


BigInteger BigInteger::negate() const {
    return BigInteger(number, -signum);
}

BigInteger BigInteger::value_of(const long long number) {
    BigInteger result;
    vector<int> result_number;
    int result_signum = 0;
    if (number > 0) {
        result_signum = 1;
    } else {
        if (number < 0) {
            result_signum = -1;
        }
    }
    long long abs_number = llabs(number);
    if (abs_number == 0) {
        result_number.push_back(0);
    } else {
        while (abs_number > 0) {
            result_number.push_back(int(abs_number % BigInteger::BASE));
            abs_number /= BigInteger::BASE;
        }
    }
    return BigInteger(result_number, result_signum);
}

BigInteger BigInteger::abs() const {
    return BigInteger(number, signum * signum);
}


BigInteger BigInteger::random(const BigInteger &mod) {
    BigInteger::assert_legal_mod(mod);

    vector<int> number;
    number.reserve(mod.number.size());

    for (uint32_t i = 0; i < mod.number.size() - 1; i++) {
        number.push_back(rand() % BASE);
    }
    number.push_back(rand() % mod.number[mod.number.size() - 1]);
    return BigInteger(number, 1);
}

int BigInteger::operator[](int idx) const {
    return number[idx];
}

uint64_t BigInteger::size() {
    return number.size();
}