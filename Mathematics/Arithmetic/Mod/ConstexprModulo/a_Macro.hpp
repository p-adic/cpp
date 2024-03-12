// c:/Users/user/Documents/Programming/Mathematics/Arithmetic/Mod/ConstexprModulo/a_Macro.hpp

#pragma once

#define DECLARATION_OF_COMPARISON_FOR_MOD( OPR )			\
  inline constexpr bool operator OPR( const Mod<M>& n ) const noexcept	\

#define DECLARATION_OF_ARITHMETIC_FOR_MOD( OPR , EX )		   \
  inline constexpr Mod<M> operator OPR( Mod<M> n ) const EX; \

#define DEFINITION_OF_COMPARISON_FOR_MOD( OPR )			\
  template <INT_TYPE_FOR_MOD M> inline constexpr bool Mod<M>::operator OPR( const Mod<M>& n ) const noexcept { return m_n OPR n.m_n; } \

#define DEFINITION_OF_ARITHMETIC_FOR_MOD( OPR , EX , LEFT , OPR2 )	\
  template <INT_TYPE_FOR_MOD M> inline constexpr Mod<M> Mod<M>::operator OPR( Mod<M> n ) const EX { return move( LEFT OPR2 ## = *this ); } \
  template <INT_TYPE_FOR_MOD M , typename T> inline constexpr Mod<M> operator OPR( T n0 , const Mod<M>& n1 ) EX { return move( Mod<M>( move( n0 ) ) OPR ## = n1 ); } \


