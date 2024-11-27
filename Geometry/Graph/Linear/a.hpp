// c:/Users/user/Documents/Programming/Mathematics/Geometry/Graph/Linear/a.hpp

#pragma once
#include "../a.hpp"

class LinearEdge
{

private:
  int m_size;
  // 0: —£U
  // 1: ³•ûŒü
  // 2: •‰•ûŒü
  // 3: ³•‰—¼•ûŒü
  int m_direction;

public:
  inline LinearEdge( const int& size , const int& direction );
  inline vector<int> operator()( const int& t );

};

class LinearGraph :
  public Graph<LinearEdge>
{

public:
  inline LinearGraph( const int& size , const int& direction = 1 );

};
