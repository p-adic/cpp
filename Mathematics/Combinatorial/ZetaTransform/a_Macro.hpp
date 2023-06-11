// c:/Users/user/Documents/Programming/Mathematics/Combinatorial/ZetaTransform/a_Macro.hpp

#pragma once
#define DEFINITION_OF_GET_FOR_ZETA_TRANSFORM( MU )			\
  list<T> sub = Sub( t );						\
  sub.push_front( t );							\
  U answer = Zero();							\
									\
  while( ! sub.empty() ){						\
									\
    const T& t_sub = sub.front();					\
    answer = Sum( answer , Prod( m_val[e_inv( t_sub )] , MU( t_sub , t ) ) ); \
    sub.pop_front();							\
									\
  }									\
									\
  return answer;							\

#define DEFINITION_OF_INVERSE_IMAGE_SUM_FOR_ZETA_TRANSFORM( MU )	\
  const T t = f_inv_max( s );						\
  list<S> sub = r( s );							\
  U answer = Zero();							\
									\
  while( ! sub.empty() ){						\
									\
    const T& t_sub = f_inv_max( sub.front() );				\
    answer = Sum( answer , Prod( m_val[e_inv( t_sub )] , MU( t_sub , t ) ) ); \
    sub.pop_front();							\
									\
  }									\
									\
  return answer;							\


