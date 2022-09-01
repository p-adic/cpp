// c:/Users/user/Documents/Programming/Mathematics/Arithmetic/Prime/a.hpp

#pragma once
#include <vector>

// 1+i”Ô–Ú‚Ì‘f”‚ğ•Ô‚·
const uint& GetPrime( const uint& i ) noexcept;

// i<N‚Ì‚É1+i”Ô–Ú‚Ì‘f”‚ğ•Ô‚·
template <uint N>
const uint& GetPrimeBounded( const uint& i );

// ”ñ•‰®”n‚Ì‘fˆö”‚ğP‚ÉŠi”[‚µA‘fˆö”‚Ìw”‚ğexponent‚ÉŠi”[‚·‚éB
void SetPrimeFactorisation( const uint& n , vector<uint>& P , vector<uint>& exponent );

// ‘fˆö”‚ğ‚XNŒÂ‚µ‚©‚½‚È‚¢”ñ•‰®”n‚Ì‘fˆö”‚ğP‚ÉŠi”[‚µA‘fˆö”‚Ìw”‚ğexponent‚ÉŠi”[‚·‚éB
template <uint N>
void SGetPrimeFactorisationBounded( const uint& n , uint ( &P )[N] , uint ( &exponent )[N] );

// 1+i”Ô–Ú‚Ì‘f”ˆÈã‚Ì‘ŠˆÙ‚È‚é‘f”—LŒÀŒÂ‚Ì˜a‚Å•\‚¹‚È‚¢Å¬‚Ì”ñ•‰®”‚ğ•Ô‚·
uint GetKloveSequence( const uint& i ) noexcept;
