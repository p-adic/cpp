// c:/Users/user/Documents/Programming/Mathematics/Combinatorial/IncreasingSubsequence/a.hpp

#pragma once
#include "a_macro.hpp"

// Tがbool operator<(const T&,const T&)に関して全順序である場合にのみサポート。

// O(size log size)でaの連続とは限らない非空単調増加部分列を数え上げる。
template <typename T> ll CountStrictlyIncreasingSubsequence( const vector<T>& a );
template <typename T> ll CountNonStrictlyIncreasingSubsequence( const vector<T>& a );
template <typename T> ll CountStrictlyIncreasingSubsequence( const vector<T>& a , const ll& mod );
template <typename T> ll CountNonStrictlyIncreasingSubsequence( const vector<T>& a , const ll& mod );

// 入力の範囲内で
// (1) bool operator<=(const T&,const T&)が等号つき全順序である。
// (2) aの成分かinftyである任意の項tに対しt <= f(t)がtrueである。
// (3) aの任意の成分tに対しt <= infty && t!=inftyがtrueである。
// が満たされる場合にのみサポート。

// O(size log size)でaの連続とは限らない非空部分列であって任意の隣接２成分s,tに対し
// f(s) <= tであるものの長さの最大値を返す。
template <typename T , T f(const T&)> int LongestIncreasingSubsequence( const vector<T>& a , const T& infty );

