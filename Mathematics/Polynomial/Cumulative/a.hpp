// c:/Users/user/Documents/Programming/Mathematics/Polynomial/Cumulative/a.hpp

#pragma once
#include "a_Macro.hpp"
#include "../a.hpp"

// 以下D = 次数の上限、L = fの長さ、N = 打ち切り次数（D<N）とする。

// 多項式の総和(O(DL))
template <typename T , template <typename...> typename V> Polynomial<T>& Sum( V<Polynomial<T>>& f );

// 有理式の総和（O(DL(log DL)^2)）
template <typename T , template <typename...> typename V> pair<Polynomial<T>,Polynomial<T>>& RationalSum( V<pair<Polynomial<T>,Polynomial<T>>>& f );
// 有理式の総和のN次で打ち切りO(DL(log N)(1+log N/D))
template <typename T , template <typename...> typename V> V<pair<TruncatedPolynomial<T>,TruncatedPolynomial<T>>>& RationalSum( V<pair<TruncatedPolynomial<T>,TruncatedPolynomial<T>>>& f );

// 多項式の総乗（O(DL(log DL)^2)）
template <typename T , template <typename...> typename V> Polynomial<T>& Prod( V<Polynomial<T>>& f );
// 多項式の総乗のN次で打ち切り（O(DL(log N)(1+log N/D))）
template <typename T , template <typename...> typename V>TruncatedPolynomial<T>& Prod( V<TruncatedPolynomial<T>>& f );

// 多項式のe乗（O(De(log De)^2)）
template <typename T> inline Polynomial<T> Power( const Polynomial<T>& f , const uint& e );
// Tが標数0またはN以上の体でかつf[0] == 1の場合に多項式のt乗のN次打ち切り。
template <typename T> inline TruncatedPolynomial<T> Power( const TruncatedPolynomial<T>& f , const T& t );
// Tが標数0またはf.m_N以上の体の場合に多項式のe乗のN次打ち切り。
template <typename T> TruncatedPolynomial<T> Power( const TruncatedPolynomial<T>& f , const uint& e );


// a exp(bx)の総和をN次打ち切り（O(L(log N)^2 + N(log N))）
template <typename T , template <typename...> typename V> TruncatedPolynomial<T> ExponentialSum( const uint& N , const V<pair<T,T>>& coef );

// f(x)の累積和多項式f(0)+...+f(x)（O(D log D)）
// Lain, https://codeforces.com/blog/entry/98563, Lain's blog, Codeforces, 2021.
// をもとに実装
template <typename T , uint deg_max> Polynomial<T> CumulativeSum( Polynomial<T> f , const bool& exponential = false );
