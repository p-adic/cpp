// c:/Users/user/Documents/Programming/Mathematics/SetTheory/DirectProduct/AffineSpace/BIT/Template/a.hpp

#pragma once

// verify: https://yukicoder.me/submissions/942885（零初期化、一点加算、区間和）

// 演算がoperator+=でない場合に使用。
// M_Tは乗算m_T:T^2->Tに相当する型。
// I_Tは逆元i_T:T->Tに相当する型。

// 入力の範囲内で要件
// (1) (T,m_T:T^2->T,e_T:1->T)が可換群である。
// を満たす場合にのみサポート。
// ただしi_Tを使うのはSetとIntervalSumのみなので、
// AddとInitialSegmentSumしか使わない場合は
// i_Tを好きに設定して(T,m_T,e_T)をモノイドとして良い。

// e_Tによる初期化O(size)
// 配列による初期化O(size)

// 一点取得O(log_2 size)
// LSB切片和取得O(1)（a[j-(j&-j)]+...+a[j-1]）
// 始切片和取得O(log_2 size)
// 区間和取得O(log_2 size)

// 一点更新O(log_2 size)
// 一点加算O(log_2 size)
// 配列の加算による全体更新O(size)

// 以下は入力の範囲内で要件
// (2) operator<(const T&,const T&)に関して(T,m_T:T^2->T,e_T:1->T)が順序群である。
// (3) 各成分がe_Tより小さくない。
// を満たす場合にのみサポート。
// 始切片和がn以上となる要素の添字の最小値の二分探索O(log_2 size)
template <typename T , typename M_T , typename I_T>
class AbstractBIT
{
private:
  M_T m_m_T;
  T m_e_T;
  I_T m_i_T;
  int m_size;
  vector<T> m_fenwick;
  int m_power;
  
public:
  inline AbstractBIT( M_T m_T , T e_T , I_T i_T , const int& size = 0 );
  inline AbstractBIT( M_T m_T , T e_T , I_T i_T , const vector<T>& a );

  inline AbstractBIT<T,M_T,I_T>& operator=( AbstractBIT<T,M_T,I_T>&& a );
  
  inline void Set( const int& i , const T& n );
  inline void Set( const vector<T>& a );
  inline void Initialise( const int& size = 0 );
  inline AbstractBIT<T,M_T,I_T>& operator+=( const vector<T>& a );
  void Add( const int& i , const T& n );

  // const参照でないことに注意。
  inline T operator[]( const int& i ) const;
  inline T Get( const int& i ) const;
  inline const T& LSBSegmentSum( const int& j ) const;
  T InitialSegmentSum( const int& i_final ) const;
  inline T IntervalSum( const int& i_start , const int& i_final ) const;

  // InitialSegmentSum( i )がn以上となるiが存在する場合にその最小値を2進法で探索。
  // 存在しない場合はN以上の最小の2羃×2-1を返す（N以上であることで判定可能）。
  int BinarySearch( const T& n ) const;
  // IntervalSum( i_start , i )がn以上となるi_start以上のiが存在する場合にその最小値を2進法で探索。
  // 存在しない場合はN以上の最小の2羃×2-1を返す（N以上であることで判定可能）。
  inline int BinarySearch( const int& i_start , const T& n ) const;
  
};
