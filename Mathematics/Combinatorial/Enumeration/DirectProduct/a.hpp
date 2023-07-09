// c:/Users/user/Documents/Programming/Mathematics/Combinatorial/Enumeration/DirectProduct/a.hpp

#pragma once
#include "../../../Arithmetic/ExtendedNatural/a.hpp"

// îZìxd_1Ç∆d_2ÇÃèWçáÇÃíºêœÇÃêîÇ¶è„Ç∞
void BijProd12( const euint& , const euint& , const INT_TYPE_FOR_EUINT& , INT_TYPE_FOR_EUINT& , INT_TYPE_FOR_EUINT& );
inline void BijProd12( const INT_TYPE_FOR_EUINT& n , INT_TYPE_FOR_EUINT& n_1 , INT_TYPE_FOR_EUINT& n_2 );

// BijProd12ÇÃãt
INT_TYPE_FOR_EUINT BijProd21( const euint& d_1 , const euint& d_2 , const INT_TYPE_FOR_EUINT& n_1 , const INT_TYPE_FOR_EUINT& n_2 );
inline INT_TYPE_FOR_EUINT BijProd21( const INT_TYPE_FOR_EUINT& n_1 , const INT_TYPE_FOR_EUINT& n_2 );
