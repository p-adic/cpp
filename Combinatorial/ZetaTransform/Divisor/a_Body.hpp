// c:/Users/user/Documents/Programming/Mathematics/Combinatorial/ZetaTransform/Divisor/a_Body.hpp

#pragma once
#include "a.hpp"

#include "../a_Body.hpp"
#include "../../../Algebra/Monoid/Semirng/Ring/Algebra/a_Body.hpp"
#include "../../../Arithmetic/Divisor/Enumeration/a_Body.hpp"
#include "../../../Arithmetic/Divisor/Moevius/a_Body.hpp"

template <typename LD> inline DivisorMoeviusFunction<LD>::DivisorMoeviusFunction( const LD& ld , const int& n_max ) : m_val( TotalMoeviusFunction( ld , n_max ) ) {}
template <typename LD> inline MultipleMoeviusFunction<LD>::MultipleMoeviusFunction( const LD& ld , const int& n_max ) : m_val( TotalMoeviusFunction( ld , n_max ) ) {}

template <typename LD> inline int DivisorMoeviusFunction<LD>::operator()( const int& t0 , const int& t1 ) { return m_val[t1 / t0]; }
template <typename LD> inline int MultipleMoeviusFunction<LD>::operator()( const int& t0 , const int& t1 ) { return m_val[t0 / t1]; }

template <typename LD> inline DivisorEdge<LD>::DivisorEdge( const LD& ld ) : m_p_ld( &ld ) {}
inline MultipleEdge::MultipleEdge( const int& size ) : m_size( size ) {}

template <typename LD> inline vector<int> DivisorEdge<LD>::operator()( const int& t ) { assert( 0 <= t ); vector<int> answer{}; return t == 0 ? vector<int>( 1 ) : EnumerateDivisor( *m_p_ld , t ); }
inline vector<int> MultipleEdge::operator()( const int& t ) { assert( 0 <= t && t < m_size ); const int size = t == 0 ? 0 : ( m_size - 1 ) / t; vector<int> answer( size ); for( int i = 0 ; i < size ; i++ ){ answer[i] = t * ( i + 1 ); } return answer; }


template <typename LD , typename U , typename Z_ALG> inline AbstractDivisorZetaTransform<LD,U,Z_ALG>::AbstractDivisorZetaTransform( const LD& ld , Z_ALG R , vector<U> a , const bool& transformed ) : AbstractDivisorZetaTransform( ld , move( R ) , a.size() , a , transformed ) {}
template <typename LD , typename U , typename Z_ALG> inline AbstractDivisorZetaTransform<LD,U,Z_ALG>::AbstractDivisorZetaTransform( const LD& ld , Z_ALG R , const int& size , vector<U>& a , const bool& transformed ) : AbstractZetaTransform<int,Graph<DivisorEdge<LD>>,Graph<MultipleEdge>,U,Z_ALG,DivisorMoeviusFunction<LD>>( Graph( size , DivisorEdge( ld ) ) , Graph( size , MultipleEdge( size ) ) , move( R ) , DivisorMoeviusFunction( ld , size - 1 ) , move( a ) , transformed ) {}
template <typename LD , typename U> inline DivisorZetaTransform<LD,U>::DivisorZetaTransform( const LD& ld , const U& one , const int& size ) : AbstractDivisorZetaTransform<LD,U,Algebra<int,U>>( ld , Algebra<int,U>( one ) , vector<U>( size ) , true ) {}
template <typename LD , typename U> inline DivisorZetaTransform<LD,U>::DivisorZetaTransform( const LD& ld , const U& one , vector<U> a , const bool& transformed ) : AbstractDivisorZetaTransform<LD,U,Algebra<int,U>>( ld , Algebra<int,U>( one ) , move( a ) , transformed ) {}

template <typename LD , typename U , typename Z_ALG> inline AbstractMultipleZetaTransform<LD,U,Z_ALG>::AbstractMultipleZetaTransform( const LD& ld , Z_ALG R , vector<U> a , const bool& transformed ) : AbstractMultipleZetaTransform( ld , move( R ) , a.size() , a , transformed ) {}
template <typename LD , typename U , typename Z_ALG> inline AbstractMultipleZetaTransform<LD,U,Z_ALG>::AbstractMultipleZetaTransform( const LD& ld , Z_ALG R , const int& size , vector<U>& a , const bool& transformed ) : AbstractZetaTransform<int,Graph<MultipleEdge>,Graph<DivisorEdge<LD>>,U,Z_ALG,MultipleMoeviusFunction<LD>>( Graph( size , MultipleEdge( size ) ) , Graph( size , DivisorEdge( ld ) ) , move( R ) , MultipleMoeviusFunction( ld , size - 1 ) , move( a ) , transformed ) {}
template <typename LD , typename U> inline MultipleZetaTransform<LD,U>::MultipleZetaTransform( const LD& ld , const U& one , const int& size ) : AbstractMultipleZetaTransform<LD,U,Algebra<int,U>>( ld , Algebra<int,U>( one ) , vector<U>( size ) , true ) {}
template <typename LD , typename U> inline MultipleZetaTransform<LD,U>::MultipleZetaTransform( const LD& ld , const U& one , vector<U> a , const bool& transformed ) : AbstractMultipleZetaTransform<LD,U,Algebra<int,U>>( ld , Algebra<int,U>( one ) , move( a ) , transformed ) {}

