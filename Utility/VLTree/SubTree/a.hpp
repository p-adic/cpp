// c:/Users/user/Documents/Programming/Utility/VLTree/SubTree/a.hpp

#pragma once
#include "../Entry/a.hpp"

template <typename T> class IteratorOfVLTree;
template <typename T> class ConstIteratorOfVLTree;
template <typename T> class VLConstSubTree;
template <typename T> class VLTree;
template <typename Arg> class WrappedType;

template <typename T>
class VLSubTree
{

  friend VLConstSubTree<T>;
  friend VLTree<T>;
  
private:
  EntryOfVLTree<T> m_e;
  EntryOfVLTree<T>& m_root;
  uint m_size;

private:
  // Tは引数0のコンストラクタを持つクラスのみ許容。
  // デストラクタがdelete演算子を呼ばないため、VLTree経由でしか呼び出してはいけない。
  inline VLSubTree();

  // Tは引数0のコンストラクタを持つクラスのみ許容。
  // デストラクタがdelete演算子を呼ばないため、VLTree経由でしか呼び出してはいけない。
  template <typename Arg1 , typename... Arg2> inline VLSubTree( const Arg1& , const Arg2&... );
  
  // Tが引数0のコンストラクタを持たないクラスの場合に使用。
  // デストラクタがdelete演算子を呼ばないため、VLTree経由でしか呼び出してはいけない。
  template <typename Arg> inline VLSubTree( const WrappedType<Arg>& t );

  // 明示的に代入演算子を経由してコピーしているため、構築された木への変更がコピー元へは反映されない。
  // デストラクタがdelete演算子を呼ばないため、VLTree経由でしか呼び出してはいけない。
  inline VLSubTree( const VLSubTree<T>& );

  // const_castを行うため、VLConstSubTree経由でしか呼び出してはいけない。
  inline VLSubTree( const ConstIteratorOfVLTree<T>& );

  // 直接木を構築して返すため、戻り値の木への変更が自身へも反映されうる。
  // VLTreeを経由しなくても呼び出して良い。
  inline VLSubTree( EntryOfVLTree<T>& );

public:
  virtual ~VLSubTree() = default;

  // CutBranchesとpush_RightMostで新たに木を構築するため、構築された木への変更がoperator=のコピー元へは反映されないが部分木としての埋め込み先へは反映される。
  VLSubTree<T>& operator=( const VLSubTree<T>& );
  
  inline const uint& size() const noexcept;
  inline void CutBranches();
  void CutBranches( const T& );
  void CutLeaf();
  inline bool IsLeaf() const noexcept;

  // 部分木を構築して返すため、部分木への変更が自身へも反映される。
  inline VLSubTree<T> LeftMostSubTree();
  inline VLSubTree<T> RightMostSubTree();
  
  // 部分木のコピーを構築して返すため、部分木への変更が自身へは反映されない。
  VLTree<T> LeftMostSubTreeCopy() const;
  VLTree<T> RightMostSubTreeCopy() const;
  
  inline void push_RightMost() const noexcept;
  template <typename Arg1 , typename... Arg2> void push_RightMost( const Arg1& , const Arg2&... );

  // 部分木のコピーを構築して挿入するため、自身への変更が部分木へは反映されない。
  template <typename... Args> void push_RightMost( const VLSubTree<T>& , const Args&... );
  template <typename... Args> void push_RightMost( const VLTree<T>& , const Args&... );

  template <typename Arg> void push_LeftMost( const Arg& );
  
  void pop_RightMost();
  void pop_LeftMost();
  void pop_Root();

  template <typename... Args> inline void push_back( const Args&... );
  template <typename Arg> inline void push_front( const Arg& );
  inline void pop_back();
  inline void pop_front();

  using iterator = IteratorOfVLTree<T>;
  using const_iterator = ConstIteratorOfVLTree<T>;

  // *thisがconstである場合に確実にconst_iterator返しをするために、iterator返しは非constにする必要がある。
  inline iterator LeftMostNode() noexcept;
  inline const_iterator LeftMostNode() const noexcept;
  inline iterator RightMostNode() noexcept;
  inline const_iterator RightMostNode() const noexcept;
  iterator LeftMostLeaf() noexcept;
  const_iterator LeftMostLeaf() const noexcept;
  iterator RightMostLeaf() noexcept;
  const_iterator RightMostLeaf() const noexcept;
  inline iterator Root() noexcept;
  inline const_iterator Root() const noexcept;

  // iteratorの右に新たなLeafを構築する。
  template <typename Arg> void insert( const iterator& , const Arg& );

  // RightMostである場合はrootへのイテレータを返す。
  iterator erase( iterator& );

  // RootやNodeのラベルに直接読み書きを行う。
  inline const T& GetRoot() const noexcept;
  inline void SetRoot( const T& );
  void SetNode( const iterator& , const T& );

  // 部分木を構築して返すため、部分木への変更が自身へも反映される。
  VLSubTree<T> operator[]( const uint& );
  VLSubTree<T> operator[]( iterator& );
  
  // 定数部分木を構築して返すため、部分木への変更が自身へは反映されない。
  VLConstSubTree<T> operator[]( const const_iterator& ) const;

  // 部分木のコピーを構築して返すため、部分木への変更が自身へは反映されない。
  VLTree<T> GetBranchCopy( const uint& ) const;
  VLTree<T> GetBranchCopy( const iterator& ) const;
  VLTree<T> GetBranchCopy( const const_iterator& ) const;
  
  // 部分木のコピーを構築して挿入するため、自身への変更が部分木へは反映されない。
  void Concatenate( const VLSubTree<T>& );
  void Concatenate( const iterator& , const VLSubTree<T>& );

  bool CheckContain( const iterator& ) const noexcept;
  bool CheckContain( const const_iterator& ) const noexcept;

  string Display() const;
  
};
