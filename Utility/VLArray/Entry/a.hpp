// c:/Users/user/Documents/Programming/Utility/VLArray/Entry/a.hpp

#pragma once

template <typename T> class VLArray;
template <typename T> class IteratorOfVLArray;
template <typename T> class ConstIteratorOfVLArray;

template <typename T>
class EntryOfVLArray
{

  friend VLArray<T>;
  friend IteratorOfVLArray<T>;
  friend ConstIteratorOfVLArray<T>;

private:
  T m_t;
  EntryOfVLArray<T>* m_prev;
  EntryOfVLArray<T>* m_next;
  
private:
  inline EntryOfVLArray();
  template <typename Arg> inline EntryOfVLArray( const Arg& );
  template <typename Arg> inline EntryOfVLArray( const Arg& , EntryOfVLArray<T>* const& , EntryOfVLArray<T>* const& );

};
