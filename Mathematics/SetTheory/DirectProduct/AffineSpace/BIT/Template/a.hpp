// c:/Users/user/Documents/Programming/Mathematics/SetTheory/DirectProduct/AffineSpace/BIT/Template/a.hpp

#pragma once
#include "a_Macro.hpp"

// 可換群(T,m_T:T^2->T,e_T:1->T,i_T:T->T)と非負整数Nをパラメータとする。
template <TEMPLETE_ARGUMENTS_FOR_BIT>
class AbstractBIT
{
private:
  T m_fenwick[N + 1];
  
public:
  static const T& g_e;

  inline AbstractBIT();
  inline AbstractBIT( const T ( & a )[N] );

  inline void Set( const int& i , const T& n );

  inline AbstractBIT<T,m_T,e_T,i_T,N>& operator+=( const T ( & a )[N] );
  void Add( const int& i , const T& n );

  T InitialSegmentSum( const int& i_final );
  inline T IntervalSum( const int& i_start , const int& i_final );
  
};
