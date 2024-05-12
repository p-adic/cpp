// c:/Users/user/Documents/Programming/Mathematics/Geometry/Graph/Discrete/a_Body.hpp

#pragma once
#include "../a.hpp"

#include "../a_Body.hpp"

inline vector<int> DiscreteEdge::operator()( const int& ) { return {}; }

inline DiscreteGraph::DiscreteGraph( const int& size ) : Graph<DiscreteEdge>( size , DiscreteEdge() ) {}
