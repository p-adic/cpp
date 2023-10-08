// c:/Users/user/Documents/Programming/Mathematics/Geometry/Graph/Dijkstra/a_Macro.hpp

#pragma once

#define DIJKSTRA_BODY( SET_FOUND , SET_WEIGHT , UPDATE_FOUND , CHECK_FOUND , INITIALISE_PREV , SET_PREV ) \
  static const U& unit = Unit();					\
  assert( unit != m_found && unit < m_infty );				\
  const int i_start = e_inv( t_start );					\
  set<pair<U,int> > vertex{};						\
  SET_FOUND;								\
  SET_WEIGHT;								\
  vertex.insert( pair<U,int>( weight[i_start] = unit , i_start ) );	\
  INITIALISE_PREV;							\
									\
  if( i_start != i_final ){						\
  									\
    while( ! vertex.empty() ){						\
									\
      auto itr_vertex = vertex.begin();					\
      const pair<U,int> v = *itr_vertex;				\
      const int& i = v.second;						\
									\
      if( i == i_final ){						\
									\
	break;								\
									\
      }									\
									\
      const U& u = v.first;						\
      UPDATE_FOUND;							\
      vertex.erase( itr_vertex );					\
      const list<pair<T,U> > edge_i = E( e( i ) );			\
      list<pair<U,int> > changed_vertex{};				\
									\
      for( auto itr_edge_i = edge_i.begin() , end_edge_i = edge_i.end() ; itr_edge_i != end_edge_i ; itr_edge_i++ ){ \
									\
	const int& j = e_inv( itr_edge_i->first );			\
	U& weight_j = weight[j];					\
      									\
	if( CHECK_FOUND ){						\
									\
	  const U& edge_ij = itr_edge_i->second;			\
	  const U temp = Addition( u , edge_ij );			\
	  assert( edge_ij != m_found && temp != m_found && !( temp < edge_ij ) && temp < m_infty ); \
									\
	  if( weight_j > temp ){					\
									\
	    if( weight_j != m_infty ){					\
									\
	      vertex.erase( pair<U,int>( weight_j , j ) );		\
									\
	    }								\
									\
	    SET_PREV;							\
	    changed_vertex.push_back( pair<U,int>( weight_j = temp , j ) ); \
									\
	  }								\
									\
	}								\
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
									\
  }									\
  

