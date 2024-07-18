// c:/Users/user/Documents/Programming/Mathematics/Function/MaxTwoAryHierarchy/a.hpp

#pragma once
#include "a_Macro.hpp"

#include "../../../Utility/Reverse/a.hpp"

// verify:
// https://yukicoder.me/submissions/995706（一次関数）

// 基本的に下記URLのConvex Hull Trickに準じる。
// https://rsk0315.hatenablog.com/entry/2022/04/29/141726

template <typename U , typename V , typename X>
class VirtualTwoAryHierarchyIntersection
{

protected:
  virtual X Intersection( const U& u0 , const V& v0 , const U& u1 , const V& v1 ) = 0;
  
};

// FUNCは関数func:U \times V \times X \to Yに相当する型。
// 入力の範囲内で要件
// (1) bool operator<(const U&const U&)は全順序である。
// (2) bool operator<(const V&const V&)は全順序である。
// (3) bool operator<(const X&const X&)は全順序である。
// (4) bool operator<(const Y&const Y&)は全順序である。
// (5) x_min <= x_maxである。
// (6) 任意の(u0,u1) in U^2とv in Vに対し、u0 < u1ならばあるx0 in Xが存在して、
//     任意のx in [x_min,x_max]に対しfunc(u0,v,x) > func(u1,v,x)とx < x0は同値である。
// (7) 任意のu in Uと(v0,v1) in V^2に対し、v0 < v1ならばあるx0 in Xが存在して、
//     任意のx in [x_min,x_max]に対しfunc(u,v0,x) > func(u,v1,x)とx < x0は同値である。
// を満たす場合にのみサポート。
// 例えばU=V=X=Y=llでfunc(u,v,x) = ux+vなど。以下uを傾き、vをY切片と呼ぶ。

// (6),(7)の不等式を反転させるにはReversedを使う。
// 正しく動作しない時は(6),(7)の不成立を疑うこと。

// 全体更新回数をQと置く。

// func(u,v,-)による構築O(1)
// func(u,v,-)とのmaxによる全体更新O(log Q)（均し）
// 一点取得O(log Q)
template <typename U , typename V , typename X , typename FUNC>
class VirtualMaxTwoAryHierarchy :
  virtual public VirtualTwoAryHierarchyIntersection<U,V,X>
{

protected:
  FUNC m_func;
  X m_x_min;
  X m_x_max;
  // m_uvx[傾きu] = { y切片v , 最大値を取る区間左端のx座標 } として管理。
  map<U,pair<V,X> > m_uvx;
  // m_xu[最大値を取る区間左端のx座標] = 傾きu として管理。
  map<X,U> m_xu;

public:
  // vector<U>,vector<V>で初期化を行うと仮想継承されたIntersectionを呼び出すのでREとなる。
  inline VirtualMaxTwoAryHierarchy( FUNC func , const X& x_min , const X& x_max , const U& dummy1 , const V& dummy2 );

  void SetMax( const U& u , const V& v );
  // {最大値,傾きu（2個ある場合は大きい方）,y切片v}を返す。
  // uの小さい方が必要な場合は(6),(7)を満たすようにU,V,X全てをReversedに置き換える。
  tuple<ret_t<FUNC,const U&,const V&,const X&>,U,V> Get( const X& x );

};

template <typename U , typename V , typename X , typename FUNC>
class ReversedTwoAryHierarchy :
  public FUNC
{

public:
  inline ReversedTwoAryHierarchy( FUNC&& func );
  
  inline Reversed<ret_t<FUNC,const U&,const V&,const X&>> operator()( const Reversed<U>& u , const Reversed<V>& v , const X& x );

};

template <typename U , typename V , typename X , typename FUNC>
class VirtualMinTwoAryHierarchy :
  public VirtualMaxTwoAryHierarchy<Reversed<U>,Reversed<V>,X,ReversedTwoAryHierarchy<U,V,X,FUNC>>
{

public:
  inline VirtualMinTwoAryHierarchy( FUNC func , const X& x_min , const X& x_max , const U& dummy1 , const V& dummy2 );

  inline void SetMin( const U& u , const V& v );
  // {最小値,傾きu（2個ある場合は小さい方）,y切片v}を返す。
  // uの大きい方が必要な場合は(6),(7)を満たすようにU,V,X全てをReversedに置き換える。
  inline tuple<ret_t<FUNC,const U&,const V&,const X&>,U,V> Get( const X& x );

};

template <typename U , typename V , typename X , typename INTERSECTION>
class AbstractTwoAryHierarchyIntersection :
  virtual public VirtualTwoAryHierarchyIntersection<U,V,X>
{

private:
  INTERSECTION m_intersection;

public:
  inline AbstractTwoAryHierarchyIntersection( INTERSECTION intersection );

protected:
  inline X Intersection( const U& u0 , const V& v0 , const U& u1 , const V& v1 );

};

template <typename U , typename V , typename X , typename FUNC , typename INTERSECTION>
class AbstractMaxTwoAryHierarchy :
  public VirtualMaxTwoAryHierarchy<U,V,X,FUNC> ,
  public AbstractTwoAryHierarchyIntersection<U,V,X,INTERSECTION>
{

public:
  inline AbstractMaxTwoAryHierarchy( FUNC func , const X& x_min , const X& x_max , const U& dummy1 , const V& dummy2 , INTERSECTION intersection );

};

template <typename U , typename V , typename X , typename FUNC , typename INTERSECTION>
class AbstractMinTwoAryHierarchy :
  public VirtualMinTwoAryHierarchy<U,V,X,FUNC> ,
  public AbstractTwoAryHierarchyIntersection<U,V,X,INTERSECTION>
{

public:
  inline AbstractMinTwoAryHierarchy( FUNC func , const X& x_min , const X& x_max , const U& dummy1 , const V& dummy2 , INTERSECTION intersection );
  
};

