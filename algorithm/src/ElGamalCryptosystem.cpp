#include <utility>

//
// Created by Semen on 11/19/2018.
//

#include "ElGamalCryptosystem.h"


const pair<BigInteger, BigInteger> ElGamalCryptosystem::INF = {BigInteger::value_of(0), BigInteger::value_of(0)};
const BigInteger ElGamalCryptosystem::DEFAULT_ATOMIC_MESSAGE_BASE = BigInteger::value_of(100);

ElGamalCryptosystem::ElGamalCryptosystem(const EllipticCurve &curve,
                                         const BigInteger &atomic_message_base) : curve(curve),
                                                                                  atomic_message_base(
                                                                                          atomic_message_base) {
    modulo = curve.getP();
    x = BigInteger::random(curve.getP() - 1);
    y = multiply_on_curve(curve.getG(), x);
    fill_maps();
}

void ElGamalCryptosystem::fill_maps() {
    pair<BigInteger, BigInteger> point = curve.getG();
    for (BigInteger i = BigInteger::value_of(0); i < atomic_message_base; ++i) {
        messages_to_points_map.insert({i, point});
        points_to_messages_map.insert({point, i});
        point = add_on_curve(point, curve.getG());
    }
}


void ElGamalCryptosystem::send_message(BigInteger m) {
    if (m <= 0) {
        throw invalid_argument("message should be positive");
    }
    BigInteger message = BigInteger::value_of(0);
    BigInteger received_message = BigInteger::value_of(0);
    point message_point;

    uint64_t i = 0;
    for (; m >= atomic_message_base; i++) {
        message = m % atomic_message_base;
        message_point = getPoint(message);
        m = m / atomic_message_base;
        cout << "message: " << message << endl;
        cout << "M: " << message_point.first << " " << message_point.second << endl;
        point received = ElGamalCryptosystem::send_point(message_point);

        BigInteger decrypted_m = getM(received);
        received_message = received_message + decrypted_m * atomic_message_base.to_power(i);
        cout << "received message: " << decrypted_m << endl;
    }

    cout << "message: " << m << endl;
    message_point = getPoint(m);
    cout << "M: " << message_point.first << " " << message_point.second << endl;
    m = BigInteger::value_of(0);
    point received = ElGamalCryptosystem::send_point(message_point);

    BigInteger decrypted_m = getM(received);
    received_message = received_message + decrypted_m * atomic_message_base.to_power(i);
    cout << "received message: " << decrypted_m << endl << endl;

    cout << "received message: " << received_message << endl;
}

point ElGamalCryptosystem::send_point(point M) {
//    seance key
    BigInteger r = BigInteger::random(curve.getP() - 1);
    cout << "r: " << r << endl;

//    encrypting
    pair<BigInteger, BigInteger> g = multiply_on_curve(curve.getG(), r);
    pair<BigInteger, BigInteger> h = add_on_curve(std::move(M), multiply_on_curve(y, r));

    cout << "g: " << g.first << " " << g.second << endl;
    cout << "h: " << h.first << " " << h.second << endl;


//   decrypting
    pair<BigInteger, BigInteger> s = multiply_on_curve(g, x);
    pair<BigInteger, BigInteger> s1 = negate(s);
    pair<BigInteger, BigInteger> decrypted_M = add_on_curve(s1, h);

    cout << "s: " << s.first << " " << s.second << endl;
    cout << "s1: " << s1.first << " " << s1.second << endl;
    cout << "decrypted_M: " << decrypted_M.first << " " << decrypted_M.second << endl;
    return decrypted_M;
}

pair<BigInteger, BigInteger> ElGamalCryptosystem::getPoint(const BigInteger &m) {
    return messages_to_points_map.at(m);
}

BigInteger ElGamalCryptosystem::getM(pair<BigInteger, BigInteger> point) {
    return points_to_messages_map.at(point);
}

pair<BigInteger, BigInteger> ElGamalCryptosystem::negate(pair<BigInteger, BigInteger> point) {
    return {point.first, curve.getP() - point.second};
}

