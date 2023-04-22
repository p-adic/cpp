// c:/Users/user/Documents/Programming/Mathematics/SetTheory/DirectProduct/AffineSpace/SqrtDecomposition/Template/Monoid/IntervalAdd/a.hpp

#pragma once
#include "../../../Sqrt/a.hpp"

// 可換モノイド(T,m_T:T^2->T,e_T:1->T)と非負整数Nをパラメータとする。
// 単位元による初期化O(N)
// 配列による初期化O(N)

// 区間和取得O(i_start - i_final)（可換性を使う）

// 乗法による一点更新O(1)（可換性を使う）
// 乗法による区間更新O(N^{1/2})（可換性を使う）

// 一点更新と区間積取得はなし

template <TEMPLATE_ARGUMENTS_FOR_INTERVAL_ADD_SQRT_DECOMPOSITION = SqrtCalculation<N>{}.m_val >
class IntervalAddSqrtDecomposition
{

private:
  T m_a[N];
  T m_b[N_sqrt];
  static constexpr int N_d = N / N_sqrt;
  static constexpr int N_m = N_d * N_sqrt;

public:
  inline constexpr IntervalAddSqrtDecomposition();
  inline constexpr IntervalAddSqrtDecomposition( const T ( &a )[N] );

  inline constexpr T IntervalSum( const int& i_start , const int& i_final ) const;

  inline constexpr void Add( const int& i , const T& n );
  inline constexpr void IntervalAdd( const int& i_start , const int& i_final , const T& n );
  
};

