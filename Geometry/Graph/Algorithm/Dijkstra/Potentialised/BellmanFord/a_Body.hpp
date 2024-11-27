// c:/Users/user/Documents/Programming/Mathematics/Geometry/Graph/Algorithm/Dijkstra/Potentialised/BellmanFord/a_Body.hpp

#pragma once
#include "a.hpp"

#ifdef DEBUG
  #include "../Debug/a_Body.hpp"
#else
  #include "../a_Body.hpp"
#endif
#include "../../../BellmanFord/a_Body.hpp"

template <typename T , typename GRAPH , typename U , typename GROUP , typename On> inline AbstractBellmanFordPotentialisedDijkstra<T,GRAPH,U,GROUP,On>::AbstractBellmanFordPotentialisedDijkstra( GRAPH& G , GROUP M , const T& t_start , const U& infty , On on ) : AbstractBellmanFordPotentialisedDijkstra( G , M , t_start , infty , on , AbstractBellmanFord( G , M , infty ).GetDistance( t_start ) ) {}
template <typename T , typename GRAPH , typename U , typename GROUP , typename On> inline AbstractBellmanFordPotentialisedDijkstra<T,GRAPH,U,GROUP,On>::AbstractBellmanFordPotentialisedDijkstra( GRAPH& G , GROUP& M , const T& t_start , const U& infty , On& on , tuple<vector<bool>,vector<U>> vp ) : AbstractBellmanFordPotentialisedDijkstra( G , move( M ) , t_start , infty , move( on ) , move( get<1>( vp ) ) ) { for( auto valid : get<0>( vp ) ){ assert( valid ); } }
template <typename T , typename GRAPH , typename U , typename GROUP , typename On> inline AbstractBellmanFordPotentialisedDijkstra<T,GRAPH,U,GROUP,On>::AbstractBellmanFordPotentialisedDijkstra( GRAPH& G , GROUP M , const T& t_start , const U& infty , On on , vector<U> potential ) : AbstractPotentialisedDijkstra<T,GRAPH,U,GROUP,On>( G , move( M ) , t_start , infty , move( on ) , move( potential ) ) {}

template <typename T , typename GRAPH , typename On> template <typename...Args> inline BellmanFordPotentialisedDijkstra<T,GRAPH,On>::BellmanFordPotentialisedDijkstra( GRAPH& G , const T& t_start , On on , Args&&... args ) : AbstractBellmanFordPotentialisedDijkstra<T,GRAPH,ll,AdditiveGroup<>,On>( G , AdditiveGroup<>() , t_start , 1e18 , move( on ) , forward<decay_t<Args>>( args )... ) {}
