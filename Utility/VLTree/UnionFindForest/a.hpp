// c:/Users/user/Documents/Programming/Utility/VLTree/UnionFindForest/a.hpp

#pragma once
#include "Entry/a.hpp"
#include "../../LinkedVector/a.hpp"

template <typename T>
class UnionFindForest :
  private LinkedVector<EntryOfUnionFindForest<T> >
{

public:
  // EntryOfUnionFindForest<T>::m_nodeはVLSubTree<T>型でありポインタをメンバに持つため
  // 予め最大要素数を固定しないといけない。
  inline UnionFindForest( const uint& max_size );

  // num番目のNodeをRootとする部分木を構築する。
  inline const VLSubTree<T>& GetSubTree( const uint& num ) const;
  // num番目のNodeのPredecessor Nodeを返す。
  inline const uint& GetPredecessorNode( const uint& num ) const;
  // num番目のNodeのRootを返す。
  inline const uint& GetRootOfNode( const uint& num ) const;
  // num番目のRootを返す。
  uint GetRoot( const uint& num ) const;
  inline const uint& GetSizeOfNode() const noexcept;
  inline const uint& GetSizeOfRoot() const noexcept;

  // 最初に指定したmax_sizeよりGetSizeOfNode()が大きい場合はサポート外
  inline void push_RightMost();
  void push_RightMost( const T& t );
  template <typename... ARGS> inline void push_RightMost( const T& t , const ARGS&... args );
  
  void Graft( const uint& num0 , const uint& num1 );
  
};
