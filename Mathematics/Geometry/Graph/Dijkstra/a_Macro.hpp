// c:/Users/user/Documents/Programming/Mathematics/Geometry/Graph/Dijkstra/a_Macro.hpp

#pragma once

#define DIJKSTRA_PREP( INITIALISE_PREV )		\
  const U& one = m_M.One();				\
  assert( one < infty );				\
  auto&& i_start = m_G.Enumeration_inv( t_start );	\
  assert( 0 <= i_start && i_start < size );		\
  INITIALISE_PREV;					\

#define DIJKSTRA_BODY_1( SET_PREV )					\
  if( walk_length == -1 ){						\
									\
    walk_length = size - 1;						\
									\
  }									\
									\
  weight[i_start] = one;						\
  int i = i_start;							\
									\
  for( int num = 0 ; num < walk_length ; num++ ){			\
									\
    const U& weight_i = weight[i];					\
    fixed[i] = true;							\
    auto&& edge_i = m_G.Edge( m_G.Enumeration( i ) );			\
									\
    for( auto itr = edge_i.begin() , end = edge_i.end() ; itr != end ; itr++ ){ \
									\
      auto&& j = m_G.Enumeration_inv( itr->first );			\
      									\
      if( !fixed[j] ){							\
									\
	const U& edge_ij = get<1>( *itr );				\
	U temp = m_M.Product( weight_i , edge_ij );			\
	assert( temp < infty );						\
	U& weight_j = weight[j];					\
									\
	if( temp < weight_j ){						\
									\
	  SET_PREV;							\
	  weight_j = move( temp );					\
									\
	}								\
									\
      }									\
									\
    }									\
									\
    U temp = infty;							\
									\
    for( int j = 0 ; j < size ; j++ ){					\
									\
      if( !fixed[j] ){							\
									\
	U& weight_j = weight[j];					\
									\
	if( weight_j < temp ){						\
									\
	  temp = weight_j;						\
	  i = j;							\
									\
	}								\
									\
      }									\
									\
    }									\
									\
  }									\

#define DIJKSTRA_BODY_2( CHECK_FINAL , SET_PREV )			\
  assert( walk_length == -1 );						\
  set<pair<U,int>> vertex{};						\
  vertex.insert( pair<U,int>( weight[i_start] = one , i_start ) );	\
									\
  while( ! vertex.empty() ){						\
									\
    auto begin = vertex.begin();					\
    auto [weight_i,i] = *begin;						\
    CHECK_FINAL;							\
    fixed[i] = true;							\
    vertex.erase( begin );						\
    auto&& edge_i = m_G.Edge( m_G.Enumeration( i ) );			\
    list<pair<U,int>> changed_vertex{};					\
									\
    for( auto itr = edge_i.begin() , end = edge_i.end() ; itr != end ; itr++ ){ \
									\
      auto&& j = m_G.Enumeration_inv( itr->first );			\
      									\
      if( !fixed[j] ){							\
									\
	const U& edge_ij = get<1>( *itr );				\
	U temp = m_M.Product( weight_i , edge_ij );			\
	assert( temp < infty );						\
	U& weight_j = weight[j];					\
									\
	if( temp < weight_j ){						\
									\
	  if( weight_j != infty ){					\
									\
	    vertex.erase( pair<U,int>( weight_j , j ) );		\
									\
	  }								\
									\
	  SET_PREV;							\
	  changed_vertex.push_back( pair<U,int>( weight_j = move( temp ) , j ) ); \
									\
	}								\
									\
      }									\
									\
    }									\
									\
    for( auto itr_changed = changed_vertex.begin() , end_changed = changed_vertex.end() ; itr_changed != end_changed ; itr_changed++ ){ \
									\
      vertex.insert( *itr_changed );					\
									\
    }									\
									\
  }									\

#define DIJKSTRA_BODY( INITIALISE_PREV , CHECK_FINAL , SET_PREV )	\
  DIJKSTRA_PREP( INITIALISE_PREV );					\
									\
  if( many_edges ){							\
									\
    DIJKSTRA_BODY_1( SET_PREV );					\
									\
  } else {								\
									\
    DIJKSTRA_BODY_2( CHECK_FINAL , SET_PREV );				\
									\
  }									\
  

