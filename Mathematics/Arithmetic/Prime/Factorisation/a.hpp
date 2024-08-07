// c:/Users/user/Documents/Programming/Mathematics/Arithmetic/Prime/Factorisation/a.hpp

#pragma once

// 非負整数nの素因数をPに格納し、素因数の指数をexponentに格納する。
template <typename INT1 , typename INT2 , typename INT3> void SetPrimeFactorisation( INT1 n , vector<INT2>& P , vector<INT3>& exponent );
// sqrt( n )以下の最大の素数 < val_limit の時のみサポート。
template <typename INT , INT val_limit , int length_max , typename INT1 , typename INT2 , typename INT3> void SetPrimeFactorisation( const PrimeEnumeration<INT,val_limit,length_max>& prime , INT1 n , vector<INT2>& P , vector<INT3>& exponent );

// 非負整数nの素因数をPに格納し、素因数の指数をexponentに格納し、素因数の指数乗をP_powerに格納する。
template <typename INT1 , typename INT2 , typename INT3 , typename INT4> void SetPrimeFactorisation( INT1 n , vector<INT2>& P , vector<INT3>& exponent , vector<INT4>& P_power );
// sqrt( n )以下の最大の素数 < val_limit の時のみサポート。
template <typename INT , INT val_limit , int length_max , typename INT1 , typename INT2 , typename INT3 , typename INT4> void SetPrimeFactorisation( const PrimeEnumeration<INT,val_limit,length_max>& prime , INT1 n , vector<INT2>& P , vector<INT3>& exponent , vector<INT4>& P_power );

// 素因数を高々N個しか持たない非負整数nの素因数をPに格納し、素因数の指数をexponentに格納する。
template <typename INT1 , typename INT2 , typename INT3 , int N> void SetPrimeFactorisationBounded( INT1 n , INT2 ( &P )[N] , INT3 ( &exponent )[N] );
// 素因数を高々N個しか持たない非負整数nの素因数をPに格納し、素因数の指数をexponentに格納し、素因数の指数乗をP_powerに格納する。
template <typename INT1 , typename INT2 , typename INT3 , typename INT4 , int N> void SetPrimeFactorisationBounded( INT1 n , INT2 ( &P )[N] , INT3 ( &exponent )[N] , INT4 ( &P_power )[N] );

