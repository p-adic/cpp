// c:/Users/user/Documents/Programming/Mathematics/Polynomial/Truncate/NonProth/a_Macro.hpp

#pragma once
#include "../a_Macro.hpp"

// 関数テンプレートの明示的特殊化にinlineをつけないと複数の翻訳単位でincludeできないことに注意。
#define DEFINITION_BODY_OF_PARTIAL_SPECIALISATION_OF_MULTIPLICATION_OF_POLYNOMIAL_ARBITRARY_MOD( TYPE , ARG , MINT , COEF ) \
  template <>								\
  inline Polynomial<TYPE>& Polynomial<TYPE>::operator*=( ARG f )		\
  {									\
									\
    if( m_size != 0 ){							\
									\
      if( f.m_size == 0 ){						\
									\
	m_f.clear();							\
	m_size = 0;							\
									\
      } else {								\
									\
	constexpr INT_TYPE_FOR_MOD P0 = 167772161;			\
	constexpr INT_TYPE_FOR_MOD P1 = 469762049;			\
	constexpr INT_TYPE_FOR_MOD P2 = 998244353;			\
	using M0 = MINT<P0>;					\
	using M1 = MINT<P1>;					\
	using M2 = MINT<P2>;					\
	vector<M0> v0{};						\
	vector<M1> v1{};						\
	vector<M2> v2{};						\
	v0.reserve( m_size );						\
	v1.reserve( m_size );						\
	v2.reserve( m_size );						\
									\
	for( uint d = 0 ; d < m_size ; d++ ){				\
									\
	  auto&& f_d = COEF;						\
	  v0.push_back( f_d );				\
	  v1.push_back( f_d );				\
	  v2.push_back( f_d );				\
									\
	}								\
									\
	vector<M0> w0{};						\
	vector<M1> w1{};						\
	vector<M2> w2{};						\
	w0.reserve( f.m_size );						\
	w1.reserve( f.m_size );						\
	w2.reserve( f.m_size );						\
									\
	for( uint d = 0 ; d < f.m_size ; d++ ){				\
									\
	  auto&& f_d = f.COEF;						\
	  w0.push_back( f_d );				\
	  w1.push_back( f_d );				\
	  w2.push_back( f_d );				\
									\
	}								\
									\
	m_size += f.m_size - 1;						\
	TruncatedPolynomial<M0> this_copy0{ m_size , move( v0 ) };	\
	TruncatedPolynomial<M1> this_copy1{ m_size , move( v1 ) };	\
	TruncatedPolynomial<M2> this_copy2{ m_size , move( v2 ) };	\
	TruncatedPolynomial<M0> f_copy0{ f.m_size , move( w0 ) };	\
	TruncatedPolynomial<M1> f_copy1{ f.m_size , move( w1 ) };	\
	TruncatedPolynomial<M2> f_copy2{ f.m_size , move( w2 ) };	\
	this_copy0 *= f_copy0;						\
	this_copy1 *= f_copy1;						\
	this_copy2 *= f_copy2;						\
	m_f.clear();							\
	m_f.reserve( m_size );						\
	constexpr TYPE P0_mod_M = TYPE( P0 );				\
	constexpr TYPE P01_mod_M = TYPE( P1 ) * P0_mod_M;			\
	constexpr M1 P0_mod_P1_inv = M1::Derepresent( 104391568 );	\
	constexpr M2 P0_mod_P2 = M2::Derepresent( P0 );	\
	constexpr M2 P01_mod_P2_inv = M2::Derepresent( 575867115 );	\
	static_assert( ( M1::Derepresent( P0 ) *= P0_mod_P1_inv ) == M1::Derepresent( 1 ) ); \
	static_assert( ( M2::Derepresent( P0 ) *= M2::Derepresent( P1 ) *= P01_mod_P2_inv ) == M2::Derepresent( 1 ) ); \
									\
	for( uint d = 0 ; d < m_size ; d++ ){				\
									\
	  auto&& c0 = this_copy0[d].Represent();	\
	  auto&& c1 = ( ( this_copy1[d] -= c0 ) *= P0_mod_P1_inv ).Represent(); \
	  auto&& c2 = ( ( this_copy2[d] -= P0_mod_P2 * c1 + c0 ) *= P01_mod_P2_inv ).Represent(); \
	  m_f.push_back( P01_mod_M * c2 + P0_mod_M * c1 + c0 );		\
									\
	}								\
									\
	RemoveRedundantZero();						\
									\
      }									\
									\
    }									\
									\
    return *this;							\
									\
  }									\

#define DEFINITION_OF_PARTIAL_SPECIALISATION_OF_MULTIPLICATION_OF_POLYNOMIAL_ARBITRARY_MOD( MOD , MINT ) \
  DEFINITION_BODY_OF_PARTIAL_SPECIALISATION_OF_MULTIPLICATION_OF_POLYNOMIAL_ARBITRARY_MOD( MINT<MOD> , const Polynomial<MINT<MOD> >& , MINT , m_f[d].Represent() ); \
  DEFINITION_BODY_OF_PARTIAL_SPECIALISATION_OF_MULTIPLICATION_OF_POLYNOMIAL_ARBITRARY_MOD( MINT<MOD> , Polynomial<MINT<MOD> >&& , MINT , m_f[d].Represent() ); \

#define DEFINITION_OF_PARTIAL_SPECIALISATION_OF_MULTIPLICATION_OF_POLYNOMIAL_NON_MOD( INT ) \
  DEFINITION_BODY_OF_PARTIAL_SPECIALISATION_OF_MULTIPLICATION_OF_POLYNOMIAL_ARBITRARY_MOD( INT , const Polynomial<INT>& , Mod , m_f[d] ); \
  DEFINITION_BODY_OF_PARTIAL_SPECIALISATION_OF_MULTIPLICATION_OF_POLYNOMIAL_ARBITRARY_MOD( INT , Polynomial<INT>&& , Mod , m_f[d] ); \

