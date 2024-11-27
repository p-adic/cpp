// c:/Users/user/Documents/Programming/Mathematics/Arithmetic/Mod/Function/Euler/Carmichael/a.hpp

#pragma once
#include "../../../../Prime/Enumeration/a.hpp"

// 非負整数nの{カーマイケル関数の値,素因数,素因数の指数,素因数の指数乗}を返す。
// O(√n)
template <typename INT> inline tuple<INT,vector<INT>,vector<int>,vector<INT>> CarmichaelFunction( const INT& n );
// PEはPrimeEnumeration/LeastDivisorなどで、
// peがsqrt( n )以下の素数/n以下の正整数の約数を管理する時のみサポート。
// O(√n/log n)/O((log n)^2)
template <typename PE , typename INT> inline tuple<INT,vector<int>,vector<int>,vector<int>> CarmichaelFunction( const PE& pe , const INT& n );

// 素因数分解の指数がEである非負整数に対し、そのCarmichael関数の値の素因数分解の指数を返す。
template <typename INT> inline vector<INT> CarmichaelTransformation( const vector<INT>& E );
// PEはPrimeEnumerationなどで、E.size() <= pe.length()の時のみサポート。
template <typename PE , typename INT> inline vector<INT> CarmichaelTransformation( const PE& pe , const vector<INT>& E );
