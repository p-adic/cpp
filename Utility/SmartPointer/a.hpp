// SmartPointer/a.hpp

#pragma once

template <typename T>
class SmartPointer
{

private:
  T* m_p;
  uint* m_n;
  bool* m_b;

public:
  inline SmartPointer();
  template <typename Arg> inline SmartPointer( const Arg& );
  inline SmartPointer( const SmartPointer<T>& ) noexcept;;
  inline SmartPointer( SmartPointer<T>&& ) noexcept;
  ~SmartPointer();
  SmartPointer<T>& operator=( const SmartPointer<T>& ) noexcept;
  SmartPointer<T>& operator=( T* const& ) noexcept;
  T& operator*() const;
  inline T* operator->() const noexcept;
  inline void Forget() const noexcept;
  inline const bool& IsAccessible() const noexcept;

};

template <typename T> inline bool operator==( const SmartPointer<T>& , const nullptr_t& ) noexcept;
template <typename T> inline const bool& operator!=( const SmartPointer<T>& , const nullptr_t& ) noexcept;

template <typename T> inline T& Access( const SmartPointer<T>& );
template <typename T> inline SmartPointer<T> to_SmartPointer( const T& );
template <typename T> list<SmartPointer<T> > to_SmartPointer_Listed( const list<T>& );
