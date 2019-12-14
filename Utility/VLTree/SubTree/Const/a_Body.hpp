// c:/Users/user/Documents/Programming/Utility/VLTree/SubTree/Const/a_Body.hpp

#pragma once
#include "a.hpp"

#include "../a_Body.hpp"

template <typename T> inline VLConstSubTree<T>::VLConstSubTree( const ConstIteratorOfVLTree<T>& itr ) : VLSubTree<T>( itr ) {}
