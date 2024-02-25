// c:/Users/user/Documents/Programming/Mathematics/SetTheory/DirectProduct/AffineSpace/CumulativeProduct/a_Body.hpp

#pragma once
#include "a.hpp"

#include "../../../../Algebra/Monoid/Group/a_Body.hpp"

#include "../../../../Function/Map/a_Body.hpp"

template <typename U , typename GROUP> inline PathProductImplementation<U,GROUP>::PathProductImplementation( const int& size , GROUP M ) : m_size( size ) , m_M( move( M ) ) , m_right( m_size , m_M.One() ) , m_left( m_right ) {}
template <typename U , typename GROUP> inline AbstractCumulativeProduct<U,GROUP>::AbstractCumulativeProduct( GROUP M , const vector<U>& a ) : PathProductImplementation<U,GROUP>( a.size() , move( M ) )
{

  if( !a.empty() ){

    this->m_right[0] = this->m_left[0] = a[0];

    for( int i = 1 ; i < this->m_size ; i++ ){

      this->m_right[i] = this->m_M.Product( this->m_right[i-1] , a[i] );
      this->m_left[i] = this->m_M.Product( a[i] , this->m_left[i-1] );

    }

  }

}

template <typename U> inline CumulativeSum<U>::CumulativeSum( const int& size ) : CumulativeSum( vector<U>( size ) ){}
template <typename U> inline CumulativeSum<U>::CumulativeSum( const vector<U>& a ) : AbstractCumulativeProduct<U,AdditiveGroup<U>>( AdditiveGroup<U>() , a ) {}

template <typename U , typename GROUP> inline void AbstractCumulativeProduct<U,GROUP>::Set( const vector<U>& a ) { *this = AbstractCumulativeProduct( move( this->m_M ) , a ); }

template <typename U , typename GROUP> inline void AbstractCumulativeProduct<U,GROUP>::RightMultiply( const int& i , const U& u )
{

  const U m_right_i_inv = this->m_M.Inverse( this->m_right[i] );
  const U& m_right_i = this->m_right[i] = this->m_M.Product( this->m_right[i] , u );

  for( int j = i + 1 ; j < this->m_size ; j++ ){

    this->m_right[j] = this->m_M.Product( m_right_i , this->m_M.Product( m_right_i_inv , this->m_right[j] ) );

  }

  const U m_left_i_prev_inv = i == this->m_size - 1 ? One() : this->m_M.Inverse( this->m_left[i-1] );
  const U m_left_i_prev = this->m_M.Product( u , this->m_left[i-1] );

  for( int j = i + 1 ; j < this->m_size ; j++ ){

    this->m_left[j] = this->m_M.Product( this->m_M.Product( this->m_left[j] , m_left_i_prev_inv ) , m_left_i_prev );

  }

}

template <typename U , typename GROUP> inline void AbstractCumulativeProduct<U,GROUP>::LeftMultiply( const int& i , const U& u )
{

  const U m_right_i_prev_inv = i == 0 ? One() : this->m_M.Inverse( this->m_right[i-1] );
  const U m_right_i_prev = i == 0 ? u : this->m_M.Product( this->m_right[i-1] , u );

  for( int j = i ; j < this->m_size ; j++ ){

    this->m_right[j] = this->m_M.Product( m_right_i_prev , this->m_M.Product( m_right_i_prev_inv , this->m_right[j] ) );

  }

  const U m_left_i_inv = this->m_M.Inverse( this->m_left[i] );
  const U& m_left_i = this->m_left[i] = this->m_M.Product( u , this->m_left[i] );

  for( int j = i + 1 ; j < this->m_size ; j++ ){

    this->m_left[j] = this->m_M.Product( this->m_M.Product( this->m_left[j] , m_left_i_inv ) , m_left_i );

  }

}

template <typename U> inline void CumulativeSum<U>::Add( const int& i , const U& u ) { this->RightMultiply( i , u ); }

template <typename U , typename GROUP> inline U PathProductImplementation<U,GROUP>::PathProduct( const int& i , const int& j ) { assert( 0 <= i && i < m_size && 0 <= j && j < m_size ); const int k = this->LCA( i , j ); return m_M.Product( m_M.Product( m_left[i] , m_M.Inverse( m_left[k] ) ) , k == 0 ? m_right[j] : m_M.Product( m_M.Inverse( m_right[this->Parent( k ) ] ) , m_right[j] )); }