pair<BigInteger, BigInteger>
ElGamalCryptosystem::multiply_on_curve(pair<BigInteger, BigInteger> p, const BigInteger &multiplier) {
    if (multiplier < 1) {
        throw invalid_argument("multiplier equal to 0");
    }
    if (multiplier == 1) {
        return p;
    }
    pair<BigInteger, BigInteger> result = INF;
    pair<BigInteger, BigInteger> addend = p;

    BigInteger multiplier_copy = multiplier;
    while (multiplier_copy > 0) {
        if (multiplier_copy % 2 == 1) {
            result = add_on_curve(result, addend);
        }
        addend = add_on_curve(addend, addend);
        multiplier_copy = multiplier_copy / 2;
//        cout << "addend: " << addend.first << " " << addend.second << endl;
    }
    return result;
}

pair<BigInteger, BigInteger>
ElGamalCryptosystem::add_on_curve(pair<BigInteger, BigInteger> a, pair<BigInteger, BigInteger> b) {
    if (a == INF) {
        return b;
    } else if (b == INF) {
        return a;
    } else if (a.first == b.first && a.second != b.second) { //P + -P = O
        return INF;
    } else if (a.first == b.first && a.second == b.second) { // P + P = 2P
//        cout << a.first.modulo_multiplication(a.first, modulo) << endl;
//        cout << a.first.modulo_multiplication(a.first, modulo).modulo_multiplication(3, modulo) << endl;
//        cout << (a.first.modulo_multiplication(a.first, modulo).modulo_multiplication(3, modulo).modulo_addition(curve.getA(), modulo)) << endl;
//        cout << a.second.modulo_multiplication(2, modulo) << endl;
//        cout << modulo << endl;
//        cout << get<1>(gcd.extended_gcd(a.second.modulo_multiplication(2, modulo), modulo)) << endl;
//        cout << ((a.first.modulo_multiplication(a.first, modulo).modulo_multiplication(3, modulo).modulo_addition(curve.getA(), modulo)).modulo_multiplication(get<1>(gcd.extended_gcd(a.second.modulo_multiplication(2, modulo), modulo)), modulo)) << endl;
//        cout << ((a.first.modulo_multiplication(a.first, modulo).modulo_multiplication(3, modulo).modulo_addition(curve.getA(), modulo)).modulo_multiplication(get<1>(gcd.extended_gcd(a.second.modulo_multiplication(2, modulo), modulo)), modulo)).to_power(2,modulo)<< endl;
//        cout << a.first.modulo_multiplication(2, modulo) << endl;
        BigInteger cx =
                ((a.first
                        .modulo_multiplication(a.first, modulo)
                        .modulo_multiplication(3, modulo)
                        .modulo_addition(curve.getA(), modulo)
                )
                        .modulo_multiplication(
                                get<1>(gcd.extended_gcd(a.second.modulo_multiplication(2, modulo), modulo)) % modulo,
                                modulo)
                )
                        .to_power(2, modulo)
                        .modulo_subtraction(a.first.modulo_multiplication(2, modulo), modulo);
        BigInteger cy =
                ((a.first
                        .modulo_multiplication(a.first, modulo)
                        .modulo_multiplication(3, modulo)
                        .modulo_addition(curve.getA(), modulo)
                )
                        .modulo_multiplication(
                                get<1>(gcd.extended_gcd(a.second.modulo_multiplication(2, modulo), modulo)) % modulo,
                                modulo
                        )
                )
                        .modulo_multiplication(a.first.modulo_subtraction(cx, modulo), modulo)
                        .modulo_subtraction(a.second, modulo);
//        cout << "first" << endl;
//        cout << cx << endl;
//        cout << cy << endl;
        return {cx, cy};
    } else { // P neq Q
        BigInteger cx = ((b.second.modulo_subtraction(a.second, modulo))
                .modulo_multiplication(
                        get<1>(gcd.extended_gcd(b.first.modulo_subtraction(a.first, modulo), modulo)) % modulo,
                        modulo)
        )
                .to_power(2, modulo)
                .modulo_subtraction(a.first, modulo)
                .modulo_subtraction(b.first, modulo);
        BigInteger cy = ((b.second.modulo_subtraction(a.second, modulo))
                .modulo_multiplication(
                        get<1>(gcd.extended_gcd(b.first.modulo_subtraction(a.first, modulo), modulo)) % modulo,
                        modulo)
        )
                .modulo_multiplication(a.first.modulo_subtraction(cx, modulo), modulo)
                .modulo_subtraction(a.second, modulo);
//        cout << "second" << endl;
//        cout << cx << endl;
//        cout << cy << endl;
        return {cx, cy};
    }
}













