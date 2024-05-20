// c:/Users/user/Documents/Programming/Mathematics/Geometry/Graph/Acyclic/Double/Grid/a_Body.hpp

#pragma once
#include "a.hpp"

#include "../a_Body.hpp"
#include "../../../Linear/a_Body.hpp"
#include "../../../Grid/a_Body.hpp"

#include "../../../../../../Utility/Vector/a_Body.hpp"

inline vector<int> GridVertex( const int& i ){ return id<>( W ); }

template <typename E> inline AcyclicGridGraph<E>::AcyclicGridGraph( E e , const int& direction ) : AcyclicDoubleGraph<int,LinearGraph,int,decldecay_t(declval<E>()({0,0}).front().second),GridGraph<E>,vector<int>(&)(const int&)>( LinearGraph( H , direction ) , GridGraph( move( e ) ) , GridVertex ) { assert( direction == 1 || direction == 2 ); }
