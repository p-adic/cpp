// c:/Users/user/Documents/Programming/Utility/VLTree/UnionFindForest/Entry/a.hpp

#pragma once
#include "../../SubTree/a.hpp"
#include "../../../LinkedVector/a.hpp"

template <typename T> class UnionFindForest;
template <typename T> class EntryOfLinkedVector;

template <typename T>
class EntryOfUnionFindForest
{

  friend UnionFindForest<T>;
  friend EntryOfLinkedVector<EntryOfUnionFindForest<T> >;
  
private:
  VLSubTree<T> m_node;
  uint m_pred_node;
  uint m_root;
  uint m_depth;

private:
  inline EntryOfUnionFindForest();
  inline EntryOfUnionFindForest( const T& t , const uint& num );
  inline EntryOfUnionFindForest( EntryOfUnionFindForest&& e );

};
