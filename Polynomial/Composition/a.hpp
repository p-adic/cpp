// c:/Users/user/Documents/Programming/Mathematics/Polynomial/Composition/a.hpp

#pragma once
#include "../a.hpp"

// verify:
// https://judge.yosupo.jp/submission/176829 平行移動
// https://yukicoder.me/submissions/938613 メビウス変換

// 以下次数の上限をDとし、断りのない限り乗算の計算量をO(D log D)とする。

// 一般の合成f(g(x))（乗算がO(D^2)ならO(D^{5/2})、O(D log D)ならO(D^2)）
// R. P. Brent and H. T. Kung, Fast Algorithms for Manipulating Formal Power Series, Journal of the Association for Computing Machinery, Vol. 25, No. 4 (1978), pp 581--595.
// をもとに実装。
template <typename T> TruncatedPolynomial<T> Composite( const TruncatedPolynomial<T>& f  , const TruncatedPolynomial<T>& g );

// fをN-1次までで打ち切ったgの反転g(x^{-1})*x^{N-1}（O(D+N)）
template <typename T> void TruncatedReverse( const unt& N , Polynomial<T>& f );
// 平行移動f(x+t)（O(D log D)）
template <typename T> void Shift( Polynomial<T>& f , const T& t , const bool& exponential = false );
// アフィン変換f(tx+u)（O(D log D)）
template <typename T> void AffineTransformation( Polynomial<T>& f , const T& t , const T& u = Polynomial<T>::c_zero() , const bool& exponential = false );
// メビウス変換f((ax+b)/(cx+d))をh(x)/(ux+v)^eの形で表示して{h,u,v,e}を返す。（O((D log D))）
template <typename T> tuple<Polynomial<T>,T,T,uint> MoeviusComposition( Polynomial<T> f , T a , T b , T c , T d );
// メビウス変換f((ax+b)/(cx+d))をN次で打ち切る（O(D(log D)+N(log N))）
template <typename T> TrucatedPolynomial<T> MoeviusComposition( const uint& N , Polynomial<T> f , T a , T b , T c , T d );

// 合成f(exp(tx))をN次で打ち切る（O(D(log N)^2 + N(log N))）
template <typename T> TruncatedPolynomial<T> ExponentialComposition( const uint& N , const Polynomial<T>& f , const T& t );
// 合成f((a exp(tx)+b)/(c exp(tx) + d))をN次で打ち切る（O(D((log D)+(log N)^2) + N(log N))）
template <typename T> TruncatedPolynomial<T> MoeviusExponentialComposition( const uint& N , const Polynomial<T>& f , T a , T b , T c , T d , const T& t );

// 合成f(t log(1+x))をN次で打ち切る（O(O((D+N)(log (D+N))^2))）
template <typename T> TruncatedPolynomial<T> LogarithmComposition( const uint& N , Polynomial<T> f , const T& t );
// b==d!=0の場合に合成f(t log((ax+b)/(cx+d)))をN次で打ち切る（O(O((D+N)(log (D+Nx))^2))）
template <typename T> TruncatedPolynomial<T> LogarithmComposition( const uint& N , Polynomial<T> f , T a , T b , T c , const T& t );
