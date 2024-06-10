// c:/Users/user/Documents/Programming/Mathematics/Polynomial/Cumulative/a_Macro.hpp

#pragma once
#define DF_OF_PROD( RECURSION , UNIT , APPLY )	\
  if( f.empty() ){				\
						\
    f.push_back( UNIT );			\
						\
  }						\
						\
  if( f.size() == 1 ){				\
						\
    return f.front();				\
						\
  }						\
						\
  auto itr = f.begin() , end = f.end();		\
						\
  while( itr != end ){				\
						\
    T& t = *itr;				\
    itr++;					\
						\
    if( itr != end ){				\
						\
      APPLY;					\
      itr = f.erase( itr );			\
						\
    }						\
						\
  }						\
						\
  return RECURSION;				\

#define EXPRESSION1_FOR_RATIONAL_SUM { Polynomial<T>::zero() , Polynomial<T>::one() }
#define EXPRESSION2_FOR_RATIONAL_SUM { t.first * itr->second + t.second * itr->first,t.second * itr->second }
#define EXPRESSION3_FOR_RATIONAL_SUM { TruncatedPolynomial<T>() , TruncatedPolynomial<T>( 1 , Polynomial<T>::one() ) }
