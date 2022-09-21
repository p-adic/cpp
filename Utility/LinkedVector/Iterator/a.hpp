// c:/Users/user/Documents/Programming/Utility/LinkedVector/Iterator/a.hpp

#pragma once

template <typename T> class EntryOfLinkedVector;
template <typename T> class ConstIteratorOfLinkedVector;
template <typename T> class LinkedVector;

template <typename T>
class IteratorOfLinkedVector
{

  friend ConstIteratorOfLinkedVector<T>;
  friend LinkedVector<T>;

private:
  LinkedVector<T>* m_p;
  uint m_i;
  
public:
  inline IteratorOfLinkedVector( LinkedVector<T>* const& p , const uint& i ) noexcept;
  inline IteratorOfLinkedVector( const IteratorOfLinkedVector<T>& itr ) noexcept;

  inline T& operator*() const;
  inline T* operator->() const;
  IteratorOfLinkedVector<T>& operator=( const IteratorOfLinkedVector<T>& itr ) noexcept;
  inline void operator++( int );
  inline void operator--( int );

  inline const LinkedVector<T>& GetLinkedVector() const noexcept;
  inline LinkedVector<T>& RefLinkedVector() noexcept;
  inline const uint& GetIndex() const noexcept;
  inline const& RefIndex() noexcept;

};

template <typename T>
class ConstIteratorOfLinkedVector
{

  friend LinkedVector<T>;

private:
  const LinkedVector<T>* m_p;
  uint m_i;
  
public:
  inline ConstIteratorOfLinkedVector( const LinkedVector<T>* const& p , const uint& i ) noexcept;
  inline ConstIteratorOfLinkedVector( const ConstIteratorOfLinkedVector<T>& itr ) noexcept;
  inline ConstIteratorOfLinkedVector( const IteratorOfLinkedVector<T>& itr ) noexcept;

  inline const T& operator*() const;
  inline const T* operator->() const;
  ConstIteratorOfLinkedVector<T>& operator=( const ConstIteratorOfLinkedVector<T>& itr ) noexcept;
  ConstIteratorOfLinkedVector<T>& operator=( const IteratorOfLinkedVector<T>& itr ) noexcept;
  inline void operator++( int );
  inline void operator--( int );

  inline const LinkedVector<T>& GetLinkedVector() const noexcept;
  inline const uint& GetIndex() const noexcept;
  inline const& RefIndex() noexcept;

  
  static inline bool Equal( const IteratorOfLinkedVector<T>& , const IteratorOfLinkedVector<T>& ) noexcept;
  static inline bool Equal( const ConstIteratorOfLinkedVector<T>& , const IteratorOfLinkedVector<T>& ) noexcept;
  static inline bool Equal( const IteratorOfLinkedVector<T>& , const ConstIteratorOfLinkedVector<T>& ) noexcept;
  static inline bool Equal( const ConstIteratorOfLinkedVector<T>& , const ConstIteratorOfLinkedVector<T>& ) noexcept;

};

template <typename T> inline bool operator==( const IteratorOfLinkedVector<T>& , const IteratorOfLinkedVector<T>& ) noexcept;
template <typename T> inline bool operator!=( const IteratorOfLinkedVector<T>& , const IteratorOfLinkedVector<T>& ) noexcept;

template <typename T> inline bool operator==( const ConstIteratorOfLinkedVector<T>& , const IteratorOfLinkedVector<T>& ) noexcept;
template <typename T> inline bool operator!=( const ConstIteratorOfLinkedVector<T>& , const IteratorOfLinkedVector<T>& ) noexcept;

template <typename T> inline bool operator==( const IteratorOfLinkedVector<T>& , const ConstIteratorOfLinkedVector<T>& ) noexcept;
template <typename T> inline bool operator!=( const IteratorOfLinkedVector<T>& , const ConstIteratorOfLinkedVector<T>& ) noexcept;

template <typename T> inline bool operator==( const ConstIteratorOfLinkedVector<T>& , const ConstIteratorOfLinkedVector<T>& ) noexcept;
template <typename T> inline bool operator!=( const ConstIteratorOfLinkedVector<T>& , const ConstIteratorOfLinkedVector<T>& ) noexcept;
