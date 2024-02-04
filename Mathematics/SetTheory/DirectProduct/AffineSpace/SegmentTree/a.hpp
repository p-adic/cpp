// c:/Users/user/Documents/Programming/Mathematics/SetTheory/DirectProduct/AffineSpace/SegmentTree/a.hpp

#pragma once
#include "../../../../Algebra/Monoid/a.hpp"

// verify:
// https://yukicoder.me/submissions/947853（AbstractSegtree、配列による初期化、一点更新、区間積取得）
// https://yukicoder.me/submissions/947852（Segtree、配列による初期化、一点更新、区間積取得）

// M.One()による初期化O(size)
// 配列による初期化O(N)

// 一点更新O(log_2 N)

// 一点取得O(1)
// 区間積取得O(log_2 N)
template <typename U , typename MONOID>
class AbstractSegmentTree
{
private:
  int m_size;
  int m_power;
  MONOID m_M;
  vector<U> m_a;

public:
  inline AbstractSegmentTree( MONOID M );
  inline AbstractSegmentTree( MONOID M , const vector<U>& a );

  inline void Set( const vector<U>& a );
  void Set( const int& i , const U& u );

  inline const U& operator[]( const int& i ) const;
  inline const U& Get( const int& i ) const;
  U IntervalProduct( const int& i_start , const int& i_final );

};
template <typename MONOID> AbstractSegmentTree( MONOID M ) -> AbstractSegmentTree<inner_t<MONOID>,MONOID>;

template <typename U>
class SegmentTree :
  public AbstractSegmentTree<U,MultiplicativeMonoid<U>>
{

public:
  template <typename...Args> inline SegmentTree( const U& one_U , const Args&... args );

};
