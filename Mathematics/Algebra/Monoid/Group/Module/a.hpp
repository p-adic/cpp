// c:/Users/user/Documents/Programming/Mathematics/Algebra/Monoid/Group/Module/a.hpp

#pragma once
#include "../a.hpp"

// verify:
// https://yukicoder.me/submissions/950182（Module）

template <typename R , typename U>
class VirtualModule
{

public:
  virtual U Action( const R& r , const U& u ) = 0;
  inline U Power( const U& u , const R& r );
  inline U ScalarProduct( const R& r , const U& u );

};

template <typename R , typename U , typename O_U , typename GROUP>
class AbstractModule :
  virtual public VirtualModule<R,U> ,
  public GROUP
{

private:
  O_U m_o_U;
  
public:
  // 型推論のために余計な引数dummyが必要
  inline AbstractModule( const R& dummy , O_U o_U , GROUP M );
  inline U Action( const R& r , const U& u );

};
template <typename R , typename O_U , typename GROUP> AbstractModule( const R& dummy , O_U o_U , GROUP M ) -> AbstractModule<R,inner_t<GROUP>,O_U,GROUP>;

template <typename R , typename U>
class Module :
  virtual public VirtualModule<R,U> ,
  public AdditiveGroup<U>
{

private:
  inline U Action( const R& r , const U& u );
  
};
