// c:/Users/user/Documents/Programming/Mathematics/Geometry/Graph/Acyclic/LongestWalk/a_Body.hpp

#pragma once
#include "a.hpp"

#include "../a_Body.hpp"


template <typename ACYCLIC_GRAPH , typename MONOID> pair<inner_t<MONOID>,list<inner_t<ACYCLIC_GRAPH>>> GetLongestWalk( ACYCLIC_GRAPH& G , MONOID M )
{

  using T = inner_t<ACYCLIC_GRAPH>;
  using U = inner_t<MONOID>;
  const int& size = G.size();
  const U& one = M.One();

  if( size == 0 ){

    return { one , list<T>() };

  }
  
  vector<T> top_sort = TopologicalSort( G );
  vector<U> dp( size , one );
  vector<int> prev( size , -1 );

  for( auto itr_vertex = top_sort.begin() , end_vertex = top_sort.end() ; itr_vertex != end_vertex ; itr_vertex++ ){

    auto&& edge_i = G.Edge( *itr_vertex );
    auto&& i = G.Enumeration_inv( *itr_vertex );
    const U& dp_i = dp[i];

    for( auto itr_edge_i = edge_i.begin() , end_edge_i = edge_i.end() ; itr_edge_i != end_edge_i ; itr_edge_i++ ){
      auto& [t,u] = *itr_edge_i;
      auto&& j = G.Enumeration_inv( t );
      U& dp_j = dp[j];

      if( !( dp_i < dp_j ) ){

	dp_j = M.Product( dp_i , u );
	prev[j]	= i;

      }

    }

  }

  U answer = one;
  int end_num = -1;

  for( int i = 0 ; i < size ; i++ ){

    const U& dp_i = dp[i];

    if( end_num == -1 || answer < dp_i ){
      
      answer = dp_i;
      end_num = i;

    }

  }

  list<T> path{};

  while( end_num != -1 ){

    path.push_front( G.Enumeration( end_num ) );
    end_num = prev[end_num];

  }

  return { move( answer ) , move( path ) };

}
