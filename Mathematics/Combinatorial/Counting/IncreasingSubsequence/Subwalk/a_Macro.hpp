// c:/Users/user/Documents/Programming/Mathematics/Combinatorial/Counting/IncreasingSubsequence/Subwalk/a_Macro.hpp

#pragma once
#define COUNT_SUBWALK( EDGE_SUM , UPDATE , VERTEX_SUM )			\
  assert( V <= V_max );							\
  map<T,ll> count{};							\
									\
  for( int i = 0 ; i < V ; i++ ){					\
									\
    const T& a_i = a[i];						\
    const list<T> edge_inv_i = E_inv( a_i );				\
    ll count_temp = 1;							\
									\
    for( auto itr = edge_inv_i.begin() , end = edge_inv_i.end() ; itr != end ; itr++ ){	\
									\
      const ll& count_curr = count[*itr];				\
      EDGE_SUM;								\
									\
    }									\
									\
    ll& count_i = count[a_i];						\
    UPDATE;								\
									\
  }									\
									\
  ll count_temp = 0;							\
									\
  for( auto itr = count.begin() , end = count.end() ; itr != end ; itr++ ){ \
									\
    VERTEX_SUM;								\
									\
  }									\
									\
  return count_temp							\


