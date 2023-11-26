// c:/Users/user/Documents/Programming/Mathematics/Combinatorial/ZetaTransform/Divisor/a_Macro.hpp

#pragma once

#define DECLARATION_OF_FUNCTIONS_FOR_DIVISOR_ZETA_TRANSFORM( CONSTEXPR_SQRT_BOUND_NUM ) \
  constexpr PrimeEnumeration<int, CONSTEXPR_SQRT_BOUND_NUM + 1> PRIME_FOR_DIVISOR_ZETA_FUNCTION{}; \
  inline int DivisorMoeviusFunction( const int& t0 , const int& t1 );	\
  inline int MultipleMoeviusFunction( const int& t0 , const int& t1 );	\
  inline list<int> DivisorEdge( const int& t );				\
  inline list<int> MultipleEdge( const int& t );			\

#define DEFINITION_OF_FUNCTIONS_FOR_DIVISOR_ZETA_TRANSFORM( NUM )	\
  inline int DivisorMoeviusFunction( const int& t0 , const int& t1 ) { return TwoAryMoeviusFunction( PRIME_FOR_DIVISOR_ZETA_FUNCTION , t0 , t1 ); } \
  inline int MultipleMoeviusFunction( const int& t0 , const int& t1 ) { return TwoAryMoeviusFunction( PRIME_FOR_DIVISOR_ZETA_FUNCTION , t1 , t0 ); } \
  inline list<int> DivisorEdge( const int& t ) { return DivisorEdgeForZetaTransform( PRIME_FOR_DIVISOR_ZETA_FUNCTION , NUM , t ); } \
  inline list<int> MultipleEdge( const int& t ) { return MultipleEdgeForZetaTransform( NUM , t ); }	\

