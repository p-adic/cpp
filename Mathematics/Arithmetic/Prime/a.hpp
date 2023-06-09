// c:/Users/user/Documents/Programming/Mathematics/Arithmetic/Prime/a.hpp

#pragma once
#include "Constexpr/a.hpp"

#include <vector>

// 1+i”Ô–Ú‚Ì‘f”‚ğ•Ô‚·
template <typename INT> const INT& GetPrime( const INT& i ) noexcept;

// i<N‚Ì‚É1+i”Ô–Ú‚Ì‘f”‚ğ•Ô‚·
template <typename INT , INT N> const INT& GetPrimeBounded( const INT& i );

// ”ñ•‰®”n‚Ì‘fˆö”‚ğP‚ÉŠi”[‚µA‘fˆö”‚Ìw”‚ğexponent‚ÉŠi”[‚·‚éB
template <typename INT> void SetPrimeFactorisation( const INT& n , vector<INT>& P , vector<INT>& exponent );
// n < val_limit‚Ì2æ ‚Ì‚Ì‚İƒTƒ|[ƒgB
template <typename INT , INT val_limit , int length_max> void SetPrimeFactorisation( const PrimeEnumeration<INT,val_limit,length_max>& prime , const INT& n , vector<INT>& P , vector<INT>& exponent );

// ”ñ•‰®”n‚Ì‘fˆö”‚ğP‚ÉŠi”[‚µA‘fˆö”‚Ìw”‚ğexponent‚ÉŠi”[‚µA‘fˆö”‚Ìw”æ‚ğP_power‚ÉŠi”[‚·‚éB
template <typename INT> void SetPrimeFactorisation( const INT& n , vector<INT>& P , vector<INT>& exponent , vector<INT>& P_power );
// n < val_limit‚Ì2æ ‚Ì‚Ì‚İƒTƒ|[ƒgB
template <typename INT , INT val_limit , int length_max> void SetPrimeFactorisation( const PrimeEnumeration<INT,val_limit,length_max>& prime  const INT& n , vector<INT>& P , vector<INT>& exponent , vector<INT>& P_power );

// ‘fˆö”‚ğ‚XNŒÂ‚µ‚©‚½‚È‚¢”ñ•‰®”n‚Ì‘fˆö”‚ğP‚ÉŠi”[‚µA‘fˆö”‚Ìw”‚ğexponent‚ÉŠi”[‚·‚éB
template <typename INT , INT N> void SetPrimeFactorisationBounded( const INT& n , INT ( &P )[N] , INT ( &exponent )[N] );
// ‘fˆö”‚ğ‚XNŒÂ‚µ‚©‚½‚È‚¢”ñ•‰®”n‚Ì‘fˆö”‚ğP‚ÉŠi”[‚µA‘fˆö”‚Ìw”‚ğexponent‚ÉŠi”[‚µA‘fˆö”‚Ìw”æ‚ğP_power‚ÉŠi”[‚·‚éB
template <typename INT , INT N> void SetPrimeFactorisationBounded( const INT& n , INT ( &P )[N] , INT ( &exponent )[N] , INT ( &P_power )[N] );

// GCD‚âLCM‚Í../Mod/CRT/a_Body.hpp‚Å’è‹`
