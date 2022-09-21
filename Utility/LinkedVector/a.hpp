// c:/Users/user/Documents/Programming/Utility/LinkedVector/a.hpp

#pragma once
#include "Entry/a.hpp"
#include "Iterator/a.hpp"
#include <vector>

template <typename T>
class LinkedVector
{

private:
  vector<EntryOfLinkedVector<T> > m_entry;
  uint m_front_linked_entry;
  uint m_back_linked_entry;
  uint m_size_of_vector;
  uint m_size_of_link;

public:
  inline LinkedVector();
  // 要素やそのメンバへのポインタをメンバに持ちうるクラスに対しては
  // vectorのcapacityを超える際のコピーでポインタの参照先が無効になってしまうので
  // 予め最大要素数を設定する。
  inline LinkedVector( const uint& max_size );

  // vector上でi番目の要素を返す。
  inline const T& operator[]( const uint& i ) const;
  inline T& operator[]( const uint& i );

  // link上でi番目の要素の座標を返す。
  uint GetLinkedEntry( const uint& i ) const;

  inline const uint& GetFrontLinkedEntryIndex() const noexcept;
  inline const uint& GetBackLinkedEntryIndex() const noexcept;
  inline const uint& GetSizeOfVector() const noexcept;
  inline const uint& GetSizeOfLink() const noexcept;

  inline void re();
  inline void push_back();
  template <typename U> void push_back( const U& u );
  template <typename U , typename... ARGS> inline void push_back( const U& u , const ARGS&... args );

  inline void SetPreviousLink( const uint& i , const uint& j );
  inline void SetNexttLink( const uint& i , const uint& j );
  inline const uint& GetPreviousLinkIndex( const uint& i ) const;
  inline const uint& GetNexttLinkIndex( const uint& i ) const;

  // vector上でi番目の要素がlink上にある場合のみサポート
  const uint& DeLink( const uint& i );
  // vector上でi番目の要素がlink上にない場合のみサポート
  void ReLink( const uint& i );

  using iterator = IteratorOfLinkedVector<T>;
  using const_iterator = ConstIteratorOfLinkedVector<T>;

  // *thisがconstである場合に確実にconst_iterator返しをするために、iterator返しは非constにする必要がある。
  inline iterator GetIterator( const uint& i ) noexcept;
  inline const_iterator GetIterator( const uint& i ) const noexcept;
  inline iterator begin() noexcept;
  inline const_iterator begin() const noexcept;
  inline iterator end() noexcept;
  inline const_iterator end() const noexcept;
  // itrの指す要素がlink上にある場合のみサポート
  iterator erase( iterator& itr );


private:
  inline EntryOfLinkedVector<T>& push_back_Body_0();
  inline void push_back_Body_1( EntryOfLinkedVector<T>& e );
  
};
