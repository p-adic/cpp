// c:/Users/user/Documents/Programming/Mathematics/Arithmetic/Enumeration/a.hpp

#pragma once
#include "../Dimension/a.hpp"
#include "../../../Utility/VLArray/a.hpp"

// 濃度d_1とd_2の集合の排他的和集合の数え上げ
void BijSum12( const dim& d_1 , const dim& d_2, const INT_TYPE_FOR_DIM& n , INT_TYPE_FOR_DIM& n_1 , INT_TYPE_FOR_DIM& n_2 );
inline void BijSum12( const INT_TYPE_FOR_DIM& m , INT_TYPE_FOR_DIM& n_1 , INT_TYPE_FOR_DIM& n_2 );

// BijSum12の逆
INT_TYPE_FOR_DIM BijSum21( const dim& d_1 , const dim& d_2 , const INT_TYPE_FOR_DIM& n_1 , const INT_TYPE_FOR_DIM& n_2 );
inline INT_TYPE_FOR_DIM BijSum21( const INT_TYPE_FOR_DIM& n_1 , const INT_TYPE_FOR_DIM& n_2 );

// 可算無限濃度の集合のN個排他的和集合の数え上げ
inline void BijSum1N( const INT_TYPE_FOR_DIM& N , const INT_TYPE_FOR_DIM& n , INT_TYPE_FOR_DIM& n_1 , INT_TYPE_FOR_DIM& n_2 );

// BijSum1Nの逆
inline INT_TYPE_FOR_DIM BijSumN1( const INT_TYPE_FOR_DIM& N , const INT_TYPE_FOR_DIM& n_1 , const INT_TYPE_FOR_DIM& n_2 );


// 濃度d_1とd_2の集合の直積の数え上げ
void BijProd12( const dim& , const dim& , const INT_TYPE_FOR_DIM& , INT_TYPE_FOR_DIM& , INT_TYPE_FOR_DIM& );
inline void BijProd12( const INT_TYPE_FOR_DIM& n , INT_TYPE_FOR_DIM& n_1 , INT_TYPE_FOR_DIM& n_2 );

// BijProd12の逆
INT_TYPE_FOR_DIM BijProd21( const dim& d_1 , const dim& d_2 , const INT_TYPE_FOR_DIM& n_1 , const INT_TYPE_FOR_DIM& n_2 );
inline INT_TYPE_FOR_DIM BijProd21( const INT_TYPE_FOR_DIM& n_1 , const INT_TYPE_FOR_DIM& n_2 );

// sum( i , 0 , n ){ ( a_0 + a_1 * i ) / q }
template <typename INT>
INT FloorSum( const INT& a_0 , const INT& a_1 , const INT& q , const INT& n );
