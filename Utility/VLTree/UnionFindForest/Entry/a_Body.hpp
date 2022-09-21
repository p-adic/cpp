// c:/Users/user/Documents/Programming/Utility/VLTree/UnionFindForest/Entry/a_Body.hpp

#pragma once
#include "a.hpp"

#include "../../SubTree/a_Body.hpp"

template <typename T> inline EntryOfUnionFindForest<T>::EntryOfUnionFindForest() : m_node() , m_pred_node( 0 ) , m_root( 0 ) , m_depth( 0 ) {}
template <typename T> inline EntryOfUnionFindForest<T>::EntryOfUnionFindForest( const T& t , const uint& num ) : m_node() , m_pred_node( num ) , m_root( num ) , m_depth( 0 ) { SetRoot( t ); }
