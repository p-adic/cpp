// c:/Users/user/Documents/Programming/Utility/Search/Dijkstra/a_Macro.hpp

#pragma once

#define DIJKSTRA_BODY( INITIALISE_PREV , SET_PREV )			\
  set<PairForDijkstra<T> > vertex{};					\
									\
  for( int i = 0 ; i < size ; i++ ){					\
									\
    vertex.insert( PairForDijkstra<T>( i == i_start ? e_T() : infty , i ) ); \
									\
  }									\
									\
  T answer{};								\
  INITIALISE_PREV;							\
									\
  while( ! vertex.empty() ){						\
									\
    auto itr = vertex.begin();						\
    const PairForDijkstra<T> v = *itr;					\
    const T& t = v.Get();						\
    const int& i = v.index();						\
									\
    if( i == i_final ){							\
									\
      answer = t;							\
      break;								\
									\
    }									\
									\
    itr = vertex.erase( itr );						\
									\
    if( t != infty ){							\
									\
      auto end = vertex.end();						\
      const T ( &di )[size_max] = d[i];					\
      list<PairForDijkstra<T> > changed_vertex{};			\
									\
      while( itr != end ){						\
									\
	const int& j = itr->index();					\
	const T& dij = di[j];						\
									\
	if( dij != infty ){						\
									\
	  const T& weight_curr = itr->Get();				\
	  const T weight_temp = m_T( t , dij );				\
									\
	  if( weight_curr == infty ? true : weight_curr > weight_temp ){ \
									\
	    SET_PREV;							\
	    itr = vertex.erase( itr );					\
	    changed_vertex.push_back( PairForDijkstra<T>( weight_temp , j ) ); \
									\
	  } else {							\
									\
	    itr++;							\
									\
	  }								\
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


