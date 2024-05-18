// c:/Users/user/Documents/Programming/Utility/String/RollingHash/a.hpp

#pragma once
#include "a_Macro.hpp"

// verify:
// https://yukicoder.me/submissions/981380（Encode）
// https://yukicoder.me/submissions/982690（CumulativeEncode）

// 素数の候補
// { 999182201 , 999281719 , 999309403 , 999391993 , 999462649 , 999582757 , 999682811 , 999728287 , 999892849 , 999927217 };

// MODINTは素数を法とする整数型。
// 文字列を右方向に、配列を添字方向に次数付けしてハッシュ化する。
// Foldなどで長さが32bitに収まらない時はINTをllにする。
template <typename MODINT , typename INT = int>
class RollingHash
{
  
private:
  INT m_size;
  MODINT m_r;
  MODINT m_r_inv;
  vector<MODINT> m_r_power;

public:
  inline RollingHash( MODINT r );

  inline const MODINT& r() const noexcept;
  inline const MODINT& r_inv() const noexcept;
  inline const vector<MODINT>& r_power() const noexcept;
  
  // sを{ハッシュ,r^長さ,長さ}でコードする。（O(s.size())）
  template <typename STR> inline tuple<MODINT,MODINT,INT> Encode( const STR& s , const bool& reversed = false );
  template <typename STR , typename Enum> tuple<MODINT,MODINT,INT> Encode( const STR& s , Enum& e , const bool& reversed = false );
  
  // {s[:0]のハッシュ,s[:1]のハッシュ,...}を返す。（O(s.size())）
  template <typename STR> inline vector<MODINT> CumulativeEncode( const STR& s , const bool& reversed = false );
  template <typename STR , typename Enum> vector<MODINT> CumulativeEncode( const STR& s , Enum& e , const bool& reversed = false );
  
  // {s[0]のコード,s[1]のコード,...}を返す。（O(s.size())）
  template <typename STR> inline vector<tuple<MODINT,MODINT,INT>> PointwiseEncode( const STR& s , const bool& reversed = false );
  template <typename STR , typename Enum> vector<tuple<MODINT,MODINT,INT>> PointwiseEncode( const STR& s , Enum& e , const bool& reversed = false );

  template <typename CHAR> inline tuple<MODINT,MODINT,INT> Replace( tuple<MODINT,MODINT,INT> code , const INT& i , const CHAR& c_prev , const CHAR& c_next ) const;
  template <typename CHAR , typename Enum> tuple<MODINT,MODINT,INT> Replace( tuple<MODINT,MODINT,INT> code , const INT& i , const CHAR& c_prev , const CHAR& c_next , Enum& e ) const;
  
  // codeでコードされる文字列がsに連続部分列として含まれる個数の推定値を返す。（O(s.size())）
  template <typename STR> inline INT CountContain( const STR& s , const tuple<MODINT,MODINT,INT>& code , const bool& reversed = false );
  template <typename STR , typename Enum> INT CountContain( const STR& s , const tuple<MODINT,MODINT,INT>& code , Enum& e , const bool& reversed = false );

  // 文字列に対しては通常の連結、配列に対しては第1引数に第2引数を連結する演算をコードに翻訳。（O(1)）
  static inline tuple<MODINT,MODINT,INT> Concatenate( tuple<MODINT,MODINT,INT> code0 , const tuple<MODINT,MODINT,INT>& code1 );
  static inline tuple<MODINT,MODINT,INT> Fold( tuple<MODINT,MODINT,INT> code , INT n );

private:
  void CheckSize( const INT& size );
  template <typename CHAR> static inline MODINT Enumeration( const CHAR& c );

};

