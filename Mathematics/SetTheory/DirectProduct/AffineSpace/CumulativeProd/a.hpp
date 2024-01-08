// c:/Users/user/Documents/Programming/Mathematics/SetTheory/DirectProduct/AffineSpace/CumulativeProd/a.hpp

#pragma once
#include "a_Macro.hpp"

// verify: https://atcoder.jp/contests/agc023/submissions/49156204（左右区間積逆像数え上げ）

// 入力の範囲内で要件
// (1) (T,m_T:T^2->T,i_T:T->T)が群である。
// が成り立つ場合のみサポート。（単位元はテンプレート引数に渡さなくてよい）
template <typename T , T m_T(const T&,const T&) , T i_T(const T&)>
class CumulativeProd_Body
{

protected:
  int m_size;
  vector<T> m_right;
  vector<T> m_left;

public:
  inline CumulativeProd_Body( const int& size = 0 );

  // 0 <= i,j < m_sizeの場合のみサポート。
  // iからへのpathがi=v_0->...->v_k=jの時、Setした配列aに対する
  // 右総乗a[v_0]...a[v_k]を計算する。
  inline T PathProd( const int& i , const int& j );

private:
  virtual int Parent( const int& i ) = 0;
  virtual int LCA( const int& i , const int& j ) = 0;

};

// 通常の配列上の累積積。
// テンプレート引数に単位元e_T:1->Tも渡す。

// e_Tによる初期化O(size)
// 配列による初期化O(size)

// 一点左乗算O(size)
// 一点右乗算O(size)

// 右区間積取得O(1)
// 左区間積取得O(1)

// 右区間積逆像数え上げO(size log size)
// 右区間積逆像数え上げO(size log size)
template <typename T , T m_T(const T&,const T&) , const T& e_T() , T i_T(const T&)>
class CumulativeProd :
  public CumulativeProd_Body<T,m_T,i_T>
{

public:
  inline CumulativeProd( const int& size = 0 );
  template <typename U , SFINAE_FOR_CUMULATIVE_PROD( = nullptr )> inline CumulativeProd( const vector<U>& a );

  template <typename U , SFINAE_FOR_CUMULATIVE_PROD( = nullptr )> inline void Set( const vector<U>& a );
  // a[i]をm_T(t,a[i])に置き変える。
  inline void LeftMultiply( const int& i , const T& t );
  // a[i]をm_T(a[i],t)に置き変える。
  inline void RightMultiply( const int& i , const T& t );
  
  // 0 <= iかつi-1 <= j < m_sizeの場合のみサポート。
  // 右区間積a[i]...a[j]をm_Tに関して計算する。
  inline T RightProd( const int& i , const int& j );
  // 左区間積a[j]...a[i]をm_Tに関して計算する。
  inline T LeftProd( const int& i , const int& j );

  // 以下はe_Tとi_Tを使用しないので、m_Tが群演算でさえあればe_Tとi_Tをm_Tと無関係なものにしてもよい。
  // 右区間積a[i]...a[j]がtと等しい区間[i,j]の個数を計算する。
  ll CountRightProdInverseImage( const T& t );
  // 左区間積a[j]...a[i]がtと等しい区間[i,j]の個数を計算する。
  ll CountLeftProdInverseImage( const T& t );
  
private:
  inline int Parent( const int& i );
  inline int LCA( const int& i , const int& j );

};
