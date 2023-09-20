// c:/Users/user/Documents/Programming/Mathematics/SetTheory/DirectProduct/AffineSpace/BIT/IntervalAdd/a.hpp

#pragma once
#include "../BIT/a.hpp"

// verify: https://yukicoder.me/submissions/910789

// 使用演算：
// T& T::operator=( const T& )（BITそのものに使用）
// T& T::operator+=( const T& )
// T& operator+( const T& , const T& )
// T operator-( const T& )
// T operator-( const T& , const T& )
template <typename T , int N>
class IntervalAddBIT
{
private:
  // 母関数の微分の負の階差数列（(i-1)a_{i-1} - ia_i）の管理
  BIT<T,N> m_bit_0;
  // 階差数列（a_i - a_{i-1}）の管理
  BIT<T,N> m_bit_1;

public:
  inline IntervalAddBIT();
  inline IntervalAddBIT( const T ( &a )[N] );

  // const参照でないことに注意。
  inline T Get( const int& i ) const;
  inline void Set( const int& i , const T& n );
  inline void Set( const T ( &a )[N] );
  inline void Initialise();

  inline IntervalAddBIT<T,N>& operator+=( const T ( & a )[N] );
  // 0<=i<Nの場合は第i成分にnを足し、そうでない場合は何もしない。
  inline void Add( const int& i , const T& n );
  // max(0,i_start)<=i<=min(N-1,i_final)を満たすiに対し各第i成分にnを足す。
  inline void IntervalAdd( const int& i_start , const int& i_final , const T& n );

  inline T InitialSegmentSum( const int& i_final ) const;
  inline T IntervalSum( const int& i_start , const int& i_final ) const;
  
};
