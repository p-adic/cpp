// c:/Users/user/Documents/Programming/Mathematics/Geometry/Graph/BellmanFord/a_Macro.hpp

#pragma once

#define BELLMAN_FORD_BODY( INITIALISE_PREV , SET_PREV )			\
  const U& zero = m_M.Zero();						\
  const U& infty = this->Infty();					\
  assert( zero < infty );						\
  const int& size = m_G.size();						\
  auto&& i_start = m_G.Enumeration_inv( t_start );			\
  assert( 0 <= i_start && i_start < size );				\
  vector<bool> found( size );						\
  vector<U> weight( size , infty );					\
  found[i_start] = true;						\
  weight[i_start] = 0;							\
  INITIALISE_PREV;							\
									\
  for( int length = 0 ; length < size ; length++ ){			\
  									\
    for( int i = 0 ; i < size ; i++ ){					\
									\
      if( found[i] ){							\
									\
	const U& weight_i = weight[i];					\
	assert( weight_i != infty );					\
	auto&& edge_i = m_G.Edge( m_G.Enumeration( i ) );		\
									\
	for( auto itr = edge_i.begin() , end = edge_i.end() ; itr != end ; itr++ ){ \
									\
	  auto&& j = m_G.Enumeration_inv( itr->first );			\
	  const U& edge_ij = itr->second;				\
	  U temp = m_M.Sum( weight_i , edge_ij );			\
	  U& weight_j = weight[j];					\
									\
	  if( weight_j > temp ){					\
									\
	    found[j] = true;						\
	    weight_j = move( temp );					\
	    SET_PREV;							\
									\
	  }								\
									\
	}								\
									\
      }									\
									\
    }									\
									\
  }									\
									\
  bool valid = true;							\
									\
  for( int i = 0 ; i < size && valid ; i++ ){				\
									\
    if( found[i] ){							\
									\
      const U& weight_i = weight[i];					\
      auto&& edge_i = m_G.Edge( m_G.Enumeration( i ) );			\
									\
      for( auto itr = edge_i.begin() , end = edge_i.end() ; itr != end ; itr++ ){ \
									\
	auto&& j = m_G.Enumeration_inv( itr->first );			\
	const U& edge_ij = itr->second;					\
	U& weight_j = weight[j];					\
	const U temp = m_M.Sum( weight_i , edge_ij );			\
									\
	if( weight_j > temp ){						\
									\
	  valid = false;						\
	  break;							\
									\
	}								\
									\
      }									\
									\
    }									\
									\
  }									\
