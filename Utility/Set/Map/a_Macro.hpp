// c:/Users/user/Documents/Programming/Utility/Set/Map/a_Macro.hpp

#pragma once

#define DECLARATION_OF_ARITHMETIC_FOR_MAP( MAP , OPR )			\
  template <typename T , typename U> inline MAP<T,U>& operator OPR ## = ( MAP<T,U>& a , const pair<T,U>& v ); \
  template <typename T , typename U> inline MAP<T,U>& operator OPR ## = ( MAP<T,U>& a0 , const MAP<T,U>& a1 ); \
  template <typename T , typename U , typename ARG> inline MAP<T,U> operator OPR( MAP<T,U> a , const ARG& arg ); \

#define DEFINITION_OF_ARITHMETIC_FOR_MAP( MAP , OPR )			\
  template <typename T , typename U> inline MAP<T,U>& operator OPR ## = ( MAP<T,U>& a , const pair<T,U>& v ) { a[v.first] OPR ## = v.second; return a; } \
  template <typename T , typename U> inline MAP<T,U>& operator OPR ## = ( MAP<T,U>& a0 , const MAP<T,U>& a1 ) { for( auto& [t,u] : a1 ){ a0[t] OPR ## = u; } return a0; } \
  template <typename T , typename U , typename ARG> inline MAP<T,U> operator OPR( MAP<T,U> a , const ARG& arg ) { return move( a OPR ## = arg ); } \

#define DECLARATION_OF_ARITHMETICS_FOR_MAP( MAP )	\
  DECLARATION_OF_ARITHMETIC_FOR_MAP( MAP , + );		\
  DECLARATION_OF_ARITHMETIC_FOR_MAP( MAP , - );		\
  DECLARATION_OF_ARITHMETIC_FOR_MAP( MAP , * );		\
  DECLARATION_OF_ARITHMETIC_FOR_MAP( MAP , / );		\
  DECLARATION_OF_ARITHMETIC_FOR_MAP( MAP , % );		\

#define DEFINITION_OF_ARITHMETICS_FOR_MAP( MAP ) \
  DEFINITION_OF_ARITHMETIC_FOR_MAP( MAP , + );	\
  DEFINITION_OF_ARITHMETIC_FOR_MAP( MAP , - );	\
  DEFINITION_OF_ARITHMETIC_FOR_MAP( MAP , * );	\
  DEFINITION_OF_ARITHMETIC_FOR_MAP( MAP , / );	\
  DEFINITION_OF_ARITHMETIC_FOR_MAP( MAP , % );	\

