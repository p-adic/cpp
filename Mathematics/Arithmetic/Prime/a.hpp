// c:/Users/user/Documents/Programming/Mathematics/Arithmetic/Prime/a.hpp

#pragma once
#include "Constexpr/a.hpp"


// 1+i”Ô–Ú‚Ì‘f”‚ğ•Ô‚·
template <typename INT> const INT& GetPrime( const INT& i ) noexcept;

// i<N‚Ì‚É1+i”Ô–Ú‚Ì‘f”‚ğ•Ô‚·
template <typename INT , INT N> const INT& GetPrimeBounded( const INT& i );
