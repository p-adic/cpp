// c:/Users/user/Documents/Programming/Mathematics/Arithmetic/Mod/Residue/a.hpp

#pragma once

template <typename INT1 , typename INT2> inline INT1 Residue( const INT1& n , const INT2& M ) noexcept;
// nが参照で渡されるのでnが変化することに注意。
template <typename INT1 , typename INT2> inline INT1& Residue( INT1& n , const INT2& M ) noexcept;
template <typename INT1 , typename INT2> inline INT1 Residue( INT1&& n , const INT2& M ) noexcept;

template <typename INT1 , typename INT2> inline constexpr INT1 Residue_constexpr( const INT1& n , const INT2& M ) noexcept;

