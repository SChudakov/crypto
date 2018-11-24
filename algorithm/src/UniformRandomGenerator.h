//
// Created by Semen on 10/28/2018.
//

#ifndef CRYPTO_UNIFORMRANDOMGENERATOR_H
#define CRYPTO_UNIFORMRANDOMGENERATOR_H

#include <random>

using namespace std;


class UniformRandomGenerator {
    random_device device;
    mt19937 gen;
    uniform_int_distribution<> distribution;
public:
    UniformRandomGenerator(int a, int b);

    int generate_random();
};


#endif //CRYPTO_UNIFORMRANDOMGENERATOR_H
