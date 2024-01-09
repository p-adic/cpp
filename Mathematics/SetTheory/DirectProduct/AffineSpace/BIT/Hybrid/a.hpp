// c:/Users/user/Documents/Programming/Mathematics/SetTheory/DirectProduct/AffineSpace/BIT/Hybrid/a.hpp

#pragma once
#include "../a.hpp"

// 使用演算：
// T& T::operator=( const T& )
// T& T::operator+=( const T& )
// T operator-( const T& , const T& )（ただしIntervalSumを用いない場合は不要）
// T operator<( const T& , const T& )（ただしBinarySearchを用いない場合は不要）

// T()による初期化O(size)
// 配列による初期化O(size)

// 一点取得O(1)
// LSB切片和取得O(1)
// 始切片和取得O(log_2 size)
// 区間和取得O(log_2 size)

// 一点更新O(log_2 size)
// +による一点更新O(log_2 size)
// 配列の加算による全体更新O(size)

// 始切片和がn以上となる要素の添字の最小値の二分探索O(log_2 size)
template <typename T>
class HybridBIT :
  public BIT<T>
{
private:
  vector<T> m_a;

public:
  inline HybridBIT( const int& size = 0 );
  inline HybridBIT( const vector<T>& a );
  inline HybridBIT( vector<T>&& a );

  inline const T& operator[]( const int& i ) const;
  inline const T& Get( const int& i ) const;
  inline void Set( const int& i , const T& n );
  inline void Set( vector<T>&& a );

  inline HybridBIT<T>& operator+=( const vector<T>& a );
  inline void Add( const int& i , const T& n );
  
};

