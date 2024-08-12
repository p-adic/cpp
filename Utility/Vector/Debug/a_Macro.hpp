// c:/Users/user/Documents/Programming/Utility/Vector/Debug/a_Macro.hpp

#pragma once

#define DECLARATION_OF_COUT_FOR_VECTOR( V ) template <class Traits , typename Arg> inline basic_ostream<char,Traits>& operator<<( basic_ostream<char,Traits>& os , const V<Arg>& arg )

#define DEFINITION_OF_COUT_FOR_VECTOR( V , LBRACK , RBRACK ) template <class Traits , typename Arg> inline basic_ostream<char,Traits>& operator<<( basic_ostream<char,Traits>& os , const V<Arg>& arg ) { os << LBRACK; auto begin = arg.begin() , end = arg.end(); auto itr = begin; while( itr != end ){ ( itr == begin ? os : os << ", " ) << *itr; itr++; } return os << RBRACK; }

#define DEFINITION_OF_COUT_FOR_DOUBLE_VECTOR_BODY( V , W , LBRACK , RBRACK ) template <class Traits , typename Arg> inline basic_ostream<char,Traits>& operator<<( basic_ostream<char,Traits>& os , const V<W<Arg>>& arg ) { os << LBRACK << "\n"; auto begin = arg.begin() , end = arg.end(); auto itr = begin; while( itr != end ){ ( itr == begin ? os << " " : os << ",\n " ) << *itr; itr++; } return os << "\n" << RBRACK; }

#define DEFINITION_OF_COUT_FOR_DOUBLE_VECTOR( V , LBRACK , RBRACK )	\
  DEFINITION_OF_COUT_FOR_DOUBLE_VECTOR_BODY( V , vector , LBRACK , RBRACK ); \
  DEFINITION_OF_COUT_FOR_DOUBLE_VECTOR_BODY( V , list , LBRACK , RBRACK ); \
  DEFINITION_OF_COUT_FOR_DOUBLE_VECTOR_BODY( V , set , LBRACK , RBRACK ); \
  DEFINITION_OF_COUT_FOR_DOUBLE_VECTOR_BODY( V , unordered_set , LBRACK , RBRACK );

#define DECLARATION_OF_ARITHMETIC_FOR_VECTOR( V , OPR )			\
  template <typename T> inline V<T>& operator OPR ## = ( V<T>& a , const T& t ); \
  template <typename T> inline V<T>& operator OPR ## = ( V<T>& a0 , const V<T>& a1 ); \
  template <typename T , typename U> inline V<T> operator OPR( V<T> a , const U& u ); \

#define DEFINITION_OF_ARITHMETIC_FOR_VECTOR( V , OPR )			\
  template <typename T> inline V<T>& operator OPR ## = ( V<T>& a , const T& t ) { for( auto& s : a ){ s OPR ## = t; } return a; } \
  template <typename T> inline V<T>& operator OPR ## = ( V<T>& a0 , const V<T>& a1 ) { assert( a0.size() <= a1.size() ); auto itr0 = a0.begin() , end0 = a0.end(); auto itr1 = a1.begin(); while( itr0 != end0 ){ *( itr0++ ) OPR ## = *( itr1++ ); } return a0; } \
  template <typename T , typename U> inline V<T> operator OPR( V<T> a , const U& u ) { return move( a OPR ## = u ); } \

#define DECLARATION_OF_INCREMENT_FOR_VECTOR( V , INCR )		\
  template <typename T> inline V<T>& operator INCR( V<T>& a );	\

#define DEFINITION_OF_INCREMENT_FOR_VECTOR( V , INCR )			\
  template <typename T> inline V<T>& operator INCR( V<T>& a ) { for( auto& i : a ){ INCR i; } return a; } \

#define DECLARATION_OF_ARITHMETICS_FOR_VECTOR( V )			\
  DECLARATION_OF_ARITHMETIC_FOR_VECTOR( V , + );			\
  DECLARATION_OF_ARITHMETIC_FOR_VECTOR( V , - );			\
  DECLARATION_OF_ARITHMETIC_FOR_VECTOR( V , * );			\
  DECLARATION_OF_ARITHMETIC_FOR_VECTOR( V , / );			\
  DECLARATION_OF_ARITHMETIC_FOR_VECTOR( V , % );			\
  DECLARATION_OF_INCREMENT_FOR_VECTOR( V , ++ );			\
  DECLARATION_OF_INCREMENT_FOR_VECTOR( V , -- );			\
  template <typename T> inline V<T> operator*( const T& scalar , V<T> v ) \

#define DEFINITION_OF_ARITHMETICS_FOR_VECTOR( V )			\
  DEFINITION_OF_ARITHMETIC_FOR_VECTOR( V , + );				\
  DEFINITION_OF_ARITHMETIC_FOR_VECTOR( V , - );				\
  DEFINITION_OF_ARITHMETIC_FOR_VECTOR( V , * );				\
  DEFINITION_OF_ARITHMETIC_FOR_VECTOR( V , / );				\
  DEFINITION_OF_ARITHMETIC_FOR_VECTOR( V , % );				\
  DEFINITION_OF_INCREMENT_FOR_VECTOR( V , ++ );				\
  DEFINITION_OF_INCREMENT_FOR_VECTOR( V , -- );				\
  template <typename T> inline V<T> operator*( const T& scalar , V<T> v ) { for( auto& t : v ){ v *= t; } return move( v ); } \


