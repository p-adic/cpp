// c:/Users/user/Documents/Programming/Mathematics/Arithmetic/Mod/ConstexprModulo/Template/a_Macro.hpp

#pragma once

#define SFINAE_FOR_MOD( DEFAULT )						\
  typename T , enable_if_t<is_constructible<INT_TYPE_FOR_MOD,decay_t<T> >::value>* DEFAULT \

#define DECLARATION_OF_COMPARISON_FOR_MOD( FUNC )		\
  inline bool operator FUNC( const Mod<M,OPR>& n ) const noexcept	\

#define DECLARATION_OF_ARITHMETIC_FOR_MOD( FUNC )			\
  inline Mod<M,OPR> operator FUNC( const Mod<M,OPR>& n ) const noexcept;	\
  template <SFINAE_FOR_MOD( = nullptr )> inline Mod<M,OPR> operator FUNC( T&& n ) const noexcept; \

#define DEFINITION_OF_COMPARISON_FOR_MOD( FUNC )			\
  template <INT_TYPE_FOR_MOD M , typename OPR> inline bool Mod<M,OPR>::operator FUNC( const Mod<M,OPR>& n ) const noexcept { return m_n FUNC n.m_n; } \

#define DEFINITION_OF_ARITHMETIC_FOR_MOD( FUNC , FORMULA ) \
  template <INT_TYPE_FOR_MOD M , typename OPR> inline Mod<M,OPR> Mod<M,OPR>::operator FUNC( const Mod<M,OPR>& n ) const noexcept { return move( Mod<M,OPR>( *this ) FUNC ## = n ); } \
  template <INT_TYPE_FOR_MOD M , typename OPR> template <SFINAE_FOR_MOD()> inline Mod<M,OPR> Mod<M,OPR>::operator FUNC( T&& n ) const noexcept { return Mod<M,OPR>( forward<T>( n ) ) FORMULA; } \
  template <INT_TYPE_FOR_MOD M , typename OPR = OperatorsForMod<M> , SFINAE_FOR_MOD( = nullptr )> inline Mod<M,OPR> operator FUNC( T&& n0 , const Mod<M,OPR>& n1 ) noexcept { return move( Mod<M,OPR>( forward<T>( n0 ) ) FUNC ## = n1 ); } \


