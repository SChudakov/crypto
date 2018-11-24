//
// Created by Semen on 11/25/2018.
//

#include <BigInteger.h>
#include <gtest/gtest.h>
#include <ElGamalCryptosystem.h>


TEST(el_gamal, el_gamal_1) {
    srand(time(nullptr));
    ElGamalCryptosystem cryptosystem(EllipticCurve(
            BigInteger("4451685225093714772084598273548427"),
            BigInteger("1970543761890640310119143205433388"),
            BigInteger("1660538572255285715897238774208265"),
            {BigInteger("1534098225527667214992304222930499"),
             BigInteger("3525120595527770847583704454622871")},
            BigInteger("1112921306273428674967732714786891"),
            BigInteger("4")
    ));
    cryptosystem.send_message(BigInteger::value_of(1000));
}