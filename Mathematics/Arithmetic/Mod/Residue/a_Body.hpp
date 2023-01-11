// c:/Users/user/Documents/Programming/Mathematics/Arithmetic/Mod/Residue/a_Body.hpp

#pragma once
#include "a.hpp"

template <typename INT1 , typename INT2> inline constexpr INT1 Residue( const INT1& n , const INT2& M ) noexcept { return Residue( move( INT1( n ) ) , M ); }
template <typename INT1 , typename INT2> inline constexpr INT1& Residue( INT1& n , const INT2& M ) noexcept { return n < 0 ? ( ( ( ( ++n ) *= -1 ) %= M ) *= -1 ) += M - 1 : n %= M; }
template <typename INT1 , typename INT2> inline constexpr INT1 Residue( INT1&& n , const INT2& M ) noexcept { return move( Residue( n , M ) ); }

template <INT_TYPE_FOR_MOD M , typename INT> inline constexpr INT Residue( const INT& n ) noexcept { return Residue<M>( INT( n ) ); }

template <INT_TYPE_FOR_MOD M , typename INT> inline constexpr INT& Residue( INT& n ) noexcept { return n < 0 ? ( ( ( ( ++n ) *= -1 ) %= M ) *= -1 ) += M - 1 : n %= M; }
template <INT_TYPE_FOR_MOD M> inline constexpr uint& Residue( uint& n ) noexcept { return n %= M; }
template <INT_TYPE_FOR_MOD M> inline constexpr ull& Residue( ull& n ) noexcept { return n %= M; }
template <> inline constexpr ull& Residue<998244353,ull>( ull& n ) noexcept { constexpr const ull Pull = 998244353; constexpr const ull Pull2 = ( Pull - 1 ) * ( Pull - 1 ); return Residue998244353( n > Pull2 ? n -= Pull2 : n ); }

template <INT_TYPE_FOR_MOD M , typename INT> inline constexpr INT Residue( INT&& n ) noexcept { return move( Residue<M>( n ) ); }


template <typename INT> inline constexpr INT& Residue998244353( INT& n ) noexcept { constexpr uint P = 998244353; constexpr const uint trunc = ( 1 << 23 ) - 1; INT n_u = n >> 23; n &= trunc; INT n_uq = ( n_u / 7 ) / 17; n_u -= n_uq * 119; n += n_u << 23; return n < n_uq ? n += P - n_uq : n -= n_uq; }
