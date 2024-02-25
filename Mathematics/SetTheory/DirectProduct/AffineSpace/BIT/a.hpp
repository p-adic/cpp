// c:/Users/user/Documents/Programming/Mathematics/SetTheory/DirectProduct/AffineSpace/BIT/Abstract/a.hpp

#pragma once
#include "a_Macro.hpp"
#include "../../../../Algebra/Monoid/Group/a.hpp"

// verify:
// https://yukicoder.me/submissions/950337（零初期化、一点加算、区間和）
// https://yukicoder.me/submissions/950342（零初期化、配列初期化、始切片和）
// https://yukicoder.me/submissions/955156（配列初期化、一点加算、通常の二分探索）

// 入力の範囲内で要件
// (1) MがUの可換群構造である。
// を満たす場合にのみサポート。
// ただしM.Inverse()を使うのはSetとIntervalSumと単調関係に関する区間でのBinarySearchのみなので、
// AddとInitialSegmentSumとその他のBinarySearchしか使わない場合は
// M.Inverse()を好きに設定してMをUの可換モノイド構造として良い。

// 配列による初期化O(size)

// 一点取得O(log_2 size)
// U.Sum()によるLSB切片和取得O(1)（a[j-(j&-j)]+...+a[j-1]）
// U.Sum()による始切片和取得O(log_2 size)
// U.Sum()による区間和取得O(log_2 size)

// 一点代入O(log_2 size)
// U.Sum()による一点加算O(log_2 size)
// U.Sum()による加法O(size)

// 以下は入力の範囲内で要件
// (2) operator<(const U&,const U&)に関してMがUの全順序可換群構造である。
// (3) 各成分がM.One()より小さくない。
// を満たす場合にのみサポート。
// U.Sum()による始切片和がu以上となる要素の添字の最小値の二分探索O(log_2 size)
// 左端点を固定した時にU.Sum()による区間和がu以上となる要素の添字の最小値の二分探索O(log_2 size)
template <typename U , typename ABELIAN_GROUP>
class AbstractBIT
{
protected:
  ABELIAN_GROUP m_M;
  int m_size;
  vector<U> m_fenwick;
  int m_power;
  
public:
  inline AbstractBIT( ABELIAN_GROUP M , const int& size = 0 );
  inline AbstractBIT( ABELIAN_GROUP M , const vector<U>& a );
  
  template <typename...Args> inline void Reset( const Args&... args );
  inline void Set( const int& i , const U& u );
  inline AbstractBIT<U,ABELIAN_GROUP>& operator+=( const vector<U>& a );
  void Add( const int& i , const U& u );

  inline const int& size() const noexcept;
  // const参照でないことに注意。
  inline U operator[]( const int& i ) const;
  inline U Get( const int& i ) const;
  inline const U& LSBSegmentSum( const int& j ) const;
  U InitialSegmentSum( const int& i_final );
  inline U IntervalSum( const int& i_start , const int& i_final );

  // Fは積順序に関して単調な写像f:U \times int -> {0,1}に相当する型。
  // f( InitialSegmentSum( i ) , i )がtrueとなるiが存在する場合にその最小値を2進法で探索。
  // 存在しない場合はN以上の最小の2羃×2-1を返す（N以上であることで判別可能）。
  template <typename F , SFINAE_FOR_BIT_BS = nullptr> int BinarySearch( const F& f );
  // f( IntervalSum( i_start , i ) , i )がtrueとなるi_start以上のiが存在する場合に
  // その最小値を2進法で探索。
  // 存在しない場合はN以上の最小の2羃×2-1を返す（N以上であることで判別可能）。
  template <typename F , SFINAE_FOR_BIT_BS = nullptr> inline int BinarySearch( const int& i_start , const F& f );

  // InitialSegmentSum( i )がu以上となるiが存在する場合にその最小値を2進法で探索。
  // 存在しない場合はN以上の最小の2羃×2-1を返す（N以上であることで判別可能）。
  inline int BinarySearch( const U& u );
  // IntervalSum( i_start , i )がu以上となるi_start以上のiが存在する場合にその最小値を2進法で探索。
  // 存在しない場合はN以上の最小の2羃×2-1を返す（N以上であることで判別可能）。
  inline int BinarySearch( const int& i_start , const U& u );

private:
  inline void Initialise();

  
};
template <typename ABELIAN_GROUP , typename...Args> AbstractBIT( ABELIAN_GROUP M , const Args&... args ) -> AbstractBIT<inner_t<ABELIAN_GROUP>,ABELIAN_GROUP>;

template <typename U = ll>
class BIT :
  public AbstractBIT<U,AdditiveGroup<U>>
{

public:
  template <typename...Args> inline BIT( const Args&... args );

};
template <typename U> BIT( const vector<U>& a ) -> BIT<U>;
