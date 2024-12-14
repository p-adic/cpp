// c:/Users/user/Documents/Programming/Mathematics/Function/ConvexHullTrick/BinarySearch/a.hpp

#pragma once
#include "../a.hpp"

// verify:
// https://yukicoder.me/submissions/995705（一次関数）
// https://yukicoder.me/submissions/995704（等差数列との差の絶対値）

// X=INTにおいて二分探索を行うため、Xを反転させる時はReversed<X>でなくoperator-()を使うこと。

template <typename U , typename V , typename INT , typename FUNC>
class CrossingHierarchyBinarySearchIntersection :
  virtual public VirtualCrossingHierarchyIntersection<U,V,INT>
{

private:
  FUNC* m_p_func;
  const INT* m_p_x_min;
  const INT* m_p_x_max;

public:
  inline CrossingHierarchyBinarySearchIntersection( FUNC& func , const INT& x_min , const INT& x_max );

protected:
  INT Intersection( const U& u0 , const V& v0 , const U& u1 , const V& v1 );

};

// 構築O(N log N)
// func(u,v,-)とのmaxによる全体更新O(log(N + Q))（均し）
// 一点取得O(log(N + Q))
template <typename U , typename V , typename INT , typename FUNC>
class MaxCrossingHierarchyBinarySearch :
  public VirtualMaxCrossingHierarchy<U,V,INT,FUNC> ,
  public CrossingHierarchyBinarySearchIntersection<U,V,INT,FUNC>
{

public:
  inline MaxCrossingHierarchyBinarySearch( FUNC func , const INT& x_min , const INT& x_max , const U& dummy1 , const V& dummy2 );

};

template <typename U , typename V , typename INT , typename FUNC>
class MinCrossingHierarchyBinarySearch :
  public VirtualMinCrossingHierarchy<U,V,INT,FUNC> ,
  public CrossingHierarchyBinarySearchIntersection<Reversed<U>,Reversed<V>,INT,ReversedCrossingHierarchy<U,V,INT,FUNC>>
{

public:
  inline MinCrossingHierarchyBinarySearch( FUNC func , const INT& x_min , const INT& x_max , const U& dummy1 , const V& dummy2 );
  
};

