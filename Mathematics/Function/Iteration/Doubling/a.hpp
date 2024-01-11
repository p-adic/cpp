// c:/Users/user/Documents/Programming/Mathematics/Function/Iteration/Doubling/a.hpp

#pragma once

// verify:
// https://atcoder.jp/contests/abc013/submissions/49214926（Doubling）
// https://yukicoder.me/submissions/942761（Doubling）
// https://yukicoder.me/submissions/942770（MemorisationDoubling）
// https://yukicoder.me/submissions/942771（EnumerationDoubling）

// 2^16 = 65536
// 2^17 = 131072
// 2^18 = 262144
// 2^60 = 1152921504606846976 > 10^18
// 2^63 = 9223372036854775808 < 10^19

// FはT->U(-->T)に相当する型
template <typename T , typename F>
class Doubling_Body
{
  
protected:
  F m_f;
  int m_size;
  int m_digit;
  vector<vector<int> > m_doubling;
  
  inline Doubling_Body( F f , const int& size , const int& digit );
  
public:
  // f^n(t)を計算する。
  template <typename INT> T IteratedComposition( T t , INT n );

private:
  virtual T e( const int& i ) = 0;
  virtual int e_inv( const T& t ) = 0;

};

// size未満の非負整数全体の集合をSと置く。要件
// (1) Sの任意の要素iに対しf(i)はSの要素である。
// が成り立つ場合にのみサポート。

// Sの各要素tとn < 2^digitを満たす各非負整数nをわたるf^n(t)全体を
// 合計O(size log n)の計算量で求める。
template <typename F>
class Doubling :
  public Doubling_Body<int,F>
{

public:
  inline Doubling( F f , const int& size , const int& digit = 64 );
  
private:
  inline int e( const int& i );
  inline int e_inv( const int& t );

};

// 要素数sizeのある集合Sが要件
// (1) Sの任意の要素iに対しf(i)はSの要素である。
// (2) fはデフォルト引数による呼び出し可能（推論補助に用いる）
// を満たす場合にのみサポート。

// そのようなSの各要素tとn < 2^digitを満たす各非負整数nをわたるf^n(t)全体を
// 合計O(size log size log n)の計算量で求める。
template <typename T, typename F>
class MemorisationDoubling :
  public Doubling_Body<T,F>
{

private:
  int m_length;
  Map<T,int> m_memory;
  vector<T> m_memory_inv;
  
public:
  inline MemorisationDoubling( F f , const int& size , const int& digit = 64 );
  
private:
  inline T e( const int& i );
  inline int e_inv( const T& t );
  
};
template <typename F,typename... Args> MemorisationDoubling(F,Args...) -> MemorisationDoubling<decltype(declval<F>()()),F>;

// 要素数sizeのある集合Sが要件
// (1) Sの任意の要素iに対しf(i)はSの要素である。
// (2) fはデフォルト引数による呼び出し可能（推論補助に用いる）
// (3) (enum_T,enum_T_inv)がSとsize未満の非負整数全体の集合の間の全単射を与える。
// を満たす場合にのみサポート。

// そのようなSの各要素tとn < 2^digitを満たす各非負整数nをわたるf^n(t)全体を
// 合計O(size log n)の計算量で求める。
template <typename T , typename Enum_T , typename Enum_T_inv , typename F>
class EnumerationDoubling :
  public Doubling_Body<T,F>
{

private:
  Enum_T m_enum_T;
  Enum_T_inv m_enum_T_inv;

public:
  inline EnumerationDoubling( Enum_T enum_T , Enum_T_inv enum_T_inv , F f , const int& size , const int& digit = 64 );
  
private:
  inline T e( const int& i );
  inline int e_inv( const T& t );

};
template <typename Enum_T,typename Enum_T_inv,typename F,typename...Args> EnumerationDoubling(Enum_T,Enum_T_inv,F,Args...) -> EnumerationDoubling<decltype(declval<F>()()),Enum_T,Enum_T_inv,F>;
