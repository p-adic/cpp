// c:/Users/user/Documents/Programming/Mathematics/Geometry/Graph/Acyclic/a_Body.hpp

#pragma once
#include "a.hpp"

#include "../a_Body.hpp"

template <typename T , typename PATH , typename ACYCLIC_GRAPH> inline void TopologicalSort_Body( ACYCLIC_GRAPH& G , vector<T>& answer , const PATH& e , vector<bool>& found , int& num );
template <typename T , typename ACYCLIC_GRAPH> inline void TopologicalSort_Body( ACYCLIC_GRAPH& G , vector<T>& answer , const T& t , vector<bool>& found , int& num );

template <typename T , typename ACYCLIC_GRAPH>
void TopologicalSort_Body( ACYCLIC_GRAPH& G , vector<T>& answer , const T& t , const int& i , vector<bool>& found , int& num )
{

  if( !found[i] ){

    found[i] = true;
    auto&& edge_i = G.Edge( t );

    for( auto itr = edge_i.begin() , end = edge_i.end() ; itr != end ; itr++ ){

      TopologicalSort_Body( G , answer , *itr , found , num );

    }

    answer[num--] = t;

  }

  return;

}

template <typename T , typename PATH , typename ACYCLIC_GRAPH> inline void TopologicalSort_Body( ACYCLIC_GRAPH& G , vector<T>& answer , const PATH& e , vector<bool>& found , int& num ) { TopologicalSort_Body( G , answer , get<0>( e ) , found , num ); }
template <typename T , typename ACYCLIC_GRAPH> inline void TopologicalSort_Body( ACYCLIC_GRAPH& G , vector<T>& answer , const T& t , vector<bool>& found , int& num ) { TopologicalSort_Body( G , answer , t , G.Enumeration_inv( t ) , found , num ); }

template <typename ACYCLIC_GRAPH>
vector<inner_t<ACYCLIC_GRAPH>> TopologicalSort( ACYCLIC_GRAPH& G )
{

  const int& size = G.size();
  vector<inner_t<ACYCLIC_GRAPH>> answer( size );
  vector<bool> found( size );
  int num = size - 1;

  for( int i = 0 ; i < size ; i++ ){

    TopologicalSort_Body( G , answer , G.Enumeration( i ) , i , found , num );

  }

  return answer;

}

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
