// c:/Users/user/Documents/Programming/Mathematics/Arithmetic/Mod/Residue/a_Body.hpp

#pragma once
#include "a.hpp"

template <typename INT> inline INT Residue( const INT& n , const INT& M ) noexcept { return n >= 0 ? n % M : M - 1 - ( - ( n + 1 ) ); }
template <typename INT> inline INT Residue( INT&& n , const INT& M ) noexcept { return move( n >= 0 ? n %= M : ( ( ( ( ++n ) *= -1 ) %= M ) *= -1 ) += M - 1 ); }
