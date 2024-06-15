// c:/Users/user/Documents/Programming/Mathematics/Geometry/Graph/Algorithm/UnionFindForest/ParallelBinarySearch/a_Macro.hpp

#pragma once

#ifndef CERR
  #ifdef DEBUG
    #define CERR( ... ) VariadicCout( cerr , __VA_ARGS__ ) << endl
    #define COUT( ... ) VariadicCout( cout << "出力： " , __VA_ARGS__ ) << endl
    #define CERR_A( A , N ) OUTPUT_ARRAY( cerr , A , N ) << endl
    #define COUT_A( A , N ) cout << "出力： "; OUTPUT_ARRAY( cout , A , N ) << endl
    #define CERR_ITR( A ) OUTPUT_ITR( cerr , A ) << endl
    #define COUT_ITR( A ) cout << "出力： "; OUTPUT_ITR( cout , A ) << endl
  #else
    #define CERR( ... ) 
    #define COUT( ... ) VariadicCout( cout , __VA_ARGS__ ) << ENDL
    #define CERR_A( A , N ) 
    #define COUT_A( A , N ) OUTPUT_ARRAY( cout , A , N ) << ENDL
    #define CERR_ITR( A ) 
    #define COUT_ITR( A ) OUTPUT_ITR( cout , A ) << ENDL
  #endif
#endif

#define INITIALISE_FOR_PBUF					\
  CERR( "" );					\
  CERR( "並列二分探索中：" );					\
  CERR( "l = (" , l , ")" );					\
  CERR( "r = (" , r , ")" );					\
  AbstractUnionFindForest uff{ G , AdditiveGroup<int>() };	\
  auto itr = begin;						\

#define GRAFT_FOR_PBUF( VAL )					\
  CERR( "操作する辺の重みの上界 =" , VAL );		\
								\
  while( itr != end && itr->first <= VAL ){			\
								\
    CERR( "操作中の辺の重み =" , itr->first );			\
								\
    for( auto& [s,t] : itr->second ){				\
								\
      if( uff.RootOfNode( s ) != uff.RootOfNode( t ) ){		\
								\
	CERR( "結合： ( s , t ) = (" , s , "," , t , ")" );	\
								\
      }								\
								\
      uff.Graft( s , t );					\
								\
    }								\
								\
    itr++;							\
								\
  }								\
  
#define UPDATE_FOR_PBUF( VAL )						\
  auto& [s,t] = query[q];						\
  uff.RootOfNode( s ) == uff.RootOfNode( t ) ? r[q] = VAL : ++( l[q] = VAL ); \


