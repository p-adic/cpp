// c:/Users/user/Documents/Programming/Utility/Reverse/a_Macro.hpp

#pragma once

#define DECLARATION_OF_REVERSED_RELATION( OPR )			\
  inline bool operator OPR( const Reversed<T>& t ) const	\

#define DEFINITION_OF_REVERSED_RELATION( OPR )				\
  template <typename T> inline bool Reversed<T>::operator OPR( const Reversed<T>& t ) const { return t.m_t OPR m_t; } \

#define DECLARATION_OF_REVERSED_ARITHMETIC( OPR , TYPE )	\
  inline Reversed<T>& operator OPR ## =( const TYPE& t );	\
  inline Reversed<T> operator OPR( const TYPE& t ) const;	\

#define DEFINITION_OF_REVERSED_ARITHMETIC( OPR , TYPE , OBJ )		\
  template <typename T> inline Reversed<T>& Reversed<T>::operator OPR ## =( const TYPE& t ) { m_t OPR ## = OBJ; return *this; } \
  template <typename T> inline Reversed<T> Reversed<T>::operator OPR( const TYPE& t ) const { return move( Reversed<T>( *this ) OPR ## = t ); } \


