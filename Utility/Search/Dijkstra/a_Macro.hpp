// c:/Users/user/Documents/Programming/Utility/Search/Dijkstra/a_Macro.hpp

#pragma once

#define DIJKSTRA_BODY( INITIALISE_PREV , SET_PREV )			\
  set<PairForDijkstra<T> > vertex{};					\
									\
  for( int i = 0 ; i < size ; i++ ){					\
									\
    vertex.insert( PairForDijkstra<T>( i == i_start ? e_T() : weight_max , i ) ); \
									\
  }									\
									\
  T weight[size_max] = {};						\
  INITIALISE_PREV;							\
									\
  while( ! vertex.empty() ){						\
									\
    auto itr = vertex.begin() , end = vertex.end();			\
    PairForDijkstra<T> v = *itr;					\
    const T& t = v.Get();						\
    const int& i = v.index();						\
    const T ( &di )[size_max] = d[i];					\
    weight[i] = t;							\
									\
    if( i == i_final ){							\
									\
      break;								\
									\
    }									\
									\
    itr = vertex.erase( itr );						\
    list<PairForDijkstra<T> > changed_vertex{};				\
									\
    while( itr != end ){						\
									\
      const T& weight_curr = itr->Get();				\
      const T weight_temp = m_T( t , di[itr->index()] );		\
									\
      if( weight_curr > weight_temp ){					\
									\
	const int i_curr = itr->index();				\
	SET_PREV;							\
	itr = vertex.erase( itr );					\
	changed_vertex.push_back( PairForDijkstra<T>( weight_temp , i_curr ) ); \
									\
      } else {								\
									\
	itr++;								\
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


