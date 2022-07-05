// c:/Users/user/Documents/Programming/Mathematics/Arithmetic/Enumeration/a.hpp

#pragma once
#include "../Dimension/a.hpp"
#include "../../../Utility/VLArray/a.hpp"

// 濃度d_1とd_2の集合の排他的和集合の数え上げ
void BijSum12( const dim& d_1 , const dim& d_2, const uint& n , uint& n_1 , uint& n_2 );
inline void BijSum12( const uint& m , uint& n_1 , uint& n_2 );

// BijSum12の逆
uint BijSum21( const dim& d_1 , const dim& d_2 , const uint& n_1 , const uint& n_2 );
inline uint BijSum21( const uint& n_1 , const uint& n_2 );

// 可算無限濃度の集合のN個排他的和集合の数え上げ
inline void BijSum1N( const uint& N , const uint& n , uint& n_1 , uint& n_2 );

// BijSum1Nの逆
inline uint BijSumN1( const uint& N , const uint& n_1 , const uint& n_2 );


// 濃度d_1とd_2の集合の直積の数え上げ
void BijProd12( const dim& , const dim& , const uint& , uint& , uint& );
inline void BijProd12( const uint& n , uint& n_1 , uint& n_2 );

// BijProd12の逆
uint BijProd21( const dim& d_1 , const dim& d_2 , const uint& n_1 , const uint& n_2 );
inline uint BijProd21( const uint& n_1 , const uint& n_2 );
