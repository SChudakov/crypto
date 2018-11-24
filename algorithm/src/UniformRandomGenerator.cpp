//
// Created by Semen on 10/28/2018.
//

#include <stdexcept>
#include <iostream>
#include "UniformRandomGenerator.h"


int UniformRandomGenerator::generate_random() {
    return distribution(gen);
}

UniformRandomGenerator::UniformRandomGenerator(int a, int b) {
    if (a > b) {
        throw invalid_argument("a should be less than or equal to b");
    }
    gen = mt19937(device());
    distribution = uniform_int_distribution<>(a, b);
}
