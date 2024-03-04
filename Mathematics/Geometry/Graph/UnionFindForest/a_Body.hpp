// c:/Users/user/Documents/Programming/Mathematics/Geometry/Graph/UnionFindForest/a_Body.hpp

#pragma once
#include "a.hpp"

#include "../../../Algebra/Monoid/Group/a_Body.hpp"

template <typename U , typename GROUP> inline AbstractUnionFindForest<U,GROUP>::AbstractUnionFindForest( const int& size , GROUP M ) : m_M( move( M ) ) , m_node_size( size ) , m_root_size( m_node_size ) , m_pred( m_node_size ) , m_height( m_node_size , 1 ) , m_w( m_node_size , m_M.Zero() ) { for( int i = 0 ; i < m_node_size ; i++ ){ m_pred[i] = i; } }
template <typename U> inline UnionFindForest<U>::UnionFindForest( const int& size ) : AbstractUnionFindForest<U,AdditiveGroup<U>>( size , AdditiveGroup<U>() ) {}

template <typename U , typename GROUP>
const int& AbstractUnionFindForest<U,GROUP>::RootOfNode( const int& num )
{

  int& pred1 = m_pred[num];

  while( true ){
    
    int& pred2 = m_pred[pred1];

    if( pred1 == pred2 ){

      break;

    }

    m_w[num] = m_M.Sum( m_w[num] , m_w[pred1] = m_M.Sum( m_w[pred1] , m_w[pred2] ) );
    pred1 = pred2 = m_pred[pred2];

  }

  return pred1;

}

template <typename U , typename GROUP> template <template <typename...> typename V>
void AbstractUnionFindForest<U,GROUP>::SetRoot( V<int>& a ) const
{

  a.clear();

  for( int i = 0 ; i < m_node_size ; i++ ){

    if( i == m_pred[i] ){
      
      a.push_back( i );

    }

  }

  return;

}

template <typename U , typename GROUP>
U AbstractUnionFindForest<U,GROUP>::Potential( const int& num0 , const int& num1 )
{

  assert( num0 < m_node_size && num1 < m_node_size );
  const int& root0 = RootOfNode( num0 );
  const int& root1 = RootOfNode( num1 );
  assert( root0 == root1 );
  return m_M.Sum( m_w[num0] , m_M.Inverse( m_w[num1] ) );

}

template <typename U , typename GROUP> inline const int& AbstractUnionFindForest<U,GROUP>::size( const bool& node ) const noexcept { return node ? m_node_size : m_root_size; }

template <typename U , typename GROUP>
bool AbstractUnionFindForest<U,GROUP>::Graft( const int& num0 , const int& num1 , const U& w )
{

  assert( num0 < m_node_size && num1 < m_node_size );
  const int& root0 = RootOfNode( num0 );
  const int& root1 = RootOfNode( num1 );

  if( root0 == root1 ){

    return Potential( num0 , num1 ) == w;
    
  }

  int& height0 = m_height[root0];
  const int& height1 = m_height[root1];
  const int* p_removed_root;
  const int* p_removed_node;
  const int* p_kept_root;

  if( height0 < height1 ){

    p_removed_root = &root0;
    p_removed_node = &num0;
    p_kept_root = &root1;
    m_w[*p_removed_root] = m_M.Sum( m_w[*p_removed_root] , m_M.Sum( m_M.Sum( m_w[num1] , w ) , m_M.Inverse( m_w[num0] ) ) );

  } else {

    if( height0 == height1 ){

      height0++;

    }

    p_removed_root = &root1;
    p_removed_node = &num1;
    p_kept_root = &root0;
    m_w[*p_removed_root] = m_M.Sum( m_w[*p_removed_root] , m_M.Sum( m_M.Inverse( m_M.Sum( m_w[num1] , w ) ) , m_w[num0] ) );

  }

  if( *p_removed_node != *p_removed_root ){

    m_w[*p_removed_node] = m_M.Sum( m_w[*p_removed_node] , m_w[*p_removed_root] );

  }
  
  m_pred[*p_removed_node] = m_pred[*p_removed_root] = *p_kept_root;
  m_root_size--;
  return true;

}
