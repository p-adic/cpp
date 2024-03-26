// c:/Users/user/Documents/Programming/Mathematics/Arithmetic/Prime/a.hpp

#pragma once
#include "Constexpr/a.hpp"

#include <vector>

// 1+i”Ô–Ú‚Ì‘f”‚ğ•Ô‚·
template <typename INT> const INT& GetPrime( const INT& i ) noexcept;

// i<N‚Ì‚É1+i”Ô–Ú‚Ì‘f”‚ğ•Ô‚·
template <typename INT , INT N> const INT& GetPrimeBounded( const INT& i );

// ”ñ•‰®”n‚Ì‘fˆö”‚ğP‚ÉŠi”[‚µA‘fˆö”‚Ìw”‚ğexponent‚ÉŠi”[‚·‚éB
template <typename INT1 , typename INT2 , typename INT3> void SetPrimeFactorisation( const INT1& n , vector<INT2>& P , vector<INT3>& exponent );
// sqrt( n )ˆÈ‰º‚ÌÅ‘å‚Ì‘f” < val_limit ‚Ì‚Ì‚İƒTƒ|[ƒgB
template <typename INT , INT val_limit , int length_max , typename INT1 , typename INT2 , typename INT3> void SetPrimeFactorisation( const PrimeEnumeration<INT,val_limit,length_max>& prime , const INT1& n , vector<INT2>& P , vector<INT3>& exponent );

// ”ñ•‰®”n‚Ì‘fˆö”‚ğP‚ÉŠi”[‚µA‘fˆö”‚Ìw”‚ğexponent‚ÉŠi”[‚µA‘fˆö”‚Ìw”æ‚ğP_power‚ÉŠi”[‚·‚éB
template <typename INT1 , typename INT2 , typename INT3 , typename INT4> void SetPrimeFactorisation( const INT1& n , vector<INT2>& P , vector<INT3>& exponent , vector<INT4>& P_power );
// sqrt( n )ˆÈ‰º‚ÌÅ‘å‚Ì‘f” < val_limit ‚Ì‚Ì‚İƒTƒ|[ƒgB
template <typename INT , INT val_limit , int length_max , typename INT1 , typename INT2 , typename INT3> void SetPrimeFactorisation( const PrimeEnumeration<INT,val_limit,length_max>& prime , const INT1& n , vector<INT2>& P , vector<INT3>& exponent , vector<INT4>& P_power );

// ‘fˆö”‚ğ‚XNŒÂ‚µ‚©‚½‚È‚¢”ñ•‰®”n‚Ì‘fˆö”‚ğP‚ÉŠi”[‚µA‘fˆö”‚Ìw”‚ğexponent‚ÉŠi”[‚·‚éB
template <typename INT1 , typename INT2 , typename INT3 , int N> void SetPrimeFactorisationBounded( const INT1& n , INT2 ( &P )[N] , INT3 ( &exponent )[N] );
// ‘fˆö”‚ğ‚XNŒÂ‚µ‚©‚½‚È‚¢”ñ•‰®”n‚Ì‘fˆö”‚ğP‚ÉŠi”[‚µA‘fˆö”‚Ìw”‚ğexponent‚ÉŠi”[‚µA‘fˆö”‚Ìw”æ‚ğP_power‚ÉŠi”[‚·‚éB
template <typename INT1 , typename INT2 , typename INT3 , typename INT4 , int N> void SetPrimeFactorisationBounded( const INT1& n , INT2 ( &P )[N] , INT3 ( &exponent )[N] , INT4 ( &P_power )[N] );

// GCD‚âLCM‚ÍDivisor/GCD/a_Body.hpp‚Å’è‹`
