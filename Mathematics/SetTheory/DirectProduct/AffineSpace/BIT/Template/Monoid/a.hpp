// c:/Users/user/Documents/Programming/Mathematics/SetTheory/DirectProduct/AffineSpace/BIT/Template/Monoid/a.hpp

#pragma once
#include "a_Macro.hpp"

// verify: https://yukicoder.me/submissions/942886（零初期化、一点更新、一点取得、区間和）

// M_Tは乗算m_T:T^2->Tに相当する型。

// 入力の範囲内で要件
// (1) (T,m_T:T^2->T,e_T:1->T)が（可換とは限らない）モノイドである。
// を満たす場合にのみサポート。

// e_Tによる初期化O(N)
// 配列による初期化O(N)

// 一点取得O(1)
// LSB切片積取得O(1)（left:a[j-(j&-j)]*...*a[j-1]、right:a[j-1]*...*a[j+(j&-j)-1]）
// 区間積取得O(log_2 N)（a[i_start]*...*a[i_final]）

// 一点更新O((log_2 N)^2)

// 以下は入力の範囲内で要件
// (2) operator<(const T&,const T&)に関して(T,m_T:T^2->T,e_T:1->T)が順序モノイドである。
// (3) 各成分がe_Tより小さくない。
// を満たす場合にのみサポート。
// 始切片積がn以上となる要素の添字の最小値の二分探索O(log_2 size)

// そのうちの区間積取得と一点更新は
// M. Dima, R. Ceterchi, Efficient Range Minimum Queries using Binary Indexed Trees, Olympiads in Informatics, 2015, Vol. 9, 39--44
// の手法を一般のモノイドに拡張することで実装
template <typename T , typename M_T>
class MonoidBIT
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
  inline MonoidBIT( M_T m_T , T e_T , const int& size = 0 );
  inline MonoidBIT( M_T m_T , T e_T , vector<T> a );

  inline MonoidBIT<T,M_T>& operator=( MonoidBIT<T,M_T>&& a );

  void Set( const int& i , const T& n );
  inline void Set( vector<T>&& a );
  inline void Initialise( const int& size = 0 );

  inline const T& operator[]( const int& i ) const;
  inline const T& Get( const int& i ) const;
  inline const T& LSBSegmentProduct( const int& j , const bool& left = true ) const;
  T IntervalProduct( const int& i_start , const int& i_final ) const;

  // IntervalSegmentProduct( 0 , i )がt以上となるiが存在する場合にその最小値を2進法で探索。
  // 存在しない場合はN以上の最小の2羃×2-1を返す（N以上であることで判定可能）。
  int BinarySearch( const T& t ) const;
  
};
