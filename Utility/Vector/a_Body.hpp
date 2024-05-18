// c:/Users/user/Documents/Programming/Utility/Vector/a_Body.hpp

#pragma once
#include "a.hpp"

DEFINITION_OF_COUT_FOR_VECTOR( vector );
DEFINITION_OF_COUT_FOR_VECTOR( list );
DEFINITION_OF_COUT_FOR_VECTOR( set );
DEFINITION_OF_COUT_FOR_VECTOR( unordered_set );

DEFINITION_OF_ARITHMETICS_FOR_VECTOR( vector );
DEFINITION_OF_ARITHMETICS_FOR_VECTOR( list );

inline void VariadicResize( const int& size ) {}
template <typename Arg , typename... ARGS> inline void VariadicResize( const int& size , Arg& arg , ARGS&... args ) { arg.resize( size ); VariadicResize( size , args... ); }

template <typename T> void sort( vector<T>& a , const bool& reversed ) { if( reversed ){ static auto comp = []( const T& t0 , const T& t1 ) { return t1 < t0; }; sort( a.begin() , a.end() , comp ); } else { sort( a.begin() , a.end() ); } }

