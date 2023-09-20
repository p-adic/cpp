// c:/Users/user/Documents/Programming/Mathematics/SetTheory/DirectProduct/AffineSpace/BIT/Template/a.hpp

#pragma once
#include "a_Macro.hpp"

// 演算がoperator+=でない場合に使用
// 可換群(T,m_T:T^2->T,e_T:1->T,i_T:T->T)と非負整数Nをパラメータとする。
// ただしi_Tを使うのはSetとIntervalSumのみなので、
// AddとInitialSegmentSumしか使わない場合は
// i_Tを好きに設定して(T,m_T,e_T)をモノイドとして良い。
template <TEMPLATE_ARGUMENTS_FOR_BIT>
class AbstractBIT
{
private:
  T m_fenwick[N + 1];
  
public:
  static const T& g_e;

  inline AbstractBIT();
  inline AbstractBIT( const T ( &a )[N] );

  // const参照でないことに注意。
  inline T Get( const int& i ) const;
  inline void Set( const int& i , const T& n );
  inline void Set( const T ( &a )[N] );
  inline void Initialise();

  inline AbstractBIT<T,m_T,e_T,i_T,N>& operator+=( const T ( & a )[N] );
  void Add( const int& i , const T& n );

  T InitialSegmentSum( const int& i_final ) const;
  inline T IntervalSum( const int& i_start , const int& i_final ) const;

  // 順序群構造operator<( const T& , const T& )が定義されている時のみサポート。
  // g_eより小さくない要素のみを成分に持つ場合のみサポート。
  // InitialSegmentSum( i )がn以上となるiが存在する場合にその最小値を2進法で探索。
  // 存在しない場合はN以上の最小の2羃×2-1を返す（N以上であることで判定可能）。
  int BinarySearch( const T& n ) const;
  // IntervalSum( i_start , i )がn以上となるi_start以上のiが存在する場合にその最小値を2進法で探索。
  // 存在しない場合はN以上の最小の2羃×2-1を返す（N以上であることで判定可能）。
  inline int BinarySearch( const int& i_start , const T& n ) const;
  
};
