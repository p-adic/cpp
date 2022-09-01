// c:/Users/user/Documents/Programming/Mathematics/Arithmetic/Prime/a.hpp

#pragma once
#include <vector>

// 1+i番目の素数を返す
const uint& GetPrime( const uint& i ) noexcept;

// i<Nの時に1+i番目の素数を返す
template <uint N>
const uint& GetPrimeBounded( const uint& i );

// 非負整数nの素因数をPに格納し、素因数の指数をexponentに格納する。
void SetPrimeFactorisation( const uint& n , vector<uint>& P , vector<uint>& exponent );

// 素因数を高々N個しか持たない非負整数nの素因数をPに格納し、素因数の指数をexponentに格納する。
template <uint N>
void SGetPrimeFactorisationBounded( const uint& n , uint ( &P )[N] , uint ( &exponent )[N] );

// 1+i番目の素数以上の相異なる素数有限個の和で表せない最小の非負整数を返す
uint GetKloveSequence( const uint& i ) noexcept;
