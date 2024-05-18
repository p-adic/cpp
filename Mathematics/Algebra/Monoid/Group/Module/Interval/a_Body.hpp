// c:/Users/user/Documents/Programming/Mathematics/Algebra/Monoid/Group/Module/Interval/a_Body.hpp

#pragma once
#include "a.hpp"

#include "../a_Body.hpp"

template <typename R , typename ABEL_GROUP , typename U , typename R_SET> inline AbstractIntervalRSet<R,ABEL_GROUP,U,R_SET>::AbstractIntervalRSet( ABEL_GROUP L , R_SET M ) : R_SET( move( M ) ) , m_L( move( L ) ) { static_assert( is_same_v<R,inner_t<ABEL_GROUP>> && is_same_v<U,inner_t<R_SET>> ); }
template <typename R , typename U> IntervalModule<R,U>::IntervalModule() : AbstractIntervalRSet<R,AdditiveGroup<R>,U,Module<R,U>>( AdditiveGroup<R>() , Module<R,U>() ) {}

template <typename R , typename ABEL_GROUP , typename U , typename R_SET> inline U AbstractIntervalRSet<R,ABEL_GROUP,U,R_SET>::Action( const pair<R,R>& lr , U u ) { return R_SET::Action( m_L.Sum( lr.second , m_L.Inverse( lr.first ) ) , move( u ) ); }
