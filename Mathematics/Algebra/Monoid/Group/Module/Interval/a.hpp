// c:/Users/user/Documents/Programming/Mathematics/Algebra/Monoid/Group/Module/Interval/a.hpp

#pragma once
#include "../a.hpp"

template <typename R , typename ABEL_GROUP , typename U , typename R_SET>
class AbstractIntervalRSet :
  public VirtualRSet<pair<R,R>,U> ,
  public R_SET
{

private:
  ABEL_GROUP m_L;

public:
  inline AbstractIntervalRSet( ABEL_GROUP L , R_SET M );

  inline U Action( const pair<R,R>& lr , U u );

};
template <typename ABEL_GROUP , typename R_SET> AbstractIntervalRSet( ABEL_GROUP , R_SET ) -> AbstractIntervalRSet<inner_t<ABEL_GROUP>,ABEL_GROUP,inner_t<R_SET>,R_SET>;

template <typename R , typename U>
class IntervalModule :
  public AbstractIntervalRSet<R,AdditiveGroup<R>,U,Module<R,U>>
{

public:
  inline IntervalModule();
  
};
