// c:/Users/user/Documents/Programming/Mathematics/Geometry/Graph/Algorithm/DepthFirstSearch/a_Body.hpp

#pragma once
#include "a.hpp"

#ifdef DEBUG
  #include "../BreadthFirstSearch/Debug/a_Body.hpp"
#else
  #include "../BreadthFirstSearch/a_Body.hpp"
#endif

template <typename T , typename GRAPH> template <typename...Args> inline DepthFirstSearch<T,GRAPH>::DepthFirstSearch( GRAPH& G , const T& not_found , Args&&... args ) : VirtualBreadthFirstSearch<T,GRAPH>( G , not_found , forward<Args>( args )... ) {}

template <typename T , typename GRAPH> inline void DepthFirstSearch<T,GRAPH>::Push( list<T>& next , const T& t ) { next.push_front( t ); }
