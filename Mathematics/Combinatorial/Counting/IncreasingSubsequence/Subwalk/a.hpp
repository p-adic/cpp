// c:/Users/user/Documents/Programming/Mathematics/Combinatorial/Counting/IncreasingSubsequence/Subwalk/a.hpp

#pragma once
#include "a_macro.hpp"

// O(|E_inv| log V)でaの連続とは限らない非空部分列であって任意の隣接２成分がE_invの定める有向辺の
// 逆向きの有向辺で結ばれるものを数え上げる。
template <typename T , list<T> E_inv(const T&) , int V_max> ll CountSubwalk( const T ( &a )[V_max] , const int& V );
template <typename T , list<T> E_inv(const T&) , int V_max> ll CountSubwalk( const T ( &a )[V_max] , const int& V , const ll& mod );


// O((V + |E_inv|) log V)でaの連続とは限らない非空部分列であって任意の隣接２成分がE_invの定める有向辺の
// 逆向きの有向辺で結ばれるものの長さの最大値を返す。
template <typename T , list<T> E_inv(const T&) , int V_max> int LongestSubwalk( const T ( &a )[V_max] , const int& V );

