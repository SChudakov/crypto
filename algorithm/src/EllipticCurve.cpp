#include <utility>

//
// Created by Semen on 11/19/2018.
//

#include "EllipticCurve.h"

EllipticCurve::EllipticCurve(const BigInteger &p, const BigInteger &a, const BigInteger &b,
                             pair<BigInteger, BigInteger> G,
                             const BigInteger &n, const BigInteger &h) : p(p), a(a), b(b), G(std::move(G)), n(n), h(h) {
}


const BigInteger &EllipticCurve::getA() const {
    return a;
}

const BigInteger &EllipticCurve::getB() const {
    return b;
}

const BigInteger &EllipticCurve::getN() const {
    return n;
}

const BigInteger &EllipticCurve::getH() const {
    return h;
}

const BigInteger &EllipticCurve::getP() const {
    return p;
}

const pair<BigInteger, BigInteger> &EllipticCurve::getG() const {
    return G;
}

