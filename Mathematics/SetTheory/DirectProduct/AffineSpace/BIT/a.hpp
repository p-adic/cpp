// c:/Users/user/Documents/Programming/Mathematics/SetTheory/DirectProduct/AffineSpace/BIT/a.hpp

#pragma once

// verify: https://yukicoder.me/submissions/942586

// 配列の各要素がint型の範疇でも総和がそうでない場合はTをint型にすると正しく動作しないことに注意。
// InitialSegmentSumで負の入力を扱うためにuintではなくintをテンプレート引数にする。

// 使用演算：
// T& T::operator=( const T& )
// T& T::operator+=( const T& )
// T operator-( const T& , const T& )（ただしIntervalSumを用いない場合は不要）
// T operator<( const T& , const T& )（ただしBinarySearchを用いない場合は不要）

// T()による初期化O(size)
// 配列による初期化O(size)

// 一点取得O(log_2 size)
// LSB切片和取得O(1)
// 始切片和取得O(log_2 size)
// 区間和取得O(log_2 size)

// 一点更新O(log_2 size)
// +による一点更新O(log_2 size)
// 配列の加算による全体更新O(size)

// 始切片和がn以上となる要素の添字の最小値の二分探索O(log_2 size)
template <typename T>
class BIT
{
private:
  int m_size;
  vector<T> m_fenwick;

  // m_size以上である最小の2羃。
  int m_power;

public:
  inline BIT( const int& size = 0 );
  BIT( const vector<T>& a );

  inline BIT<T>& operator=( BIT<T>&& a );

  // const参照でないことに注意。
  inline T Get( const int& i ) const;
  inline void Set( const int& i , const T& n );
  inline void Set( const vector<T>& a );
  inline void Initialise( const int& size = 0 );

  inline BIT<T>& operator+=( const vector<T>& a );
  // 0<=i<m_sizeの場合は第i成分にnを足し、そうでない場合は何もしない。
  void Add( const int& i , const T& n );

  // a[j-(j&-j)]+...+a[j-1]を返す。
  inline const T& LSBSegmentSum( const int& j ) const;
  // a[0]+...+a[i_final]を返す。
  T InitialSegmentSum( const int& i_final ) const;
  // a[i_start]+...+a[i_final]を返す。
  inline T IntervalSum( const int& i_start , const int& i_final ) const;
  
  // operator+=の単位元T()より小さくない要素のみを成分に持つ場合のみサポート。
  // InitialSegmentSum( i )がn以上となるiが存在する場合にその最小値を2進法で探索。
  // 存在しない場合はm_size以上の最小の2羃×2-1を返す（m_size以上であることで判定可能）。
  int BinarySearch( const T& n ) const;
  // IntervalSum( i_start , i )がn以上となるi_start以上のiが存在する場合にその最小値を2進法で探索。
  // 存在しない場合はm_size以上の最小の2羃×2-1を返す（m_size以上であることで判定可能）。
  inline int BinarySearch( const int& i_start , const T& n ) const;
  
};
