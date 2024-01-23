// c:/Users/user/Documents/Programming/Mathematics/Geometry/Graph/DepthFirstSearch/a_Body.hpp

#pragma once
#include "a.hpp"

#include "../BreadFirst/a_Body.hpp"

template <typename GRAPH> template <typename...Args> inline DepthFirstSearch<GRAPH>::DepthFirstSearch( GRAPH& G , const Args&... args ) : VirtualBreadthFirstSearch<GRAPH>( G , args... ) {}

template <typename GRAPH> inline void DepthFirstSearch<GRAPH>::Push( list<int>& next , const int& i ) { next.push_front( i ); }
