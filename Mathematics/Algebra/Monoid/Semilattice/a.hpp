// c:/Users/user/Documents/Programming/Mathematics/Algebra/Monoid/Semilattice/a.hpp

#pragma once
#include "../a.hpp"

// verify:
// https://yukicoder.me/submissions/946106（MinSemilattice）
// https://yukicoder.me/submissions/947872（MaxSemilattice）

template <typename U>
class VirtualMeetSemilattice :
  virtual public VirtualMonoid<U>
{

public:
  inline U Meet( const U& u0 , const U& u1 );

};

template <typename U>
class MinSemilattice :
  virtual public VirtualMeetSemilattice<U> ,
  public PointedSet<U>
{

public:
  inline MinSemilattice( const U& infty_U );
  inline U Product( const U& u0 , const U& u1 );
  
};

template <typename U>
class MaxSemilattice :
  virtual public VirtualMeetSemilattice<U> ,
  public PointedSet<U>
{

public:
  inline MaxSemilattice( const U& zero_U );
  inline U Product( const U& u0 , const U& u1 );
  
};

