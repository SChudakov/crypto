//
// Created by Semen on 10/27/2018.
//
#include <BigInteger.h>
#include <gtest/gtest.h>
#include <EulerFunction.h>


TEST(euler_function, euler_function_1) {
    EulerFunction eulerFunction;

    BigInteger zero = BigInteger::value_of(0);
    BigInteger minus_one = BigInteger::value_of(-1);

    ASSERT_THROW(eulerFunction.eulerFunction(zero), std::invalid_argument);
    ASSERT_THROW(eulerFunction.eulerFunction(minus_one), std::invalid_argument);
}

TEST(euler_function, euler_function_2) {
    EulerFunction eulerFunction;

    ASSERT_EQ(eulerFunction.eulerFunction(BigInteger::value_of(1)), BigInteger::value_of(1));
    ASSERT_EQ(eulerFunction.eulerFunction(BigInteger::value_of(2)), BigInteger::value_of(1));
    ASSERT_EQ(eulerFunction.eulerFunction(BigInteger::value_of(3)), BigInteger::value_of(2));
    ASSERT_EQ(eulerFunction.eulerFunction(BigInteger::value_of(4)), BigInteger::value_of(2));
    ASSERT_EQ(eulerFunction.eulerFunction(BigInteger::value_of(5)), BigInteger::value_of(4));
    ASSERT_EQ(eulerFunction.eulerFunction(BigInteger::value_of(6)), BigInteger::value_of(2));
    ASSERT_EQ(eulerFunction.eulerFunction(BigInteger::value_of(7)), BigInteger::value_of(6));
    ASSERT_EQ(eulerFunction.eulerFunction(BigInteger::value_of(8)), BigInteger::value_of(4));
    ASSERT_EQ(eulerFunction.eulerFunction(BigInteger::value_of(9)), BigInteger::value_of(6));

    ASSERT_EQ(eulerFunction.eulerFunction(BigInteger::value_of(10)), BigInteger::value_of(4));
    ASSERT_EQ(eulerFunction.eulerFunction(BigInteger::value_of(11)), BigInteger::value_of(10));
    ASSERT_EQ(eulerFunction.eulerFunction(BigInteger::value_of(12)), BigInteger::value_of(4));
    ASSERT_EQ(eulerFunction.eulerFunction(BigInteger::value_of(13)), BigInteger::value_of(12));
    ASSERT_EQ(eulerFunction.eulerFunction(BigInteger::value_of(14)), BigInteger::value_of(6));
    ASSERT_EQ(eulerFunction.eulerFunction(BigInteger::value_of(15)), BigInteger::value_of(8));
    ASSERT_EQ(eulerFunction.eulerFunction(BigInteger::value_of(16)), BigInteger::value_of(8));
    ASSERT_EQ(eulerFunction.eulerFunction(BigInteger::value_of(17)), BigInteger::value_of(16));
    ASSERT_EQ(eulerFunction.eulerFunction(BigInteger::value_of(18)), BigInteger::value_of(6));
    ASSERT_EQ(eulerFunction.eulerFunction(BigInteger::value_of(19)), BigInteger::value_of(18));

    ASSERT_EQ(eulerFunction.eulerFunction(BigInteger::value_of(20)), BigInteger::value_of(8));
    ASSERT_EQ(eulerFunction.eulerFunction(BigInteger::value_of(21)), BigInteger::value_of(12));
    ASSERT_EQ(eulerFunction.eulerFunction(BigInteger::value_of(22)), BigInteger::value_of(10));
    ASSERT_EQ(eulerFunction.eulerFunction(BigInteger::value_of(23)), BigInteger::value_of(22));
    ASSERT_EQ(eulerFunction.eulerFunction(BigInteger::value_of(24)), BigInteger::value_of(8));
    ASSERT_EQ(eulerFunction.eulerFunction(BigInteger::value_of(25)), BigInteger::value_of(20));
    ASSERT_EQ(eulerFunction.eulerFunction(BigInteger::value_of(26)), BigInteger::value_of(12));
    ASSERT_EQ(eulerFunction.eulerFunction(BigInteger::value_of(27)), BigInteger::value_of(18));
    ASSERT_EQ(eulerFunction.eulerFunction(BigInteger::value_of(28)), BigInteger::value_of(12));
    ASSERT_EQ(eulerFunction.eulerFunction(BigInteger::value_of(29)), BigInteger::value_of(28));

    ASSERT_EQ(eulerFunction.eulerFunction(BigInteger::value_of(30)), BigInteger::value_of(8));
    ASSERT_EQ(eulerFunction.eulerFunction(BigInteger::value_of(31)), BigInteger::value_of(30));
    ASSERT_EQ(eulerFunction.eulerFunction(BigInteger::value_of(32)), BigInteger::value_of(16));
    ASSERT_EQ(eulerFunction.eulerFunction(BigInteger::value_of(33)), BigInteger::value_of(20));
    ASSERT_EQ(eulerFunction.eulerFunction(BigInteger::value_of(34)), BigInteger::value_of(16));
    ASSERT_EQ(eulerFunction.eulerFunction(BigInteger::value_of(35)), BigInteger::value_of(24));
    ASSERT_EQ(eulerFunction.eulerFunction(BigInteger::value_of(36)), BigInteger::value_of(12));
    ASSERT_EQ(eulerFunction.eulerFunction(BigInteger::value_of(37)), BigInteger::value_of(36));
    ASSERT_EQ(eulerFunction.eulerFunction(BigInteger::value_of(38)), BigInteger::value_of(18));
    ASSERT_EQ(eulerFunction.eulerFunction(BigInteger::value_of(39)), BigInteger::value_of(24));
    
    ASSERT_EQ(eulerFunction.eulerFunction(BigInteger::value_of(40)), BigInteger::value_of(16));
    ASSERT_EQ(eulerFunction.eulerFunction(BigInteger::value_of(41)), BigInteger::value_of(40));
    ASSERT_EQ(eulerFunction.eulerFunction(BigInteger::value_of(42)), BigInteger::value_of(12));
    ASSERT_EQ(eulerFunction.eulerFunction(BigInteger::value_of(43)), BigInteger::value_of(42));
    ASSERT_EQ(eulerFunction.eulerFunction(BigInteger::value_of(44)), BigInteger::value_of(20));
    ASSERT_EQ(eulerFunction.eulerFunction(BigInteger::value_of(45)), BigInteger::value_of(24));
    ASSERT_EQ(eulerFunction.eulerFunction(BigInteger::value_of(46)), BigInteger::value_of(22));
    ASSERT_EQ(eulerFunction.eulerFunction(BigInteger::value_of(47)), BigInteger::value_of(46));
    ASSERT_EQ(eulerFunction.eulerFunction(BigInteger::value_of(48)), BigInteger::value_of(16));
    ASSERT_EQ(eulerFunction.eulerFunction(BigInteger::value_of(49)), BigInteger::value_of(42));
    
    ASSERT_EQ(eulerFunction.eulerFunction(BigInteger::value_of(50)), BigInteger::value_of(20));
    ASSERT_EQ(eulerFunction.eulerFunction(BigInteger::value_of(51)), BigInteger::value_of(32));
    ASSERT_EQ(eulerFunction.eulerFunction(BigInteger::value_of(52)), BigInteger::value_of(24));
    ASSERT_EQ(eulerFunction.eulerFunction(BigInteger::value_of(53)), BigInteger::value_of(52));
    ASSERT_EQ(eulerFunction.eulerFunction(BigInteger::value_of(54)), BigInteger::value_of(18));
    ASSERT_EQ(eulerFunction.eulerFunction(BigInteger::value_of(55)), BigInteger::value_of(40));
    ASSERT_EQ(eulerFunction.eulerFunction(BigInteger::value_of(56)), BigInteger::value_of(24));
    ASSERT_EQ(eulerFunction.eulerFunction(BigInteger::value_of(57)), BigInteger::value_of(36));
    ASSERT_EQ(eulerFunction.eulerFunction(BigInteger::value_of(58)), BigInteger::value_of(28));
    ASSERT_EQ(eulerFunction.eulerFunction(BigInteger::value_of(59)), BigInteger::value_of(58));
    
    ASSERT_EQ(eulerFunction.eulerFunction(BigInteger::value_of(60)), BigInteger::value_of(16));
    ASSERT_EQ(eulerFunction.eulerFunction(BigInteger::value_of(61)), BigInteger::value_of(60));
    ASSERT_EQ(eulerFunction.eulerFunction(BigInteger::value_of(62)), BigInteger::value_of(30));
    ASSERT_EQ(eulerFunction.eulerFunction(BigInteger::value_of(63)), BigInteger::value_of(36));
    ASSERT_EQ(eulerFunction.eulerFunction(BigInteger::value_of(64)), BigInteger::value_of(32));
    ASSERT_EQ(eulerFunction.eulerFunction(BigInteger::value_of(65)), BigInteger::value_of(48));
    ASSERT_EQ(eulerFunction.eulerFunction(BigInteger::value_of(66)), BigInteger::value_of(20));
    ASSERT_EQ(eulerFunction.eulerFunction(BigInteger::value_of(67)), BigInteger::value_of(66));
    ASSERT_EQ(eulerFunction.eulerFunction(BigInteger::value_of(68)), BigInteger::value_of(32));
    ASSERT_EQ(eulerFunction.eulerFunction(BigInteger::value_of(69)), BigInteger::value_of(44));
    
    ASSERT_EQ(eulerFunction.eulerFunction(BigInteger::value_of(70)), BigInteger::value_of(24));
    ASSERT_EQ(eulerFunction.eulerFunction(BigInteger::value_of(71)), BigInteger::value_of(70));
    ASSERT_EQ(eulerFunction.eulerFunction(BigInteger::value_of(72)), BigInteger::value_of(24));
    ASSERT_EQ(eulerFunction.eulerFunction(BigInteger::value_of(73)), BigInteger::value_of(72));
    ASSERT_EQ(eulerFunction.eulerFunction(BigInteger::value_of(74)), BigInteger::value_of(36));
    ASSERT_EQ(eulerFunction.eulerFunction(BigInteger::value_of(75)), BigInteger::value_of(40));
    ASSERT_EQ(eulerFunction.eulerFunction(BigInteger::value_of(76)), BigInteger::value_of(36));
    ASSERT_EQ(eulerFunction.eulerFunction(BigInteger::value_of(77)), BigInteger::value_of(60));
    ASSERT_EQ(eulerFunction.eulerFunction(BigInteger::value_of(78)), BigInteger::value_of(24));
    ASSERT_EQ(eulerFunction.eulerFunction(BigInteger::value_of(79)), BigInteger::value_of(78));
    
    ASSERT_EQ(eulerFunction.eulerFunction(BigInteger::value_of(80)), BigInteger::value_of(32));
    ASSERT_EQ(eulerFunction.eulerFunction(BigInteger::value_of(81)), BigInteger::value_of(54));
    ASSERT_EQ(eulerFunction.eulerFunction(BigInteger::value_of(82)), BigInteger::value_of(40));
    ASSERT_EQ(eulerFunction.eulerFunction(BigInteger::value_of(83)), BigInteger::value_of(82));
    ASSERT_EQ(eulerFunction.eulerFunction(BigInteger::value_of(84)), BigInteger::value_of(24));
    ASSERT_EQ(eulerFunction.eulerFunction(BigInteger::value_of(85)), BigInteger::value_of(64));
    ASSERT_EQ(eulerFunction.eulerFunction(BigInteger::value_of(86)), BigInteger::value_of(42));
    ASSERT_EQ(eulerFunction.eulerFunction(BigInteger::value_of(87)), BigInteger::value_of(56));
    ASSERT_EQ(eulerFunction.eulerFunction(BigInteger::value_of(88)), BigInteger::value_of(40));
    ASSERT_EQ(eulerFunction.eulerFunction(BigInteger::value_of(89)), BigInteger::value_of(88));
    
    ASSERT_EQ(eulerFunction.eulerFunction(BigInteger::value_of(90)), BigInteger::value_of(24));
    ASSERT_EQ(eulerFunction.eulerFunction(BigInteger::value_of(91)), BigInteger::value_of(72));
    ASSERT_EQ(eulerFunction.eulerFunction(BigInteger::value_of(92)), BigInteger::value_of(44));
    ASSERT_EQ(eulerFunction.eulerFunction(BigInteger::value_of(93)), BigInteger::value_of(60));
    ASSERT_EQ(eulerFunction.eulerFunction(BigInteger::value_of(94)), BigInteger::value_of(46));
    ASSERT_EQ(eulerFunction.eulerFunction(BigInteger::value_of(95)), BigInteger::value_of(72));
    ASSERT_EQ(eulerFunction.eulerFunction(BigInteger::value_of(96)), BigInteger::value_of(32));
    ASSERT_EQ(eulerFunction.eulerFunction(BigInteger::value_of(97)), BigInteger::value_of(96));
    ASSERT_EQ(eulerFunction.eulerFunction(BigInteger::value_of(98)), BigInteger::value_of(42));
    ASSERT_EQ(eulerFunction.eulerFunction(BigInteger::value_of(99)), BigInteger::value_of(60));
}
/*
 * \	+0	+1	+2	+3	+4	+5	+6	+7	+8	+9
0+	    	1	1	2	2	4	2	6	4	6
10+	    4	10	4	12	6	8	8	16	6	18
20+	    8	12	10	22	8	20	12	18	12	28
30+	    8	30	16	20	16	24	12	36	18	24
40+	    16	40	12	42	20	24	22	46	16	42
50+	    20	32	24	52	18	40	24	36	28	58
60+	    16	60	30	36	32	48	20	66	32	44
70+	    24	70	24	72	36	40	36	60	24	78
80+	    32	54	40	82	24	64	42	56	40	88
90+	    24	72	44	60	46	72	32	96	42	60
*/
