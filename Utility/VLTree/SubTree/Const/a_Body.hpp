// c:/Users/user/Documents/Programming/Utility/VLTree/SubTree/Const/a_Body.hpp

#pragma once
#include "a.hpp"

#include "../a_Body.hpp"

template <typename T> inline VLConstSubTree<T>::VLConstSubTree( const ConstIteratorOfVLTree<T>& itr ) : VLSubTree<T>( itr ) {}

template <typename T> inline VLConstSubTree<T>::VLConstSubTree( const EntryOfVLTree<T>& e ) : VLSubTree<T>( ConstIteratorOfVLTree<T>( &e ) ) {}

template <typename T> inline VLConstSubTree<T>::VLConstSubTree( const VLSubTree<T>& t ) : VLSubTree<T>( ConstIteratorOfVLTree<T>( &( t.m_root ) ) ) {}
