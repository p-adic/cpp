// c:/Users/user/Documents/Programming/Utility/VLTree/Forest/a.hpp

#pragma once
#include "Entry/a.hpp"
#include <vector>

template <typename T>
class Forest
{

private:
  vector<EntryOfForest<T> > m_e;
  uint m_leftmost_root;
  uint m_rightmost_root;
  uint m_size_of_node;
  uint m_size_of_root;

public:
  inline Forest();

  // num番目のNodeをRootとする部分木を構築する。
  inline const VLSubTree<T>& GetSubTree( const uint& num ) const;
  // num番目のNodeのRootを返す。
  inline const uint& GetRootOfNode( const uint& num ) const;
  // num番目のRootを返す。
  uint GetRoot( const uint& num ) const;
  inline const uint& GetSizeOfNode() const noexcept;
  inline const uint& GetSizeOfRoot() const noexcept;

  inline void push_RightMost();
  void push_RightMost( const T& );
  template <typename... ARGS> inline void push_RightMost( const T& t , const ARGS&... args );
  
  void Graft( const uint& num0 , const uint& num1 );
  
};
