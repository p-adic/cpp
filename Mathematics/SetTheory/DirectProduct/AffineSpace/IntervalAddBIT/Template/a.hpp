// c:/Users/user/Documents/Programming/Mathematics/SetTheory/DirectProduct/AffineSpace/IntervalAddBIT/Template/a.hpp

#pragma once
#include "../BIT/Template/a.hpp"

template <TEMPLETE_ARGUMENTS_FOR_BIT>
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

  inline void Set( const int& i , const T& n );

  inline AbstractIntervalAddBIT<T,m_T,e_T,i_T,N>& operator+=( const T ( & a )[N] );
  inline void Add( const int& i , const T& n );
  inline void IntervalAdd( const int& i_start , const int& i_final , const T& n );

  inline T InitialSegmentSum( const int& i_final );
  inline T IntervalSum( const int& i_start , const int& i_final );

private:
  inline T prod( const T& n , int exponent );
  
};
