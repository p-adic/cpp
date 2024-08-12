// c:/Users/user/Documents/Programming/Utility/Vector/StdStream/a_Body.hpp

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
