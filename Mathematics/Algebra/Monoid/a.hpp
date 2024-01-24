// c:/Users/user/Documents/Programming/Mathematics/Algebra/Monoid/a.hpp

#pragma once
#include "../a.hpp"

// verify:
// https://yukicoder.me/submissions/945944ÅiAbstractMonoidÅj

template <typename U>
class VirtualMonoid :
  virtual public VirtualMagma<U> ,
  virtual public VirtualPointedSet<U>
{};

template <typename U = ll>
class AdditiveMonoid :
  virtual public VirtualMonoid<U> ,
  public AdditiveMagma<U> ,
  public PointedSet<U>
{};

template <typename U = ll>
class MultiplicativeMonoid :
  virtual public VirtualMonoid<U> ,
  public MultiplicativeMagma<U> ,
  public PointedSet<U>
{

public:
  inline MultiplicativeMonoid( const U& e_U );

};

template <typename U , typename M_U>
class AbstractMonoid :
  virtual public VirtualMonoid<U> ,
  public AbstractMagma<U,M_U> ,
  public PointedSet<U>
{

public:
  inline AbstractMonoid( M_U& m_U , const U& e_U );

};
