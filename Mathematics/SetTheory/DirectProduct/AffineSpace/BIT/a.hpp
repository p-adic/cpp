// c:/Users/user/Documents/Programming/Mathematics/SetTheory/DirectProduct/AffineSpace/BIT/a.hpp

#pragma once

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
  BIT( const T ( & a )[N] );

  // const参照でないことに注意。
  inline T Get( const int& i ) const;
  inline void Set( const int& i , const T& n );

  inline BIT<T,N>& operator+=( const T ( & a )[N] );
  void Add( const int& i , const T& n );

  T InitialSegmentSum( const int& i_final ) const;
  inline T IntervalSum( const int& i_start , const int& i_final ) const;
  
  // operator+=の単位元T()より小さくない要素のみを成分に持つ場合のみサポート。
  // InitialSegmentSum( i )がn以上となるiが存在する場合にその最小値を2進法で探索。
  int BinarySearch( const T& n ) const;
  // IntervalSum( i_start , i )がt以上となるi_start以上のiが存在する場合にその最小値を2進法で探索。
  inline int BinarySearch( const int& i_start , const T& n ) const;
  
};
