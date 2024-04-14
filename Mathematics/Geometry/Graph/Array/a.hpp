// c:/Users/user/Documents/Programming/Mathematics/Geometry/Graph/Array/a.hpp

#pragma once
#include "../a.hpp"

class LinearEdge
{

private:
  int m_size;
  bool m_directed;

public:
  inline LinearEdge( const int& size , const bool& directed = true );
  inline vector<int> operator()( const int& t );

};

class LinearGraph :
  public Graph<LinearEdge>
{

public:
  inline LinearGraph( const int& size , const bool& directed = true );

};
