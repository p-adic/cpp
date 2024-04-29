// c:/Users/user/Documents/Programming/Utility/Vector/a_Macro.hpp

#pragma once

#define DECLARATION_OF_COUT_FOR_VECTOR( V ) template <class Traits , typename Arg> inline basic_ostream<char,Traits>& operator<<( basic_ostream<char,Traits>& os , const V<Arg>& arg )
#define DEFINITION_OF_COUT_FOR_VECTOR( V ) template <class Traits , typename Arg> inline basic_ostream<char,Traits>& operator<<( basic_ostream<char,Traits>& os , const V<Arg>& arg ) { auto begin = arg.begin() , end = arg.end(); auto itr = begin; while( itr != end ){ ( itr == begin ? os : os << " " ) << *itr; itr++; } return os; }

#define DECLARATION_OF_OPERATOR_FOR_VECTOR( V , OPR )			\
  template <typename T> inline V<T>& operator OPR ## = ( V<T>& a , const T& t ); \
  template <typename T> inline V<T>& operator OPR ## = ( V<T>& a0 , const V<T>& a1 ); \
  template <typename T , typename U> inline V<T> operator OPR( V<T> a , const U& u ); \

#define DEFINITION_OF_OPERATOR_FOR_VECTOR( V , OPR )			\
  template <typename T> inline V<T>& operator OPR ## = ( V<T>& a , const T& t ) { for( auto& s : a ){ s OPR ## = t; } return a; } \
  template <typename T> inline V<T>& operator OPR ## = ( V<T>& a0 , const V<T>& a1 ) { const size_t size = a0.size(); assert( a0.size() <= a1.size() ); auto itr0 = a0.begin() , end0 = a0.end() , itr1 = a1.begin(); while( itr0 != end0 ){ itr0 OPR ## = itr1; } return a0; } \
  template <typename T , typename U> inline V<T> operator OPR( V<T> a , const U& u ) { return move( a OPR ## = u ); } \

#define DECLARATION_OF_INCREMENT_FOR_VECTOR( V , INCR )			\
  template <typename T> inline V<T>& operator INCR( V<T>& a ); \

#define DEFINITION_OF_INCREMENT_FOR_VECTOR( V , INCR )			\
  template <typename T> inline V<T>& operator INCR( V<T>& a ) { for( auto& i : a ){ INCR i; } return a; } \

#define DECLARATION_OF_OPERATORS_FOR_VECTOR( V )	\
  DECLARATION_OF_OPERATOR_FOR_VECTOR( V , + );		\
  DECLARATION_OF_OPERATOR_FOR_VECTOR( V , - );		\
  DECLARATION_OF_OPERATOR_FOR_VECTOR( V , * );		\
  DECLARATION_OF_OPERATOR_FOR_VECTOR( V , / );		\
  DECLARATION_OF_OPERATOR_FOR_VECTOR( V , % );		\
  DECLARATION_OF_INCREMENT_FOR_VECTOR( V , ++ );	\
  DECLARATION_OF_INCREMENT_FOR_VECTOR( V , -- )		\

#define DEFINITION_OF_OPERATORS_FOR_VECTOR( V ) \
  DEFINITION_OF_OPERATOR_FOR_VECTOR( V , + );	\
  DEFINITION_OF_OPERATOR_FOR_VECTOR( V , - );	\
  DEFINITION_OF_OPERATOR_FOR_VECTOR( V , * );	\
  DEFINITION_OF_OPERATOR_FOR_VECTOR( V , / );	\
  DEFINITION_OF_OPERATOR_FOR_VECTOR( V , % );	\
  DEFINITION_OF_INCREMENT_FOR_VECTOR( V , ++ );	\
  DEFINITION_OF_INCREMENT_FOR_VECTOR( V , -- )	\

