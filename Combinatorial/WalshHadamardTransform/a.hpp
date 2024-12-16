// c:/Users/user/Documents/Programming/Mathematics/Combinatorial/WalshHadamardTransform/a.hpp

#pragma once

// verify:
// https://yukicoder.me/submissions/1031817 (InverseWalshHadamardTransform,AbstractTwistedWalshHadamardTransform)

// 以下f.size()をsizeと置く。

// f[i]を{a_i,b_i,c_i}と置き、群環T[Z/order Z]におけるsum_{j in [0,order)} 1[j]をtrと置き、
// prod_{i<size} (a_i * tr + b_i * [c_i])をO(size)で求める。
template <typename T , typename INT> tuple<T,T,INT> AffineTraceProduct( const vector<tuple<T,T,INT>>& f , const INT& order );

// f[i]を{a_i,b_i,c_i}と置き、
// (prod_{i<size}(2^digit*a_i+(-1)^{popcount(c_i&j)}b_i))_{j<2^digit}
// をO(size+2^digit)で求める。
template <typename T> vector<T> AffineShiftProduct( const vector<tuple<T,T,int>>& f , const int digit );

// size <= 2^digitとする。fのWalsh-Hadamard変換
// (sum_{i<size} (-1)^{popcount(i&j)} f[i])_{j<2^digit}
// をO(digit 2^{digit})で計算する。
template <typename T> vector<T> WalshHadamardTransform( vector<T> f , const int& digit );
template <typename T> vector<T> InverseWalshHadamardTransform( vector<T> f , const int& digit );

// size <= 2^digitとし、f[i]を(a_i,b_i)と置く。fの乗法的Walsh-Hadamard変換
// ((prod_{i<size}(popcount(i&j)&1==b?a[i]:b[i]))_{b<2)_{j<2^digit}
// をO(digit 2^{digit})で計算する。
template <typename COMM_SEMIGRP , typename T> vector<pair<T,T>> AbstractWalshHadamardTransform( COMM_SEMIGRP M , vector<pair<T,T>> f , const int& digit );

// f[i]を{a_i,b_i,c_i}と置き、0<=c_i<2^digitとし、
// ((prod_{i<size}(popcount(c_i&j)&1==b?a[i]:b[i]))_{b<2)_{j<2^digit}
// をO(size+digit 2^{digit})で計算する。
template <typename COMM_SEMIGRP , typename T> vector<pair<T,T>> AbstractTwistedWalshHadamardTransform( COMM_SEMIGRP M , vector<tuple<T,T,int>> f , const int& digit );
