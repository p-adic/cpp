// c:/Users/user/Documents/Programming/Mathematics/Arithmetic/Mod/ConstexprModulo/Template/Montgomery/a_Macro.hpp

#pragma once

#define SPECIALISATION_FOR_MONTGOMERY( MODULO )				\
  template <> template <SFINAE_FOR_MOD()> inline constexpr Montgomery<MODULO>::Mod( const T& n ) noexcept : m_n( OperatorsForMontgomery<MODULO>::Express( OperatorsForMontgomery<MODULO>::Residue( n ) ) ) {} \
									\
  template <> template <SFINAE_FOR_MOD()> inline constexpr Montgomery<MODULO>::Mod( T& n ) noexcept : m_n( OperatorsForMontgomery<MODULO>::Express( OperatorsForMontgomery<MODULO>::Residue( decay_t<T>( n ) ) ) ) {} \
  template <> template <SFINAE_FOR_MOD()> inline constexpr Montgomery<MODULO>::Mod( T&& n ) noexcept : m_n( OperatorsForMontgomery<MODULO>::Express( OperatorsForMontgomery<MODULO>::Residue( move( n ) ) ) ) {} \
									\
  template <> inline constexpr conditional_t<is_same<OperatorsForMontgomery<MODULO>,OperatorsForMod<MODULO> >::value,const INT_TYPE_FOR_MOD&,INT_TYPE_FOR_MOD> Montgomery<MODULO>::Represent() const noexcept { return OperatorsForMontgomery<MODULO>::Reduce( m_n ); } \									\
  template <> inline constexpr Montgomery<MODULO> Montgomery<MODULO>::Derepresent( const INT_TYPE_FOR_MOD& n ) noexcept { Montgomery<MODULO> n_copy{}; n_copy.m_n = OperatorsForMontgomery<MODULO>::Express( n ); return n_copy; } \

