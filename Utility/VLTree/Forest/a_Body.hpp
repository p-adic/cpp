// c:/Users/user/Documents/Programming/Utility/VLTree/Forest/a_Body.hpp

#pragma once
#include "a.hpp"

#include "Entry/a_Body.hpp"

template <typename T> inline Forest<T>::Forest() : m_e() , m_leftmost_root( 0 ) , m_rightmost_root( 0 ) , m_size_of_node( 0 ) , m_size_of_root( 0 ) {}

template <typename T> inline const VLSubTree<T>& Forest<T>::GetSubTree( const uint& num ) const { return m_e[num].m_node; }
template <typename T> inline const uint& Forest<T>::GetRootOfNode( const uint& num ) const { return m_e[num].m_root; }

template <typename T>
uint Forest<T>::GetRoot( const uint& num ) const
{

  uint root_num = m_leftmost_root;

  for( uint i = 0 ; i < num ; i++ ){

    root_num = m_e[root_num].m_next_root;

  }

  return root_num;
  
}

template <typename T> inline const uint& Forest<T>::GetSizeOfNode() const noexcept { return m_size_of_node; }
template <typename T> inline const uint& Forest<T>::GetSizeOfRoot() const noexcept { return m_size_of_root; }


template <typename T> inline void Forest<T>::push_RightMost() {}

template <typename T>
void Forest<T>::push_RightMost( const T& t )
{

  m_e.push_back( EntryOfForest<T>( t , m_rightmost_root , m_size_of_node ) );
  EntryOfForest<T>& a = m_e.back();
  a.m_e.m_left_branch = a.m_e.m_right_branch = a.m_e.m_leftmost_node = a.m_e.m_rightmost_node = a.m_p_root = &( a.m_e );

  if( m_size_of_node != 0 ){

    m_e[m_rightmost_root].m_next_root = m_size_of_node;
    
  }
  
  m_rightmost_root = m_size_of_node;
  m_size_of_node++;
  m_size_of_root++;
  return;
  
}

template <typename T> template <typename... ARGS> inline void Forest<T>::push_RightMost( const T& t , const ARGS&... args ) { push_RightMost( t ); push_RightMost( args... ); }


template <typename T>
void Forest<T>::Graft( const uint& num0 , const uint& num1 )
{

  EntryOfForest<T>& e0_root = m_e[num0]->m_root;
  EntryOfForest<T>& e1_root = m_e[num1]->m_root;

  if( e0_root == e1_root ){

    return;
    
  }

  const uint i0 = e0_root.m_depth < e1_root.m_depth ? 0 : 1;
  const uint i1 = 1 - i0;
  EntryOfForest<T>* const p_e_root = { &e0_root , &e1_root };
  EntryOfForest<T>& root_0 = p_e_root[i0];
  EntryOfForest<T>& root_1 = p_e_root[i1];

  if( root_0 == m_leftmost_root ){

    m_leftmost_root = m_e[root_0.m_next_root].m_prev_root = root_0.m_next_root;

  } else {

    if( root_0 == m_rightmost_root ){

      m_rightmost_root = m_e[root_0.m_prev_root].m_next_root = root_0.m_prev_root;

    } else {

      m_e[root_0.m_prev_root].m_next_root = root_0.m_next_root;
      m_e[root_0.m_next_root].m_prev_root = root_0.m_prev_root;

    }

  }

  root_0.m_root = root_0.m_pred_node = root_1.m_root;

  if( root_0.m_depth == root_1.m_depth ){

    root_1.m_depth++;

  }

  m_size_of_root--;
  return;

}
