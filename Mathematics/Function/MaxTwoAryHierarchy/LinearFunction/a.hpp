// c:/Users/user/Documents/Programming/Mathematics/Function/MaxTwoAryHierarchy/LinearFunction/a.hpp

#pragma once
#include "../a.hpp"

// verify:
// https://yukicoder.me/submissions/981613

template <typename INT>
class LinearFunction
{

public:
  inline constexpr INT operator()( const INT& u , const INT& v , const INT& x );

};

template <typename INT>
class LinearFunctionIntersection :
  virtual public VirtualTwoAryHierarchyIntersection<INT,INT,INT> ,
  virtual public VirtualTwoAryHierarchyIntersection<Reversed<INT>,Reversed<INT>,INT>
{

public:
  inline INT Intersection( const INT& u0 , const INT& v0 , const INT& u1 , const INT& v1 );
  inline INT Intersection( const Reversed<INT>& u0 , const Reversed<INT>& v0 , const Reversed<INT>& u1 , const Reversed<INT>& v1 );

};

// 構築O(N log N)
// 一次関数ux+vとのmaxによる全体更新O(log(N + Q))（均し）
// 一点取得O(log(N + Q))
template <typename INT>
class MaxLinearFunction :
  public VirtualMaxTwoAryHierarchy<INT,INT,INT,LinearFunction<INT>> ,
  public LinearFunctionIntersection<INT>
{

public:
  inline MaxLinearFunction( const INT& x_min , const INT& x_max , const INT& u = 0 , const INT& v = 0 );

};

template <typename INT>
class MinLinearFunction :
  public VirtualMinTwoAryHierarchy<INT,INT,INT,LinearFunction<INT>> ,
  public LinearFunctionIntersection<INT>
{

public:
  inline MinLinearFunction( const INT& x_min , const INT& x_max , const INT& u = 0 , const INT& v = 0 );

};

