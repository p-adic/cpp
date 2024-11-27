// c:/Users/user/Documents/Programming/Mathematics/Function/Computable/Syntax/Translation/cpp/Type/a.hpp

#pragma once
#include "a_Macro.hpp"

#include "a_Alias.hpp"

template <typename T>
class VLNestedArray
{

private:
  VLTree<T> m_t;
  VLTree<bool> m_denestable;

public:
  inline VLNestedArray( const T& t = T() );
  inline VLNestedArray( const VLTree<T>& t , const VLTree<bool>& denestable );
  inline VLNestedArray( const VLNestedArray<T>& a );
  VLNestedArray( const VLArray<T>& t );

  inline VLNestedArray<T>& operator=( const VLNestedArray<T>& a );

  inline const bool& Denestable() const noexcept;
  inline const uint& size() const noexcept;

  inline string Display() const noexcept;
  
  inline VLNestedArray<T> GetBranchCopy( const uint& n ) const;
  inline const T& GetRoot() const noexcept;
  VLNestedArray<T> Wrap() const;

  void Concatenate( const VLNestedArray& a );
  inline void pop_RightMost();
  inline void pop_LeftMost();

  static inline bool Equal( const VLNestedArray<T>& a0 , const VLNestedArray<T>& a1 ) noexcept;

};

template <typename T> inline bool operator==( const VLNestedArray<T>& a0 , const VLNestedArray<T>& a1 ) noexcept;
template <typename T> inline bool operator!=( const VLNestedArray<T>& a0 , const VLNestedArray<T>& a1 ) noexcept;


inline string WrapInParenthesis( const string& arg );

template <typename Arg> inline auto ConcatenateWithSeparator( const string& s , const Arg& arg ) -> typename enable_if<is_same<Arg,string>::value,string>::type;

template <typename Arg1, typename Arg2, typename... Args> inline auto ConcatenateWithSeparator( const string& s , const Arg1& arg1 , const Arg2& arg2 , const Args&... args ) -> typename enable_if<is_same<Arg1,string>::value && is_same<Arg2,string>::value && conjunction<is_same<Args,string>...>::value,string>::type;

inline string ArgumentString();
template <typename Arg, typename... Args> inline string ArgumentString( const Arg& arg , const Args&... args );
template <typename Arg, typename... Args> inline string TypeString();
inline string TypeAndArgumentString();
template <typename Arg, typename... Args> inline string TypeAndArgumentString( const Arg& arg , const Args&... args );

