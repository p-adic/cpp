// c:/Users/user/Documents/Programming/Mathematics/SetTheory/DirectProduct/AffineSpace/SqrtDecomposition/Template/LazyEvaluation/a.hpp

#pragma once
#include "a_Macro.hpp"
#include "../../Sqrt/a.hpp"

// （結合的とも単位的とも可換とも限らない）基点付きマグマ(T,m_T:T^2->T,e_T:1->T)と
// （可換とは限らない）モノイド(U,m_U:U^2->U,e_U:1->U)と
// 基点が恒等変換に対応するT作用(o_U:T×U->U)と非負整数Nをパラメータとする。

// e_Uによる初期化O(N)
// 配列による初期化O(N)

// 一点取得O(1)
// 区間積取得O(min(i_final-i_start+1,N^{1/2}))（Uのモノイド性を使う）

// 一点更新O(N^{1/2})（区間更新とオーダーは同じだが定数倍良い）
// １つの代入値による区間更新O(N^{1/2})

// o_Uによる一点更新はなし。
// o_Uによる区間更新O(N^{1/2})
template <TEMPLATE_ARGUMENTS_FOR_LAZY_SQRT_DECOMPOSITION = SqrtCalculation<N>{}.m_val >
class LazySqrtDecomposition
{

private:
  static constexpr const int N_d = ( N + N_sqrt - 1 ) / N_sqrt;
  static constexpr const int N_m = N_d * N_sqrt;
  U m_a[N_m];
  U m_b[N_d];
  U m_lazy_substitution[N_d];
  bool m_suspended[N_d];
  T m_lazy_action[N_d];

public:
  static const T& g_e_T;
  static const U& g_e_U;
  
  inline constexpr LazySqrtDecomposition();
  inline constexpr LazySqrtDecomposition( const U ( &a )[N] );

  inline constexpr U Get( const int& i ) const;
  inline constexpr U IntervalProd( const int& i_start , const int& i_final ) const;

  inline constexpr void Set( const int& i , const U& u );
  inline constexpr void IntervalSet( const int& i_start , const int& i_final , const U& u );
  inline constexpr void IntervalAct( const int& i_start , const int& i_final , const T& t );

  static inline constexpr U Power( const U& u , int exponent );

private:
  inline constexpr U IntervalProd_Body( const int& i_min , const int& i_ulim ) const;

  inline constexpr void SetProd( const int& i );
  inline constexpr void SolveSuspension( const int& d , const U& う );
  inline constexpr void IntervalSet_Body( const int& i_min , const int& i_ulim , const TU& t );
  inline constexpr void IntervalAct_Body( const int& i_min , const int& i_ulim , const T& t );
  
};

