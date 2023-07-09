// c:/Users/user/Documents/Programming/Mathematics/Combinatorial/Enumeration/VLArray/a_Body.hpp

#pragma once
#include "a.hpp"

#include "../a_Body.hpp"

#include "VLArray/a_Body.hpp"

inline VLArray<INT_TYPE_FOR_EUINT> BijProd1N( const INT_TYPE_FOR_EUINT& N , const INT_TYPE_FOR_EUINT& n ) { return BijProd1N( to_VLArray<euint>( N , infty() ) , n ); }
inline void BijProd1N( const INT_TYPE_FOR_EUINT& N , const INT_TYPE_FOR_EUINT& n , VLArray<INT_TYPE_FOR_EUINT>& a_n ) { BijProd1N(to_VLArray<euint>( N , infty() ) , n , a_n ); }

inline INT_TYPE_FOR_EUINT BijProdN1( const VLArray<INT_TYPE_FOR_EUINT>& a_n ) { return BijProdN1( to_VLArray<euint>( a_n.size() , infty() ) , a_n ); }
