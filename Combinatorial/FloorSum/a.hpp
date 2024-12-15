// c:/Users/user/Documents/Programming/Mathematics/Combinatorial/FloorSum/a.hpp

#pragma once

// verify:
// https://atcoder.jp/contests/practice2/submissions/44638653 (FloorSum)
// https://atcoder.jp/contests/abc230/submissions/57700207 (HarmonicFloorSum)
// https://yukicoder.me/submissions/1009595 (HarmonicFloorSum)

// e=0.1と置いた時、xy平面内の４点(0,0),(0,y/q),(n-e,(y+d*(n-e))/q)),(n-e,0)を結ぶ
// 台形内の格子点の個数
// sum( int i = 0 ; i < n ; i++ ){ ( y + d * i ) / q }
// をO(log_2 min(d,q))で求める。
template <typename INT> INT FloorSum( const INT& y , const INT& d , const INT& q , const INT& n );

// n >= 0かつexponent >= 0の時
// sum( int i = 1 ; i <= n ; i++ ){ ( n / i ) ^ exponent }
// をO(√n)で求める。
template <typename INT> inline INT FloorRiemannZeta( const INT& n , const INT& exponent );

// sum( int i = 1 ; i <= n ; i++ ){ ( n / i ) }
// をO(√|n|)で求める。特にn>=0の時、xy平面内の第1象限（軸含まず）でxy<=nを満たす格子点(x,y)の
// 個数と一致する。
template <typename INT> inline INT HarmonicFloorSum( const INT& n );

