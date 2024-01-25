// c:/Users/user/Documents/Programming/Mathematics/Algebra/Monoid/Semirng/Ring/a.hpp

#pragma once
#include "../a.hpp"

// verify:
// https://yukicoder.me/submissions/946132（Ring）
// https://yukicoder.me/submissions/946198（AbstractRing）

template <typename U , typename GROUP , typename MONOID>
class VirtualRing :
  virtual public VirtualSemirng<U,GROUP,MONOID>
{

public:
virtual U Inverse( const U& u ) = 0;
virtual const U& One() const noexcept = 0;
inline GROUP& AdditiveGroup() noexcept;
inline MONOID& MultiplicativeMonoid() noexcept;

};

template <typename U , typename GROUP , typename MONOID>
class AbstractRing :
virtual public VirtualRing<U,GROUP,MONOID> ,
public AbstractSemirng<U,GROUP,MONOID>
{

public:
inline AbstractRing( GROUP R0 , MONOID R1 );
inline U Inverse( const U& u );
inline const U& One() const noexcept;

};

template <typename U = ll>
class Ring :
virtual public AbstractRing<U,AdditiveGroup<U>,MultiplicativeMonoid<U>>
{

public:
inline Ring( const U& one_U );

};