template <typename U , typename GROUP> inline U AbstractCumulativeProduct<U,GROUP>::RightIntervalProduct( const int& i , int j ) { j = min( j , this->m_size - 1 ); return i <= j ? i <= 0 ? this->m_right[j] : this->m_M.Product( this->m_M.Inverse( this->m_right[i-1] ) , this->m_right[j] ) : One(); }
template <typename U , typename GROUP> inline U AbstractCumulativeProduct<U,GROUP>::LeftIntervalProduct( const int& i , int j ) { j = min( j , this->m_size - 1 ); return i <= j ? i <= 0 ? this->m_left[j] : this->m_M.Product( this->m_left[j] , this->m_M.Inverse( this->m_left[i - 1] ) ) : One(); }
template <typename U> inline U CumulativeSum<U>::IntervalSum( const int& i , int j ) { return this->RightIntervalProduct( i , move( j ) ); }

template <typename U , typename GROUP> ll AbstractCumulativeProduct<U,GROUP>::CountRightIntervalProductInverseImage( const U& u )
{

  Map<U,ll> f{};
  f[u]++;
  ll answer = 0;

  for( int i = 0 ; i < this->m_size ; i++ ){

    const U& m_right_i = this->m_right[i];
    f.count( m_right_i ) == 1 ? answer += f[m_right_i] : answer;
    f[this->m_M.Product( m_right_i , u )]++;

  }

  return answer;

}

template <typename U , typename GROUP> ll AbstractCumulativeProduct<U,GROUP>::CountLeftIntervalProductInverseImage( const U& u )
{

  Map<U,ll> f{};
  f[u]++;
  ll answer = 0;

  for( int i = 0 ; i < this->m_size ; i++ ){

    const U& m_left_i = this->m_left[i];
    f.count( m_left_i ) == 1 ? answer += f[m_left_i] : answer;
    f[this->m_M.Product( u , m_left_i )]++;

  }

  return answer;

}

template <typename U> ll CumulativeSum<U>::CountIntervalSumInverseImage( const U& u ) { return this->CountRightIntervalProductInverseImage( u ); }

template <typename U , typename GROUP> template <typename F , SFINAE_FOR_CP_BS>
int AbstractCumulativeProduct<U,GROUP>::RightBinarySearch( const int& i_start , const F& f )
{

  int l = i_start - 1;
  int r = this->m_size - 1;
  
  while( l + 1 < r ){

    int m = ( l + r ) / 2;
    ( f( RightIntervalProduct( i_start , m ) , m ) ? r : l ) = m;

  }

  return r;

}

template <typename U , typename GROUP> template <typename F , SFINAE_FOR_CP_BS>
int AbstractCumulativeProduct<U,GROUP>::LeftBinarySearch( const int& i_start , const F& f )
{

  int l = i_start - 1;
  int r = this->m_size - 1;
  
  while( l + 1 < r ){

    int m = ( l + r ) / 2;
    ( f( LeftIntervalProduct( i_start , m ) , m ) ? r : l ) = m;

  }

  return r;

}

template <typename U , typename GROUP> inline int AbstractCumulativeProduct<U,GROUP>::RightBinarySearch( const int& i_start , const U& u ) { return RightBinarySearch( i_start , [&]( const U& prod , const int& i ){ return !( prod < u ); } ); }
template <typename U , typename GROUP> inline int AbstractCumulativeProduct<U,GROUP>::LeftBinarySearch( const int& i_start , const U& u ) { return LeftBinarySearch( i_start , [&]( const U& prod , const int& i ){ return !( prod < u ); } ); }

template <typename U> template <typename F> int CumulativeSum<U>::BinarySearch( const int& i_start , const F& f ) { return this->RightBinarySearch( i_start , f ); }

template <typename U , typename GROUP> inline int AbstractCumulativeProduct<U,GROUP>::Parent( const int& i ) { return i - 1; }
template <typename U , typename GROUP> inline int AbstractCumulativeProduct<U,GROUP>::LCA( const int& i , const int& j ) { return min( i , j ); }
template <typename U , typename GROUP> inline const U& AbstractCumulativeProduct<U,GROUP>::One() const { return this->m_M.One(); }
