// c:/Users/user/Documents/Programming/Mathematics/Arithmetic/Mod/Residue/a_Body.hpp

#pragma once
#include "a.hpp"

template <typename INT> inline INT Residue( const INT& n , const INT& M ) noexcept { return n >= 0 ? n % M : M - ( - n - 1 ) % M - 1; }
