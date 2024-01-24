// c:/Users/user/Documents/Programming/Mathematics/Algebra/Monoid/Semirng/MeetSemirng/a.hpp

#pragma once
#include "../a.hpp"
#include "../../Semilattice/a.hpp"

template <typename U , typename MEET_SEMILATTICE , typename SEMIGROUP>
class VirtualMeetSemirng :
  virtual public VirtualSemirng<U,MEET_SEMILATTICE,SEMIGROUP>
{

public:
  inline const U& Infty();
  inline U Meet( const U& u0 , const U& u1 );

};

template <typename U , typename SEMIGROUP>
class AbstractTropicalSemirng :
  virtual public VirtualMeetSemirng<U,MinSemilattice<U>,SEMIGROUP> ,
  public AbstractSemirng<U,MinSemilattice<U>,SEMIGROUP>
{

public:
  inline AbstractTropicalSemirng( const U& infty_U , SEMIGROUP M );
  inline U Product( const U& u0 , const U& u1 );

};

template <typename U>
class AdditiveTropicalSemirng :
  public AbstractTropicalSemirng<U,AdditiveMagma<U>>
{

public:
  inline AdditiveTropicalSemirng( const U& infty_U );

};

template <typename U>
class MultiplicativeTropicalSemirng :
  public AbstractTropicalSemirng<U,MultiplicativeMagma<U>>
{

public:
  inline MultiplicativeTropicalSemirng( const U& infty_U );

};
