// c:/Users/user/Documents/Programming/Mathematics/SetTheory/DirectProduct/AffineSpace/BIT/Abstract/Monoid/a.hpp

#pragma once
#include "../a_Macro.hpp"

// verify:
// https://yukicoder.me/submissions/955164（一点代入、区間積）

// 入力の範囲内で要件
// (1) MがUのモノイド構造である。
// を満たす場合にのみサポート。

// 配列による初期化O(size)

// 一点取得O(1)
// LSB切片積取得O(1)（left:a[j-(j&-j)]*...*a[j-1]、right:a[j-1]*...*a[j+(j&-j)-1]）
// 区間積取得O(log_2 size)（a[i_start]*...*a[i_final]）

// 一点代入O((log_2 size)^2)

// 以下は入力の範囲内で要件
// (2) operator<(const U&,const U&)に関してMがUの全順序モノイド構造である。
// (3) 各成分がM.One()より小さくない。
// を満たす場合にのみサポート。
// 始切片積がu以上となる要素の添字の最小値の二分探索O(log_2 size)

// そのうちの区間積取得と一点代入は
// M. Dima, R. Ceterchi, Efficient Range Minimum Queries using Binary Indexed Trees, Olympiads in Informatics, 2015, Vol. 9, 39--44
// の手法を一般のモノイドに拡張することで実装
template <typename U , typename MONOID>
class MonoidBIT
{
private:
  int m_size;
  MONOID m_M;
  vector<U> m_a;
  vector<U> m_fenwick_0;
  vector<U> m_fenwick_1;
  int m_power;

public:
  inline MonoidBIT( MONOID M , vector<U> a = vector<U>() );

  inline void Set( vector<U>&& a );
  void Set( const int& i , const U& u );

  inline const int& size() const noexcept;
  inline const U& operator[]( const int& i ) const;
  inline const U& Get( const int& i ) const;
  inline const U& LSBSegmentProduct( const int& j , const bool& left = true ) const;
  U IntervalProduct( const int& i_start , const int& i_final );

  // Fは積順序に関して単調な写像f:U \times int -> {0,1}に相当する型。
  // f( IntervalProduct( 0 , i ) , i )がtrueとなるiが存在する場合にその最小値を
  // 2進法で探索。存在しない場合はN以上の最小の2羃×2-1を返す（N以上であることで判別可能）。
  template <typename F , SFINAE_FOR_BIT_BS = nullptr> int BinarySearch( const F& f );
  // IntervalProduct( 0 , i )がu以上となるiが存在する場合にその最小値を2進法で探索。
  // 存在しない場合はN以上の最小の2羃×2-1を返す（N以上であることで判別可能）。
  inline int BinarySearch( const U& u );
  
};
template <typename MONOID> MonoidBIT( MONOID M ) -> MonoidBIT<inner_t<MONOID>,MONOID>;
