// c:/Users/user/Documents/Programming/Utility/String/RollingHash/a.hpp

#pragma once
#include "a_Macro.hpp"

// verify:
// https://yukicoder.me/submissions/981380（Encode）

// 素数の候補
// { 999182201 , 999281719 , 999309403 , 999391993 , 999462649 , 999582757 , 999682811 , 999728287 , 999892849 , 999927217 };

// MODINTは素数を法とする整数型。
// 文字列を右方向に、配列を添字方向に次数付けしてハッシュ化する。
template <typename MODINT , typename INT = int>
class RollingHash
{
  
private:
  INT m_size;
  vector<MODINT> m_power;
  MODINT m_r;
  MODINT m_r_inv;

public:
  inline RollingHash( MODINT r );

  // sを{ハッシュ,r^長さ,長さ}でコードする（O(s.size())）
  template <typename STR> inline tuple<MODINT,MODINT,INT> Encode( const STR& s );
  template <typename STR , typename Enum> tuple<MODINT,MODINT,INT> Encode( const STR& s , Enum& e );

  // 文字列に対しては通常の連結、配列に対しては第1引数に第2引数を連結する演算をコードに翻訳
  inline tuple<MODINT,MODINT,INT> Concatenate( const tuple<MODINT,MODINT,INT>& code0 , const tuple<MODINT,MODINT,INT>& code1 ) const;
  inline tuple<MODINT,MODINT,INT> Fold( tuple<MODINT,MODINT,INT> code , INT n ) const;

  template <typename CHAR> inline tuple<MODINT,MODINT,INT> Replace( tuple<MODINT,MODINT,INT> code , const INT& i , const CHAR& c_prev , const CHAR& c_next ) const;
  template <typename CHAR , typename Enum> tuple<MODINT,MODINT,INT> Replace( tuple<MODINT,MODINT,INT> code , const INT& i , const CHAR& c_prev , const CHAR& c_next , Enum& e ) const;
  
  // codeでコードされる文字列がsに連続部分列として含まれる個数の推定値を返す。（O(s.size())）
  template <typename STR> inline INT CountContain( const STR& s , const tuple<MODINT,MODINT,INT>& code );
  template <typename STR , typename Enum> INT CountContain( const STR& s , const tuple<MODINT,MODINT,INT>& code , Enum& e );

private:
  void CheckSize( const INT& size );
  template <typename CHAR> static inline MODINT Enumeration( const CHAR& c );

};

