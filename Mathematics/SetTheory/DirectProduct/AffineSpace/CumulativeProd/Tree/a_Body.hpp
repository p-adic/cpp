// c:/Users/user/Documents/Programming/Mathematics/SetTheory/DirectProduct/AffineSpace/CumulativeProd/Tree/a_Body.hpp

#pragma once
#include "a.hpp"

#include "../a_Body.hpp"
#include "../../../../../Geometry/Graph/DepthFirstSearch/Tree/a_Body.hpp"

template <typename TREE , typename GROUP> template <typename V> inline CumulativeProdOnTree<TREE, GROUP>::CumulativeProdOnTree( TREE T , const vector<V>& a , const int& digit , GROUP M ) : PathProdImplementation<inner_t<GROUP>,GROUP>( a.size() , move( M ) ) , m_dfst( move( T ) , 0 , digit )
{

  assert( this->m_size == m_dfst.size() );

  if( !a.empty() ){

    this->m_right[0] = this->m_left[0] = a[0];

    for( int n = 1 ; n < this->m_size ; n++ ){

      const int& i = m_dfst.NodeNumber( n );
      const int& j = m_dfst.Parent( i );
      this->m_right[i] = this->m_M.Product( this->m_right[j] , a[i] );
      this->m_left[i] = this->m_M.Product( a[i] , this->m_left[j] );

    }

  }

}

template <typename TREE , typename GROUP> inline int CumulativeProdOnTree<TREE, GROUP>::Parent( const int& i ) { return m_dfst.Parent( i ); }
template <typename TREE , typename GROUP> inline int CumulativeProdOnTree<TREE, GROUP>::LCA( const int& i , const int& j ) { return m_dfst.LCA( i , j ); }
