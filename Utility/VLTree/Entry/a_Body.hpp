// c:/Users/user/Documents/Programming/Utility/VLTree/Entry/a_Body.hpp

#pragma once
#include "a.hpp"

template <typename T> inline EntryOfVLTree<T>::EntryOfVLTree() : m_t() , m_left_branch( this ) , m_right_branch( this ) , m_leftmost_node( this ) , m_rightmost_node( this ) {}
template <typename T> template <typename Arg> inline EntryOfVLTree<T>::EntryOfVLTree( const Arg& t ) : EntryOfVLTree( t , this , this ) {}
template <typename T> template <typename Arg> inline EntryOfVLTree<T>::EntryOfVLTree( const Arg& t , EntryOfVLTree<T>* const& left_branch , EntryOfVLTree<T>* const& right_branch ) : m_t( t ) , m_left_branch( left_branch ) , m_right_branch( right_branch ) , m_leftmost_node( this ) , m_rightmost_node( this ) {}

template <typename T>
EntryOfVLTree<T>::EntryOfVLTree( const EntryOfVLTree<T>& e ) :
  EntryOfVLTree( e.m_t )
{

  if( e.m_left_branch != &e ){

    m_left_branch = e.m_left_branch;

  }
  
  if( e.m_right_branch != &e ){

    m_right_branch = e.m_right_branch;

  }
  
  if( e.m_leftmost_node != &e ){

    m_leftmost_node = e.m_leftmost_node;
    m_rightmost_node = e.m_rightmost_node;

  }

}

template <typename T> EntryOfVLTree<T>& EntryOfVLTree<T>::operator=( const EntryOfVLTree<T>& e )
{

  m_t = e.m_t;

  if( e.m_left_branch == &e ){

    m_left_branch = this;

  } else {

    m_left_branch = e.m_left_branch;

  }
  
  if( e.m_right_branch == &e ){

    m_right_branch = this;

  } else {

    m_right_branch = e.m_right_branch;

  }
  
  if( e.m_leftmost_node == &e ){

    m_leftmost_node = this;
    m_rightmost_node = this;

  } else {

    m_leftmost_node = e.m_leftmost_node;
    m_rightmost_node = e.m_rightmost_node;

  }

  return *this;

}
