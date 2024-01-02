// c:/Users/user/Documents/Programming/Utility/VLTree/UnionFindForest/a_Body.hpp

#pragma once
#include "a.hpp"

template <typename T> inline UnionFindForest<T>::UnionFindForest( const uint& size ) : m_node_size( size ) , m_root_size( m_node_size ) , m_pred( m_node_size ) , m_height( m_node_size , 1 ) , m_w( m_node_size ) { for( uint i = 0 ; i < m_node_size ; i++ ){ m_pred[i] = i; } }

template <typename T>
const uint& UnionFindForest<T>::RootOfNode( const uint& num )
{

  uint& pred1 = m_pred[num];

  while( true ){
    
    uint& pred2 = m_pred[pred1];

    if( pred1 == pred2 ){

      break;

    }

    m_w[num] += m_w[pred1] += m_w[pred2];
    pred1 = pred2 = m_pred[pred2];

  }

  return pred1;

}

template <typename T> template <template <typename...> typename V>
void UnionFindForest<T>::SetRoot( V<uint>& a ) const
{

  a.clear();

  for( uint i = 0 ; i < m_node_size ; i++ ){

    if( i == m_pred[i] ){
      
      a.push_back( i );

    }

  }

  return;

}

template <typename T>
T UnionFindForest<T>::Weight( const uint& num0 , const uint& num1 )
{

  assert( num0 < m_node_size && num1 < m_node_size );
  const uint& root0 = RootOfNode( num0 );
  const uint& root1 = RootOfNode( num1 );
  assert( root0 == root1 );
  return m_w[num1] - m_w[num0];

}

template <typename T> inline const uint& UnionFindForest<T>::SizeOfNode() const noexcept { return m_node_size; }
template <typename T> inline const uint& UnionFindForest<T>::SizeOfRoot() const noexcept { return m_root_size; }

template <typename T>
bool UnionFindForest<T>::Graft( const uint& num0 , const uint& num1 , const T& w )
{

  assert( num0 < m_node_size && num1 < m_node_size );
  const uint& root0 = RootOfNode( num0 );
  const uint& root1 = RootOfNode( num1 );

  if( root0 == root1 ){

    return Weight( num0 , num1 ) == w;
    
  }

  uint& height0 = m_height[root0];
  const uint& height1 = m_height[root1];
  const uint* p_removed_root;
  const uint* p_removed_node;
  const uint* p_kept_root;

  if( height0 < height1 ){

    p_removed_root = &root0;
    p_removed_node = &num0;
    p_kept_root = &root1;
    m_w[*p_removed_root] -= w - m_w[num1] + m_w[num0];

  } else {

    if( height0 == height1 ){

      height0++;

    }

    p_removed_root = &root1;
    p_removed_node = &num1;
    p_kept_root = &root0;
    m_w[*p_removed_root] += w - m_w[num1] + m_w[num0];

  }

  if( *p_removed_node != *p_removed_root ){

    m_w[*p_removed_node] += m_w[*p_removed_root];

  }
  
  m_pred[*p_removed_node] = m_pred[*p_removed_root] = *p_kept_root;
  m_root_size--;
  return true;

}
