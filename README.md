# Сrypto
C++ long arithmetic implementation and various numerical algorithms as well as ElGamal cryptosystem.

## Long arithmetic

The `arithmetic` module provides an easy-to-use interface for log arithmetic calculations. 
The `BigInteger` has following constructors

```
BigInteger()            initializes object to represent 0
BigInteger(string)      initializes object to a numeric value represented by string parameter
```

Once a number object is created, it can be used in arithmetical expressions
both with other objects of the type as well as primitive numerical values due
to implicit type conversion.

## Algorithms

Example of usage:

```
PollardsRhoFactorization factorization;     create algorithm object
factorization.factorize(BigInteger)         returns vector of prime factors
```

Currently supported algorithms for the following problems

- Discrete logarithm problem (baby step gigian step)
- Chinese remainder problem
- Discrete square root (Cipolla`s algorithm)
- Primality test (Soloway-Strassen algorithm)
- Computing GCD
- Computing extended GCD
- Computing Euler function 
- Computing Mobius function 
- Computing Jacobian symbol 
- Computing Legendre symbol 
- Finding sequence loop (Floyd algorithm)

