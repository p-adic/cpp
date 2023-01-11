// c:/Users/user/Documents/Programming/Mathematics/Arithmetic/Mod/Constant/a_Body.hpp

#pragma once
#include "a.hpp"

#include "../a_Body.hpp"

template <INT_TYPE_FOR_MOD M> inline constexpr ull ConstantsForMod<M>::MontgomeryBasePower( ull&& exponent ) noexcept { ull prod = 1; ull power = M; while( exponent != 0 ){ ( exponent & 1 ) == 1 ? ( prod *= power ) &= g_Montgomery_base_minus : prod; exponent >>= 1; ( power *= power ) &= g_Montgomery_base_minus; } return prod; }
