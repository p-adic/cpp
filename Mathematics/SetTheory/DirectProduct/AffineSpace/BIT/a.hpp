// c:/Users/user/Documents/Programming/Mathematics/SetTheory/DirectProduct/AffineSpace/BIT/a.hpp

#pragma once

// verify:
// https://yukicoder.me/submissions/947999（零初期化、一点加算、区間和）

// 使用演算：
// U& U::operator=( const U& )
// U& U::operator+=( const U& )
// U operator-( const U& , const U& )（ただしIntervalSumを用いない場合は不要）
// U operator<( const U& , const U& )（ただしBinarySearchを用いない場合は不要）

// U()による初期化O(size)
// 配列による初期化O(size)

// 一点更新O(log_2 size)
// +による一点更新O(log_2 size)
// 配列の加算による全体更新O(size)

// 一点取得O(log_2 size)
// LSB切片和取得O(1)
x// 始切片和取得O(log_2 size)
// 区間和取得O(log_2 size)

// 始切片和がu以上となる要素の添字の最小値の二分探索O(log_2 size)
// 左端点を固定した時に区間和がu以上となる要素の添字の最小値の二分探索O(log_2 size)
template <typename U>
class BIT
{
private:
  int m_size;
  vector<U> m_fenwick;

  // m_size以上である最小の2羃。
  int m_power;

public:
  inline BIT( const int& size = 0 );
  BIT( const vector<U>& a );

  inline void Set( const int& i , const U& u );
  inline void Set( const vector<U>& a );
  inline void Initialise( const int& size = 0 );

  inline BIT<U>& operator+=( const vector<U>& a );
  void Add( const int& i , const U& u );

  inline const int& size() const noexcept;
  // const参照でないことに注意。
  inline U operator[]( const int& i ) const;
  inline U Get( const int& i ) const;
  // a[j-(j&-j)]+...+a[j-1]を返す。
  inline const U& LSBSegmentSum( const int& j ) const;
  // a[0]+...+a[i_final]を返す。
  U InitialSegmentSum( const int& i_final ) const;
  // a[i_start]+...+a[i_final]を返す。
  inline U IntervalSum( const int& i_start , const int& i_final ) const;
  
  // operator+=の単位元U()より小さくない要素のみを成分に持つ場合のみサポート。
  // InitialSegmentSum( i )がu以上となるiが存在する場合にその最小値を2進法で探索。
  // 存在しない場合はsize以上の最小の2羃×2-1を返す（size以上であることで判定可能）。
  int BinarySearch( const U& u ) const;
  // IntervalSum( i_start , i )がu以上となるi_start以上のiが存在する場合にその最小値を2進法で探索。
  // 存在しない場合はsize以上の最小の2羃×2-1を返す（size以上であることで判定可能）。
  inline int BinarySearch( const int& i_start , const U& u ) const;
  
};
