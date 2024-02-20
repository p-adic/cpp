// c:/Users/user/Documents/Programming/Mathematics/Geometry/Graph/TopologicalSort/a_Body.hpp

#pragma once
#include "a.hpp"

#include "../a_Body.hpp"

template <typename T , typename PATH , typename GRAPH> inline void TopologicalSort_Body( GRAPH& G , list<T>& answer , const PATH& e , vector<bool>& found );
template <typename T , typename GRAPH> inline void TopologicalSort_Body( GRAPH& G , list<T>& answer , const T& t , vector<bool>& found );

template <typename T , typename GRAPH>
void TopologicalSort_Body( GRAPH& G , list<T>& answer , const T& t , const int& i , vector<bool>& found )
{

  if( !found[i] ){

    found[i] = true;
    auto&& edge_i = G.Edge( t );

    for( auto itr = edge_i.begin() , end = edge_i.end() ; itr != end ; itr++ ){

      TopologicalSort_Body( G , answer , *itr , found );

    }

    answer.push_front( t );

  }

  return;

}

template <typename T , typename PATH , typename GRAPH> inline void TopologicalSort_Body( GRAPH& G , list<T>& answer , const PATH& e , vector<bool>& found ) { TopologicalSort_Body( G , answer , get<0>( e ) , found ); }
template <typename T , typename GRAPH> inline void TopologicalSort_Body( GRAPH& G , list<T>& answer , const T& t , vector<bool>& found ) { TopologicalSort_Body( G , answer , t , G.Enumeration_inv( t ) , found ); }

template <typename GRAPH>
list<inner_t<GRAPH>> TopologicalSort( GRAPH& G )
{

  list<inner_t<GRAPH>> answer{};
  const int& size = G.size();
  vector<bool> found( size );

  for( int i = 0 ; i < size ; i++ ){

    TopologicalSort_Body( G , answer , G.Enumeration( i ) , i , found );

  }

  return answer;

}

template <typename GRAPH , typename MONOID> pair<inner_t<MONOID>,list<inner_t<GRAPH>>> GetLongestWalk( GRAPH& G , MONOID M )
{

  using T = inner_t<GRAPH>;
  using U = inner_t<MONOID>;
  const int& size = G.size();
  const U& one = M.One();

  if( size == 0 ){

    return { one , list<T>() };

  }
  
  list<T> top_sort = TopologicalSort( G );
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
