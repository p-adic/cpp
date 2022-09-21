// c:/Users/user/Documents/Programming/Utility/VLTree/UnionFindForest/a_Body.hpp

#pragma once
#include "a.hpp"

#include "Entry/a_Body.hpp"
#include "../../LinkedVector/a_Body.hpp"

template <typename T> inline UnionFindForest<T>::UnionFindForest( const uint& max_size ) : LinkedVector<EntryOfUnionFindForest<T> >( max_size ) {}

template <typename T> inline const VLSubTree<T>& UnionFindForest<T>::GetSubTree( const uint& num ) const { return LinkedVector<EntryOfUnionFindForest<T> >::operator[]( num ).m_node; }
template <typename T> inline const uint& UnionFindForest<T>::GetPredecessorNode( const uint& num ) const { return LinkedVector<EntryOfUnionFindForest<T> >::operator[]( num ).m_pred_node; }

template <typename T>
const uint& UnionFindForest<T>::GetRootOfNode( const uint& num )
{

  uint& root = LinkedVector<EntryOfUnionFindForest<T> >::operator[]( num ).m_root;

  if( root != LinkedVector<EntryOfUnionFindForest<T> >::operator[]( root ).m_root ){

    root = GetRootOfNode( root );
    
  }

  return root;

}

template <typename T>
uint UnionFindForest<T>::GetRoot( const uint& num ) const
{

  auto itr = LinkedVector<EntryOfUnionFindForest<T> >::begin();

  for( uint i = 0 ; i < num ; i++ ){

    itr++;

  }

  return itr.GetIndex();
  
}

template <typename T> inline const uint& UnionFindForest<T>::GetSizeOfNode() const noexcept { return LinkedVector<EntryOfUnionFindForest<T> >::GetSizeOfVector(); }
template <typename T> inline const uint& UnionFindForest<T>::GetSizeOfRoot() const noexcept { return LinkedVector<EntryOfUnionFindForest<T> >::GetSizeOfLink(); }

template <typename T> inline void UnionFindForest<T>::push_RightMost() {}

template <typename T>
void UnionFindForest<T>::push_RightMost( const T& t )
{

  EntryOfLinkedVector<EntryOfUnionFindForest<T> >& e = LinkedVector<EntryOfUnionFindForest<T> >::push_back_Body_0();
  e.m_t.m_node.SetRoot( t );
  e.m_t.m_pred_node = e.m_t.m_root = LinkedVector<EntryOfUnionFindForest<T> >::m_size_of_vector;
  LinkedVector<EntryOfUnionFindForest<T> >::push_back_Body_1( e );
  return;

}

template <typename T> template <typename... ARGS> inline void UnionFindForest<T>::push_RightMost( const T& t , const ARGS&... args ) { push_RightMost( t ); push_RightMost( args... ); }


template <typename T>
void UnionFindForest<T>::Graft( const uint& num0 , const uint& num1 )
{

  const uint& e0_root_index = LinkedVector<EntryOfUnionFindForest<T> >::operator[]( num0 ).m_root;
  const uint& e1_root_index = LinkedVector<EntryOfUnionFindForest<T> >::operator[]( num1 ).m_root;

  if( e0_root_index == e1_root_index ){

    return;
    
  }

  EntryOfUnionFindForest<T>& e0_root = LinkedVector<EntryOfUnionFindForest<T> >::operator[]( e0_root_index );
  EntryOfUnionFindForest<T>& e1_root = LinkedVector<EntryOfUnionFindForest<T> >::operator[]( e1_root_index );
  const uint i0 = ( e0_root.m_depth < e1_root.m_depth ? 0 : 1 );
  const uint i1 = 1 - i0;
  EntryOfUnionFindForest<T>* const p_e_root[2] = { &e0_root , &e1_root };
  EntryOfUnionFindForest<T>& root_0 = *( p_e_root[i0] );
  EntryOfUnionFindForest<T>& root_1 = *( p_e_root[i1] );

  if( root_0.m_depth == root_1.m_depth ){

    root_1.m_depth++;

  }

  root_1.m_node.Graft( root_0.m_node );
  LinkedVector<EntryOfUnionFindForest<T> >::DeLink( root_0.m_root );
  root_0.m_root = root_0.m_pred_node = root_1.m_root;
  return;

}
