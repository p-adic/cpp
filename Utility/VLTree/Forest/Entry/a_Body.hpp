// c:/Users/user/Documents/Programming/Utility/VLTree/Forest/Entry/a_Body.hpp

#pragma once
#include "a.hpp"

#include "../../SubTree/a_Body.hpp"

template <typename T> inline EntryOfForest<T>::EntryOfForest() : m_node() , m_pred_node( 0 ) , m_root( 0 ) , m_prev_root( 0 ) , m_next_root( 0 ) , m_depth( 0 ) {}
template <typename T> inline EntryOfForest<T>::EntryOfForest( const T& t , const uint& prev_root , const uint& num ) : m_node() , m_pred_node( num ) , m_root( num ) , m_prev_root( prev_root ) , m_next_root( num + 1 ) , m_depth( 0 ) { SetRoot( t ); }
