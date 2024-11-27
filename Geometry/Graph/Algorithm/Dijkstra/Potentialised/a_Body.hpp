// c:/Users/user/Documents/Programming/Mathematics/Geometry/Graph/Algorithm/Dijkstra/Potentialised/a_Body.hpp

#pragma once
#include "a.hpp"

#include "../../../../../Algebra/Monoid/Group/a_Body.hpp"

#include "../a_Body.hpp"

template <typename T , typename GRAPH , typename U , typename GROUP , typename On> inline AbstractPotentialisedDijkstra<T,GRAPH,U,GROUP,On>::AbstractPotentialisedDijkstra( GRAPH& G , GROUP M , const T& t_start , const U& infty , On on , vector<U> potential ) : PointedSet<U>( infty ) , m_G( G ) , m_M( move( M ) ) , m_t_start( t_start ) , m_on( move( on ) ) , m_potential( potential ) { static_assert( is_invocable_r_v<bool,On,decltype(declval<GRAPH>().Edge(declval<T>()).back())> ); if( m_potential.empty() ){ m_potential = vector<U>( m_G.size() , m_M.Zero() ); } else { assert( int( m_potential.size() ) == m_G.size() ); } }

template <typename T , typename GRAPH , typename On> template <typename...Args> inline PotentialisedDijkstra<T,GRAPH,On>::PotentialisedDijkstra( GRAPH& G , const T& t_start , On on , Args&&... args ) : AbstractPotentialisedDijkstra<T,GRAPH,ll,AdditiveGroup<>,On>( G , AdditiveGroup<>() , t_start , 1e18 , move( on ) , forward<decay_t<Args>>( args )... ) {}

template <typename T , typename GRAPH , typename U , typename GROUP , typename On> inline const vector<U>& AbstractPotentialisedDijkstra<T,GRAPH,U,GROUP,On>::Potential() const noexcept { return m_potential; }
template <typename T , typename GRAPH , typename U , typename GROUP , typename On> inline void AbstractPotentialisedDijkstra<T,GRAPH,U,GROUP,On>::SetPotential( vector<U> potential ) { assert( int( potential.size() ) == m_G.size() ); m_potential = move( potential ); }

template <typename T , typename GRAPH , typename U , typename GROUP , typename On> template <typename...Args> vector<U> AbstractPotentialisedDijkstra<T,GRAPH,U,GROUP,On>::GetDistance( Args&&... args ) { POTENTIALISED_DIJKSTRA_BODY( GetDistance( m_t_start , forward<Args>( args )... ) , value ); }
template <typename T , typename GRAPH , typename U , typename GROUP , typename On> template <typename...Args> pair<vector<U>,vector<list<T>>> AbstractPotentialisedDijkstra<T,GRAPH,U,GROUP,On>::GetPath( Args&&... args ) { POTENTIALISED_DIJKSTRA_BODY( GetPath( m_t_start , forward<Args>( args )... ) , get<0>( value ) ); }
