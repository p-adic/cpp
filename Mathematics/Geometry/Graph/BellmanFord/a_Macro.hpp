// c:/Users/user/Documents/Programming/Mathematics/Geometry/Graph/BellmanFord/a_Macro.hpp

#pragma once

#define BELLMAN_FORD_BODY( INITIALISE_PREV , SET_PREV )		\
  const U& one = m_M.One();					\
  const U& infty = this->Infty();				\
  assert( one < infty );					\
  const int& size = m_G.size();					\
  auto&& i_start = m_G.Enumeration_inv( t_start );		\
  assert( 0 <= i_start && i_start < size );			\
  vector<U> weight( size , infty ) , weight_copy;		\
  weight[i_start] = one;					\
  vector<bool> found( size );					\
  found[i_start] = true;					\
  INITIALISE_PREV;						\
								\
  if( path_length == -1 ){					\
								\
    path_length = size - 1;					\
								\
  } else {							\
								\
    assert( many_edges );					\
								\
  }								\
								\
  for( int num = 0 ; num < path_length ; num++ ){		\
								\
    for( int i = 0 ; i < size ; i++ ){				\
								\
      const U& weight_i = weight[i];				\
								\
      if( found[i] ){						\
								\
	auto&& edge_i = m_G.Edge( m_G.Enumeration( i ) );	\
								\
	for( auto& edge_ij : edge_i ){				\
								\
	  auto&& j = m_G.Enumeration_inv( edge_ij.first );	\
	  const U& weight_ij = edge_ij.second;			\
	  U temp = m_M.Product( weight_i , weight_ij );		\
	  U& weight_j = weight[j];				\
								\
	  if( weight_j > temp ){				\
								\
	    weight_j = move( temp );				\
	    found[j] = true;					\
	    SET_PREV;						\
								\
	  }							\
								\
	}							\
								\
      }								\
								\
    }								\
								\
  }								\
								\
  vector<bool> invalid( size );					\
								\
  for( int i = 0 ; i < size ; i++ ){				\
								\
    if( found[i] ){						\
								\
      const U& weight_i = weight[i];				\
      auto&& edge_i = m_G.Edge( m_G.Enumeration( i ) );		\
								\
      for( auto& edge_ij : edge_i ){				\
								\
	auto&& j = m_G.Enumeration_inv( edge_ij.first );	\
	const U& weight_ij = edge_ij.second;			\
	U& weight_j = weight[j];				\
	const U temp = m_M.Product( weight_i , weight_ij );	\
								\
	if( weight_j > temp ){					\
								\
	  invalid[i] = true;					\
								\
	}							\
								\
      }								\
								\
    }								\
								\
  }								\
								\
  vector<int> dfs{};						\
								\
  for( int i = 0 ; i < size ; i++ ){				\
								\
    if( invalid[i] ){						\
								\
      dfs.push_back( i );					\
								\
    }								\
								\
  }								\
								\
  while( !dfs.empty() ){					\
								\
    const int i = dfs.back();					\
    dfs.pop_back();						\
    auto&& edge_i = m_G.Edge( m_G.Enumeration( i ) );		\
								\
    for( auto& edge_ij : edge_i ){				\
								\
      auto&& j = m_G.Enumeration_inv( edge_ij.first );		\
								\
      if( !invalid[j] ){					\
								\
	invalid[j] = true;					\
	dfs.push_back( j );					\
								\
      }								\
								\
    }								\
								\
  }								\
								\
  for( int i = 0 ; i < size ; i++ ){				\
								\
    found[i] = found[i] && !invalid[i];				\
								\
  }								\


