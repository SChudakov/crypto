//
// Created by Semen on 10/24/2018.
//
#include <BigInteger.h>
#include <gtest/gtest.h>
#include <GCD.h>

TEST(gcd, gcd_1) {
    GCD gcd;

    BigInteger a("1611623773");
    BigInteger b("945636286");

    BigInteger abgcd("1");
    ASSERT_EQ(gcd.gcd(a, b), abgcd);
}

TEST(gcd, gcd_2) {
    GCD gcd;

    BigInteger a("1611623773");
    BigInteger b("1913713685");

    BigInteger abgcd("1");
    ASSERT_EQ(gcd.gcd(a, b), abgcd);
}

TEST(gcd, gcd_3) {
    GCD gcd;

    BigInteger a("100000000000000000000000000001313711692");
    BigInteger b("1611623773");

    BigInteger abgcd("1");
    ASSERT_EQ(gcd.gcd(a, b), abgcd);
}

TEST(gcd, gcd_4) {
    GCD gcd;

    BigInteger a("1000000001361814298");
    BigInteger b("1611623773");

    BigInteger abgcd("1");
    ASSERT_EQ(gcd.gcd(a, b), abgcd);
}

TEST(gcd, gcd_5) {
    GCD gcd;

    BigInteger a("10967535067");
    BigInteger b("5588653627");

    BigInteger abgcd("104729");
    BigInteger g = gcd.gcd(a, b);
    cout << a / g << endl;
    ASSERT_EQ(g, abgcd);
}
