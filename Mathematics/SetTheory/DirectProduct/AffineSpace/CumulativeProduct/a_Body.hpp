// c:/Users/user/Documents/Programming/Mathematics/SetTheory/DirectProduct/AffineSpace/CumulativeProduct/a_Body.hpp

#pragma once
#include "a.hpp"

#include "../../../../Algebra/Monoid/Group/a_Body.hpp"

#include "../../../../../Utility/Set/a_Body.hpp"

template <typename U , typename GROUP> inline AbstractCumulativeProduct<U,GROUP>::AbstractCumulativeProduct( GROUP M , const int& size ) : AbstractCumulativeProduct( M , vector<U>( size , M.One() ) ) {}
template <typename U , typename GROUP> inline AbstractCumulativeProduct<U,GROUP>::AbstractCumulativeProduct( GROUP M , vector<U> a ) : m_M( move( M ) ) , m_size( a.size() ) , m_a( move( a ) ) , m_right( m_size + 1 , m_M.One() ) , m_left( m_right )
{

  static_assert( is_same_v<U,inner_t<GROUP>> );
  
  for( int i = 0 ; i < m_size ; i++ ){

    m_right[i+1] = m_M.Product( m_right[i] , m_a[i] );
    m_left[i+1] = m_M.Product( m_a[i] , m_left[i] );

  }

}

template <typename U> template <typename...Args> inline CumulativeSum<U>::CumulativeSum( Args&&... args ) : AbstractCumulativeProduct<U,AdditiveGroup<U>>( AdditiveGroup<U>() , forward<Args>( args )... ) {}

template <typename U , typename GROUP> template <typename...Args> inline void AbstractCumulativeProduct<U,GROUP>::Initialise( Args&&... args ) { AbstractCumulativeProduct temp{ m_M , forward<Args>( args )... }; m_size = temp.m_size; m_a = move( temp.m_a ); m_right = move( temp.m_right ); m_left = move( temp.m_left ); }

template <typename U , typename GROUP> inline void AbstractCumulativeProduct<U,GROUP>::Set( const int& i , U u )
{

  assert( 0 <= i && i < m_size );

  // m_a[i]‚ªmove‚³‚ê‚Ä‚¢‚é‰Â”\«‚ª‚ ‚é‚Ìm_a[i]!=u‚Å‚ ‚é‚©”Û‚©‚Åê‡•ª‚¯‚ð‚µ‚È‚¢B
  m_a[i] = move( u );
  
  for( int j = i ; j < m_size ; j++ ){

    m_right[j+1] = m_M.Product( m_right[j] , m_a[j] );
    m_left[j+1] = m_M.Product( m_a[j] , m_left[j] );

  }

}

template <typename U , typename GROUP> inline void AbstractCumulativeProduct<U,GROUP>::RightMultiply( const int& i , const U& u ) { Set( i , m_M.Product( move( m_a[i] ) , u ) ); }
template <typename U , typename GROUP> inline void AbstractCumulativeProduct<U,GROUP>::LeftMultiply( const int& i , U u ) { Set( i , m_M.Product( move( u ) , m_a[i] ) ); }
template <typename U> inline void CumulativeSum<U>::Add( const int& i , const U& u ) { this->RightMultiply( i , u ); }

template <typename U , typename GROUP> inline const U& AbstractCumulativeProduct<U,GROUP>::RightInitialSegmentProduct( int i_final ) { return m_right[max( 0 , min( ++i_final , m_size ) )]; }
template <typename U , typename GROUP> inline const U& AbstractCumulativeProduct<U,GROUP>::LeftInitialSegmentProduct( int i_final ) { return m_left[max( 0 , min( ++i_final , m_size ) )]; }
template <typename U> inline const U& CumulativeSum<U>::InitialSegmentSum( int i_final ) { return this->RightInitialSegmentProduct( move( i_final ) ); }

template <typename U , typename GROUP> inline U AbstractCumulativeProduct<U,GROUP>::RightIntervalProduct( const int& i_start , int i_final ) { return i_start < ( i_final = min( i_final + 1 , m_size ) ) ? i_start <= 0 ? m_right[i_final] : m_M.Product( m_M.Inverse( m_right[i_start] ) , m_right[i_final] ) : m_M.One(); }
template <typename U , typename GROUP> inline U AbstractCumulativeProduct<U,GROUP>::LeftIntervalProduct( const int& i_start , int i_final ) { return i_start < ( i_final = min( i_final + 1 , m_size ) ) ? i_start <= 0 ? m_left[i_final] : m_M.Product( m_left[i_final] , m_M.Inverse( m_left[i_start] ) ) : m_M.One(); }
template <typename U> inline U CumulativeSum<U>::IntervalSum( const int& i_start , int i_final ) { return this->RightIntervalProduct( i_start , move( i_final ) ); }

template <typename U , typename GROUP> ll AbstractCumulativeProduct<U,GROUP>::CountRightIntervalProductInverseImage( const U& u )
{

  Map<U,ll> f{};
  f[u]++;
  ll answer = 0;

  for( int i = 1 ; i <= m_size ; i++ ){

    const U& m_right_i = m_right[i];
    f.count( m_right_i ) == 1 ? answer += f[m_right_i] : answer;
    f[m_M.Product( m_right_i , u )]++;

  }

  return answer;

}

template <typename U , typename GROUP> ll AbstractCumulativeProduct<U,GROUP>::CountLeftIntervalProductInverseImage( const U& u )
{

  Map<U,ll> f{};
  f[u]++;
  ll answer = 0;

  for( int i = 1 ; i <= m_size ; i++ ){

    const U& m_left_i = m_left[i];
    f.count( m_left_i ) == 1 ? answer += f[m_left_i] : answer;
    f[m_M.Product( u , m_left_i )]++;

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
  int r = m_size;
  
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
  int r = m_size;
  
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
  int r = m_size;
  
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
  int r = m_size;
  
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
