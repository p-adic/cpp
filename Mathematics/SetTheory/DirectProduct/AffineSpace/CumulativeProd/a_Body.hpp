// c:/Users/user/Documents/Programming/Mathematics/SetTheory/DirectProduct/AffineSpace/CumulativeProd/a_Body.hpp

#pragma once
#include "a.hpp"

#include "../../../../Function/Map/a_Body.hpp"

template <typename U , typename GROUP> inline PathProdImplementation<U,GROUP>::PathProdImplementation( const int& size , GROUP M ) : m_size( size ) , m_M( move( M ) ) , m_right( m_size , m_M.One() ) , m_left( m_right ) {}
template <typename U , typename GROUP> inline CumulativeProd<U,GROUP>::CumulativeProd( const int& size , GROUP M ) : PathProdImplementation<U,GROUP>( size , move( M ) ) {}

template <typename U , typename GROUP> template <typename V> inline CumulativeProd<U,GROUP>::CumulativeProd( const vector<V>& a , GROUP M ) : CumulativeProd<U,GROUP>( a.size() , move( M ) )
{

  static_assert( is_convertible_v<V,U> );

  if( !a.empty() ){

    this->m_right[0] = this->m_left[0] = a[0];

    for( int i = 1 ; i < this->m_size ; i++ ){

      this->m_right[i] = this->m_M.Product( this->m_right[i-1] , a[i] );
      this->m_left[i] = this->m_M.Product( a[i] , this->m_left[i-1] );

    }

  }

}

template <typename U , typename GROUP> template <typename V> inline void CumulativeProd<U,GROUP>::Set( const vector<V>& a ) { *this = CumulativeProd( a , move( this->m_M ) ); }


template <typename U , typename GROUP> inline void CumulativeProd<U,GROUP>::LeftMultiply( const int& i , const U& t )
{

  const U m_right_i_prev_inv = i == 0 ? One() : this->m_M.Inverse( this->m_right[i-1] );
  const U m_right_i_prev = i == 0 ? t : this->m_M.Product( this->m_right[i-1] , t );

  for( int j = i ; j < this->m_size ; j++ ){

    this->m_right[j] = this->m_M.Product( m_right_i_prev , this->m_M.Product( m_right_i_prev_inv , this->m_right[j] ) );

  }

  const U m_left_i_inv = this->m_M.Inverse( this->m_left[i] );
  const U& m_left_i = this->m_left[i] = this->m_M.Product( t , this->m_left[i] );

  for( int j = i + 1 ; j < this->m_size ; j++ ){

    this->m_left[j] = this->m_M.Product( this->m_M.Product( this->m_left[j] , m_left_i_inv ) , m_left_i );

  }

}

template <typename U , typename GROUP> inline void CumulativeProd<U,GROUP>::RightMultiply( const int& i , const U& t )
{

  const U m_right_i_inv = this->m_M.Inverse( this->m_right[i] );
  const U& m_right_i = this->m_right[i] = this->m_M.Product( this->m_right[i] , t );

  for( int j = i + 1 ; j < this->m_size ; j++ ){

    this->m_right[j] = this->m_M.Product( m_right_i , this->m_M.Product( m_right_i_inv , this->m_right[j] ) );

  }

  const U m_left_i_prev_inv = i == this->m_size - 1 ? One() : this->m_M.Inverse( this->m_left[i-1] );
  const U m_left_i_prev = this->m_M.Product( t , this->m_left[i-1] );

  for( int j = i + 1 ; j < this->m_size ; j++ ){

    this->m_left[j] = this->m_M.Product( this->m_M.Product( this->m_left[j] , m_left_i_prev_inv ) , m_left_i_prev );

  }

}

template <typename U , typename GROUP> inline U PathProdImplementation<U,GROUP>::PathProd( const int& i , const int& j ) { assert( 0 <= i && i < m_size && 0 <= j && j < m_size ); const int k = this->LCA( i , j ); return m_M.Product( m_M.Product( m_left[i] , m_M.Inverse( m_left[k] ) ) , k == 0 ? m_right[j] : m_M.Product( m_M.Inverse( m_right[this->Parent( k ) ] ) , m_right[j] )); }

template <typename U , typename GROUP> inline U CumulativeProd<U,GROUP>::RightProd( const int& i , const int& j )
{

  assert( i - 1 <= j );
  return i <= j ? i == 0 ? this->m_right[j] : this->m_M.Product( this->m_M.Inverse( this->m_right[i-1] ) , this->m_right[j] ) : One();

}

template <typename U , typename GROUP> inline U CumulativeProd<U,GROUP>::LeftProd( const int& i , const int& j )
{

  assert( i - 1 <= j );
  return i <= j ? i == 0 ? this->m_left[j] : this->m_M.Product( this->m_left[j] , this->m_M.Inverse( this->m_left[i - 1] ) ) : One();

}

template <typename U , typename GROUP> ll CumulativeProd<U,GROUP>::CountRightProdInverseImage( const U& t )
{

  Map<U,ll> f{};
  f[t]++;
  ll answer = 0;

  for( int i = 0 ; i < this->m_size ; i++ ){

    const U& m_right_i = this->m_right[i];
    f.count( m_right_i ) == 1 ? answer += f[m_right_i] : answer;
    f[this->m_M.Product( m_right_i , t )]++;

  }

  return answer;

}

template <typename U , typename GROUP> ll CumulativeProd<U,GROUP>::CountLeftProdInverseImage( const U& t )
{

  Map<U,ll> f{};
  f[t]++;
  ll answer = 0;

  for( int i = 0 ; i < this->m_size ; i++ ){

    const U& m_left_i = this->m_left[i];
    f.count( m_left_i ) == 1 ? answer += f[m_left_i] : answer;
    f[this->m_M.Product( t , m_left_i )]++;

  }

  return answer;

}

template <typename U , typename GROUP> inline int CumulativeProd<U,GROUP>::Parent( const int& i ) { return i - 1; }
template <typename U , typename GROUP> inline int CumulativeProd<U,GROUP>::LCA( const int& i , const int& j ) { return min( i , j ); }
template <typename U , typename GROUP> inline const U& CumulativeProd<U,GROUP>::One() const { return this->m_M.One(); }
