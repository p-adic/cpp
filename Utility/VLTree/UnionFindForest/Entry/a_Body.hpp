// c:/Users/user/Documents/Programming/Utility/VLTree/UnionFindForest/Entry/a_Body.hpp

#pragma once
#include "a.hpp"

#include "../../SubTree/a_Body.hpp"

template <typename T> inline EntryOfUnionFindForest<T>::EntryOfUnionFindForest() : m_node() , m_pred_node( 0 ) , m_root( 0 ) , m_depth( 0 ) {}
template <typename T> inline EntryOfUnionFindForest<T>::EntryOfUnionFindForest( const T& t , const uint& num ) : m_node() , m_pred_node( num ) , m_root( num ) , m_depth( 0 ) { m_node.SetRoot( t ); }
template <typename T> inline EntryOfUnionFindForest<T>::EntryOfUnionFindForest( EntryOfUnionFindForest<T>&& e ) : m_node() , m_pred_node( move( e.m_pred_node ) ) , m_root( move( e.m_root ) ) , m_depth( move( e.m_depth ) ) { m_node.SetRoot( move( e.m_node.m_p_root->m_t ) ); }
