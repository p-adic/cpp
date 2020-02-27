// c:/Users/user/Documents/Programming/Utility/VLTree/a.hpp

#pragma once

// VLTtree<T>を使うためにこのファイルをincludeする。
// Iteratorを不完全型として使うことを避けるために以下もincludeしている。
#include "Entry/a.hpp"
#include "Iterator/a.hpp"
#include "SubTree/Const/a.hpp"

// SequentialIteratorを使う時は更にIterator/Sequential/a_Body.hppをincludeする必要がある。

template <typename T>
class VLTree :
  public VLSubTree<T>
{

public:
  template <typename... Args> inline VLTree( const Args&... );
  inline ~VLTree();

  template <typename Arg> VLTree<T>& operator=( const Arg& );

};
