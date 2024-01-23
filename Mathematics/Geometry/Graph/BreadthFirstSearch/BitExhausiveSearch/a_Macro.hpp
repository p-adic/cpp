// c:/Users/user/Documents/Programming/Mathematics/Geometry/Graph/BreadthFirstSearch/BitExhausiveSearch/a_Macro.hpp

#pragma once
#define DEFINITION_OF_ADJACENT_SET( T_COPY , OPR , ULIM , UPDATE )	\
  list<int> answer{};							\
  int t_copy = T_COPY;							\
  int t_next;								\
  int d;								\
									\
  while( t_copy != 0 && ( t_next = ( t OPR ( d = ( t_copy & -t_copy ) ) ) ) < ULIM ){ \
									\
    t_copy -= d;							\
    UPDATE;								\
									\
  }									\
									\
  return answer								\

#define DEFINITION_OF_PROPER_SET( INCREMENT , OPR , ULIM , UPDATE )	\
  list<int> answer{};							\
  int t_next = t;							\
									\
  while( ( ( INCREMENT t_next ) OPR t ) < ULIM ){			\
									\
    UPDATE;								\
									\
  }									\
									\
  return answer								\

