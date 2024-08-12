// c:/Users/user/Documents/Programming/Utility/Tuple/Hash/a_Macro.hpp

#pragma once

#define DEFINITION_OF_HASH_FOR_TUPLE( PAIR )				\
  template <typename T , typename U> inline size_t hash<PAIR<T,U>>::operator()( const PAIR<T,U>& n ) const { static const size_t seed = ( GetRand( 1e3 , 1e8 ) << 1 ) | 1; static const hash<T> h0; static const hash<U> h1; return ( h0( get<0>( n ) ) * seed ) ^ h1( get<1>( n ) ); } \

