// c:/Users/user/Documents/Programming/Mathematics/Arithmetic/Mod/Function/Euler/a.hpp

#pragma once
#include "../../../Prime/Enumeration/a.hpp"

// 非負整数nの{オイラー関数の値,素因数,素因数の指数}を返す。
// O(√n)
template <typename INT> inline tuple<INT,vector<INT>,vector<int>> EulerFunction( const INT& n );
// PEはPrimeEnumeration/LeastDivisorなどで、
// peがsqrt( n )以下の素数/n以下の正整数の約数を管理する時のみサポート。
// O(√n/log n)/O(log n)
template <typename PE , typename INT> inline tuple<INT,vector<int>,vector<int>> EulerFunction( const PE& pe , const INT& n );

// PEはPrimeEnumerationなどで、peがsqrt( n_max )以下の素数を管理する時のみサポート。
// O(n_max log n_max)
template <typename PE , typename INT> vector<INT> TotalEulerFunction( const PE& pe , const INT& n_max );
// LDを使って毎回EulerFunctionを計算する場合と計算量は同じ。
