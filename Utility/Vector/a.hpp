// c:/Users/user/Documents/Programming/Utility/Vector/a.hpp

#pragma once
#include "a_Macro.hpp"

#include <vector>

// SFINAEÇæÇ∆stringÇ∆ã£çáÇ∑ÇÈÅB
DECLARATION_OF_COUT_FOR_VECTOR( vector );
DECLARATION_OF_COUT_FOR_VECTOR( list );
DECLARATION_OF_COUT_FOR_VECTOR( set );
DECLARATION_OF_COUT_FOR_VECTOR( unordered_set );

DECLARATION_OF_ARITHMETICS_FOR_VECTOR( vector );
template <typename T> inline operator*( const T& scalar , vector<T> v );

inline void VariadicResize( const int& size );
template <typename Arg , typename... ARGS> inline void VariadicResize( const int& size , Arg& arg , ARGS&... args );

// template <typename V> inline auto Get( V& a );

template <typename T = int> inline vector<T> id( const int& size );

template <typename T> inline void Sort( vector<T>& a , const bool& reversed = false );
template <typename T> inline vector<int> IndexSort( const vector<T>& a , const bool& reversed = false );
