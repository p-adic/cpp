// c:/Users/user/Documents/Programming/Mathematics/SetTheory/DirectProduct/Tree/CumulativeProd/a.hpp

#pragma once
#include "../../../../Geometry/Graph/DepthFirstSearch/Tree/a.hpp"

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
template <typename T , T m_T(const T&,const T&) , const T& e_T() , T i_T(const T&) , int size_max>
class CumulativeProd ：
  public CumulativeProd_Body<T,m_T,i_T,size_max>
{

public:
  inline CumulativeProd( const T ( &a )[size_max] , const int& size );

  // 0 <= iかつi-1 <= j < m_sizeの場合のみサポート。
  // m_a[i]...m_a[j]をm_Tに関して計算する。
  inline T RightProd( const int& i , const int& j );
  // m_a[j]...m_a[i]をm_Tに関して計算する。
  inline T LeftProd( const int& i , const int& j );

private:
  inline int Parent( const int& i );
  inline int LCA( const int& i , const int& j );

};


// 木上の累積積。

// 入力の範囲内で要件
// (2) グラフ(V,E)は無向グラフとして木である。
// (3) 0を根とした時の各ノードの高さが2^digit未満である。
// が成り立つ場合にのみサポート。
// 2^16 = 65536
// 2^17 = 131072
// 2^18 = 262144
template <typename T , T m_T(const T&,const T&) , T i_T(const T&) , list<int> E(const int&) , int size_max , int digit>
class CumulativeProdOnTree ：
  public CumulativeProd_Body<T,m_T,i_T,size_max>
{

private:
  DepthFirstSearchOnTree<size_max,E,digit> m_dfst;

public:
  inline CumulativeProdOnTree( const T ( &a )[size_max] , const int& V );

private:
  inline int Parent( const int& i );
  inline int LCA( const int& i , const int& j );

};
