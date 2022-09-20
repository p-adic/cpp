// c:/Users/user/Documents/Programming/Utility/VLTree/a.hpp

#pragma once
#include "SubTree/a.hpp"

template <typename T>
class VLTree :
  public VLSubTree<T>
{

public:
  template <typename... Args> inline VLTree( const Args&... );
  VLTree( EntryOfVLTree<T>& ) = delete;
  virtual ~VLTree();

  template <typename Arg> VLTree<T>& operator=( const Arg& );

};
