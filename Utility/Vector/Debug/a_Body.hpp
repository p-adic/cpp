// c:/Users/user/Documents/Programming/Utility/Vector/Debug/a_Body.hpp

#pragma once
#include "a.hpp"

DEFINITION_OF_COUT_FOR_VECTOR( vector , "(" , ")" );
DEFINITION_OF_COUT_FOR_VECTOR( list , "(" , ")" );
DEFINITION_OF_COUT_FOR_VECTOR( set , "{" , "}" );
DEFINITION_OF_COUT_FOR_VECTOR( unordered_set , "{" , "}" );
DEFINITION_OF_COUT_FOR_DOUBLE_VECTOR( vector , "(" , ")" );
DEFINITION_OF_COUT_FOR_DOUBLE_VECTOR( list , "(" , ")" );
DEFINITION_OF_COUT_FOR_DOUBLE_VECTOR( set , "{" , "}" );
DEFINITION_OF_COUT_FOR_DOUBLE_VECTOR( unordered_set , "{" , "}" );

DEFINITION_OF_ARITHMETICS_FOR_VECTOR( vector );
DEFINITION_OF_ARITHMETICS_FOR_VECTOR( list );

template <typename T> inline operator*( const T& scalar , vector<T> v ) { for( auto& t : v ){ v *= t; } return move( v ); }

inline void VariadicResize( const int& size ) {}
template <typename Arg , typename... ARGS> inline void VariadicResize( const int& size , Arg& arg , ARGS&... args ) { arg.resize( size ); VariadicResize( size , args... ); }

template <typename V> inline auto Get( V& a ) { return [&]( const int& i = 0 ) -> const decldecay_t( a[0] )& { return a[i]; }; }
template <typename T> inline vector<T> id( const int& size ) { vector<T> answer( size ); for( int i = 0 ; i < size ; i++ ){ answer[i] = i; } return answer; }

template <typename T> inline void Sort( vector<T>& a , const bool& reversed ) { if( reversed ){ static auto comp = []( const T& t0 , const T& t1 ) { return t1 < t0; }; sort( a.begin() , a.end() , comp ); } else { sort( a.begin() , a.end() ); } }

template <typename T> inline vector<int> IndexSort( const vector<T>& a , const bool& reversed ) { auto index = id<int>( a.size() ); if( reversed ){ sort( index.begin() , index.end() , [&]( const int& i , const int& j ) { return a[j] < a[i]; } ); } else { sort( index.begin() , index.end() , [&]( const int& i , const int& j ) { return a[i] < a[j]; } ); } return index; }

    
