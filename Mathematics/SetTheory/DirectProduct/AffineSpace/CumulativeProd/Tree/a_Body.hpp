// c:/Users/user/Documents/Programming/Mathematics/SetTheory/DirectProduct/AffineSpace/CumulativeProd/Tree/a_Body.hpp

#pragma once
#include "a.hpp"

#include "../a_Body.hpp"
#include "../../../../../Geometry/Graph/DepthFirstSearch/Tree/a_Body.hpp"


template <typename T , T m_T(const T&,const T&) , T i_T(const T&) , list<int> E(const int&) , int size_max , int digit> template <typename U , SFINAE_FOR_CUMULATIVE_PROD()> inline CumulativeProdOnTree<T,m_T,i_T,E,size_max,digit>::CumulativeProdOnTree( const vector<U>& a ) : CumulativeProd_Body<T,m_T,i_T>( a.size() ) , m_dfst( CumulativeProd_Body<T,m_T,i_T>::m_size , 0 )
{

  using base = CumulativeProd_Body<T,m_T,i_T>;
  base::m_a[0] = base::m_a_reverse[0] = a[0];

  for( int n = 1 ; n < V ; n++ ){

    const int& i = m_dfst.NodeNumber( n );
    const int& j = m_dfst.Parent( i );
    base::m_a[i] = m_T( base::m_a[j] , a[i] );
    base::m_a_reverse[i] = m_T( a[i] , base::m_a_reverse[j] );

  }

}

template <typename T , T m_T(const T&,const T&) , T i_T(const T&) , list<int> E(const int&) , int size_max , int digit> inline int CumulativeProdOnTree<T,m_T,i_T,E,size_max,digit>::Parent( const int& i ) { return m_dfst.Parent( i ); }

template <typename T , T m_T(const T&,const T&) , T i_T(const T&) , list<int> E(const int&) , int size_max , int digit> inline int CumulativeProdOnTree<T,m_T,i_T,E,size_max,digit>::LCA( const int& i , const int& j ) { return m_dfst.LCA( i , j ); }


