// c:/Users/user/Documents/Programming/Mathematics/Arithmetic/Power/GeometricProgressionSum/a.hpp

#pragma once
// verify:
// https://yukicoder.me/submissions/1015838 (GeometricProgressionLinearCombinationSum)

// 入力の範囲内で要件
// (1) Tがoperator+,operator-,operator*に関して単位的環をなす。
// (2) exponent_max >= 0である。
// (3) rate - 1は0でないならば(1)の単位的環構造に関して可逆である。
// を満たす場合にのみサポート。（T{}はGeometricProgressionLinearCombinationSumの）

// 等比数列init,init*rate,...,init*rate^exponent_maxの総和を
// O((log exponent_max)+逆元計算量)で求める。
template <typename T , typename UINT> inline T GeometricProgressionSum( T rate , UINT exponent_max , const T& init = 1 );
// 等比数列の線形和の総和を単に等比数列の総和の線形和として求める。
template <typename T , typename UINT>
T GeometricProgressionLinearCombinationSum( vector<T> rate , vector<UINT> exponent_max , const vector<T>& init );
