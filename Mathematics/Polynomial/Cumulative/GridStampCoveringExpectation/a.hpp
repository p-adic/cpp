// c:/Users/user/Documents/Programming/Mathematics/Polynomial/Cumulative/GridStampCoveringExpectation/a.hpp

#pragma once

// verify:
// https://yukicoder.me/submissions/963393（H,W<998244353,X,Y<=1e3,N<=1e9）
// https://yukicoder.me/submissions/963394（H,W,X,Y<2e5,N=2）

// H×Wの白色グリッドでX×Yの領域を一様ランダムにN回選び黒色に塗り潰す時の黒色マスの個数の期待値を
// https://yukicoder.me/problems/no/2457/editorial
// をもとにO(min(XY,N^2)log_2 N)で計算。
template <typename T> inline T GridStampCoveringExpectation( const int& H ,  const int& W ,  const int& X ,  const int& Y , const ull& N );
