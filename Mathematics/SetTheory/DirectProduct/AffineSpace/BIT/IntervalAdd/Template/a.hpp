// c:/Users/user/Documents/Programming/Mathematics/SetTheory/DirectProduct/AffineSpace/BIT/IntervalAdd/Template/a.hpp

#pragma once
#include "../Template/a.hpp"

// Zชoperator+=ลศข๊ษgp
// ยทQ(T,m_T:T^2->T,e_T:1->T,i_T:T->T)ฦ๑ฎN๐p[^ฦท้B
template <TEMPLATE_ARGUMENTS_FOR_BIT>
class AbstractIntervalAddBIT
{
private:
  // ๊ึฬ๗ชฬฬKท๑i(i-1)a_{i-1} - ia_ijฬว
  AbstractBIT<T,m_T,e_T,i_T,N> m_bit_0;
  // Kท๑ia_i - a_{i-1}jฬว
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
