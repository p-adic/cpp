// c:/Users/user/Documents/Programming/Utility/VLTree/SubTree/a.hpp

#pragma once
#include "../Iterator/a.hpp"
#include "../../WrappedType/a.hpp"

template <typename T> class VLTree;

template <typename T>
class VLSubTree
{

  friend VLTree<T>;
  
private:
  EntryOfVLTree<T> m_e;
  // 通常はm_eを指すが、VLSubTree( EntryOfVLTree<T>& )や
  // VLSubTree( const IteratorOfVLTree<T>& )経由で呼び出された場合のみ
  // 参照元のNodeを指す。
  EntryOfVLTree<T>* m_p_root;
  uint m_size;

private:
  // Tは引数0のコンストラクタを持つクラスのみ許容。
  // デストラクタがdelete演算子を呼ばないため、VLTreeかForest経由でしか呼び出してはいけない。
  inline VLSubTree();

  // Tは引数0のコンストラクタを持つクラスのみ許容。
  // rootのみの木に引数たちをpush_RightMostして高々m_size == 1の木を構築する。
  // デストラクタがdelete演算子を呼ばないため、VLTree経由でしか呼び出してはいけない。
  template <typename Arg1 , typename... Arg2> inline VLSubTree( const Arg1& , const Arg2&... );
  
  // Tが引数0のコンストラクタを持たないクラスの場合に使用。
  // デストラクタがdelete演算子を呼ばないため、VLTree経由でしか呼び出してはいけない。
  template <typename Arg> inline VLSubTree( const WrappedType<Arg>& t );

  // 構築された木への変更がコピー元へは反映されない。
  // デストラクタがdelete演算子を呼ばないため、VLTree経由でしか呼び出してはいけない。
  // Substriture_Bodyを経由するため、自身への変更が引数へは反映されない。
  // 引数をVLSubConstTree<T>にしたものを定義して委譲するとループしてしまう。
  inline VLSubTree( const VLSubTree<T>& );

  // 構築された木への変更がコピー元へは反映される。
  // VLTreeを経由しなくても呼び出して良い。
  // VLTreeを経由してはならない。
  inline VLSubTree( EntryOfVLTree<T>& );
  inline VLSubTree( const IteratorOfVLTree<T>& );
  
  // 構築された木への変更がコピー元へは反映されない。
  // デストラクタがdelete演算子を呼ばないため、VLTree経由でしか呼び出してはいけない。
  // intはダミー引数。
  inline VLSubTree( const int& , const EntryOfVLTree<T>& );
  inline VLSubTree( const int& , const ConstIteratorOfVLTree<T>& );

  // 部分木のコピーを構築してpush_RightMostNodeで挿入するため、自身への変更が引数へは反映されない。
  // LeafToTreeとpush_RightMostとConcatenateの相互再帰。
  // m_size == 0の時しか呼んではいけない。
  void LeafToTree( const VLSubTree<T>& );

  // 新たにRightMostNodeを構築し、そこを部分木のRootとして結合する。
  // 構築された木への変更がコピー元へ反映される。
  // Forest経由でしか呼び出してはいけない。
  void Graft( VLSubTree<T>& );

  
public:
  virtual ~VLSubTree() = default;

  // Substriture_Bodyを経由するため、引数が自身と独立でさえあれば、自身への変更が引数へは反映されない。
  // CutBranchesを呼び出すため、引数が自身と独立でない場合は、自身への変更が引数へ反映されうる上に、Segmentation Faultを引き起こす可能性がある。
  // 引数をVLTree<T>にしたものを定義して呼び出すとループしてしまう。
  VLSubTree<T>& operator=( const VLSubTree<T>& );
  
  inline const uint& size() const noexcept;
  inline void CutBranches();
  inline bool IsLeaf() const noexcept;

  // 部分木を構築して返すため、部分木への変更が自身へも反映される。
  inline VLSubTree<T> LeftMostSubTree();
  inline VLSubTree<T> RightMostSubTree();
  
  // 部分木のコピーを構築して返すため、部分木への変更が自身へは反映されない。
  inline VLTree<T> LeftMostSubTreeCopy() const;
  inline VLTree<T> RightMostSubTreeCopy() const;
  
  // LeafToTreeとpush_RightMostとConcatenateの相互再帰。
  inline void push_RightMost() const noexcept;
  template <typename Arg1 , typename... Arg2> void push_RightMost( const Arg1& , const Arg2&... );
  template <typename... Args> void push_RightMost( const VLTree<T>& , const Args&... );
  template <typename Arg> void push_LeftMost( const Arg& );
  
  void pop_RightMost();
  void pop_LeftMost();

  // m_size == 1（特にm_p_root->m_leftmost_node== m_p_root->m_rightmost_node）の時しか呼んではならない。
  // m_p_rootはdelete可能とは限らないため、代わりに値のすげかえを行い実際にdeleteされるのはm_p_rootでなくm_p_root->m_leftmost_nodeである。
  // 従って特にiteratorの処理に注意が必要。
  void pop_Root();

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
  template <typename... Args> inline iterator GetIterator( const Args&... );
  template <typename... Args> inline const_iterator GetIterator( const Args&... ) const;

  // iteratorの右に新たなLeafを構築する。
  template <typename Arg> void insert( const iterator& , const Arg& );

  // RightMostである場合はrootへのイテレータを返す。
  iterator erase( iterator& );

  // RootやNodeのラベルに直接読み書きを行う。
  inline const T& GetRoot() const noexcept;
  inline void SetRoot( const T& );
  template <typename... Args> inline const T& GetNode( const Args&... ) const;

  // 部分木を構築して返すため、部分木への変更が自身へも反映される。
  VLSubTree<T> operator[]( const uint& );
  VLSubTree<T> operator[]( iterator& );
  
  // 部分木のコピーを構築して返すため、部分木への変更が自身へは反映されない。
  VLTree<T> operator[]( const const_iterator& ) const;
  VLTree<T> GetBranchCopy( const uint& ) const;
  VLTree<T> GetBranchCopy( const iterator& ) const;
  VLTree<T> GetBranchCopy( const const_iterator& ) const;

  // 現在のRightMostNodeやiteratorの指す位置を部分木のRootとしてコピーを構築する。
  // 構築された木への変更がコピー元へは反映されない。
  // LeafToTreeとpush_RightMostとConcatenateの相互再帰。
  void Concatenate( const VLTree<T>& );
  void Concatenate( const iterator& , const VLTree<T>& );

  bool CheckContain( const iterator& ) const noexcept;
  bool CheckContain( const const_iterator& ) const noexcept;
  string Display() const;
  
};

template <typename T> bool operator==( const VLTree<T>& , const VLTree<T>& );
template <typename T> inline bool operator!=( const VLTree<T>& , const VLTree<T>& );
