// c:/Users/user/Documents/Programming/Mathematics/SetTheory/DirectProduct/AffineSpace/BIT/IntervalAdd/Template/a.hpp

#pragma once
#include "../../Template/a_Macro.hpp"

// 演算がoperator+=でない場合に使用
// 可換群(T,m_T:T^2->T,e_T:1->T,i_T:T->T)と非負整数Nをパラメータとする。
template <TEMPLATE_ARGUMENTS_FOR_BIT>
class AbstractIntervalAddBIT
{
private:
  // 母関数の微分の負の階差数列（(i-1)a_{i-1} - ia_i）の管理
  AbstractBIT<T,m_T,e_T,i_T,N> m_bit_0;
  // 階差数列（a_i - a_{i-1}）の管理
  AbstractBIT<T,m_T,e_T,i_T,N> m_bit_1;

public:
  inline AbstractIntervalAddBIT();
  inline AbstractIntervalAddBIT( const T ( & a )[N] );

  // const参照でないことに注意。
  inline T Get( const int& i ) const;
  inline void Set( const int& i , const T& n );

  inline AbstractIntervalAddBIT<T,m_T,e_T,i_T,N>& operator+=( const T ( & a )[N] );
  inline void Add( const int& i , const T& n );
  inline void IntervalAdd( const int& i_start , const int& i_final , const T& n );

  inline T InitialSegmentSum( const int& i_final ) const;
  inline T IntervalSum( const int& i_start , const int& i_final ) const;

private:
  inline T prod( const T& n , int exponent ) const;
  
};
