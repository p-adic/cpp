// c:/Users/user/Documents/Programming/Mathematics/Combinatorial/Enumeration/DirectProduct/a_Body.hpp

#pragma once
#include "a.hpp"

#include "../../../Arithmetic/ExtendedNatural/a_Body.hpp"

inline void BijProd12( const INT_TYPE_FOR_EUINT& n , INT_TYPE_FOR_EUINT& n_1 , INT_TYPE_FOR_EUINT& n_2 ) { BijProd12( infty() , infty() , n , n_1 , n_2 ); }

inline INT_TYPE_FOR_EUINT BijProd21( const INT_TYPE_FOR_EUINT& n_1 , const INT_TYPE_FOR_EUINT& n_2 ) { return BijProd21( infty() , infty() , n_1 , n_2 ); }
