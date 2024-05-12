// c:/Users/user/Documents/Programming/Mathematics/Geometry/Graph/Discrete/a.hpp

#pragma once
#include "../a.hpp"

class DiscreteEdge
{

public:
  inline vector<int> operator()( const int& );

};

class DiscreteGraph :
  public Graph<DiscreteEdge>
{

public:
  inline DiscreteGraph( const int& size );

};
