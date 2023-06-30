// c:/Users/user/Documents/Programming/Mathematics/Arithmetic/Prime/Divisor/a_Macro.hpp

#pragma once

#define COUNT_DIVISOR				\
  P.clear();					\
  const int length = exponent.size();		\
  INT answer = 1;				\
						\
  for( int i = 0 ; i < length ; i++ ){		\
						\
    answer *= exponent[i] + 1;			\
						\
  }						\
						\
  return answer;				\

#define ENUMERATE_DIVISOR				\
  const int length = P.size();				\
							\
  list<INT> divisor{};					\
  divisor.push_back( 1 );				\
  auto begin = divisor.begin() , end = divisor.end();	\
							\
  for( int i = 0 ; i < length ; i++ ){			\
							\
    const INT& P_i = P[i];				\
    const int& exponent_i = exponent[i];		\
    list<INT> temp{};					\
    INT power = 1;					\
							\
    for( int e = 1 ; e <= exponent_i ; e++ ){		\
							\
      power *= P_i;					\
							\
      for( auto itr = begin ; itr != end ; itr++ ){	\
							\
	temp.push_back( *itr * power );			\
							\
      }							\
							\
    }							\
							\
    while( ! temp.empty() ){				\
							\
      divisor.push_back( temp.front() );		\
      temp.pop_front();					\
							\
    }							\
							\
  }							\
							\
  return divisor;					\


