// c:/Users/user/Documents/Programming/Mathematics/SetTheory/DirectProduct/AffineSpace/CumulativeProduct/a_Body.hpp

#pragma once
#include "a.hpp"

#include "../../../../Algebra/Monoid/Group/a_Body.hpp"

#include "../../../../Function/Map/a_Body.hpp"

template <typename U , typename GROUP> inline PathProductImplementation<U,GROUP>::PathProductImplementation( GROUP M , const int& size ) : m_M( move( M ) ) , m_size( size ) , m_right( m_size , m_M.One() ) , m_left( m_right ) {}
template <typename U , typename GROUP> inline AbstractCumulativeProduct<U,GROUP>::AbstractCumulativeProduct( GROUP M , const int& size ) : AbstractCumulativeProduct( M , vector<U>( size , M.One() ) ) {}
template <typename U , typename GROUP> inline AbstractCumulativeProduct<U,GROUP>::AbstractCumulativeProduct( GROUP M , vector<U> a ) : PathProductImplementation<U,GROUP>( move( M ) , a.size() ) , m_a( move( a ) )
{

  if( !m_a.empty() ){

    this->m_right[0] = this->m_left[0] = m_a[0];

    for( int i = 1 ; i < this->m_size ; i++ ){

      this->m_right[i] = this->m_M.Product( this->m_right[i-1] , m_a[i] );
      this->m_left[i] = this->m_M.Product( m_a[i] , this->m_left[i-1] );

    }

  }

}

template <typename U> inline CumulativeSum<U>::CumulativeSum( const int& size ) : CumulativeSum( vector<U>( size ) ){}
template <typename U> inline CumulativeSum<U>::CumulativeSum( vector<U> a ) : AbstractCumulativeProduct<U,AdditiveGroup<U>>( AdditiveGroup<U>() , move( a ) ) {}

template <typename U , typename GROUP> inline void AbstractCumulativeProduct<U,GROUP>::Initialise( const vector<U>& a ) { *this = AbstractCumulativeProduct( move( this->m_M ) , a ); }

template <typename U , typename GROUP> inline void AbstractCumulativeProduct<U,GROUP>::Set( const int& i , const U& u )
{

  assert( 0 <= i && i < this->_size );
  m_a[i] = u;

  if( i == 0 ){

    this->m_right[0] = this->m_left[0] = m_a[0];

  }
  
  for( int j = max( i , 1 ) ; j < this->m_size ; j++ ){

    this->m_right[j] = this->m_M.Product( this->m_right[j-1] , m_a[j] );
    this->m_left[j] = this->m_M.Product( m_a[j] , this->m_left[j-1] );

  }

}

template <typename U , typename GROUP> inline void AbstractCumulativeProduct<U,GROUP>::RightMultiply( const int& i , const U& u ) { Set( i , this->m_M.Product( m_a[i] , u ) ); }

template <typename U , typename GROUP> inline void AbstractCumulativeProduct<U,GROUP>::LeftMultiply( const int& i , const U& u ) { Set( i , this->m_M.Product( u , m_a[i] ) ); }

template <typename U> inline void CumulativeSum<U>::Add( const int& i , const U& u ) { this->RightMultiply( i , u ); }

template <typename U , typename GROUP> inline U PathProductImplementation<U,GROUP>::PathProduct( const int& i_start , const int& i_final ) { assert( 0 <= i_start && i_start < m_size && 0 <= i_final && i_final < m_size ); const int k = this->LCA( i_start , i_final ); return m_M.Product( m_M.Product( m_left[i_start] , m_M.Inverse( m_left[k] ) ) , k == 0 ? m_right[i_final] : m_M.Product( m_M.Inverse( m_right[this->Parent( k ) ] ) , m_right[i_final] )); }

template <typename U , typename GROUP> inline const U& AbstractCumulativeProduct<U,GROUP>::RightInitialSegmentProduct( int i_final ) { i_final = min( i_final , this->m_size - 1 ); return 0 <= i_final ? this->m_right[i_final] : this->m_M.One(); }
template <typename U , typename GROUP> inline const U& AbstractCumulativeProduct<U,GROUP>::LeftInitialSegmentProduct( int i_final ) { i_final = min( i_final , this->m_size - 1 ); return 0 <= i_final ? this->m_left[i_final] : this->m_M.One();; }
template <typename U> inline const U& CumulativeSum<U>::InitialSegmentSum( int i_final ) { return this->RightInitialSegmentProduct( move( i_final ) ); }

