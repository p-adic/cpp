// c:/Users/user/Documents/Programming/Mathematics/Arithmetic/a_Macro.hpp

#pragma once

#define DEFIINTION_OF_PROD( FUNC , UNIT , APPLY )	\
							\
  if( f.empty() ){					\
							\
    f.push_back( UNIT );				\
							\
  }							\
							\
  if( f.size() == 1 ){					\
							\
    return f.front();					\
							\
  }							\
							\
  auto itr = f.begin() , end = f.end();			\
							\
  while( itr != end ){					\
							\
    T& t = *itr;					\
    itr++;						\
							\
    if( itr != end ){					\
							\
      APPLY;						\
      itr = f.erase( itr );				\
							\
    }							\
							\
  }							\
							\
  return Prod( f );					\
							\


