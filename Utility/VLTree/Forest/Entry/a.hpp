// c:/Users/user/Documents/Programming/Utility/VLTree/Forest/Entry/a.hpp

#pragma once
#include "../../SubTree/a.hpp"

template <typename T> class Forest;

template <typename T>
class EntryOfForest
{

  friend Forest<T>;
  
private:
  VLSubTree<T> m_node;
  uint m_pred_node;
  uint m_root;
  uint m_prev_root;
  uint m_next_root;
  uint m_depth;

private:
  inline EntryOfForest();
  inline EntryOfForest( const T& t , const uint& prev_root , const uint& num );
};
