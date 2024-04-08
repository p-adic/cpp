// c:/Users/user/Documents/Programming/Mathematics/Combinatorial/ZetaTransform/Divisor/a_Body.hpp

#pragma once
#include "a.hpp"

#include "../a_Body.hpp"
#include "../../../Algebra/Monoid/Semirng/Ring/Algebra/a_Body.hpp"
#include "../../../Arithmetic/Prime/Divisor/Constexpr/a_Body.hpp"
#include "../../../Arithmetic/Prime/Divisor/Moevius/Constexpr/a_Body.hpp"

#include "../../../Arithmetic/Prime/Divisor/a_Body.hpp"

template <typename MU> inline constexpr DivisorMoeviusFunction<MU>::DivisorMoeviusFunction( const MU& mu ) : m_p_mu( &mu ) {}
template <typename MU> inline constexpr MultipleMoeviusFunction<MU>::MultipleMoeviusFunction( const MU& mu ) : m_p_mu( &mu ) {}

template <typename MU> inline int DivisorMoeviusFunction<MU>::operator()( const int& t0 , const int& t1 ) { return ( *m_p_mu )( t1 / t0 ); }
template <typename MU> inline int MultipleMoeviusFunction<MU>::operator()( const int& t0 , const int& t1 ) { return ( *m_p_mu )( t0 / t1 ); }

template <typename LD> inline DivisorEdge<LD>::DivisorEdge( const LD& ld ) : m_p_ld( &ld ) {}
inline MultipleEdge::MultipleEdge( const int& size ) : m_size( size ) {}

template <typename LD> inline vector<int> DivisorEdge<LD>::operator()( const int& t ) { assert( 0 <= t ); vector<int> answer{}; return t == 0 ? vector<int>( 1 ) : EnumerateDivisor( *m_p_ld , t ); }
inline vector<int> MultipleEdge::operator()( const int& t ) { assert( 0 <= t && t < m_size ); const int size = t == 0 ? 0 : ( m_size - 1 ) / t; vector<int> answer( size ); for( int i = 0 ; i < size ; i++ ){ answer[i] = t * ( i + 1 ); } return answer; }


template <typename LD , typename MU , typename U , typename Z_ALG> inline AbstractDivisorZetaTransform<LD,MU,U,Z_ALG>::AbstractDivisorZetaTransform( const LD& ld , Z_ALG R , const int& size ) : AbstractZetaTransform<int,Graph<DivisorEdge<LD>>,Graph<MultipleEdge>,U,Z_ALG,DivisorMoeviusFunction<MU>>( Graph( size , DivisorEdge( ld ) ) , Graph( size , MultipleEdge( size ) ) , move( R ) , DivisorMoeviusFunction( m_mu ) ) , m_mu( ld ) {}
template <typename LD , typename MU , typename U , typename Z_ALG> inline AbstractDivisorZetaTransform<LD,MU,U,Z_ALG>::AbstractDivisorZetaTransform( const LD& ld , Z_ALG R , vector<U> a , const bool& transformed ) : AbstractDivisorZetaTransform( ld , move( R ) , a.size() , a , transformed ) {}
template <typename LD , typename MU , typename U , typename Z_ALG> inline AbstractDivisorZetaTransform<LD,MU,U,Z_ALG>::AbstractDivisorZetaTransform( const LD& ld , Z_ALG R , const int& size , vector<U>& a , const bool& transformed ) : AbstractZetaTransform<int,Graph<DivisorEdge<LD>>,Graph<MultipleEdge>,U,Z_ALG,DivisorMoeviusFunction<MU>>( Graph( size , DivisorEdge( ld ) ) , Graph( size , MultipleEdge( size ) ) , move( R ) , DivisorMoeviusFunction( m_mu ) , move( a ) , transformed ) , m_mu( ld ) {}
template <int val_limit , typename U> template <typename...Args> inline DivisorZetaTransform<val_limit,U>::DivisorZetaTransform( const LeastDivisor<int,val_limit>& ld , const U& one , Args&&... args ) : AbstractDivisorZetaTransform<LeastDivisor<int,val_limit>,MoeviusFunction<int,val_limit>,U,Algebra<int,U>>( ld , Algebra<int,U>( one ) , forward<Args>( args )... ) {}

template <typename LD , typename MU , typename U , typename Z_ALG> inline AbstractMultipleZetaTransform<LD,MU,U,Z_ALG>::AbstractMultipleZetaTransform( const LD& ld , Z_ALG R , const int& size ) : AbstractZetaTransform<int,Graph<MultipleEdge>,Graph<DivisorEdge<LD>>,U,Z_ALG,MultipleMoeviusFunction<MU>>( Graph( size , MultipleEdge( size ) ) , Graph( size , DivisorEdge( ld ) ) , move( R ) , MultipleMoeviusFunction( m_mu ) ) , m_mu( ld ) {}
template <typename LD , typename MU , typename U , typename Z_ALG> inline AbstractMultipleZetaTransform<LD,MU,U,Z_ALG>::AbstractMultipleZetaTransform( const LD& ld , Z_ALG R , vector<U> a , const bool& transformed ) : AbstractMultipleZetaTransform( ld , move( R ) , a.size() , a , transformed ) {}
template <typename LD , typename MU , typename U , typename Z_ALG> inline AbstractMultipleZetaTransform<LD,MU,U,Z_ALG>::AbstractMultipleZetaTransform( const LD& ld , Z_ALG R , const int& size , vector<U>& a , const bool& transformed ) : AbstractZetaTransform<int,Graph<MultipleEdge>,Graph<DivisorEdge<LD>>,U,Z_ALG,MultipleMoeviusFunction<MU>>( Graph( size , MultipleEdge( ld ) ) , Graph( size , DivisorEdge( ld ) ) , move( R ) , MultipleMoeviusFunction( m_mu ) , move( a ) , transformed ) , m_mu( ld ) {}
template <int val_limit , typename U> template <typename...Args> inline MultipleZetaTransform<val_limit,U>::MultipleZetaTransform( const LeastDivisor<int,val_limit>& ld , const U& one , Args&&... args ) : AbstractMultipleZetaTransform<LeastDivisor<int,val_limit>,MoeviusFunction<int,val_limit>,U,Algebra<int,U>>( ld , Algebra<int,U>( one ) , forward<Args>( args )... ) {}

