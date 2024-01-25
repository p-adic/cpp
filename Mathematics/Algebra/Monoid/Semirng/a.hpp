// c:/Users/user/Documents/Programming/Mathematics/Algebra/Monoid/Semirng/a.hpp

#pragma once
#include "../a.hpp"

template <typename U , typename MONOID , typename SEMIGROUP>
class VirtualSemirng
{

public:
  virtual U Sum( const U& u0 , const U& u1 ) = 0;
  virtual const U& Zero() const noexcept = 0;
  virtual U Product( const U& u0 , const U& u1 ) = 0;
  virtual MONOID& AdditiveMonoid() noexcept = 0;
  virtual SEMIGROUP& MultiplicativeSemigroup() noexcept = 0;
  using type = U;

};

template <typename U , typename MONOID , typename SEMIGROUP>
class AbstractSemirng :
  virtual public VirtualSemirng<U,MONOID,SEMIGROUP>

{

protected:
  MONOID m_R0;
  SEMIGROUP m_R1;

public:
  inline AbstractSemirng( MONOID R0 , SEMIGROUP R1 );
  inline U Sum( const U& u0 , const U& u1 );
  inline const U& Zero() const noexcept;
  inline U Product( const U& u0 , const U& u1 );
  inline MONOID& AdditiveMonoid() noexcept;
  inline SEMIGROUP& MultiplicativeSemigroup() noexcept;

};

template <typename U>
class Semirng :
  public AbstractSemirng<U,AdditiveMonoid<U>,MultiplicativeMagma<U>>
{

public:
  inline Semirng();

};
