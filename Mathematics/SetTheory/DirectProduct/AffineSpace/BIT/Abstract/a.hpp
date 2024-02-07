// c:/Users/user/Documents/Programming/Mathematics/SetTheory/DirectProduct/AffineSpace/BIT/Abstract/a.hpp

#pragma once

// verify:
// https://yukicoder.me/submissions/947861（一点加算、区間和）

// 演算がoperator+=などで与えられている場合は特殊化ではなく
// ../a.hpp
// を使うことでファイル容量を削減する。

// 入力の範囲内で要件
// (1) MがUの可換群構造である。
// を満たす場合にのみサポート。
// ただしM.Inverse()を使うのはSetとIntervalSumのみなので、
// AddとInitialSegmentSumしか使わない場合は
// M.Inverse()を好きに設定してMをUの可換モノイド構造として良い。

// 配列による初期化O(size)

// 一点取得O(log_2 size)
// LSB切片和取得O(1)（a[j-(j&-j)]+...+a[j-1]）
// 始切片和取得O(log_2 size)
// 区間和取得O(log_2 size)

// 一点更新O(log_2 size)
// 一点加算O(log_2 size)
// 配列の加算による全体更新O(size)

// 以下は入力の範囲内で要件
// (2) operator<(const U&,const U&)に関してMがUの全順序可換群構造である。
// (3) 各成分がM.One()より小さくない。
// を満たす場合にのみサポート。
// 始切片和がu以上となる要素の添字の最小値の二分探索O(log_2 size)
// 左端点を固定した時に区間和がu以上となる要素の添字の最小値の二分探索O(log_2 size)
template <typename U , typename ABELIAN_GROUP>
class AbstractBIT
{
private:
  int m_size;
  ABELIAN_GROUP m_M;
  vector<U> m_fenwick;
  int m_power;
  
public:
  inline AbstractBIT( ABELIAN_GROUP M , const vector<U>& a = vector<U>() );
  
  inline void Set( const int& i , const U& u );
  inline void Set( const vector<U>& a );
  inline AbstractBIT<U,ABELIAN_GROUP>& operator+=( const vector<U>& a );
  void Add( const int& i , const U& u );

  inline const int& size() const noexcept;
  // const参照でないことに注意。
  inline U operator[]( const int& i ) const;
  inline U Get( const int& i ) const;
  inline const U& LSBSegmentSum( const int& j ) const;
  U InitialSegmentSum( const int& i_final );
  inline U IntervalSum( const int& i_start , const int& i_final );

  // InitialSegmentSum( i )がu以上となるiが存在する場合にその最小値を2進法で探索。
  // 存在しない場合はN以上の最小の2羃×2-1を返す（N以上であることで判定可能）。
  int BinarySearch( const U& u );
  // IntervalSum( i_start , i )がn以上となるi_start以上のiが存在する場合にその最小値を2進法で探索。
  // 存在しない場合はN以上の最小の2羃×2-1を返す（N以上であることで判定可能）。
  inline int BinarySearch( const int& i_start , const U& u );
  
};
template <typename ABELIAN_GROUP> AbstractBIT( ABELIAN_GROUP M ) -> AbstractBIT<inner_t<ABELIAN_GROUP>,ABELIAN_GROUP>;
