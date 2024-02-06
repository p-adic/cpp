// c:/Users/user/Documents/Programming/Mathematics/SetTheory/DirectProduct/AffineSpace/BIT/IntervalAdd/a.hpp

#pragma once
#include "../a.hpp"

// verify:
// https://yukicoder.me/submissions/948000（零初期化、一点加算、区間加算、一点取得）

// 使用演算：
// U& U::operator=( const U& )（BITそのものに使用）
// U& U::operator+=( const U& )
// U& operator+( const U& , const U& )
// U operator-( const U& )
// U operator-( const U& , const U& )

// U()による初期化O(size)
// 配列による初期化O(size)

// 一点取得O(log_2 size)
// 始切片和取得O(log_2 size)
// 区間和取得O(log_2 size)

// 一点更新O(log_2 size)
// +による一点更新O(log_2 size)
// +による区間更新O(log_2 size)
// 配列の加算による全体更新O(size)
template <typename U>
class IntervalAddBIT
{
private:
  // 母関数の微分の負の階差数列（(i-1)a_{i-1} - ia_i）の管理
  BIT<U> m_bit_0;
  // 階差数列（a_i - a_{i-1}）の管理
  BIT<U> m_bit_1;

public:
  inline IntervalAddBIT( const int& size = 0 );
  inline IntervalAddBIT( const vector<U>& a );

  inline IntervalAddBIT<U>& operator=( IntervalAddBIT<U>&& a );

  inline void Set( const int& i , const U& u );
  inline void Set( const vector<U>& a );
  inline void Initialise( const int& size = 0 );

  inline IntervalAddBIT<U>& operator+=( const vector<U>& a );
  inline void Add( const int& i , const U& u );
  // max(0,i_start)<=i<=min(N-1,i_final)を満たすiに対し各第i成分にuを足す。
  inline void IntervalAdd( const int& i_start , const int& i_final , const U& u );

  inline const int& size() const noexcept;
  // const参照でないことに注意。
  inline U operator[]( const int& i ) const;
  inline U Get( const int& i ) const;
  inline U InitialSegmentSum( const int& i_final ) const;
  inline U IntervalSum( const int& i_start , const int& i_final ) const;
  
};
