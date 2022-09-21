// c:/Users/user/Documents/Programming/Utility/LinkedVector/Entry/a.hpp

#pragma once

template <typename T> class LinkedVector;
template <typename T> class IteratorOfLinkedVector;
template <typename T> class ConstIteratorOfLinkedVector;
template <typename T> class UnionFindForest;

template <typename T>
class EntryOfLinkedVector
{

  friend class LinkedVector<T>;
  friend class IteratorOfLinkedVector<T>;
  friend class ConstIteratorOfLinkedVector<T>;
  template <typename U> friend class UnionFindForest;

private:
  T m_t;
  uint m_prev_entry;
  uint m_next_entry;

private:
  inline EntryOfLinkedVector();
  inline EntryOfLinkedVector( const uint& prev_entry , const uint& next_entry );


public:
  // vectorÇÃreserveÇ…ïKóvÅB
  inline EntryOfLinkedVector( EntryOfLinkedVector<T>&& e );

};
