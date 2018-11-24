//
// Created by Semen on 11/19/2018.
//

#ifndef CRYPTO_ELGAMALCRYPTOSYSTEM_H
#define CRYPTO_ELGAMALCRYPTOSYSTEM_H


#include <ExtendedGCD.h>
#include <unordered_map>
#include "EllipticCurve.h"

typedef pair<BigInteger, BigInteger> point;


class ElGamalCryptosystem {
    static const pair<BigInteger, BigInteger> INF;
    static const BigInteger DEFAULT_ATOMIC_MESSAGE_BASE;

    struct pair_hash {
        inline int64_t operator()(const std::pair<BigInteger, BigInteger> &v) const {
            return v.first[0] * 31 + v.second[0];
        }
    };

    struct BigInteget_hash {
        inline int64_t operator()(const BigInteger &v) const {
            return v[0];
        }
    };

    BigInteger atomic_message_base;

    ExtendedGCD gcd;

    EllipticCurve curve;
    BigInteger modulo;
    BigInteger x;
    pair<BigInteger, BigInteger> y;

    unordered_map <BigInteger, pair<BigInteger, BigInteger>, BigInteget_hash> messages_to_points_map;
    unordered_map <pair<BigInteger, BigInteger>, BigInteger, pair_hash> points_to_messages_map;


    point send_point(pair<BigInteger, BigInteger> M);

    point multiply_on_curve(point p, const BigInteger &power);

    point add_on_curve(point a, point b);

    point getPoint(const BigInteger &m);

    BigInteger getM(point point);

    point negate(pair<BigInteger, BigInteger> point);

    void fill_maps();

public:
    explicit ElGamalCryptosystem(const EllipticCurve &curve, const BigInteger &atomic_message_base = DEFAULT_ATOMIC_MESSAGE_BASE);

    void send_message(BigInteger m);
};


#endif //CRYPTO_ELGAMALCRYPTOSYSTEM_H
