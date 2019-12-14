// c:/Users/user/Documents/Programming/Utility/VLArray/Iterator/a.hpp

#pragma once

template <typename T> class EntryOfVLArray;
template <typename T> class ConstIteratorOfVLArray;
template <typename T> class VLArray;

template <typename T>
class IteratorOfVLArray
{

  friend ConstIteratorOfVLArray<T>;
  friend VLArray<T>;

private:
  // ++の実装のためにはm_pをポインタへの参照にできない。
  EntryOfVLArray<T>* m_p;
  
public:
  inline IteratorOfVLArray( EntryOfVLArray<T>* const& ) noexcept;
  inline IteratorOfVLArray( const IteratorOfVLArray<T>& ) noexcept;

  inline T& operator*() const;
  inline T* operator->() const;
  IteratorOfVLArray<T>& operator=( const IteratorOfVLArray<T>& ) noexcept;
  inline void operator++( int );
  inline void operator--( int );

};

template <typename T>
class ConstIteratorOfVLArray
{

  friend VLArray<T>;

private:
  const EntryOfVLArray<T>* m_p;
  
public:
  inline ConstIteratorOfVLArray( EntryOfVLArray<T>* const& ) noexcept;
  inline ConstIteratorOfVLArray( const ConstIteratorOfVLArray<T>& ) noexcept;
  inline ConstIteratorOfVLArray( const IteratorOfVLArray<T>& ) noexcept;

  inline const T& operator*() const;
  inline const T* operator->() const;
  ConstIteratorOfVLArray<T>& operator=( const ConstIteratorOfVLArray<T>& ) noexcept;
  ConstIteratorOfVLArray<T>& operator=( const IteratorOfVLArray<T>& ) noexcept;
  inline void operator++( int );
  inline void operator--( int );
  
  static inline bool Equal( const IteratorOfVLArray<T>& , const IteratorOfVLArray<T>& ) noexcept;
  static inline bool Equal( const ConstIteratorOfVLArray<T>& , const IteratorOfVLArray<T>& ) noexcept;
  static inline bool Equal( const IteratorOfVLArray<T>& , const ConstIteratorOfVLArray<T>& ) noexcept;
  static inline bool Equal( const ConstIteratorOfVLArray<T>& , const ConstIteratorOfVLArray<T>& ) noexcept;

};

template <typename T> inline bool operator==( const IteratorOfVLArray<T>& , const IteratorOfVLArray<T>& ) noexcept;
template <typename T> inline bool operator!=( const IteratorOfVLArray<T>& , const IteratorOfVLArray<T>& ) noexcept;

template <typename T> inline bool operator==( const ConstIteratorOfVLArray<T>& , const IteratorOfVLArray<T>& ) noexcept;
template <typename T> inline bool operator!=( const ConstIteratorOfVLArray<T>& , const IteratorOfVLArray<T>& ) noexcept;

template <typename T> inline bool operator==( const IteratorOfVLArray<T>& , const ConstIteratorOfVLArray<T>& ) noexcept;
template <typename T> inline bool operator!=( const IteratorOfVLArray<T>& , const ConstIteratorOfVLArray<T>& ) noexcept;

template <typename T> inline bool operator==( const ConstIteratorOfVLArray<T>& , const ConstIteratorOfVLArray<T>& ) noexcept;
template <typename T> inline bool operator!=( const ConstIteratorOfVLArray<T>& , const ConstIteratorOfVLArray<T>& ) noexcept;
