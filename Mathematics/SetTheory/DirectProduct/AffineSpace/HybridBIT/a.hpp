// c:/Users/user/Documents/Programming/Mathematics/SetTheory/DirectProduct/AffineSpace/HybridBIT/a.hpp

#pragma once

//  InitialSegmentSumで負の入力を扱うためにintをテンプレート引数にする。
template <typename T , int N>
class HybridBIT
{
private:
  T[N] m_a;
  T[N + 1] m_fenwick;

public:
  inline HybridBIT();
  inline HybridBIT( const T ( & a )[N] );
  inline const T& operator[]( const int& i ) const;

  inline HybridBIT& operator+=( const T ( & a )[N] );
  void Add( const int& i , const T& n );

  T InitialSegmentSum( const int& i_final );
  inline T IntervalSum( const int& i_start , const int& i_final );
  
};

