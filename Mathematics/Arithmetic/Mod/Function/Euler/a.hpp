// c:/Users/user/Documents/Programming/Mathematics/Arithmetic/Mod/Function/Euler/a.hpp

#pragma once
#include "../../../Prime/Constexpr/a.hpp"

// 非負整数nの{オイラー関数の値,素因数,素因数の指数}を返す。（O(√n)）
template <typename INT> inline tuple<INT,vector<INT>,vector<int>> EulerFunction( const INT& n );
// n < val_limitの2乗 の時のみサポート。（O(π(√n)+log n)）
template <typename INT1 , INT1 val_limit , int length_max , typename INT2> inline tuple<INT2,vector<INT1>,vector<int>> EulerFunction( const PrimeEnumeration<INT1,val_limit,length_max>& pe , const INT2& n ;

// n_max <= val_limitの2乗 の時のみサポート。（O(π(√n_max) + n_max log n_max)）
template <typename INT1 , INT1 val_limit , int length_max , int size , typename INT2> vector<INT2> TotalEulerFunction( const PrimeEnumeration<INT1,val_limit,length_max>& pe , const INT2& n_max )
