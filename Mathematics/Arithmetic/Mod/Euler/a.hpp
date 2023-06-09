// c:/Users/user/Documents/Programming/Mathematics/Arithmetic/Mod/Euler/a.hpp

#pragma once
#include "../../Prime/Constexpr/a.hpp"

template <typename INT> inline INT EulerFunction( const INT& n );

// 非負整数nの素因数をPに格納し、素因数の指数をexponentに格納する。
template <typename INT>
INT EulerFunction( const INT& n , vector<INT>& P , vector<INT>& exponent );
// n < val_limitの2乗 の時のみサポート。
template <typename INT , INT val_limit , int length_max>
INT EulerFunction( const PrimeEnumeration<INT,val_limit,length_max>& prime , const INT& n , vector<INT>& P , vector<INT>& exponent );

template <typename INT> inline INT CarmichaelFunction( const INT& n );

// 非負整数nの素因数をPに格納し、素因数の指数をexponentに格納し、素因数の指数乗をP_powerに格納する。
template <typename INT>
INT CarmichaelFunction( const INT& n , vector<INT>& P , vector<INT>& exponent , vector<INT>& P_power );
// n < val_limitの2乗 の時のみサポート。
template <typename INT , INT val_limit , int length_max>
INT CarmichaelFunction( const PrimeEnumeration<INT,val_limit,length_max>& prime , const INT& n , vector<INT>& P , vector<INT>& exponent , vector<INT>& P_power );

// 素因数分解の指数がexponentである非負整数とそのCarmichael関数の値を最小公倍数の素因数の指数をexponentに格納し直す。
void CarmichaelTransformation( vector<uint>& exponent );
