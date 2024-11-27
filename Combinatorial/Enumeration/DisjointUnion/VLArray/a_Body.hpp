// c:/Users/user/Documents/Programming/Mathematics/Combinatorial/Enumeration/DisjointUnion/VLArray/a_Body.hpp

#pragma once
#include "a.hpp"

#include "../../../Utility/VLArray/a_Body.hpp"

inline void BijSum1N( const INT_TYPE_FOR_EUINT& N , const INT_TYPE_FOR_EUINT& n , INT_TYPE_FOR_EUINT& n_1 , INT_TYPE_FOR_EUINT& n_2 ) { return BijSum1N( to_VLArray<euint>( N , infty() ) , n , n_1 , n_2 ); }
inline INT_TYPE_FOR_EUINT BijSumN1( const INT_TYPE_FOR_EUINT& N , const INT_TYPE_FOR_EUINT& n_1 , const INT_TYPE_FOR_EUINT& n_2 ) { return BijSumN1( to_VLArray<euint>( N , infty() ) , n_1 , n_2 ); }
