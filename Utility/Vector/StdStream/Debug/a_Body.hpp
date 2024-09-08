// c:/Users/user/Documents/Programming/Utility/Vector/Debug/a_Body.hpp

#pragma once
#include "a.hpp"

DEFINITION_OF_COUT_FOR_VECTOR( vector , "[" , "," , "]" );
DEFINITION_OF_COUT_FOR_VECTOR( list , "[" , "," , "]" );
DEFINITION_OF_COUT_FOR_VECTOR( set , "{" , " <" , "}" );
DEFINITION_OF_COUT_FOR_VECTOR( unordered_set , "{" , "," , "}" );
DEFINITION_OF_COUT_FOR_DOUBLE_VECTOR( vector , "[" , "," , "]" );
DEFINITION_OF_COUT_FOR_DOUBLE_VECTOR( list , "[" , "," , "]" );
DEFINITION_OF_COUT_FOR_DOUBLE_VECTOR( set , "{" , " <" , "}" );
DEFINITION_OF_COUT_FOR_DOUBLE_VECTOR( unordered_set , "{" , "," , "}" );

DEFINITION_OF_COUT_FOR_VECTOR( multiset , "{" , " <=" , "}" );
DEFINITION_OF_COUT_FOR_DOUBLE_VECTOR( multiset , "{" , " <=" , "}" );

inline void VariadicResize( const int& size ) {}
template <typename Arg , typename... ARGS> inline void VariadicResize( const int& size , Arg& arg , ARGS&... args ) { arg.resize( size ); VariadicResize( size , args... ); }

