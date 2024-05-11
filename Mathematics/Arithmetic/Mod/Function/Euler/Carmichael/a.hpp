// c:/Users/user/Documents/Programming/Mathematics/Arithmetic/Mod/Function/Euler/Carmichael/a.hpp

#pragma once
#include "../../../../Prime/Constexpr/a.hpp"

// 非負整数nの{カーマイケル関数の値,素因数,素因数の指数,素因数の指数乗}を返す。
template <typename INT> inline tuple<INT,vector<INT>,vector<int>,vector<INT>> CarmichaelFunction( const INT& n );
// n < val_limitの2乗 の時のみサポート。
template <typename INT1 , INT1 val_limit , int length_max> inline tuple<INT2,vector<INT1>,vector<int>,vector<INT1>> CarmichaelFunction( const PrimeEnumeration<INT1,val_limit,length_max>& pe , const INT2& n );

// 素因数分解の指数がEである非負整数に対し、そのCarmichael関数の値の素因数分解の指数を返す。
template <typename INT> inline vector<INT> CarmichaelTransformation( const vector<INT>& E );
// E.size() <= length_maxである場合にのみサポート。
template <typename INT1 , INT1 val_limit , int length_max , typename INT2> inline vector<INT2> CarmichaelFunction( const PrimeEnumeration<INT1,val_limit,length_max>& pe , const vector<INT2>& E );
