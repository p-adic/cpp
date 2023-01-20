// c:/Users/user/Documents/Programming/Mathematics/Arithmetic/Mod/Euler/a.hpp

#pragma once

template <typename INT> inline INT EulerFunction( const INT& n );

// ”ñ•‰®”n‚Ì‘fˆö”‚ğP‚ÉŠi”[‚µA‘fˆö”‚Ìw”‚ğexponent‚ÉŠi”[‚·‚éB
template <typename INT>
INT EulerFunction( const INT& n , vector<INT>& P , vector<INT>& exponent );

template <typename INT> inline INT CarmichaelFunction( const INT& n );

// ”ñ•‰®”n‚Ì‘fˆö”‚ğP‚ÉŠi”[‚µA‘fˆö”‚Ìw”‚ğexponent‚ÉŠi”[‚µA‘fˆö”‚Ìw”æ‚ğP_power‚ÉŠi”[‚·‚éB
template <typename INT>
INT CarmichaelFunction( const INT& n , vector<INT>& P , vector<INT>& exponent , vector<INT>& P_power );

void CarmichaelTransformation( vector<uint>& exponent );
