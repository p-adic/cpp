// c:/Users/user/Documents/Programming/Mathematics/Algebra/Monoid/a.hpp

#pragma once
#include "../a.hpp"

template <typename U>
class VirtualMonoid :
  virtual public VirtualMagma<U> ,
  virtual public VirtualPointedSet<U>
{};

template <typename U = ll>
class AdditiveMonoid :
  virtual public VirtualMonoid<U> ,
  public PointedSet<U>
{

public:
  inline U Product( const U& u0 , const U& u1 );

};

template <typename U = ll>
class MultiplicativeMonoid :
  virtual public VirtualMonoid<U> ,
  public PointedSet<U>
{

public:
  inline MultiplicativeMonoid( const U& e_U );
  inline U Product( const U& u0 , const U& u1 );

};

template <typename U , typename M_U>
class AbstractMonoid :
  virtual public VirtualMonoid<U> ,
  public AbstractMagma<U,M_U> ,
  public PointedSet<U>
{

public:
  inline AbstractMonoid( M_U m_U , const U& e_U );
  inline U Product( const U& u0 , const U& u1 );

};
