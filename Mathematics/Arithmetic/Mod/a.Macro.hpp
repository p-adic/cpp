// c:/Users/user/Documents/Programming/Mathematics/Arithmetic/Mod/a.Macro.hpp

#pragma once

#define DECLARATION_OF_COMPARISON_FOR_MOD( NAME )			\
  inline bool NAME ( const Mod<M>& n ) const noexcept;			\
  inline bool NAME ( const INT_TYPE_FOR_MOD& n ) const noexcept;	\
  inline bool NAME ( INT_TYPE_FOR_MOD&& n ) const noexcept;		\

#define DEFINITION_OF_COMPARISON_FOR_MOD( NAME , OP_SYMBOL )			\
  template <INT_TYPE_FOR_MOD M> inline bool Mod<M>:: NAME ( const Mod<M>& n ) const noexcept { return m_n OP_SYMBOL n.m_n; } \
  template <INT_TYPE_FOR_MOD M> inline bool Mod<M>:: NAME ( const INT_TYPE_FOR_MOD& n ) const noexcept { return m_n OP_SYMBOL Residue<INT_TYPE_FOR_MOD>( n , M ); } \
  template <INT_TYPE_FOR_MOD M> inline bool Mod<M>:: NAME ( INT_TYPE_FOR_MOD&& n ) const noexcept { return m_n OP_SYMBOL Residue<INT_TYPE_FOR_MOD>( move( n ) , M ); } \
  
#define DECLARATION_OF_OPERATOR_FOR_MOD( TYPE , OP_SYMBOL )			\
  template <INT_TYPE_FOR_MOD M> inline TYPE operator OP_SYMBOL( const Mod<M>& n0 , const Mod<M>& n1 ) noexcept; \
  template <INT_TYPE_FOR_MOD M> inline TYPE operator OP_SYMBOL( const Mod<M>& n0 , const INT_TYPE_FOR_MOD& n1 ) noexcept; \
  template <INT_TYPE_FOR_MOD M> inline TYPE operator OP_SYMBOL( const Mod<M>& n0 , INT_TYPE_FOR_MOD&& n1 ) noexcept; \
  template <INT_TYPE_FOR_MOD M> inline TYPE operator OP_SYMBOL( const INT_TYPE_FOR_MOD& n0 , const Mod<M>& n1 ) noexcept; \
  template <INT_TYPE_FOR_MOD M> inline TYPE operator OP_SYMBOL( INT_TYPE_FOR_MOD&& n0 , const Mod<M>& n1 ) noexcept; \

#define DECLARATION_OF_COMPARISON_OPERATOR_FOR_MOD( OP_SYMBOL )	\
  DECLARATION_OF_OPERATOR_FOR_MOD( bool , OP_SYMBOL );			\

#define DEFINITION_OF_COMPARISON_OPERATOR_FOR_MOD( OP_SYMBOL , NAME , NAME_INV ) \
  template <INT_TYPE_FOR_MOD M> inline bool operator OP_SYMBOL( const Mod<M>& n0 , const Mod<M>& n1 ) noexcept { return n0. NAME ( n1 ); } \
  template <INT_TYPE_FOR_MOD M> inline bool operator OP_SYMBOL( const Mod<M>& n0 , const INT_TYPE_FOR_MOD& n1 ) noexcept { return n0. NAME ( n1 ); } \
  template <INT_TYPE_FOR_MOD M> inline bool operator OP_SYMBOL( const Mod<M>& n0 , INT_TYPE_FOR_MOD&& n1 ) noexcept { return n0. NAME ( move( n1 ) ); } \
  template <INT_TYPE_FOR_MOD M> inline bool operator OP_SYMBOL( const INT_TYPE_FOR_MOD& n0 , const Mod<M>& n1 ) noexcept { return n1. NAME_INV ( n0 ); } \
  template <INT_TYPE_FOR_MOD M> inline bool operator OP_SYMBOL( INT_TYPE_FOR_MOD&& n0 , const Mod<M>& n1 ) noexcept { return n1. NAME_INV ( move( n0 ) ); } \

#define DECLARATION_OF_ARITHMETIC_OPERATOR_FOR_MOD( OP_SYMBOL )		\
  DECLARATION_OF_OPERATOR_FOR_MOD( Mod<M> , OP_SYMBOL );			\
  template <INT_TYPE_FOR_MOD M> inline Mod<M> operator OP_SYMBOL( Mod<M>&& n0 , const Mod<M>& n1 ) noexcept; \
  template <INT_TYPE_FOR_MOD M> inline Mod<M> operator OP_SYMBOL( const Mod<M>& n0 , Mod<M>&& n1 ) noexcept; \
  template <INT_TYPE_FOR_MOD M> inline Mod<M> operator OP_SYMBOL( Mod<M>&& n0 , Mod<M>&& n1 ) noexcept; \
  template <INT_TYPE_FOR_MOD M> inline Mod<M> operator OP_SYMBOL( Mod<M>&& n0 , const INT_TYPE_FOR_MOD& n1 ) noexcept; \
  template <INT_TYPE_FOR_MOD M> inline Mod<M> operator OP_SYMBOL( Mod<M>&& n0 , INT_TYPE_FOR_MOD&& n1 ) noexcept; \
  template <INT_TYPE_FOR_MOD M> inline Mod<M> operator OP_SYMBOL( const INT_TYPE_FOR_MOD& n0 , Mod<M>&& n1 ) noexcept; \
  template <INT_TYPE_FOR_MOD M> inline Mod<M> operator OP_SYMBOL( INT_TYPE_FOR_MOD&& n0 , Mod<M>&& n1 ) noexcept; \

