// c:/Users/user/Documents/Programming/Utility/Search/Dijkstra/a_Body.hpp

#pragma once
#include "a.hpp"

template <int size_max>
int Dijkstra( const map<int,int> ( &d )[size_max] , const int& i_start , const int& i_final , const int& size , const int& infty )
{

  DIJKSTRA_BODY( int , 0 , t + dij , , );
  return answer;
  
}

template <int size_max>
int Dijkstra( const map<int,int> ( &d )[size_max] , const int& i_start , const int& i_final , const int& size , const int& infty , list<int>& path )
{

  DIJKSTRA_BODY( int , 0 , t + dij , int prev[size_max] = {} , prev[j] = i );

  int i = i_final;

  while( i != i_start ){

    path.push_front( i );
    i = prev[i];

  }

  path.push_front( i_start );
  return answer;
  
}
