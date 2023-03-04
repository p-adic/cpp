// c:/Users/user/Documents/Programming/Mathematics/Arithmetic/Mod/a.Macro.hpp

#pragma once

#define SFINAE_FOR_MOD( DEFAULT )						\
  typename T , enable_if_t<is_constructible<INT_TYPE_FOR_MOD,decay_t<T> >::value>* DEFAULT \

#define DECLARATION_OF_COMPARISON_FOR_MOD( FUNC )		\
  inline bool operator FUNC( const Mod<M>& n ) const noexcept	\

#define DECLARATION_OF_ARITHMETIC_FOR_MOD( FUNC )			\
  inline Mod<M> operator FUNC( const Mod<M>& n ) const noexcept;	\
  template <SFINAE_FOR_MOD( = nullptr )> inline Mod<M> operator FUNC( T&& n ) const noexcept; \

#define DEFINITION_OF_COMPARISON_FOR_MOD( FUNC )			\
  template <INT_TYPE_FOR_MOD M> inline bool Mod<M>::operator FUNC( const Mod<M>& n ) const noexcept { return m_n FUNC n.m_n; } \

#define DEFINITION_OF_ARITHMETIC_FOR_MOD( FUNC , FORMULA ) \
  template <INT_TYPE_FOR_MOD M> inline Mod<M> Mod<M>::operator FUNC( const Mod<M>& n ) const noexcept { return move( Mod<M>( *this ) FUNC ## = n ); } \
  template <INT_TYPE_FOR_MOD M> template <SFINAE_FOR_MOD()> inline Mod<M> Mod<M>::operator FUNC( T&& n ) const noexcept { return FORMULA; } \
  template <INT_TYPE_FOR_MOD M , SFINAE_FOR_MOD( = nullptr )> inline Mod<M> operator FUNC( T&& n0 , const Mod<M>& n1 ) noexcept { return move( Mod<M>( forward<T>( n0 ) ) FUNC ## = n1 ); } \


