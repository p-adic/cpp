// c:/Users/user/Documents/Programming/Mathematics/Arithmetic/Sqrt/a.hpp

#pragma once
#include "a.hpp"

// √nを超えない最大の整数をO(log n)で計算する。
template <typename INT> INT RoundDownSqrt( const INT& n );
// INT = long longの場合のINT(std::sqrt(n))に誤差が出るケース：
// (n,RondDownSqrt(n)^2,INT(std::sqrt(n),RondDownSqrt(n),) =
// 57337544294423649 57337544294423649 239452592 239452593
// 229350177177694596 229350177177694596 478905185 478905186
// 3667470396035093041 3667470396035093041 1915064070 1915064071
// 3667470396035093... 3667470396035093041 1915064070 1915064071
// 3667470396035093247 3667470396035093041 1915064070 1915064071

// √nを以上の最小の整数をO(log n)で計算する。
template <typename INT> INT RoundUpSqrt( const INT& n );

// 素数法の平方根は
// ../Mod/Function/QuadraticResidu/TonelliShanks/
// に実装。
