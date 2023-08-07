// c:/Users/user/Documents/Programming/Mathematics/SetTheory/DirectProduct/Tree/CumulativeProd/a_Body.hpp

#pragma once
#include "a.hpp"

#include "../../../../Geometry/Graph/DepthFirstSearch/Tree/a_Body.hpp"

template <typename T , T m_T(const T&,const T&), T i_T(const T&) , int size_max> inline CumulativeProd_Body<T,m_T,i_T,size_max>::CumulativeProd_Body( const int& size ) : m_size( size ) , m_a() , m_a_reverse() { assert( size <= size_max ); }

template <typename T , T m_T(const T&,const T&), T i_T(const T&) , int size_max> inline CumulativeProd<T,m_T,i_T,size_max>::CumulativeProd( const T ( &a )[size_max] , const int& size ) : CumulativeProd_Body<T,m_T,i_T,size_max>( size )
{

  using base = CumulativeProd_Body<T,m_T,i_T,size_max>;
  T temp , temp_reverse;
  base::m_a[0] = base::m_a_reverse[0] = temp = temp_reverse = a[0];

  for( int i = 1 ; i < size ; i++ ){

    base::m_a[i] = temp = m_T( temp , a[i] );
    base::m_a_reverse[i] = temp_reverse = m_T( a[i] , temp_reverse );

  }

}

template <typename T , T m_T(const T&,const T&), T i_T(const T&) , list<int> E(const int&) , int size_max , int digit> inline CumulativeProdOnTree<T,m_T,i_T,E,size_max,digit>::CumulativeProdOnTree( const T ( &a )[size_max] , const int& V ) : CumulativeProd_Body<T,m_T,i_T,size_max>( V ) , m_dfst( V , 0 )
{

  using base = CumulativeProd_Body<T,m_T,i_T,size_max>;
  base::m_a[0] = base::m_a_reverse[0] = a[0];

  for( int n = 1 ; n < V ; n++ ){

    const int& i = m_dfst.NodeNumber( n );
    const int& j = m_dfst.Parent( i );
    base::m_a[i] = m_T( base::m_a[j] , a[i] );
    base::m_a_reverse[i] = m_T( a[i] , base::m_a_reverse[j] );

  }

}


template <typename T , T m_T(const T&,const T&), T i_T(const T&) , int size_max> inline  T CumulativeProd_Body<T,m_T,i_T,size_max>::PathProd( const int& i , const int& j ) { const int k = LCA( i , j ); return m_T( m_T( m_a_reverse[i] , i_T( m_a_reverse[k] ) ) , k == 0 ? m_a[j] : m_T( i_T( m_a[Parent( k ) ] ) , m_a[j] )); }


template <typename T , T m_T(const T&,const T&), T i_T(const T&) , int size_max> inline int CumulativeProd<T,m_T,i_T,size_max>::Parent( const int& i ) { return i - 1; }
template <typename T , T m_T(const T&,const T&), T i_T(const T&) , list<int> E(const int&) , int size_max , int digit> inline int CumulativeProdOnTree<T,m_T,i_T,E,size_max,digit>::Parent( const int& i ) { return m_dfst.Parent( i ); }


template <typename T , T m_T(const T&,const T&), T i_T(const T&) , int size_max> inline int CumulativeProd<T,m_T,i_T,size_max>::LCA( const int& i , const int& j ) { return min( i , j ); }
template <typename T , T m_T(const T&,const T&), T i_T(const T&) , list<int> E(const int&) , int size_max , int digit> inline int CumulativeProdOnTree<T,m_T,i_T,E,size_max,digit>::LCA( const int& i , const int& j ) { return m_dfst.LCA( i , j ); }
