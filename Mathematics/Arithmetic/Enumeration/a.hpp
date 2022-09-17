// c:/Users/user/Documents/Programming/Mathematics/Arithmetic/Enumeration/a.hpp

#pragma once
#include "../Dimension/a.hpp"
#include "../../../Utility/VLArray/a.hpp"

// îZìxd_1Ç∆d_2ÇÃèWçáÇÃîrëºìIòaèWçáÇÃêîÇ¶è„Ç∞
void BijSum12( const dim& d_1 , const dim& d_2, const INT_TYPE_FOR_DIM& n , INT_TYPE_FOR_DIM& n_1 , INT_TYPE_FOR_DIM& n_2 );
inline void BijSum12( const INT_TYPE_FOR_DIM& m , INT_TYPE_FOR_DIM& n_1 , INT_TYPE_FOR_DIM& n_2 );

// BijSum12ÇÃãt
INT_TYPE_FOR_DIM BijSum21( const dim& d_1 , const dim& d_2 , const INT_TYPE_FOR_DIM& n_1 , const INT_TYPE_FOR_DIM& n_2 );
inline INT_TYPE_FOR_DIM BijSum21( const INT_TYPE_FOR_DIM& n_1 , const INT_TYPE_FOR_DIM& n_2 );

// â¬éZñ≥å¿îZìxÇÃèWçáÇÃNå¬îrëºìIòaèWçáÇÃêîÇ¶è„Ç∞
inline void BijSum1N( const INT_TYPE_FOR_DIM& N , const INT_TYPE_FOR_DIM& n , INT_TYPE_FOR_DIM& n_1 , INT_TYPE_FOR_DIM& n_2 );

// BijSum1NÇÃãt
inline INT_TYPE_FOR_DIM BijSumN1( const INT_TYPE_FOR_DIM& N , const INT_TYPE_FOR_DIM& n_1 , const INT_TYPE_FOR_DIM& n_2 );


// îZìxd_1Ç∆d_2ÇÃèWçáÇÃíºêœÇÃêîÇ¶è„Ç∞
void BijProd12( const dim& , const dim& , const INT_TYPE_FOR_DIM& , INT_TYPE_FOR_DIM& , INT_TYPE_FOR_DIM& );
inline void BijProd12( const INT_TYPE_FOR_DIM& n , INT_TYPE_FOR_DIM& n_1 , INT_TYPE_FOR_DIM& n_2 );

// BijProd12ÇÃãt
INT_TYPE_FOR_DIM BijProd21( const dim& d_1 , const dim& d_2 , const INT_TYPE_FOR_DIM& n_1 , const INT_TYPE_FOR_DIM& n_2 );
inline INT_TYPE_FOR_DIM BijProd21( const INT_TYPE_FOR_DIM& n_1 , const INT_TYPE_FOR_DIM& n_2 );

// sum( i , 0 , n ){ ( a_0 + a_1 * i ) / q }
template <typename INT>
INT FloorSum( const INT& a_0 , const INT& a_1 , const INT& q , const INT& n );
