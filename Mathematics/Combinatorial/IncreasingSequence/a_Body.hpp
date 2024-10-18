// c:/Users/user/Documents/Programming/Mathematics/Combinatorial/IncreasingSequence/a_Body.hpp

#pragma once
#include "a.hpp"

template <typename MODINT> inline MODINT CountNonStrictlyIncreasingSequence( const int& size , const int& val_min , const int& val_max ) { return MODINT::Combination( val_max - val_min + size , size ); }
template <typename MODINT> inline MODINT CountStrictlyIncreasingSequence( const int& size , const int& val_min , const int& val_max ) { return MODINT::Combination( val_max - val_min + 1 , size ); }
