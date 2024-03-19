// c:/Users/user/Documents/Programming/Mathematics/Algebra/Monoid/Semilattice/a.hpp

#pragma once
#include "../a.hpp"

// verify:
// https://yukicoder.me/submissions/946106ÅiMinSemilatticeÅj

template <typename U>
class VirtualMeetSemilattice :
  virtual public VirtualMonoid<U>
{

public:
  inline U Meet( U u0 , const U& u1 );

};

template <typename U>
class MinSemilattice :
  virtual public VirtualMeetSemilattice<U> ,
  public PointedSet<U>
{

public:
  inline MinSemilattice( U infty_U );
  inline U Product( U u0 , const U& u1 );
  
};

template <typename U>
class MaxSemilattice :
  virtual public VirtualMeetSemilattice<U> ,
  public PointedSet<U>
{

public:
  inline MaxSemilattice( U zero_U );
  inline U Product( U u0 , const U& u1 );
  
};

