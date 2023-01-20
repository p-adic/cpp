// c:/Users/user/Documents/Programming/Mathematics/Arithmetic/Prime/a.hpp

#pragma once
#include <vector>

// 1+i番目の素数を返す
template <typename INT> const INT& GetPrime( const INT& i ) noexcept;

// i<Nの時に1+i番目の素数を返す
template <typename INT , INT N> const INT& GetPrimeBounded( const INT& i );

// 非負整数nの素因数をPに格納し、素因数の指数をexponentに格納する。
template <typename INT> void SetPrimeFactorisation( const INT& n , vector<INT>& P , vector<INT>& exponent );
// 非負整数nの素因数をPに格納し、素因数の指数をexponentに格納し、素因数の指数乗をP_powerに格納する。
template <typename INT> void SetPrimeFactorisation( const INT& n , vector<INT>& P , vector<INT>& exponent , vector<INT>& P_power );

// 素因数を高々N個しか持たない非負整数nの素因数をPに格納し、素因数の指数をexponentに格納する。
template <typename INT , INT N> void SetPrimeFactorisationBounded( const INT& n , INT ( &P )[N] , INT ( &exponent )[N] );
// 素因数を高々N個しか持たない非負整数nの素因数をPに格納し、素因数の指数をexponentに格納し、素因数の指数乗をP_powerに格納する。
template <typename INT , INT N> void SetPrimeFactorisationBounded( const INT& n , INT ( &P )[N] , INT ( &exponent )[N] , INT ( &P_power )[N] );

// GCDやLCMは../Mod/CRT/a_Body.hppで定義
