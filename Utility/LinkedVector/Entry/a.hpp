// c:/Users/user/Documents/Programming/Utility/LinkedVector/Entry/a.hpp

#pragma once

template <typename T> class LinkedVector;

template <typename T>
class EntryOfLinkedVector
{

  friend LinkedVector<T>;
  
private:
  T m_t;
  uint m_prev_entry;
  uint m_next_entry;

private:
  inline EntryOfLinkedVector();
  inline EntryOfLinkedVector( const uint& prev_entry , const uint& next_entry );


public:
  // vector‚Ìreserve‚É•K—vB
  inline EntryOfLinkedVector( EntryOfLinkedVector<T>&& e );

};
