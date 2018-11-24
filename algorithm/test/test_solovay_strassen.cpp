//
// Created by Semen on 10/27/2018.
//

#include <BigInteger.h>
#include <gtest/gtest.h>
#include <PollardsRhoFactorization.h>
#include <SolovayStrassen.h>


TEST(solovay_strassen, solovay_strassen_1) {
    SolovayStrassen solovayStressen{};

    BigInteger p1 = BigInteger::value_of(-1);
    BigInteger p2 = BigInteger::value_of(1);
    ASSERT_FALSE(solovayStressen.is_prime(p1));
    ASSERT_FALSE(solovayStressen.is_prime(p2));
}

TEST(solovay_strassen, solovay_strassen_2) {
    SolovayStrassen solovayStressen{};

    ASSERT_TRUE(solovayStressen.is_prime(BigInteger::value_of(2)));
    ASSERT_TRUE(solovayStressen.is_prime(BigInteger::value_of(5)));
    ASSERT_TRUE(solovayStressen.is_prime(BigInteger::value_of(7)));
    ASSERT_TRUE(solovayStressen.is_prime(BigInteger::value_of(11)));
    ASSERT_TRUE(solovayStressen.is_prime(BigInteger::value_of(13)));
    ASSERT_TRUE(solovayStressen.is_prime(BigInteger::value_of(17)));
    ASSERT_TRUE(solovayStressen.is_prime(BigInteger::value_of(29)));
    ASSERT_TRUE(solovayStressen.is_prime(BigInteger::value_of(31)));
    ASSERT_TRUE(solovayStressen.is_prime(BigInteger::value_of(37)));
    ASSERT_TRUE(solovayStressen.is_prime(BigInteger::value_of(41)));
    ASSERT_TRUE(solovayStressen.is_prime(BigInteger::value_of(59)));
    ASSERT_TRUE(solovayStressen.is_prime(BigInteger::value_of(67)));
    ASSERT_TRUE(solovayStressen.is_prime(BigInteger::value_of(97)));

    ASSERT_TRUE(solovayStressen.is_prime(BigInteger::value_of(104723)));
}

TEST(solovay_strassen, solovay_strassen_3) {
    SolovayStrassen solovayStressen{};

    ASSERT_TRUE(solovayStressen.is_prime(BigInteger::value_of(252097800623)));
    ASSERT_TRUE(solovayStressen.is_prime(BigInteger::value_of(2760727302517)));
    ASSERT_TRUE(solovayStressen.is_prime(BigInteger::value_of(29996224275833)));
}