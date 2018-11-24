//
// Created by Semen on 9/24/2018.
//
#include <iostream>
#include <BigInteger.h>
#include <string>
#include <vector>

using namespace std;

string addition = "+";
string minus = "-";
string multiply = "*";
string divide = "/";
string modulo = "%";

string to_power = "^";
string sq = "sqrt";

string ch = "ch";

void show_prompt() {
    cout << "Available operations: " << endl;

    cout << "+ - add" << endl;
    cout << "- - subtract" << endl;
    cout << "* - multiply" << endl;
    cout << "/ - division" << endl;
    cout << "% - modulo" << endl;

    cout << "^ - pow" << endl;
    cout << "sqrt - square root" << endl;
    cout << "ch - chinese remainder problem" << endl;
}

BigInteger input_number() {
    cout << "Input number: ";
    string number;
    cin >> number;
    return BigInteger(number);
}

unsigned int input_power() {
    cout << "Input power: ";
    unsigned int power;
    cin >> power;
    return power;
}

vector<pair<int, int>> input_modulus_and_remainders() {
    cout << "input modulus and remainders:" << endl;
    cout << "num of elements:" << endl;
    int num_of_elements;
    cin >> num_of_elements;
    vector<pair<int, int>> result;
    int modulo;
    int remainder;
    for (int i = 0; i < num_of_elements; i++) {
        cout << "modulo:" << endl;
        cin >> modulo;
        cout << "remainder:" << endl;
        cin >> remainder;
        result.emplace_back(modulo, remainder);
    }
    return result;
}

void console() {
    show_prompt();
    while (true) {
        string operation;
        cin >> operation;

        if (operation == ch) {
            vector<pair<int, int>> modulus_and_remainders = input_modulus_and_remainders();
            BigInteger number = BigInteger::chinese_remainder_problem(modulus_and_remainders);
            cout << number << endl;
        } else {
            BigInteger first = input_number();
            BigInteger second = BigInteger::value_of(0);
            unsigned int power = 0;

            if (operation == addition) {
                second = input_number();
                cout << first + second << endl;
            }
            if (operation == minus) {
                second = input_number();
                cout << first - second << endl;
            }
            if (operation == multiply) {
                second = input_number();
                cout << first * second << endl;
            }
            if (operation == divide) {
                second = input_number();
                cout << first / second << endl;
            }
            if (operation == modulo) {
                second = input_number();
                cout << first % second << endl;
            }
            if (operation == to_power) {
                power = input_power();
                cout << first.to_power(power) << endl;
            }
            if (operation == sq) {
                cout << first.square_root() << endl;
            }
        }
    }
}

int main() {
//    console();
    cout << BigInteger::value_of(-12) % BigInteger::value_of(5) << endl;
    return 0;
}