template <typename U , typename GROUP> inline U AbstractCumulativeProduct<U,GROUP>::RightIntervalProduct( const int& i_start , int i_final ) { i_final = min( i_final , this->m_size - 1 ); return i_start <= i_final ? i_start <= 0 ? this->m_right[i_final] : this->m_M.Product( this->m_M.Inverse( this->m_right[i_start-1] ) , this->m_right[i_final] ) : this->m_M.One(); }
template <typename U , typename GROUP> inline U AbstractCumulativeProduct<U,GROUP>::LeftIntervalProduct( const int& i_start , int i_final ) { i_final = min( i_final , this->m_size - 1 ); return i_start <= i_final ? i_start <= 0 ? this->m_left[i_final] : this->m_M.Product( this->m_left[i_final] , this->m_M.Inverse( this->m_left[i_start - 1] ) ) : this->m_M.One(); }
template <typename U> inline U CumulativeSum<U>::IntervalSum( const int& i_start , int i_final ) { return this->RightIntervalProduct( i_start , move( i_final ) ); }

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
int AbstractCumulativeProduct<U,GROUP>::RightBinarySearch( const F& f )
{

  if( f( m_a[0] , 0 ) ){

    return 0;

  }
  
  int l = 0;
  int r = this->m_size;
  
  while( l + 1 < r ){

    int m = ( l + r ) / 2;
    ( f( RightInitialSegmentProduct( m ) , m ) ? r : l ) = m;

  }

  return r;

}

template <typename U , typename GROUP> template <typename F , SFINAE_FOR_CP_BS>
int AbstractCumulativeProduct<U,GROUP>::LeftBinarySearch( const F& f )
{

  if( f( m_a[0] , 0 ) ){

    return 0;

  }
  
  int l = 0;
  int r = this->m_size;
  
  while( l + 1 < r ){

    int m = ( l + r ) / 2;
    ( f( LeftInitialSegmentProduct( m ) , m ) ? r : l ) = m;

  }

  return r;

}

template <typename U , typename GROUP> template <typename F , SFINAE_FOR_CP_BS>
int AbstractCumulativeProduct<U,GROUP>::RightBinarySearch( const int& i_start , const F& f )
{

  if( f( m_a[i_start] , i_start ) ){

    return i_start;

  }
  
  int l = i_start;
  int r = this->m_size;
  
  while( l + 1 < r ){

    int m = ( l + r ) / 2;
    ( f( RightIntervalProduct( i_start , m ) , m ) ? r : l ) = m;

  }

  return r;

}

template <typename U , typename GROUP> template <typename F , SFINAE_FOR_CP_BS>
int AbstractCumulativeProduct<U,GROUP>::LeftBinarySearch( const int& i_start , const F& f )
{

  if( f( m_a[i_start] , i_start ) ){

    return i_start;

  }
  
  int l = i_start;
  int r = this->m_size;
  
  while( l + 1 < r ){

    int m = ( l + r ) / 2;
    ( f( LeftIntervalProduct( i_start , m ) , m ) ? r : l ) = m;

  }

  return r;

}

template <typename U , typename GROUP> inline int AbstractCumulativeProduct<U,GROUP>::RightBinarySearch( const U& u ) { return RightBinarySearch( [&]( const U& prod , const int& i ){ return !( prod < u ); } ); }
template <typename U , typename GROUP> inline int AbstractCumulativeProduct<U,GROUP>::LeftBinarySearch( const U& u ) { return LeftBinarySearch( [&]( const U& prod , const int& i ){ return !( prod < u ); } ); }
template <typename U , typename GROUP> inline int AbstractCumulativeProduct<U,GROUP>::RightBinarySearch( const int& i_start , const U& u ) { return RightBinarySearch( i_start , [&]( const U& prod , const int& i ){ return !( prod < u ); } ); }
template <typename U , typename GROUP> inline int AbstractCumulativeProduct<U,GROUP>::LeftBinarySearch( const int& i_start , const U& u ) { return LeftBinarySearch( i_start , [&]( const U& prod , const int& i ){ return !( prod < u ); } ); }
template <typename U> template <typename...Args> int CumulativeSum<U>::BinarySearch( const Args&... args ) { return this->RightBinarySearch( args... ); }

template <typename U , typename GROUP> inline int AbstractCumulativeProduct<U,GROUP>::Parent( const int& i ) { return i - 1; }
template <typename U , typename GROUP> inline int AbstractCumulativeProduct<U,GROUP>::LCA( const int& i , const int& j ) { return min( i , j ); }
