// c:/Users/user/Documents/Programming/Utility/Search/Dijkstra/a_Macro.hpp

#pragma once

#define DIJKSTRA_BODY( TYPE , UNIT , UPDATE , INITIALISE_PREV , SET_PREV ) \
  set<pair<TYPE,int> > vertex{};					\
  TYPE weight[size_max];						\
									\
  for( int i = 0 ; i < size ; i++ ){					\
									\
    vertex.insert( pair<TYPE,int>( weight[i] = ( i == i_start ? UNIT : infty ) , i ) ); \
									\
  }									\
									\
  TYPE answer{};							\
  INITIALISE_PREV;							\
									\
  while( ! vertex.empty() ){						\
									\
    auto itr_vertex = vertex.begin();					\
    const pair<TYPE,int> v = *itr_vertex;				\
    const TYPE& t = v.first;						\
    const int& i = v.second;						\
									\
    if( i == i_final ){							\
									\
      answer = t;							\
      break;								\
									\
    }									\
									\
    vertex.erase( itr_vertex );						\
									\
    if( t != infty ){							\
									\
      const map<int,TYPE>& di = d[i];					\
      list<pair<TYPE,int> > changed_vertex{};				\
									\
      for( auto itr_di = di.begin() , end_di = di.end() ; itr_di != end_di ; itr_di++ ){ \
									\
	const int& j = itr_di->first;					\
	const TYPE& dij = itr_di->second;				\
									\
	if( dij != infty ){						\
									\
	  TYPE& weight_j = weight[j];					\
	  pair<TYPE,int> w{ weight_j , j };				\
									\
	  if( vertex.count( w ) == 1 ){					\
									\
	    const TYPE temp = UPDATE;					\
									\
	    if( weight_j == infty ? true : weight_j > temp ){		\
									\
	      SET_PREV;							\
	      vertex.erase( w );					\
	      changed_vertex.push_back( pair<TYPE,int>( temp , j ) );	\
	      weight_j = temp;						\
									\
	    }								\
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


