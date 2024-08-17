// c:/Users/user/Documents/Programming/Mathematics/Polynomial/a_Macro.hpp

#pragma once

#define DECLARATION_OF_ARITHMETIC_FOR_POLYNOMIAL( FUNC )	\
  inline Polynomial<T> operator FUNC( Polynomial<T> f ) const;	\
  inline Polynomial<T> operator FUNC( T t ) const		\

#define DEFINITION_OF_ARITHMETIC_FOR_POLYNOMIAL( FUNC , DEF )		\
  template <typename T> inline Polynomial<T> Polynomial<T>::operator FUNC( Polynomial<T> f ) const { return move( DEF ); }; \
  template <typename T> inline Polynomial<T> Polynomial<T>::operator FUNC( T t ) const { return *this FUNC Polynomial<T>( move( t ) ); } \


