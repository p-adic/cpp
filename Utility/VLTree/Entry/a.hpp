// c:/Users/user/Documents/Programming/Utility/VLTree/Entry/a.hpp

#pragma once

template <typename T> class IteratorOfVLTree;
template <typename T> class ConstIteratorOfVLTree;
template <typename T> class VLSubTree;

template <typename T>
class EntryOfVLTree
{

  friend IteratorOfVLTree<T>;
  friend ConstIteratorOfVLTree<T>;
  friend VLSubTree<T>;

private:
  T m_t;
  EntryOfVLTree<T>* m_left_branch;
  EntryOfVLTree<T>* m_right_branch;
  EntryOfVLTree<T>* m_leftmost_node;
  EntryOfVLTree<T>* m_rightmost_node;
  
private:
  inline EntryOfVLTree();
  template <typename Arg> inline EntryOfVLTree( const Arg& );
  template <typename Arg> inline EntryOfVLTree( const Arg& , EntryOfVLTree<T>* const& , EntryOfVLTree<T>* const& );
  inline EntryOfVLTree( const EntryOfVLTree<T>& );
  EntryOfVLTree<T>& operator=( const EntryOfVLTree<T>& );

};
