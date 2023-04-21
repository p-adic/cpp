// c:/Users/user/Documents/Programming/Mathematics/SetTheory/DirectProduct/AffineSpace/BIT/IntervalMaxBIT/Template/a.hpp

#pragma once
#include "a_Macro.hpp"

// 可換羃等モノイド(T,m_T:T^2->T,e_T:1->T)と非負整数Nをパラメータとする。
// 単位元による初期化O(N)
// 配列による初期化O(N)

// 一点取得O(1)
// 区間和取得O(log_2 N)

// 一点更新O((log_2 N)^2)
// 一点加算O(log_2 N)（可換性と羃等性を用いる）
// 区間加算O(i_final-i_start+log_2 N)（可換性と羃等性を用いる）

// そのうちの区間和取得と一点更新は
// M. Dima, R. Ceterchi, Efficient Range Minimum Queries using Binary Indexed Trees, Olympiads in Informatics, 2015, Vol. 9, 39--44
// の手法を一般の可換羃等モノイドに拡張することで実装
template <TEMPLATE_ARGUMENTS_FOR_IDEMPOTENT_MONOID_BIT>
class IdempotentMonoidBIT
{
private:
  T m_a[N];
  T m_fenwick_0[N + 1];
  T m_fenwick_1[N + 1];

public:
  static const T& g_e;

  inline IdempotentMonoidBIT();
  inline IdempotentMonoidBIT( const T ( &a )[N] );

  inline const T& operator[]( const int& i ) const;
  inline const T& Get( const int& i ) const;
  T IntervalSum( const int& i_start , const int& i_final );

  void Set( const int& i , const T& n );
  void Add( const int& i , const T& n );
  void IntervalAdd( const int& i_start , const int& i_final , const T& n ); 

};
