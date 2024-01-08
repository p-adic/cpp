// c:/Users/user/Documents/Programming/Mathematics/Function/Map/a_Body.hpp

#pragma once
#include "a.hpp"

template <typename INT , template <typename...> typename T> inline size_t hash<T<INT>>::operator()( const T<INT>& n ) const { return hash<INT>::operator()( n.Represent() ); }
