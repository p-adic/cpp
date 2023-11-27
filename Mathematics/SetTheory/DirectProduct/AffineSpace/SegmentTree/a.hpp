// c:/Users/user/Documents/Programming/Mathematics/SetTheory/DirectProduct/AffineSpace/SegmentTree/a.hpp

#pragma once
#include "a_Macro.hpp"

#include "../../../../Arithmetic/Power/Constexpr/Inverse/a.hpp"

// verify: https://yukicoder.me/submissions/932066

// （可換とは限らない）モノイド(T,m_T:T^2->T,e_T:1->T)と非負整数Nをパラメータとする。
// 単位元による初期化O(N)
// 配列による初期化O(N)

// 一点取得O(1)
// 区間積取得O(log_2 N)

// 一点更新O(log_2 N)
template <TEMPLATE_ARGUMENTS_FOR_SEGMENT_TREE>
class SegmentTree
{
private:
  static constexpr const int g_power = PowerInverse_constexpr<N>{}.m_val;
  static constexpr const int g_power2 = g_power << 1;
  T m_a[g_power2];

public:
  static const T& g_e;

  inline SegmentTree();
  inline SegmentTree( const T ( &a )[N] );

  inline const T& operator[]( const int& i ) const;
  inline const T& Get( const int& i ) const;
  T IntervalProduct( const int& i_start , const int& i_final );

  void Set( const int& i , const T& n );

};
