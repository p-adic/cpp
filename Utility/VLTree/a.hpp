// c:/Users/user/Documents/Programming/Utility/VLTree/a.hpp

#pragma once
#include "SubTree/Const/a.hpp"

template <typename T>
class VLTree :
  public VLSubTree<T>
{

public:
  template <typename... Args> inline VLTree( const Args&... );
  inline ~VLTree();

  template <typename Arg> VLTree<T>& operator=( const Arg& );

};
