// c:/Users/user/Documents/Programming/Mathematics/SetTheory/DirectProduct/AffineSpace/CumulativeProd/a.hpp

#pragma once

// verify:
// https://yukicoder.me/submissions/946991（左累積積）
// https://atcoder.jp/contests/agc023/submissions/49678399（左右区間積逆像数え上げ）

// 木上で群に値を持つ関数の累積積を計算する。
template <typename U>
class VirtualCumulativeProd
{

public:
  // 0 <= i,j < m_sizeの場合のみサポート。
  // iからへのpathがi=v_0->...->v_k=jの時、Setした配列aに対する
  // 右総乗a[v_0]...a[v_k]を計算する。
  virtual U PathProd( const int& i , const int& j ) = 0;

protected:
  virtual int Parent( const int& i ) = 0;
  virtual int LCA( const int& i , const int& j ) = 0;

};

template <typename U , typename GROUP>
class PathProdImplementation :
  virtual public VirtualCumulativeProd<U>
{

protected:
  int m_size;
  GROUP m_M;
  vector<U> m_right;
  vector<U> m_left;

public:
  inline PathProdImplementation( const int& size , GROUP M );
  inline U PathProd( const int& i , const int& j );

};


// 木が特に通常の配列である場合。
// 入力の範囲内で要件
// (1) MがUの群構造である。
// が成り立つ場合にのみサポート。

// M.one()による初期化O(size)
// 配列による初期化O(size)

// 一点左乗算O(size)
// 一点右乗算O(size)

// 右区間積取得O(1)
// 左区間積取得O(1)

// 右区間積逆像数え上げO(size log size)
// 右区間積逆像数え上げO(size log size)
template <typename U , typename GROUP>
class CumulativeProd :
  public PathProdImplementation<U,GROUP>
{

public:
  inline CumulativeProd( const int& size , GROUP M );
  template <typename V> inline CumulativeProd( const vector<V>& a , GROUP M );

  template <typename V> inline void Set( const vector<V>& a );
  // a[i]をM.Product(t,a[i])に置き変える。
  inline void LeftMultiply( const int& i , const U& t );
  // a[i]をM.Product(a[i],t)に置き変える。
  inline void RightMultiply( const int& i , const U& t );

  // 0 <= iかつi-1 <= j < m_sizeの場合のみサポート。
  // 右区間積a[i]...a[j]をMに関して計算する。
  inline U RightProd( const int& i , const int& j );
  // 左区間積a[j]...a[i]をMに関して計算する。
  inline U LeftProd( const int& i , const int& j );

  // 以下はM.Product()しか使用しないので、M.Product()が群演算でさえあればM.One()とM.Inverse()が無関係な演算でもよい。
  // Mに関する右区間積a[i]...a[j]がtと等しい区間[i,j]の個数を計算する。
  ll CountRightProdInverseImage( const U& t = One() );
  // Mに関する左区間積a[j]...a[i]がtと等しい区間[i,j]の個数を計算する。
  ll CountLeftProdInverseImage( const U& t = One() );

private:
  inline int Parent( const int& i );
  inline int LCA( const int& i , const int& j );
  inline const U& One() const;

};
template <typename GROUP> CumulativeProd( GROUP M ) -> CumulativeProd<inner_t<GROUP>,GROUP>;
template <typename V , typename GROUP> CumulativeProd( const vector<V>& a , GROUP M ) -> CumulativeProd<inner_t<GROUP>,GROUP>;
