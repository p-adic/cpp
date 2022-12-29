// c:/Users/user/Documents/Programming/Mathematics/Arithmetic/Mod/a.Macro.hpp

#pragma once
#define DECLARATION_OF_COMPARISON_FOR_MOD( NAME )			\
  inline bool NAME ( const Mod<M>& n ) const noexcept;			\
  inline bool NAME ( const INT_TYPE_FOR_MOD& n ) const noexcept;	\

#define DEFINITION_OF_COMPARISON_FOR_MOD( NAME , OP )			\
  template <INT_TYPE_FOR_MOD M> inline bool Mod<M>:: NAME ( const Mod<M>& n ) const noexcept { return m_n OP n.m_n; } \
  template <INT_TYPE_FOR_MOD M> inline bool Mod<M>:: NAME ( const INT_TYPE_FOR_MOD& n ) const noexcept { return m_n OP Residue<INT_TYPE_FOR_MOD>( n , M ); } \
  
#define DECLARATION_OF_OPERATOR_FOR_MOD( TYPE , OP )			\
  template <INT_TYPE_FOR_MOD M> inline TYPE operator OP( const Mod<M>& n0 , const Mod<M>& n1 ) noexcept; \
  template <INT_TYPE_FOR_MOD M> inline TYPE operator OP( const Mod<M>& n0 , const INT_TYPE_FOR_MOD& n1 ) noexcept; \
  template <INT_TYPE_FOR_MOD M> inline TYPE operator OP( const INT_TYPE_FOR_MOD& n0 , const Mod<M>& n1 ) noexcept; \

#define DEFINITION_OF_COMPARISON_OPERATOR_FOR_MOD( OP , NAME , NAME_INV ) \
  template <INT_TYPE_FOR_MOD M> inline bool operator OP( const Mod<M>& n0 , const Mod<M>& n1 ) noexcept { return n0. NAME ( n1 ); } \
  template <INT_TYPE_FOR_MOD M> inline bool operator OP( const Mod<M>& n0 , const INT_TYPE_FOR_MOD& n1 ) noexcept { return n0. NAME ( n1 ); } \
  template <INT_TYPE_FOR_MOD M> inline bool operator OP( const INT_TYPE_FOR_MOD& n0 , const Mod<M>& n1 ) noexcept { return n1. NAME_INV ( n0 ); } \

#define DEFINITION_OF_ARITHMETIC_OPERATOR_FOR_MOD( OP )					\
  template <INT_TYPE_FOR_MOD M> inline Mod<M> operator OP( const Mod<M>& n0 , const Mod<M>& n1 ) noexcept { return move( Mod<M>( n0 ) OP ## = n1 ); } \
  template <INT_TYPE_FOR_MOD M> inline Mod<M> operator OP( const Mod<M>& n0 , const INT_TYPE_FOR_MOD& n1 ) noexcept { return move( Mod<M>( n0 ) OP ## = Mod<M>( n1 ) ); } \
      template <INT_TYPE_FOR_MOD M> inline Mod<M> operator OP ( const INT_TYPE_FOR_MOD& n0 , const Mod<M>& n1 ) noexcept { return move( Mod<M>( n0 ) OP ## = n1 ); } \

#define DEFINITION_OF_COMMUTATIVE_ARITHMETIC_OPERATOR_FOR_MOD( OP )			\
  template <INT_TYPE_FOR_MOD M> inline Mod<M> operator OP( const Mod<M>& n0 , const Mod<M>& n1 ) noexcept { return move( Mod<M>( n0 ) OP ## = n1 ); } \
  template <INT_TYPE_FOR_MOD M> inline Mod<M> operator OP( const Mod<M>& n0 , const INT_TYPE_FOR_MOD& n1 ) noexcept { return move( Mod<M>( n1 ) OP ## = n0 ); } \
  template <INT_TYPE_FOR_MOD M> inline Mod<M> operator OP ( const INT_TYPE_FOR_MOD& n0 , const Mod<M>& n1 ) noexcept { return move( Mod<M>( n0 ) OP ## = n1 ); } \
