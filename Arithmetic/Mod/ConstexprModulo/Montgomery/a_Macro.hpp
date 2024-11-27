// c:/Users/user/Documents/Programming/Mathematics/Arithmetic/Mod/ConstexprModulo/Montgomery/a_Macro.hpp

#pragma once

#define DECLARATION_OF_COMPARISON_FOR_MONTGOMERY( OPR )			\
  inline constexpr bool operator OPR( const Montgomery<M>& n ) const noexcept \

#define DECLARATION_OF_ARITHMETIC_FOR_MONTGOMERY( OPR , EX )		\
  inline Montgomery<M> operator OPR( Montgomery<M> n ) const EX;	\

#define DEFINITION_OF_COMPARISON_FOR_MONTGOMERY( OPR )			\
  template <INT_TYPE_FOR_MONTGOMERY M> inline constexpr bool Montgomery<M>::operator OPR( const Montgomery<M>& n ) const noexcept { return m_n OPR n.m_n; } \

#define DEFINITION_OF_ARITHMETIC_FOR_MONTGOMERY( OPR , EX , LEFT , OPR2 ) \
  template <INT_TYPE_FOR_MONTGOMERY M> inline Montgomery<M> Montgomery<M>::operator OPR( Montgomery<M> n ) const EX { return move( LEFT OPR2 ## = *this ); } \
  template <INT_TYPE_FOR_MONTGOMERY M , typename T> inline Montgomery<M> operator OPR( T n0 , const Montgomery<M>& n1 ) EX { return move( Montgomery<M>( move( n0 ) ) OPR ## = n1 ); } \


