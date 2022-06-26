// c:/Users/user/Documents/Programming/Mathematics/Arithmetic/Enumeration/a.hpp

#pragma once
#include "../Dimension/a.hpp"
#include "../../../Utility/VLArray/a.hpp"

// ”Z“xd_1‚Æd_2‚ÌW‡‚Ì”r‘¼“I˜aW‡‚Ì”‚¦ã‚°
void BijSum12( const dim& d_1 , const dim& d_2, const uint& n , uint& n_1 , uint& n_2 );
inline void BijSum12( const uint& m , uint& n_1 , uint& n_2 );

// BijSum12‚Ì‹t
uint BijSum21( const dim& d_1 , const dim& d_2 , const uint& n_1 , const uint& n_2 );
inline uint BijSum21( const uint& n_1 , const uint& n_2 );

// ‰ÂZ–³ŒÀ”Z“x‚ÌW‡‚ÌNŒÂ”r‘¼“I˜aW‡‚Ì”‚¦ã‚°
inline void BijSum1N( const uint& N , const uint& n , uint& n_1 , uint& n_2 );

// BijSum1N‚Ì‹t
inline uint BijSumN1( const uint& N , const uint& n_1 , const uint& n_2 );


// ”Z“xd_1‚Æd_2‚ÌW‡‚Ì’¼Ï‚Ì”‚¦ã‚°
void BijProd12( const dim& , const dim& , const uint& , uint& , uint& );
inline void BijProd12( const uint& n , uint& n_1 , uint& n_2 );

// BijProd12‚Ì‹t
uint BijProd21( const dim& d_1 , const dim& d_2 , const uint& n_1 , const uint& n_2 );
inline uint BijProd21( const uint& n_1 , const uint& n_2 );

// ê‡‚Ì”
template <typename U> U Comb()
