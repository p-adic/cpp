// c:/Users/user/Documents/Programming/Mathematics/Geometry/Graph/Algorithm/Dijkstra/Double/Grid/a_Body.hpp

#pragma once
#include "a.hpp"

#include "../a_Body.hpp"
#include "../../../../Graph/Linear/a_Body.hpp"
#include "../../../../Graph/Grid/a_Body.hpp"

#include "../../../../../../Utility/Vector/a_Body.hpp"

inline vector<int> GridVertex( const int& i ){ return id<>( W ); }

template <typename E> inline GridDijkstra<E>::GridDijkstra( E e , const int& direction ) : DoubleDijkstra<int,LinearGraph,int,decldecay_t(declval<E>()({0,0}).front().second),GridGraph<E>,vector<int>(&)(const int&)>( LinearGraph( H , direction ) , GridGraph( move( e ) ) , GridVertex ) { assert( direction == 1 || direction == 2 ); }
