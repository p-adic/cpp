// c:/Users/user/Documents/Programming/Mathematics/SetTheory/DirectProduct/AffineSpace/SqrtDecomposition/Dual/GeometricProgressionMin/a_Body.hpp

#pragma once
#include "a.hpp"

#include "../a_Body.hpp"
#include "../../../../../../Algebra/Monoid/Module/a_Body.hpp"

template <typename U> inline GeometricProgressionMinComposition<U>::GeometricProgressionMinComposition( const int& size , const U& infty ) : PointedSet<vector<U>>( vector( size , infty ) ) {}
template <typename U , typename N_MODULE> inline GeometricProgressionMinAction<U,N_MODULE>::GeometricProgressionMinAction( N_MODULE M , const vector<U>& memory ) : m_M( move( M ) ) , m_p_memory( &memory ) { static_assert( is_same_v<U,inner_t<N_MODULE>> ); }

template <typename U>
vector<U> GeometricProgressionMinComposition<U>::Action( const pair<int,U>& y0 , vector<U> y1 )
{

  U& y1_r = y1[y0.first];
  y1_r = min( y1_r , y0.second );
  return move( y1 );

}

template <typename U , typename N_MODULE>
pair<U,int> GeometricProgressionMinAction<U,N_MODULE>::Action( const vector<U>& y , pair<U,int> u )
{

  const int size = y.size();
  
  for( int i = 0 ; i < size ; i++ ){

    u.first = min( u.first , m_M.Product( m_M.Power( ( *m_p_memory )[i] , u.second ) , y[i] ) );

  }

  return move( u );

}

template <typename U , typename N_MODULE> template <typename...Args> inline GeometricProgressionMinDualSqrtDecomposition<U,N_MODULE>::GeometricProgressionMinDualSqrtDecomposition( N_MODULE M , const U& infty , vector<U> memory_r , vector<U> a , Args&&... args ) : BaseOfGeometricProgressionMinDualSqrtDecomposition<U,N_MODULE>( GeometricProgressionMinComposition<U>( memory_r.size() , infty ) , GeometricProgressionMinAction<U,N_MODULE>( move( M ) , m_memory ) , GetGraph( move( a ) ) , forward<decay_t<Args>>( args )... ) , m_memory( move( memory_r ) ) {}

template <typename U , typename N_MODULE> template <typename...Args> inline void GeometricProgressionMinDualSqrtDecomposition<U,N_MODULE>::Initialise( Args&&... args ) { *this = GeometricProgressionMinDualSqrtDecomposition<U,N_MODULE>( move( this->m_M , forward<decay_t<Args>>( args )... ) ); }

template <typename U , typename N_MODULE> inline void GeometricProgressionMinDualSqrtDecomposition<U,N_MODULE>::Set( const int& i , U u ) { BaseOfGeometricProgressionMinDualSqrtDecomposition<U,N_MODULE>::Set( i , { move( u ) , i } ); }

template <typename U , typename N_MODULE> inline void GeometricProgressionMinDualSqrtDecomposition<U,N_MODULE>::IntervalSetMin( const int& i_start , const int& i_final , const int& r_num , const U& y ) { assert( 0 <= r_num && r_num < int( m_memory.size() ) ); BaseOfGeometricProgressionMinDualSqrtDecomposition<U,N_MODULE>::IntervalAct( i_start , i_final , pair<int,U>{ r_num , y } ); }

template <typename U , typename N_MODULE> inline U GeometricProgressionMinDualSqrtDecomposition<U,N_MODULE>::operator[]( const int& i ) { return BaseOfGeometricProgressionMinDualSqrtDecomposition<U,N_MODULE>::operator[]( i ).first; }
template <typename U , typename N_MODULE> inline U GeometricProgressionMinDualSqrtDecomposition<U,N_MODULE>::Get( const int& i ) { return operator[]( i ); }

template <typename U , typename N_MODULE> inline vector<pair<U,int>> GeometricProgressionMinDualSqrtDecomposition<U,N_MODULE>::GetGraph( vector<U> a ) { const int size = a.size(); vector<pair<U,int>> answer( size ); for( int i = 0 ; i < size ; i++ ){ answer[i] = { move( a[i] ) , i }; } return answer; }
