// c:/Users/user/Documents/Programming/Mathematics/SetTheory/DirectProduct/AffineSpace/IntervalAddBIT/a.hpp

#pragma once
#include "../BIT/a.hpp"

template <typename T , int N>
class IntervalAddBIT
{
private:
  BIT<T,N> m_bit_0;
  BIT<T,N> m_bit_1;

public:
  inline IntervalAddBIT();
  inline IntervalAddBIT( const T ( & a )[N] );

  inline IntervalAddBIT<T,N>& operator+=( const T ( & a )[N] );
  inline void Add( const int& i , const T& n );
  inline void IntervalAdd( const int& i_start , const int& i_final , const T& n );

  inline T InitialSegmentSum( const int& i_final );
  inline T IntervalSum( const int& i_start , const int& i_final );
  
};
