// c:/Users/user/Documents/Programming/Utility/VLTree/a_Body.hpp

#pragma once
#include "a.hpp"

#include "Entry/a_Body.hpp"
#include "Iterator/Sequential/a_Body.hpp"
#include "SubTree/a_Body.hpp"

template <typename T> template <typename... Args> inline VLTree<T>::VLTree( const Args&... t ) : VLSubTree<T>( t... ) {}

template <typename T> inline VLTree<T>::~VLTree(){ VLSubTree<T>::CutBranches(); }

template <typename T> template <typename Arg>
VLTree<T>& VLTree<T>::operator=( const Arg& t )
{

  VLSubTree<T>::operator=( t );
  return *this;

}
