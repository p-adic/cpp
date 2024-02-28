// c:/Users/user/Documents/Programming/Mathematics/Algebra/Monoid/Group/a.hpp

#pragma once
#include "../a.hpp"

template <typename U>
class VirtualGroup :
  virtual public VirtualMonoid<U> ,
  virtual public VirtualPointedSet<U> ,
  virtual public VirtualNSet<U>
{};

template <typename U = ll>
class AdditiveGroup :
  virtual public VirtualGroup<U> ,
  public AdditiveMonoid<U>
{

public:
  inline U Transfer( const U& u );

};

template <typename U , typename M_U , typename I_U>
class AbstractGroup :
  virtual public VirtualGroup<U> ,
  public AbstractMonoid<U,M_U> ,
  public AbstractNSet<U,I_U>
{

public:
  inline AbstractGroup( M_U m_U , const U& e_U , I_U i_U );

};
