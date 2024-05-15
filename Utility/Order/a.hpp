// c:/Users/user/Documents/Programming/Utility/Order/a.hpp

#pragma once
#include "a_Macro.hpp"

// 順序を反転させる。
// Reversed<int>では+1が後続でなくなるので通常の二分探索ができなくなることに注意。
template <typename T>
class Reversed
{

private:
  // T = intの場合も扱うため、継承にできない。
  T m_t;

public:
  inline Reversed( const Reversed<T>& t );
  inline Reversed( Reversed<T>& t );
  inline Reversed( Reversed<T>&& t );
  template <typename...Args> inline Reversed( Args&&... args );

  inline Reversed<T>& operator=( Reversed<T> t );
  
  DECLARATION_OF_REVERSED_RELATION( == );
  DECLARATION_OF_REVERSED_RELATION( != );
  DECLARATION_OF_REVERSED_RELATION( < );
  DECLARATION_OF_REVERSED_RELATION( > );
  DECLARATION_OF_REVERSED_RELATION( <= );
  DECLARATION_OF_REVERSED_RELATION( >= );

  DECLARATION_OF_REVERSED_ARITHMETIC( + , Reversed<T> );
  inline Reversed<T> operator-() const;
  DECLARATION_OF_REVERSED_ARITHMETIC( - , Reversed<T> );
  DECLARATION_OF_REVERSED_ARITHMETIC( * , Reversed<T> );
  DECLARATION_OF_REVERSED_ARITHMETIC( / , Reversed<T> );
  DECLARATION_OF_REVERSED_ARITHMETIC( % , Reversed<T> );
  DECLARATION_OF_REVERSED_ARITHMETIC( << , int );
  DECLARATION_OF_REVERSED_ARITHMETIC( >> , int );
  
  inline T& Ref() noexcept;
  inline const T& Get() const noexcept;
  inline T&& move() noexcept;
  
};
