// c:/Users/user/Documents/Programming/Mathematics/Arithmetic/Mod/ConstexprModulo/a_Macro.hpp

#pragma once

// static_assertだとTruncatedPolynomial<Mod<M>>へのスカラー倍などで
// 余計なオーバーロード候補が生じてしまい不適。
#define SFINAE_FOR_MOD enable_if_t<is_constructible_v<INT_TYPE_FOR_MOD,decay_t<T>>>*

#define DECLARATION_OF_COMPARISON_FOR_MOD( OPR )			\
  inline constexpr bool operator OPR( const Mod<M>& n ) const noexcept	\

#define DECLARATION_OF_ARITHMETIC_FOR_MOD( OPR , EX )		\
  inline constexpr Mod<M> operator OPR( Mod<M> n ) const EX;	\

#define DEFINITION_OF_COMPARISON_FOR_MOD( OPR )				\
  template <INT_TYPE_FOR_MOD M> inline constexpr bool Mod<M>::operator OPR( const Mod<M>& n ) const noexcept { return m_n OPR n.m_n; } \

#define DEFINITION_OF_ARITHMETIC_FOR_MOD( OPR , EX , LEFT , OPR2 )	\
  template <INT_TYPE_FOR_MOD M> inline constexpr Mod<M> Mod<M>::operator OPR( Mod<M> n ) const EX { return move( LEFT OPR2 ## = *this ); } \
  template <INT_TYPE_FOR_MOD M , typename T , SFINAE_FOR_MOD = nullptr> inline constexpr Mod<M> operator OPR( T n0 , const Mod<M>& n1 ) EX { return move( Mod<M>( move( n0 ) ) OPR ## = n1 ); } \


