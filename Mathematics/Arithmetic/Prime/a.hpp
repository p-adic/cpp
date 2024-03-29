// c:/Users/user/Documents/Programming/Mathematics/Arithmetic/Prime/a.hpp

#pragma once
#include "Constexpr/a.hpp"

#include <vector>

// 1+i番目の素数を返す
template <typename INT> const INT& GetPrime( const INT& i ) noexcept;

// i<Nの時に1+i番目の素数を返す
template <typename INT , INT N> const INT& GetPrimeBounded( const INT& i );

// 非負整数nの素因数をPに格納し、素因数の指数をexponentに格納する。
template <typename INT1 , typename INT2 , typename INT3> void SetPrimeFactorisation( const INT1& n , vector<INT2>& P , vector<INT3>& exponent );
// sqrt( n )以下の最大の素数 < val_limit の時のみサポート。
template <typename INT , INT val_limit , int length_max , typename INT1 , typename INT2 , typename INT3> void SetPrimeFactorisation( const PrimeEnumeration<INT,val_limit,length_max>& prime , const INT1& n , vector<INT2>& P , vector<INT3>& exponent );

// 非負整数nの素因数をPに格納し、素因数の指数をexponentに格納し、素因数の指数乗をP_powerに格納する。
template <typename INT1 , typename INT2 , typename INT3 , typename INT4> void SetPrimeFactorisation( const INT1& n , vector<INT2>& P , vector<INT3>& exponent , vector<INT4>& P_power );
// sqrt( n )以下の最大の素数 < val_limit の時のみサポート。
template <typename INT , INT val_limit , int length_max , typename INT1 , typename INT2 , typename INT3> void SetPrimeFactorisation( const PrimeEnumeration<INT,val_limit,length_max>& prime , const INT1& n , vector<INT2>& P , vector<INT3>& exponent , vector<INT4>& P_power );

// 素因数を高々N個しか持たない非負整数nの素因数をPに格納し、素因数の指数をexponentに格納する。
template <typename INT1 , typename INT2 , typename INT3 , int N> void SetPrimeFactorisationBounded( const INT1& n , INT2 ( &P )[N] , INT3 ( &exponent )[N] );
// 素因数を高々N個しか持たない非負整数nの素因数をPに格納し、素因数の指数をexponentに格納し、素因数の指数乗をP_powerに格納する。
template <typename INT1 , typename INT2 , typename INT3 , typename INT4 , int N> void SetPrimeFactorisationBounded( const INT1& n , INT2 ( &P )[N] , INT3 ( &exponent )[N] , INT4 ( &P_power )[N] );

// GCDやLCMはDivisor/GCD/a_Body.hppで定義
