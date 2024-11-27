// c:/Users/user/Documents/Programming/Mathematics/Geometry/Graph/Algorithm/BellmanFord/a_Macro.hpp

#pragma once

#define BELLMAN_FORD_BODY( INITIALISE_PREV , SET_PREV )			\
  const U& one = m_M.One();						\
  const U& infty = this->Infty();					\
  assert( one < infty );						\
  const int& size = m_G.size();						\
  auto&& i_start = m_G.Enumeration_inv( t_start );			\
  assert( 0 <= i_start && i_start < size );				\
  vector<U> weight( size , infty ) , weight_copy;			\
  weight[i_start] = one;						\
  vector<bool> found( size );						\
  found[i_start] = true;						\
  INITIALISE_PREV;							\
									\
  if( path_length == -1 ){						\
									\
    path_length = min( size - 1 , int( m_edge.size() ) );		\
									\
  } else {								\
									\
    assert( many_edges );						\
									\
  }									\
									\
									\
  for( int num = 0 ; num < path_length ; num++ ){			\
									\
    for( auto& [i,j,w] : m_edge ){					\
									\
      if( found[i] ){							\
									\
	U temp = m_M.Product( weight[i] , w );				\
	U& weight_j = weight[j];					\
									\
	if( temp < weight_j ){						\
									\
	  weight_j = move( temp );					\
	  found[j] = true;						\
	  SET_PREV;							\
									\
	}								\
									\
      }									\
									\
    }									\
									\
  }									\
									\
									\
  vector<bool> valid( size , true );					\
									\
  for( auto& [i,j,w] : m_edge ){					\
									\
    valid[i] = valid[i] && ( !found[i] || !( m_M.Product( weight[i] , w ) < weight[j] ) ); \
									\
  }									\
									\
  vector<int> dfs{};							\
									\
  for( int i = 0 ; i < size ; i++ ){					\
									\
    if( !valid[i] ){							\
									\
      dfs.push_back( i );						\
									\
    }									\
									\
  }									\
									\
  while( !dfs.empty() ){						\
									\
    const int i = dfs.back();						\
    dfs.pop_back();							\
    auto&& edge_i = m_G.Edge( m_G.Enumeration( i ) );			\
									\
    for( auto& edge_ij : edge_i ){					\
									\
      auto&& j = m_G.Enumeration_inv( edge_ij );			\
									\
      if( valid[j] ){							\
									\
	valid[j] = false;						\
	dfs.push_back( j );						\
									\
      }									\
									\
    }									\
									\
  }									\


