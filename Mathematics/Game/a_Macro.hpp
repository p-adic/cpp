// c:/Users/user/Documents/Programming/Mathematics/Game/a_Macro.hpp

#pragma once

#define CHECK_HAS_NON_ZERO_GRUNDY_NUMBER				\
  if( reset ){								\
									\
    g.clear();								\
									\
  }									\
									\
  if( g.count( t ) == 1 ){						\
									\
    return g[t];							\
									\
  }									\
									\
  auto next = E( t );							\
  bool b = false;							\
									\
  for( auto itr = next.begin() , end = next.end() ; itr != end ; itr++ ){ \
									\
    b |= !HasNonZeroGrundyNumber<T,V,E>( *itr );			\
									\
  }									\
									\
  return ( g[t] = b );							\

#define COMPUTE_GRUNDY_NUMBER						\
  if( reset ){								\
									\
    g.clear();								\
									\
  }									\
									\
  if( g.count( t ) == 1 ){						\
									\
    return g[t];							\
									\
  }									\
									\
  auto next = E( t );							\
  MexSet mex{ int( next.size() ) };					\
									\
  for( auto itr = next.begin() , end = next.end() ; itr != end ; itr++ ){ \
									\
    mex.insert( GrundyNumber<T,V,E>( *itr ) );				\
									\
  }									\
									\
  return g[t] = mex.Get();						\


