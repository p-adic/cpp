// c:/Users/user/Documents/Programming/Mathematics/SetTheory/DirectProduct/AffineSpace/BIT/IntervalMax/Template/a.hpp

#pragma once
#include "a_Macro.hpp"

// verify:
// https://yukicoder.me/submissions/942870（一点加算／区間和取得）
// https://yukicoder.me/submissions/942873（配列による初期化／区間和取得）

// M_Tは乗算m_T:T^2->Tに相当する型。

// 入力の範囲内で要件
// - (T,m_T:T^2->T,e_T:1->T)が可換羃等モノイドである。
// を満たす場合にのみサポート。

// e_Tによる初期化O(size)
// 配列による初期化O(size)

// 一点取得O(1)
// LSB切片和取得O(1)（left:a[j-(j&-j)]+...+a[j-1]、right:a[j-1]+...+a[j+(j&-j)-1]）
// 区間和取得O(log_2 size)

// 一点更新O((log_2 size)^2)
// 一点加算O(log_2 size)（可換性と羃等性を用いる）
// 区間加算O(i_final-i_start+log_2 size)（可換性と羃等性を用いる）
// 全体加算O(size)（可換性と羃等性を用いる）

// tを吸収する（tに吸収される）要素の添字の最小値の二分探索O(log_2 size)
// （存在しない場合はsize以上の最小の2羃×2-1を返すので、size以上であることで判定可能）

// そのうちの区間和取得と一点更新は
// M. Dima, R. Ceterchi, Efficient Range Minimum Queries using Binary Indexed Trees, Olympiads in Informatics, 2015, Vol. 9, 39--44
// の手法を一般の可換羃等モノイドに拡張することで実装
template <typename T , typename M_T>
class IdempotentMonoidBIT
{
private:
  M_T m_m_T;
  T m_e_T;
  int m_size;
  vector<T> m_a;
  vector<T> m_fenwick_0;
  vector<T> m_fenwick_1;
  int m_power;

public:
  inline IdempotentMonoidBIT( M_T m_T , T e_T , const int& size = 0 );
  inline IdempotentMonoidBIT( M_T m_T , T e_T , vector<T> a );

  inline IdempotentMonoidBIT<T,M_T>& operator=( IdempotentMonoidBIT<T,M_T>&& a );

  inline const T& operator[]( const int& i ) const;
  inline const T& Get( const int& i ) const;
  inline const T& LSBSegmentSum( const int& j , const bool& left = true ) const;
  T IntervalSum( const int& i_start , const int& i_final ) const;

  void Set( const int& i , const T& n );
  inline void Set( vector<T>&& a );
  inline void Initialise( const int& size = 0 );

  inline IdempotentMonoidBIT<T,M_T>& operator+=( vector<T>&& a );
  void Add( const int& i , const T& n );
  void IntervalAdd( const int& i_start , const int& i_final , const T& n );

  int BinarySearch( const T& t ) const;
  
};
