// c:/Users/user/Documents/Programming/Mathematics/SetTheory/DirectProduct/AffineSpace/CumulativeProd/a_Body.hpp

#pragma once
#include "a.hpp"

template <typename T , T m_T(const T&,const T&) , T i_T(const T&) , int size_max> inline CumulativeProd_Body<T,m_T,i_T,size_max>::CumulativeProd_Body( const int& size ) : m_size( size ) , m_a() , m_a_reverse() { assert( size <= size_max ); }

template <typename T , T m_T(const T&,const T&) , const T& e_T() , T i_T(const T&) , int size_max> inline CumulativeProd<T,m_T,e_T,i_T,size_max>::CumulativeProd( const T ( &a )[size_max] , const int& size ) : CumulativeProd_Body<T,m_T,i_T,size_max>( size )
{

  using base = CumulativeProd_Body<T,m_T,i_T,size_max>;
  T temp , temp_reverse;
  base::m_a[0] = base::m_a_reverse[0] = temp = temp_reverse = a[0];

  for( int i = 1 ; i < size ; i++ ){

    base::m_a[i] = temp = m_T( temp , a[i] );
    base::m_a_reverse[i] = temp_reverse = m_T( a[i] , temp_reverse );

  }

}

template <typename T , T m_T(const T&,const T&) , T i_T(const T&) , int size_max> inline  T CumulativeProd_Body<T,m_T,i_T,size_max>::PathProd( const int& i , const int& j ) { assert( 0 <= i && i < m_size && 0 <= j && j < m_size ); const int k = LCA( i , j ); return m_T( m_T( m_a_reverse[i] , i_T( m_a_reverse[k] ) ) , k == 0 ? m_a[j] : m_T( i_T( m_a[Parent( k ) ] ) , m_a[j] )); }

template <typename T , T m_T(const T&,const T&) , const T& e_T() , T i_T(const T&) , int size_max> inline T CumulativeProd<T,m_T,e_T,i_T,size_max>::RightProd( const int& i , const int& j )
{
  
  assert( i - 1 <= j );
  using base = CumulativeProd_Body<T,m_T,i_T,size_max>;
  return i <= j ? i == 0 ? base::m_a[j] : m_T( i_T( base::m_a[i-1] ) , base::m_a[j] ) : e_T();

}

template <typename T , T m_T(const T&,const T&) , const T& e_T() , T i_T(const T&) , int size_max> inline T CumulativeProd<T,m_T,e_T,i_T,size_max>::LeftProd( const int& i , const int& j )
{
  
  assert( i - 1 <= j );
  using base = CumulativeProd_Body<T,m_T,i_T,size_max>;
  return i <= j ? i == 0 ? base::m_a_reverse[j] : m_T( base::m_a_reverse[j] , i_T( base::m_a_reverse[i - 1] ) ) : e_T();

}

template <typename T , T m_T(const T&,const T&) , T i_T(const T&) , int size_max> inline int CumulativeProd<T,m_T,e_T,i_T,size_max>::Parent( const int& i ) { return i - 1; }

template <typename T , T m_T(const T&,const T&) , const T& e_T() , T i_T(const T&) , int size_max> inline int CumulativeProd<T,m_T,e_T,i_T,size_max>::LCA( const int& i , const int& j ) { return min( i , j ); }
