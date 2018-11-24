//
// Created by Semen on 11/24/2018.
//

#include <string>
#include <iostream>
#include <BigInteger.h>
#include <PollardsRhoFactorization.h>
#include <BabyStepGiantStepDiscreteLogarithm.h>
#include <BabyStepGiantStepDiscreteLogarithm.h>
#include <MobuisFunction.h>
#include <ElGamalCryptosystem.h>

using namespace std;

string pollards_factorization = "pf";
string baby_step_gigant_step = "bsgs";
string euler_function = "ef";
string mobius_function = "mf";
string legendre_symbol = "ls";
string jacobi_symbol = "js";

string chipollas_algorithm = "ch";
string solovay_strassen = "ss";

string el_gamal = "eg";

string ex = "ex";

PollardsRhoFactorization factorization;
BabyStepGiantStepDiscreteLogarithm logarithm;
EulerFunction eulerFunction;
MobuisFunction mobuisFunction;
LegendreSymbol legendreSymbol;
JacobianSymbol jacobianSymbol;
CipollasAlgorithm cipollasAlgorithm;
SolovayStrassen solovayStrassen;

EllipticCurve curve(
        BigInteger("4451685225093714772084598273548427"),
        BigInteger("1970543761890640310119143205433388"),
        BigInteger("1660538572255285715897238774208265"),
        {BigInteger("1534098225527667214992304222930499"),
         BigInteger("3525120595527770847583704454622871")},
        BigInteger("1112921306273428674967732714786891"),
        BigInteger("4")
);
ElGamalCryptosystem cryptosystem(curve);

void show_prompt() {
    cout << "Available operations: " << endl;

    cout << "pf - factorize number (number)" << endl;
    cout << "bsgs - discrete logarithm (number, remainder, bsgs)" << endl;
    cout << "ef - euler function (number)" << endl;
    cout << "mf - mobuis function (number)" << endl;
    cout << "ls - legendre symbol (number)" << endl;
    cout << "js - jacobi symbol (number)" << endl;

    cout << "ch - chipollas algorithm (number, prime modulo)" << endl;
    cout << "ss - solovay strassen (number)" << endl;

    cout << "eg - send message with el Gamal protocol (numberpf)" << endl;
}

BigInteger input_number() {
    cout << "Input number: " << endl;
    string number;
    cin >> number;
    return BigInteger(number);
}

string input_operation() {
    cout << "Input operation: " << endl;
    string operation;
    cin >> operation;
    return operation;
}

void cli() {
    show_prompt();
    while (true) {
        string operation = input_operation();
        if (operation == pollards_factorization) {
            for (const auto &factor:factorization.factorize(input_number())) {
                cout << factor << endl;
            }
        } else if (operation == baby_step_gigant_step) {
            BigInteger a = input_number();
            BigInteger b = input_number();
            BigInteger m = input_number();
            cout << logarithm.discreteLogarithm(a, b, m) << endl;
        } else if (operation == euler_function) {
            cout << eulerFunction.eulerFunction(input_number()) << endl;
        } else if (operation == mobius_function) {
            cout << mobuisFunction.mobuidFunction(input_number()) << endl;
        } else if (operation == legendre_symbol) {
            BigInteger a = input_number();
            BigInteger p = input_number();
            cout << legendreSymbol.legendre_symbol(a, p) << endl;
        } else if (operation == jacobi_symbol) {
            BigInteger a = input_number();
            BigInteger p = input_number();
            cout << jacobianSymbol.jacobian_symbol(a, p) << endl;
        } else if (operation == chipollas_algorithm) {
            BigInteger n = input_number();
            BigInteger p = input_number();
            tuple<BigInteger, BigInteger, bool> result = cipollasAlgorithm.square_root(n, p);
            cout << get<0>(result) << endl;
        } else if (operation == solovay_strassen) {
            cout << solovayStrassen.is_prime(input_number()) << endl;
        } else if (operation == el_gamal) {
            cryptosystem.send_message(input_number());
        } else if (operation == ex) {
            cout << "exit" << endl;
            break;
        }
    }
}

int main() {
    cli();
    return 0;
}