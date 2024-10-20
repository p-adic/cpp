// c:/Users/user/Documents/Programming/Utility/String/RollingHash/a.hpp

#pragma once
#include "a_Macro.hpp"

// verify:
// https://yukicoder.me/submissions/981380 (Encode)
// https://yukicoder.me/submissions/982690 (CumulativeEncode)
// https://yukicoder.me/submissions/1013739 (FixedLengthEncode)

// 素数の候補
// { 999182201 , 999281719 , 999309403 , 999391993 , 999462649 , 999582757 , 999682811 , 999728287 , 999892849 , 999927217 };

// MODINTは素数を法とする整数型。
// 文字列を右方向に、配列を添字方向に次数付けしてハッシュ化する。（reversed=trueで反転）
// Foldなどで長さが32bitに収まらない時はINTをllにする。
template <typename MODINT , typename INT = int , typename CODE = tuple<MODINT,MODINT,INT>>
class RollingHash
{
  
protected:
  INT m_size;
  MODINT m_r;
  MODINT m_r_inv;
  vector<MODINT> m_r_power;

public:
  inline RollingHash();
  inline RollingHash( MODINT r );

  inline const MODINT& r() const noexcept;
  inline const MODINT& r_inv() const noexcept;
  inline const vector<MODINT>& r_power() const noexcept;
  
  // sを{ハッシュ,r^長さ,長さ}でコードする。（O(s.size())）
  template <typename STR> inline CODE Encode( const STR& s , const bool& reversed = false );
  
  // {s[:0]のコード,s[:1]のコード,...}を返す。（O(s.size())）
  template <typename STR> inline vector<CODE> CumulativeEncode( const STR& s , const bool& reversed = false );
  
  // {s[0]のコード,s[1]のコード,...}を返す。（O(s.size())）
  template <typename STR> inline vector<CODE> PointwiseEncode( const STR& s , const bool& reversed = false );

  // {s[0:length]のコード,s[1:length+1]のコード,...}を返す。（O(s.size())）
  template <typename STR> inline vector<CODE> FixedLengthEncode( const STR& s , const int& length , const bool& reversed = false );

  template <typename CHAR> inline CODE Replace( CODE code , const INT& i , const CHAR& c_prev , const CHAR& c_next ) const;

  template <typename CHAR> inline CODE PopFront( CODE code , const CHAR& c_prev ) const;
  template <typename CHAR> inline CODE PopBack( CODE code , const CHAR& c_prev ) const;
  
  // codeでコードされる文字列がsに連続部分列として含まれる個数の推定値を返す。（O(s.size())）
  template <typename STR> inline INT CountContain( const STR& s , const CODE& code , const bool& reversed = false );

  // 文字列に対しては通常の連結、配列に対しては第1引数に第2引数を連結する演算をコードに翻訳。（O(1)）
  static inline CODE Concatenate( CODE code0 , const CODE& code1 );
  static inline CODE Fold( CODE code , INT n );

protected:
  MODINT GetRand();
  void CheckSize( const INT& size );
  virtual MODINT Twist( const ll& c );

};

