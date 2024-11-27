// c:/Users/user/Documents/Programming/Mathematics/Combinatorial/Enumeration/DisjointUnion/a.hpp

#pragma once
#include "../../../Arithmetic/ExtendedNatural/a.hpp"

// ”Z“xd_1‚Æd_2‚ÌW‡‚Ì”r‘¼“I˜aW‡‚Ì”‚¦ã‚°
void BijSum12( const euint& d_1 , const euint& d_2, const INT_TYPE_FOR_EUINT& n , INT_TYPE_FOR_EUINT& n_1 , INT_TYPE_FOR_EUINT& n_2 );
inline void BijSum12( const INT_TYPE_FOR_EUINT& m , INT_TYPE_FOR_EUINT& n_1 , INT_TYPE_FOR_EUINT& n_2 );

// BijSum12‚Ì‹t
INT_TYPE_FOR_EUINT BijSum21( const euint& d_1 , const euint& d_2 , const INT_TYPE_FOR_EUINT& n_1 , const INT_TYPE_FOR_EUINT& n_2 );
inline INT_TYPE_FOR_EUINT BijSum21( const INT_TYPE_FOR_EUINT& n_1 , const INT_TYPE_FOR_EUINT& n_2 );

// ‰ÂZ–³ŒÀ”Z“x‚ÌW‡‚ÌNŒÂ”r‘¼“I˜aW‡‚Ì”‚¦ã‚°
inline void BijSum1N( const INT_TYPE_FOR_EUINT& N , const INT_TYPE_FOR_EUINT& n , INT_TYPE_FOR_EUINT& n_1 , INT_TYPE_FOR_EUINT& n_2 );

// BijSum1N‚Ì‹t
inline INT_TYPE_FOR_EUINT BijSumN1( const INT_TYPE_FOR_EUINT& N , const INT_TYPE_FOR_EUINT& n_1 , const INT_TYPE_FOR_EUINT& n_2 );

