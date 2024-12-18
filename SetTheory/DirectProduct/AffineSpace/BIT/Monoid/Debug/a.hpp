// c:/Users/user/Documents/Programming/Mathematics/SetTheory/DirectProduct/AffineSpace/BIT/Monoid/Debug/a.hpp

#pragma once
#include "../../a_Macro.hpp"

#include "../../../../../../../Error/Debug/a.hpp"

// デバッグ用に出力機能を追加したもの。
// 通常のMonoidBITと比べると一点取得にconst修飾がつき各種操作にO(N)かかることに注意。

template <typename U , typename MONOID>
class MonoidBIT :
  public Debug
{
private:
  MONOID m_M;
  int m_size;
  vector<U> m_a;
  vector<U> m_fenwick_0;
  vector<U> m_fenwick_1;
  int m_power;

public:
  inline MonoidBIT( MONOID M , const int& size = 0 , const bool& output_mode = true );
  inline MonoidBIT( MONOID M , vector<U> a , const bool& output_mode = true );

  template <typename...Args> inline void Initialise( Args&&... args );
  void Set( const int& i , const U& u );

  inline const int& size() const noexcept;
  inline const U& operator[]( const int& i ) const;
  inline const U& Get( const int& i ) const;
  inline const U& LSBSegmentProduct( const int& j , const bool& left = true ) const;
  U IntervalProduct( const int& i_start , const int& i_final );

  // Fは積順序に関して単調な写像f:U \times int -> {0,1}に相当する型。
  // f( IntervalProduct( 0 , i ) , i )がtrueとなるiが存在する場合にその最小値を
  // 2進法で探索。存在しない場合はNを返す。
  template <typename F , SFINAE_FOR_BIT_BS = nullptr> int Search( const F& f );
  // IntervalProduct( 0 , i )がu以上となるiが存在する場合にその最小値を2進法で探索。
  // 存在しない場合はNを返す。
  inline int Search( const U& u );
  
};
template <typename MONOID , typename...Args> MonoidBIT( MONOID M , Args&&... args ) -> MonoidBIT<inner_t<MONOID>,MONOID>;

template <class Traits , typename U , typename MONOID> inline basic_ostream<char,Traits>& operator<<( basic_ostream<char,Traits>& os , const MonoidBIT<U,MONOID>& bit );
