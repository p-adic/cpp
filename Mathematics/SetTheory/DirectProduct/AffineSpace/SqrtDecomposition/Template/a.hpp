// c:/Users/user/Documents/Programming/Mathematics/SetTheory/DirectProduct/AffineSpace/SqrtDecomposition/Template/a.hpp

#pragma once
#include "../Sqrt/a.hpp"

// 演算がoperator+=でない場合に使用

// 可換モノイド(T,m_T:T^2->T,e_T:1->T)と非負整数Nをパラメータとする。
// 単位元による初期化O(N)

// 一点取得O(1)
// m_Tに関する区間和取得O(N^{1/2})

// 一点更新O(1)（可換性とi_Tを使う）
// m_Tによる一点更新O(1)（可換性を使う）
template <TEMPLATE_ARGUMENTS_FOR_ABSTRACT_SQRT_DECOMPOSITION = SqrtCalculation<N>{}.m_val >
class AbstractSqrtDecomposition
{

private:
  static constexpr const int N_d = ( N + N_sqrt - 1 ) / N_sqrt;
  static constexpr const int N_m = N_d * N_sqrt;
  T m_a[N_m];
  T m_b[N_d];
  
public:
  static const T& g_e;
  
  inline constexpr AbstractSqrtDecomposition();

  inline constexpr const T& operator[]( const int& i ) const;
  inline constexpr const T& Get( const int& i ) const;
  inline constexpr T IntervalSum( const int& i_start , const int& i_final );

  inline constexpr void Set( const int& i , const T& n );
  inline constexpr void Add( const int& i , const T& n );
  
};

