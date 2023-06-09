// c:/Users/user/Documents/Programming/Mathematics/Arithmetic/Mod/Euler/a.hpp

#pragma once
#include "../../Prime/Constexpr/a.hpp"

template <typename INT> inline INT EulerFunction( const INT& n );

// ”ñ•‰®”n‚Ì‘fˆö”‚ğP‚ÉŠi”[‚µA‘fˆö”‚Ìw”‚ğexponent‚ÉŠi”[‚·‚éB
template <typename INT>
INT EulerFunction( const INT& n , vector<INT>& P , vector<INT>& exponent );
// n < val_limit‚Ì2æ ‚Ì‚Ì‚İƒTƒ|[ƒgB
template <typename INT , INT val_limit , int length_max>
INT EulerFunction( const PrimeEnumeration<INT,val_limit,length_max>& prime , const INT& n , vector<INT>& P , vector<INT>& exponent );

template <typename INT> inline INT CarmichaelFunction( const INT& n );

// ”ñ•‰®”n‚Ì‘fˆö”‚ğP‚ÉŠi”[‚µA‘fˆö”‚Ìw”‚ğexponent‚ÉŠi”[‚µA‘fˆö”‚Ìw”æ‚ğP_power‚ÉŠi”[‚·‚éB
template <typename INT>
INT CarmichaelFunction( const INT& n , vector<INT>& P , vector<INT>& exponent , vector<INT>& P_power );
// n < val_limit‚Ì2æ ‚Ì‚Ì‚İƒTƒ|[ƒgB
template <typename INT , INT val_limit , int length_max>
INT CarmichaelFunction( const PrimeEnumeration<INT,val_limit,length_max>& prime , const INT& n , vector<INT>& P , vector<INT>& exponent , vector<INT>& P_power );

// ‘fˆö”•ª‰ğ‚Ìw”‚ªexponent‚Å‚ ‚é”ñ•‰®”‚Æ‚»‚ÌCarmichaelŠÖ”‚Ì’l‚ğÅ¬Œö”{”‚Ì‘fˆö”‚Ìw”‚ğexponent‚ÉŠi”[‚µ’¼‚·B
void CarmichaelTransformation( vector<uint>& exponent );
