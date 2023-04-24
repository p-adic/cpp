// c:/Users/user/Documents/Programming/Mathematics/SetTheory/DirectProduct/AffineSpace/SqrtDecomposition/Template/Lazy/NonCommutative/a.hpp

#pragma once
#include "../a_Macro.hpp"
#include "../../../Sqrt/a.hpp"

// （可換とも結合的とも限らない）基点付きマグマ(T,m_T:T^2->T,e_T:1->T)と基点が恒等変換に対応するT作用付き集合(U,o_U:T×U->U)と非負整数Nをパラメータとする。
// 配列による初期化O(N)

// 一点取得O(1)

// 一点更新はなし
// o_Uによる一点更新はo_Uによる区間更新で処理する（O(N^{1/2})）
// o_Uによる区間更新O(N^{1/2})
template <TEMPLATE_ARGUMENTS_FOR_LAZY_SQRT_DECOMPOSITION = SqrtCalculation<N>{}.m_val >
class NonCommutativeLazySqrtDecomposition
{

private:
  U m_a[N];
  T m_b[N_sqrt];
  static constexpr int N_d = N / N_sqrt;
  static constexpr int N_m = N_d * N_sqrt;

public:
  static const T& g_e;
  
  inline constexpr NonCommutativeLazySqrtDecomposition( const U ( &a )[N] );

  inline constexpr U Get( const int& i ) const;

  inline constexpr void IntervalAct( const int& i_start , const int& i_final , const T& n );
  
};

