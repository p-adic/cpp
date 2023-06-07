// c:/Users/user/Documents/Programming/Utility/Search/Dijkstra/Template/a_Body.hpp

#pragma once
#include "a.hpp"

template <typename T , T m_T(const T&,const T&) , const T& e_T() , int size_max>
T Dijkstra( const map<int,T> ( &d )[size_max] , const int& i_start , const int& i_final , const int& size , const T& infty )
{

  ABSTRACT_DIJKSTRA_BODY( T , e_T() , m_T( t , dij ) , , );
  return answer;
  
}

template <typename T , T m_T(const T&,const T&) , const T& e_T() , int size_max>
T Dijkstra( const map<int,T> ( &d )[size_max] , const int& i_start , const int& i_final , const int& size , const T& infty , list<int>& path )
{

  ABSTRACT_DIJKSTRA_BODY( T , e_T() , m_T( t , dij ) , int prev[size_max] = {} , prev[j] = i );

  int i = i_final;

  while( i != i_start ){

    path.push_front( i );
    i = prev[i];

  }

  path.push_front( i_start );
  return answer;
  
}