#define DEFINITION_OF_ARITHMETIC_OPERATOR_FOR_MOD( OP_SYMBOL )			\
  template <INT_TYPE_FOR_MOD M> inline Mod<M> operator OP_SYMBOL( const Mod<M>& n0 , const Mod<M>& n1 ) noexcept { return move( Mod<M>( n0 ) OP_SYMBOL ## = n1 ); } \
  template <INT_TYPE_FOR_MOD M> inline Mod<M> operator OP_SYMBOL( Mod<M>&& n0 , const Mod<M>& n1 ) noexcept { return move( n0 OP_SYMBOL ## = n1 ); } \
  template <INT_TYPE_FOR_MOD M> inline Mod<M> operator OP_SYMBOL( Mod<M>&& n0 , Mod<M>&& n1 ) noexcept { return move( n0 OP_SYMBOL ## = move( n1 ) ); } \
  template <INT_TYPE_FOR_MOD M> inline Mod<M> operator OP_SYMBOL( const Mod<M>& n0 , const INT_TYPE_FOR_MOD& n1 ) noexcept { return move( Mod<M>( n0 ) OP_SYMBOL ## = n1 ); } \
  template <INT_TYPE_FOR_MOD M> inline Mod<M> operator OP_SYMBOL( Mod<M>&& n0 , const INT_TYPE_FOR_MOD& n1 ) noexcept { return move( n0 OP_SYMBOL ## = n1 ); } \
  template <INT_TYPE_FOR_MOD M> inline Mod<M> operator OP_SYMBOL( const Mod<M>& n0 , INT_TYPE_FOR_MOD&& n1 ) noexcept { return move( Mod<M>( n0 ) OP_SYMBOL ## = move( n1 ) ); } \
  template <INT_TYPE_FOR_MOD M> inline Mod<M> operator OP_SYMBOL( Mod<M>&& n0 , INT_TYPE_FOR_MOD&& n1 ) noexcept { return move( n0 OP_SYMBOL ## = move( n1 ) ); } \
  template <INT_TYPE_FOR_MOD M> inline Mod<M> operator OP_SYMBOL ( const INT_TYPE_FOR_MOD& n0 , const Mod<M>& n1 ) noexcept { return move( Mod<M>( n0 ) OP_SYMBOL ## = n1 ); } \
  template <INT_TYPE_FOR_MOD M> inline Mod<M> operator OP_SYMBOL ( INT_TYPE_FOR_MOD&& n0 , const Mod<M>& n1 ) noexcept { return move( Mod<M>( move( n0 ) ) OP_SYMBOL ## = n1 ); } \
  template <INT_TYPE_FOR_MOD M> inline Mod<M> operator OP_SYMBOL ( INT_TYPE_FOR_MOD&& n0 , Mod<M>&& n1 ) noexcept { return move( Mod<M>( move( n0 ) ) OP_SYMBOL ## = move( n1 ) ); } \

#define DEFINITION_OF_NON_COMMUTATIVE_ARITHMETIC_OPERATOR_FOR_MOD( OP_SYMBOL )	\
  DEFINITION_OF_ARITHMETIC_OPERATOR_FOR_MOD( OP_SYMBOL );			\
  template <INT_TYPE_FOR_MOD M> inline Mod<M> operator OP_SYMBOL( const Mod<M>& n0 , Mod<M>&& n1 ) noexcept { return move( Mod<M>( n0 ) OP_SYMBOL ## = move( n1 ) ); } \
  template <INT_TYPE_FOR_MOD M> inline Mod<M> operator OP_SYMBOL ( const INT_TYPE_FOR_MOD& n0 , Mod<M>&& n1 ) noexcept { return move( Mod<M>( n0 ) OP_SYMBOL ## = move( n1 ) ); } \

#define DEFINITION_OF_COMMUTATIVE_ARITHMETIC_OPERATOR_FOR_MOD( OP_SYMBOL )	\
  DEFINITION_OF_ARITHMETIC_OPERATOR_FOR_MOD( OP_SYMBOL );			\
  template <INT_TYPE_FOR_MOD M> inline Mod<M> operator OP_SYMBOL( const Mod<M>& n0 , Mod<M>&& n1 ) noexcept { return move( n1 OP_SYMBOL ## = n0 ); } \
  template <INT_TYPE_FOR_MOD M> inline Mod<M> operator OP_SYMBOL ( const INT_TYPE_FOR_MOD& n0 , Mod<M>&& n1 ) noexcept { return move( n1 OP_SYMBOL ## = n0 ); } \

