// c:/Users/user/Documents/Programming/Mathematics/Arithmetic/Power/Constexpr/Inverse/a.hpp

#pragma once

// 2^16 = 65536
// 2^17 = 131072
// 2^18 = 262144

// N以上である最小の2羃をコンパイル時計算する。
template <int N>
class PowerInverse_constexpr
{
public:
  int m_val;
  inline constexpr PowerInverse_constexpr();
};
