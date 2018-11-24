//
// Created by Semen on 11/24/2018.
//

#include <BigInteger.h>
#include <gtest/gtest.h>


TEST(random, random_1) {
    BigInteger modulo("100000000");
    for (int i = 0; i < 10; i++) {
        cout << BigInteger::random(modulo) << endl;
    }
}