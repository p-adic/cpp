// c:/Users/user/Documents/Programming/Mathematics/SetTheory/DirectProduct/AffineSpace/SqrtDecomposition/Template/Lazy/a.hpp

#pragma once
#include "a_Macro.hpp"
#include "../../Sqrt/a.hpp"

// 可換モノイド(T,m_T:T^2->T,e_T:1->T)とT作用付き集合(U,o_U:T×U->U)と非負整数Nをパラメータとする。
// 配列による初期化O(N)

// 一点取得O(1)（可換性を使う）

// 一点更新はなし
// o_Uによる一点更新O(1)（可換性を使う）
// o_Uによる区間更新O(N^{1/2})（可換性を使う）

template <TEMPLATE_ARGUMENTS_FOR_LAZY_SQRT_DECOMPOSITION = SqrtCalculation<N>{}.m_val >
class LazySqrtDecomposition
{

private:
  U m_a[N];
  T m_b[N_sqrt];
  static constexpr int N_d = N / N_sqrt;
  static constexpr int N_m = N_d * N_sqrt;

public:
  inline constexpr LazySqrtDecomposition( const U ( &a )[N] );

  inline constexpr U Get( const int& i ) const;

  inline constexpr void Act( const int& i , const T& n );
  inline constexpr void IntervalAct( const int& i_start , const int& i_final , const T& n );
  
};

