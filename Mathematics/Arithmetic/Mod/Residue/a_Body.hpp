// c:/Users/user/Documents/Programming/Mathematics/Arithmetic/Mod/Residue/a_Body.hpp

#pragma once
#include "a.hpp"

template <typename INT1 , typename INT2> inline constexpr INT1 Residue( const INT1& n , const INT2& M ) noexcept { return Residue( move( INT1( n ) ) , M ); }
template <typename INT1 , typename INT2> inline INT1& Residue( INT1& n , const INT2& M ) noexcept { return n >= 0 ? n %= M : ( ( ( ( ++n ) *= -1 ) %= M ) *= -1 ) += M - 1; }
template <typename INT1 , typename INT2> inline constexpr INT1 Residue( INT1&& n , const INT2& M ) noexcept { return move( n >= 0 ? n %= M : ( ( ( ( ++n ) *= -1 ) %= M ) *= -1 ) += M - 1 ); }

template <typename INT1 , typename INT2> inline constexpr INT1 Residue_constexpr( const INT1& n , const INT2& M ) noexcept { return n >= 0 ? n % M : M - 1 - ( ( - ( n - 1 ) ) % M ); }
