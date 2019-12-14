// c:/Users/user/Documents/Programming/Utility/VLTree/SubTree/Const/a.hpp

#pragma once
#include "../a.hpp"

template <typename T>
class VLConstSubTree :
  public VLSubTree<T>
{

public:
  inline VLConstSubTree( const ConstIteratorOfVLTree<T>& );

  // VLSubTree<T>::operator=は部分木としての埋め込み先を変更してしまうためdeleteする必要がある。
  template <typename Arg> VLConstSubTree<T>& operator=( const Arg& ) = delete;

  inline void CutBranches() = delete;
  void CutBranches( const T& ) = delete;
  void CutLeaf() = delete;

  inline VLSubTree<T> LeftMostSubTree() = delete;
  inline VLSubTree<T> RightMostSubTree() = delete;

  using VLSubTree<T>::push_RightMost;
  template <typename Arg1 , typename... Arg2> void push_RightMost( const Arg1& , const Arg2&... ) = delete;

  template <typename... Args> void push_RightMost( const VLSubTree<T>& , const Args&... ) = delete;
  template <typename... Args> void push_RightMost( const VLTree<T>& , const Args&... ) = delete;

  template <typename Arg> void push_LeftMost( const Arg& ) = delete;
  
  void pop_RightMost() = delete;
  void pop_LeftMost() = delete;
  void pop_Root() = delete;

  template <typename... Args> inline void push_back( const Args&... ) = delete;
  template <typename Arg> inline void push_front( const Arg& ) = delete;
  inline void pop_back() = delete;
  inline void pop_front() = delete;

  using VLSubTree<T>::LeftMostNode;
  inline typename VLSubTree<T>::iterator LeftMostNode() noexcept = delete;

  using VLSubTree<T>::RightMostNode;
  inline typename VLSubTree<T>::iterator RightMostNode() noexcept = delete;
  
  using VLSubTree<T>::LeftMostLeaf;
  typename VLSubTree<T>::iterator LeftMostLeaf() noexcept = delete;
  
  using VLSubTree<T>::RightMostLeaf;
  typename VLSubTree<T>::iterator RightMostLeaf() noexcept = delete;
  
  using VLSubTree<T>::Root;
  inline typename VLSubTree<T>::iterator Root() noexcept = delete;
  
  template <typename Arg> void insert( const typename VLSubTree<T>::iterator& , const Arg& ) = delete;

  typename VLSubTree<T>::iterator erase( typename VLSubTree<T>::iterator& ) = delete;

  using VLSubTree<T>::operator[];
  VLSubTree<T> operator[]( const uint& ) = delete;
  VLSubTree<T> operator[]( typename VLSubTree<T>::iterator& ) = delete;
  
  void Concatenate( const VLSubTree<T>& ) = delete;
  void Concatenate( const typename VLSubTree<T>::iterator& , const VLSubTree<T>& ) = delete;

};
