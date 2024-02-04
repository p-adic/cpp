// c:/Users/user/Documents/Programming/Mathematics/Algebra/Monoid/Group/Module/a.hpp

#pragma once
#include "../a.hpp"

// verify:
// https://yukicoder.me/submissions/947868（Module）

template <typename R , typename U>
class VirtualModule :
  virtual public VirtualGroup<U>
{

public:
  virtual inline U Act( const R& r , const U& u ) = 0;

};

template <typename R , typename U , typename O_U , typename M_U , typename I_U>
class AbstractModule :
  virtual public VirtualModule<R,U> ,
  public AbstractGroup<U,M_U,I_U>
{

private:
  O_U& m_o_U;
  
public:
  // 型推論のために余計な引数dummyが必要
  inline AbstractModule( const R& dummy , O_U& o_U , M_U& m_U , const U& e_U , I_U& i_U );
  inline U Act( const R& r , const U& u );

};

template <typename R , typename U>
class Module :
  virtual public VirtualModule<R,U> ,
  public AdditiveGroup<U>
{

public:
  inline U Act( const R& r , const U& u );

};
