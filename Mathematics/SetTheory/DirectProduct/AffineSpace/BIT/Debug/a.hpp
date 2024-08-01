// c:/Users/user/Documents/Programming/Mathematics/SetTheory/DirectProduct/AffineSpace/BIT/Debug/a.hpp

#pragma once

#include "../a_Macro.hpp"
#include "../../../../../Algebra/Monoid/Group/a.hpp"

// デバッグ用にBITに通常の配列を折衷し出力機能を追加したもの。
// HybridBITと比べると一点取得の戻り値の型が異なり、
// 通常のBITと比べるとと一点取得にconst修飾がつき各種操作にO(N)かかることに注意。

template <typename U , typename ABELIAN_GROUP>
class AbstractBIT
{
protected:
  ABELIAN_GROUP m_M;
  int m_size;
  vector<U> m_fenwick;
  int m_power;

  vector<U> m_a;
  
public:
  inline AbstractBIT( ABELIAN_GROUP M , const int& size = 0 );
  inline AbstractBIT( ABELIAN_GROUP M , const vector<U>& a );

  template <typename...Args> inline void Initialise( const Args&... args );
  inline void Set( const int& i , const U& u );
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
  // その最小値を2進法で探索。存在しない場合はNを返す。
  template <typename F , SFINAE_FOR_BIT_BS = nullptr> inline int BinarySearch( const int& i_start , const F& f );

  // InitialSegmentSum( i )がu以上となるiが存在する場合にその最小値を2進法で探索。
  // 存在しない場合はNを返す。
  inline int BinarySearch( const U& u );
  // IntervalSum( i_start , i )がu以上となるi_start以上のiが存在する場合にその最小値を
  // 2進法で探索。存在しない場合はNを返す。
  inline int BinarySearch( const int& i_start , const U& u );

private:
  inline void Construct();
  
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

// デバッグ出力用
template <class Traits , typename U , typename ABELIAN_GROUP> inline basic_ostream<char,Traits>& operator<<( basic_ostream<char,Traits>& os , const AbstractBIT<U,ABELIAN_GROUP>& bit );
