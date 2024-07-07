// c:/Users/user/Documents/Programming/Mathematics/Arithmetic/Sqrt/a.hpp

#pragma once
#include "a.hpp"

// √nを超えない最大の整数をO(n)で計算する。
template <typename INT> INT RoundDownSqrt( const INT& n );

// √nを以上の最小の整数をO(n)で計算する。
template <typename INT> INT RoundUpSqrt( const INT& n );
