// c:/Users/user/Documents/Programming/Mathematics/Algebra/Monoid/Group/Module/a.hpp

#pragma once
#include "../a.hpp"

// verify:
// https://yukicoder.me/submissions/961537（AbstractRSet）
// https://yukicoder.me/submissions/950182（Module）

template <typename R , typename U>
class VirtualModule :
  virtual public UnderlyingSet<U>
{

public:
  virtual U Action( const R& r , const U& u ) = 0;
  inline U Power( const U& u , const R& r );
  inline U ScalarProduct( const R& r , const U& u );

};

template <typename R , typename U , typename O_U>
class AbstractRSet :
  virtual public VirtualModule<R,U>
{

private:
  O_U m_o_U;
  
public:
  // 型推論のために余計な引数dummy0,dummy1が必要
  inline AbstractRSet( const R& dummy0 , const U& dummy1 , O_U o_U );
  inline U Action( const R& r , const U& u );

};

template <typename R , typename U , typename O_U , typename GROUP>
class AbstractModule :
  public AbstractRSet<R,U,O_U> ,
  public GROUP
{

public:
  // 型推論のために余計な引数dummyが必要
  inline AbstractModule( const R& dummy , O_U o_U , GROUP M );

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
