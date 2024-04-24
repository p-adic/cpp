// c:/Users/user/Documents/Programming/Utility/Sort/a_Body.hpp

#pragma once
#include "a.hpp"

template <typename T> void sort( vector<T>& a , const bool& reversed ) { if( reversed ){ static auto comp = []( const T& t0 , const T& t1 ) { return t1 < t0; }; sort( a.begin() , a.end() , comp ); } else { sort( a.begin() , a.end() ); } }
