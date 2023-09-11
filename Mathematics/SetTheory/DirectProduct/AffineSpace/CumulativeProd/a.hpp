// c:/Users/user/Documents/Programming/Mathematics/SetTheory/DirectProduct/AffineSpace/CumulativeProd/a.hpp

#pragma once
// verify: https://atcoder.jp/contests/agc023/submissions/45472183

// 入力の範囲内で要件
// (1) (T,m_T:T^2->T,i_T:T->T)が群である。
// が成り立つ場合のみサポート。（単位元はテンプレート引数に渡さなくてよい）
template <typename T , T m_T(const T&,const T&) , T i_T(const T&) , int size_max>
class CumulativeProd_Body
{

protected:
  int m_size;
  T m_a[size_max];
  T m_a_reverse[size_max];

public:
  inline CumulativeProd_Body( const int& size );

  // 0 <= i,j < m_sizeの場合のみサポート。
  // iからへのpathがi=v_0->...->v_k=jの時m_a[v_0]...m_a[v_k]を
  // Prodや逆順のProdに関して計算する。
  inline T PathProd( const int& i , const int& j );

private:
  virtual int Parent( const int& i ) = 0;
  virtual int LCA( const int& i , const int& j ) = 0;

};


// 通常の配列上の累積積。
// テンプレート引数に単位元e_T:1->Tも渡す。

// 配列による初期化O(size)

// 右区間積取得O(1)
// 左区間積取得O(1)

// 区間積が単位元である区間の数え上げO(size log size)
// 区間積が単位元である区間の列挙O(size log size + 区間数)
template <typename T , T m_T(const T&,const T&) , const T& e_T() , T i_T(const T&) , int size_max>
class CumulativeProd :
  public CumulativeProd_Body<T,m_T,i_T,size_max>
{

public:
  inline CumulativeProd( const T ( &a )[size_max] , const int& size );

  // 0 <= iかつi-1 <= j < m_sizeの場合のみサポート。
  // m_a[i]...m_a[j]をm_Tに関してで計算する。
  inline T RightProd( const int& i , const int& j );
  // m_a[j]...m_a[i]をm_Tに関して計算する。
  inline T LeftProd( const int& i , const int& j );

  // 区間積がe_T()と等しい区間の個数を計算する。
  ll CountUnitProdRange();
  // 区間積がe_T()と等しい区間を列挙する。
  list<pair<int,int> > UnitProdRange();
  
private:
  inline int Parent( const int& i );
  inline int LCA( const int& i , const int& j );

};
