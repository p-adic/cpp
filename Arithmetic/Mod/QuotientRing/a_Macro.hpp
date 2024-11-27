// c:/Users/user/Documents/Programming/Mathematics/Arithmetic/Mod/QuotientRing/a_Macro.hpp

#pragma once

#define DECLARATION_OF_ARITHMETIC_FOR_QUOTIENT( OPR , EX )		   \
  inline constexpr QuotientRing<U> operator OPR( QuotientRing<U> n ) const EX; \

#define DEFINITION_OF_ARITHMETIC_FOR_QUOTIENT( OPR , EX , LEFT , OPR2 )	\
  template <typename U> inline constexpr QuotientRing<U> QuotientRing<U>::operator OPR( QuotientRing<U> n ) const EX { return move( LEFT OPR2 ## = *this ); } \
  template <typename U , typename T> inline constexpr QuotientRing<U> operator OPR( T n0 , const QuotientRing<U>& n1 ) EX { return move( QuotientRing<U>( move( n0 ) ) OPR ## = n1 ); } \


