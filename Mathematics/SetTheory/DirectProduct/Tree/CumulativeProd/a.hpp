// c:/Users/user/Documents/Programming/Mathematics/SetTheory/DirectProduct/Tree/CumulativeProd/a.hpp

#pragma once
#include "../../../../Geometry/Graph/DepthFirstSearch/Tree/a.hpp"

// 入力の範囲内で要件
// (1) (T,m_T:T^2->T,i_T:T->T)が群である。
// が成り立つ場合のみサポート。（単位元は引数に渡さなくてよい）
template <typename T , T m_T(const T&,const T&), T i_T(const T&) , int size_max>
class CumulativeProd_Body
{

protected:
  int m_size;
  T m_a[size_max];
  T m_a_reverse[size_max];

public:
  inline CumulativeProd_Body( const int& size );
  // iからへのpathがi=v_0->...->v_k=jの時m_a[v_0]...m_a[v_k]を
  // Prodや逆順のProdに関して計算する。
  inline T PathProd( const int& i , const int& j );

private:
  virtual int Parent( const int& i ) = 0;
  virtual int LCA( const int& i , const int& j ) = 0;

};


// 通常の配列上の累積積。
template <typename T , T m_T(const T&,const T&), T i_T(const T&) , int size_max>
class CumulativeProd
{

public:
  inline CumulativeProd( const T ( &a )[size_max] , const int& size );

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
template <typename T , T m_T(const T&,const T&), T i_T(const T&) , list<int> E(const int&) , int size_max , int digit>
class CumulativeProdOnTree
{

private:
  DepthFirstSearchOnTree<size_max,E,digit> m_dfst;

public:
  inline CumulativeProdOnTree( const T ( &a )[size_max] , const int& V );

private:
  inline int Parent( const int& i );
  inline int LCA( const int& i , const int& j );

};
