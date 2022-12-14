// c:/Users/user/Documents/Programming/Mathematics/SetTheory/DirectProduct/AffineSpace/IntervalMaxBIT/a.hpp

#pragma once

template <typename T , int N>
class IntervalMaxBIT
{
private:
  T m_init;
  T m_fenwick_0[N + 1];
  T m_fenwick_1[N + 1];
  // 最小値を扱う時はfalseにする
  bool m_for_max;

public:
  // 負の数も扱えるようにnで初期化
  inline IntervalMaxBIT( const T& n , const bool& for_max = true );

  // １点のみにmax演算子を作用させる
  void SetMax( const int& i , const T& n );

  T IntervalMax( const int& i_start , const int& i_final );
  
};

