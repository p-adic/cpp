// c:/Users/user/Documents/Programming/Mathematics/SetTheory/DirectProduct/AffineSpace/BIT/a.hpp

#pragma once
// 配列の各要素がint型の範疇でも総和がそうでない場合はTをint型にすると正しく動作しないことに注意。
// InitialSegmentSumで負の入力を扱うためにuintではなくintをテンプレート引数にする。

// 使用演算：
// T& T::operator=( const T& )
// T& T::operator+=( const T& )
// T operator-( const T& , const T& )（ただしIntervalSumを用いない場合は不要）
// T operator<( const T& , const T& )（ただしBinarySearchを用いない場合は不要）
template <typename T , int N>
class BIT
{
private:
  T m_fenwick[N + 1];

public:
  inline BIT();
  BIT( const T ( &a )[N] );

  // const参照でないことに注意。
  inline T Get( const int& i ) const;
  inline void Set( const int& i , const T& n );
  inline void Set( const T ( &a )[N] );
  inline void Initialise();

  inline BIT<T,N>& operator+=( const T ( & a )[N] );
  // 0<=i<Nの場合は第i成分にnを足し、そうでない場合は何もしない。
  void Add( const int& i , const T& n );

  T InitialSegmentSum( const int& i_final ) const;
  inline T IntervalSum( const int& i_start , const int& i_final ) const;
  
  // operator+=の単位元T()より小さくない要素のみを成分に持つ場合のみサポート。
  // InitialSegmentSum( i )がn以上となるiが存在する場合にその最小値を2進法で探索。
  // 存在しない場合はN以上の最小の2羃×2-1を返す（N以上であることで判定可能）。
  int BinarySearch( const T& n ) const;
  // IntervalSum( i_start , i )がn以上となるi_start以上のiが存在する場合にその最小値を2進法で探索。
  // 存在しない場合はN以上の最小の2羃×2-1を返す（N以上であることで判定可能）。
  inline int BinarySearch( const int& i_start , const T& n ) const;
  
};
