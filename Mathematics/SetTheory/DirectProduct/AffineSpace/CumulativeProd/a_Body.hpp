// c:/Users/user/Documents/Programming/Mathematics/SetTheory/DirectProduct/AffineSpace/CumulativeProd/a_Body.hpp

#pragma once
#include "a.hpp"

#include "../../../../Function/Map/a_Body.hpp"

template <typename T , T m_T(const T&,const T&) , T i_T(const T&)> inline CumulativeProd_Body<T,m_T,i_T>::CumulativeProd_Body( const int& size ) : m_size( size ) , m_right( m_size ) , m_left( m_size ) {}

template <typename T , T m_T(const T&,const T&) , const T& e_T() , T i_T(const T&)> inline CumulativeProd<T,m_T,e_T,i_T>::CumulativeProd( const int& size ) : CumulativeProd_Body<T,m_T,i_T>( size )
{

  using base = CumulativeProd_Body<T,m_T,i_T>;
  const T& unit = e_T();
  
  if( base::m_size > 0 ? base::m_right[0] != unit : false ){
    
    for( int i = 0 ; i < size ; i++ ){

      base::m_right[i] = base::m_left[i] = unit;

    }

  }

}

template <typename T , T m_T(const T&,const T&) , const T& e_T() , T i_T(const T&)> template <typename U , SFINAE_FOR_CUMULATIVE_PROD()> inline CumulativeProd<T,m_T,e_T,i_T>::CumulativeProd( const vector<U>& a ) : CumulativeProd_Body<T,m_T,i_T>() { Set( a ); }

template <typename T , T m_T(const T&,const T&) , const T& e_T() , T i_T(const T&)> template <typename U , SFINAE_FOR_CUMULATIVE_PROD()> inline void CumulativeProd<T,m_T,e_T,i_T>::Set( const vector<U>& a )
{

  using base = CumulativeProd_Body<T,m_T,i_T>;
  T temp , temp_reverse;
  base::m_size = a.size();
  base::m_right.resize( base::m_size );
  base::m_left.resize( base::m_size );
  base::m_right[0] = base::m_left[0] = temp = temp_reverse = a[0];

  for( int i = 1 ; i < base::m_size ; i++ ){

    base::m_right[i] = temp = m_T( temp , a[i] );
    base::m_left[i] = temp_reverse = m_T( a[i] , temp_reverse );

  }

}

template <typename T , T m_T(const T&,const T&) , const T& e_T() , T i_T(const T&)> inline void CumulativeProd<T,m_T,e_T,i_T>::LeftMultiply( const int& i , const T& t )
{

  using base = CumulativeProd_Body<T,m_T,i_T>;
  const T m_right_i_prev_inv = i == 0 ? e_T() : i_T( base::m_right[i-1] );
  const T m_right_i_prev = i == 0 ? t : m_T( base::m_right[i-1] , t );

  for( int j = i ; j < base::m_size ; j++ ){

    base::m_right[j] = m_T( m_right_i_prev , m_T( m_right_i_prev_inv , base::m_right[j] ) );

  }

  const T m_left_i_inv = i_T( base::m_left[i] );
  const T& m_left_i = base::m_left[i] = m_T( t , base::m_left[i] );

  for( int j = i + 1 ; j < base::m_size ; j++ ){
  
    base::m_left[j] = m_T( m_T( base::m_left[j] , m_left_i_inv ) , m_left_i );

  }

}

template <typename T , T m_T(const T&,const T&) , const T& e_T() , T i_T(const T&)> inline void CumulativeProd<T,m_T,e_T,i_T>::RightMultiply( const int& i , const T& t )
{

  using base = CumulativeProd_Body<T,m_T,i_T>;
  const T m_right_i_inv = i_T( base::m_right[i] );
  const T& m_right_i = base::m_right[i] = m_T( base::m_right[i] , t );

  for( int j = i + 1 ; j < base::m_size ; j++ ){

    base::m_right[j] = m_T( m_right_i , m_T( m_right_i_inv , base::m_right[j] ) );

  }

  const T m_left_i_prev_inv = i == base::m_size - 1 ? e_T() : i_T( base::m_left[i-1] );
  const T m_left_i_prev = m_T( t , base::m_left[i-1] );

  for( int j = i + 1 ; j < base::m_size ; j++ ){
  
    base::m_left[j] = m_T( m_T( base::m_left[j] , m_left_i_prev_inv ) , m_left_i_prev );

  }

}

template <typename T , T m_T(const T&,const T&) , T i_T(const T&)> inline  T CumulativeProd_Body<T,m_T,i_T>::PathProd( const int& i , const int& j ) { assert( 0 <= i && i < m_size && 0 <= j && j < m_size ); const int k = LCA( i , j ); return m_T( m_T( m_left[i] , i_T( m_left[k] ) ) , k == 0 ? m_right[j] : m_T( i_T( m_right[Parent( k ) ] ) , m_right[j] )); }

template <typename T , T m_T(const T&,const T&) , const T& e_T() , T i_T(const T&)> inline T CumulativeProd<T,m_T,e_T,i_T>::RightProd( const int& i , const int& j )
{
  
  assert( i - 1 <= j );
  using base = CumulativeProd_Body<T,m_T,i_T>;
  return i <= j ? i == 0 ? base::m_right[j] : m_T( i_T( base::m_right[i-1] ) , base::m_right[j] ) : e_T();

}

template <typename T , T m_T(const T&,const T&) , const T& e_T() , T i_T(const T&)> inline T CumulativeProd<T,m_T,e_T,i_T>::LeftProd( const int& i , const int& j )
{
  
  assert( i - 1 <= j );
  using base = CumulativeProd_Body<T,m_T,i_T>;
  return i <= j ? i == 0 ? base::m_left[j] : m_T( base::m_left[j] , i_T( base::m_left[i - 1] ) ) : e_T();

}

template <typename T , T m_T(const T&,const T&) , const T& e_T() , T i_T(const T&)> ll CumulativeProd<T,m_T,e_T,i_T>::CountRightProdInverseImage( const T& t )
{

  using base = CumulativeProd_Body<T,m_T,i_T>;
  Map<T,ll> f{};
  f[t]++;
  ll answer = 0;

  for( int i = 0 ; i < base::m_size ; i++ ){

    const T& m_right_i = base::m_right[i];
    f.count( m_right_i ) == 1 ? answer += f[m_right_i] : answer;
    f[ m_T( m_right_i , t ) ]++;

  }

  return answer;

}

template <typename T , T m_T(const T&,const T&) , const T& e_T() , T i_T(const T&)> ll CumulativeProd<T,m_T,e_T,i_T>::CountLeftProdInverseImage( const T& t )
{

  using base = CumulativeProd_Body<T,m_T,i_T>;
  Map<T,ll> f{};
  f[t]++;
  ll answer = 0;

  for( int i = 0 ; i < base::m_size ; i++ ){

    const T& m_left_i = base::m_left[i];
    f.count( m_left_i ) == 1 ? answer += f[m_left_i] : answer;
    f[ m_T( t , m_left_i ) ]++;

  }

  return answer;

}

template <typename T , T m_T(const T&,const T&) , const T& e_T() , T i_T(const T&)> inline int CumulativeProd<T,m_T,e_T,i_T>::Parent( const int& i ) { return i - 1; }

template <typename T , T m_T(const T&,const T&) , const T& e_T() , T i_T(const T&)> inline int CumulativeProd<T,m_T,e_T,i_T>::LCA( const int& i , const int& j ) { return min( i , j ); }
