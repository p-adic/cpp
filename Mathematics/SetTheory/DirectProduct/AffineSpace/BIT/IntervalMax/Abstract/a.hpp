// c:/Users/user/Documents/Programming/Mathematics/SetTheory/DirectProduct/AffineSpace/BIT/IntervalMax/Abstract/a.hpp

#pragma once
#include "a_Macro.hpp"

// verify:
// https://yukicoder.me/submissions/947873（一点加算／区間和取得）

// 演算がoperator<などで与えられている場合は特殊化ではなく
// ../a.hpp
// を使うことでファイル容量を削減する。

// 入力の範囲内で要件
// - MがUの可換羃等モノイド構造である。
// を満たす場合にのみサポート。

// 配列による初期化O(size)

// 一点取得O(1)
// LSB切片和取得O(1)（left:a[j-(j&-j)]+...+a[j-1]、right:a[j-1]+...+a[j+(j&-j)-1]）
// 区間和取得O(log_2 size)

// 一点更新O((log_2 size)^2)
// 一点加算O(log_2 size)（可換性と羃等性を用いる）
// 区間加算O(i_final-i_start+log_2 size)（可換性と羃等性を用いる）
// 全体加算O(size)（可換性と羃等性を用いる）

// uを吸収する（uに吸収される）要素の添字の最小値の二分探索O(log_2 size)
// （存在しない場合はsize以上の最小の2羃×2-1を返すので、size以上であることで判定可能）

// そのうちの区間和取得と一点更新は
// M. Dima, R. Ceterchi, Efficient Range Minimum Queries using Binary Indexed Trees, Olympiads in Informatics, 2015, Vol. 9, 39--44
// の手法を一般の可換羃等モノイドに拡張することで実装
template <typename U , typename COMM_IDEM_MONOID>
class IdempotentMonoidBIT
{
private:
  int m_size;
  COMM_IDEM_MONOID m_M;
  vector<U> m_a;
  vector<U> m_fenwick_0;
  vector<U> m_fenwick_1;
  int m_power;

public:
  inline IdempotentMonoidBIT( COMM_IDEM_MONOID M , vector<U> a = vector<U>() );

  inline void Set( vector<U>&& a );
  void Set( const int& i , const U& u );

  inline IdempotentMonoidBIT<U,COMM_IDEM_MONOID>& operator+=( vector<U>&& a );
  void Add( const int& i , const U& u );
  void IntervalAdd( const int& i_start , const int& i_final , const U& u );

  inline const int& size() const noexcept;
  inline const U& operator[]( const int& i ) const;
  inline const U& Get( const int& i ) const;
  inline const U& LSBSegmentSum( const int& j , const bool& left = true ) const;
  U IntervalSum( const int& i_start , const int& i_final );

  int BinarySearch( const U& u );
  
};
template <typename COMM_IDEM_MONOID> IdempotentMonoidBIT( COMM_IDEM_MONOID M ) -> IdempotentMonoidBIT<inner_t<COMM_IDEM_MONOID>,COMM_IDEM_MONOID>;

template <typename U>
class IntervalMinBIT :
  public IdempotentMonoidBIT<U,MinSemilattice<U>>
{

  inline IntervalMaxBIT( const U& infty_U , vector<U> a = vector<U>() );

};

template <typename U>
class IntervalMaxBIT :
  public IdempotentMonoidBIT<U,MaxSemilattice<U>>
{

  inline IntervalMaxBIT( const U& zero_U , vector<U> a = vector<U>() );

};
