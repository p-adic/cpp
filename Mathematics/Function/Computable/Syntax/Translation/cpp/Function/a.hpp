// c:/Users/user/Documents/Programming/Mathematics/Function/Computable/Syntax/Translation/cpp/Function/a.hpp

#pragma once
#include "a_Macro.hpp"

#include "../Type/a.hpp"
#include "../../../../../a.hpp"

class CppClassForString;

class CppClassForFunctionString
{

private:
  const string m_f;

public:
  inline CppClassForFunctionString( const string& f ) : m_f( f ) {}

  template <typename... Args> inline CppClassForString operator()( const Args&... args ) const { return m_f + WrapInParenthesis( ArgumentString( args... ) ); };

  inline const string& Get() const noexcept { return m_f; };

};


template <typename Func>
class CppClassForArrayise
{

private:
  
  const Func m_f;

public:
  inline CppClassForArrayise( const Func& f ) : m_f( f ) {}

  inline const CppClassForArrayise<Func>& operator*() const noexcept { return *this; }
  inline const CppClassForArrayise<Func>& operator&() const noexcept { return *this; }

  using type = VLArray<decltype( m_f( 0 ) )>;
  type operator()( const uint& n ) const;

};

template <typename Func>
class CppClassForArrayise<Func*>
{

private:
  
  const Func* const& m_p;

public:
  inline CppClassForArrayise( const Func* const& p ) : m_p( p ) {}

  inline const CppClassForArrayise<Func*>& operator*() const noexcept { return *this; }
  inline const CppClassForArrayise<Func*>& operator&() const noexcept { return *this; }

  using type = VLArray<decltype( ( *m_p )( 0 ) )>;
  type operator()( const uint& n ) const;

};

template <typename Arg> inline CppClassForFunctionString ArrayiseStringApplication( const Arg& arg );

template <typename Func, typename Arg1>
class CppClassForCurrying
{

private:
  
  const Func m_f;
  const Arg1 m_arg1;

public:
  inline CppClassForCurrying( const Func& f , const Arg1& arg1 ) : m_f( f ) , m_arg1( arg1 ) {}

  inline const CppClassForCurrying<Func,Arg1>& operator*() const noexcept { return *this; }
  inline const CppClassForCurrying<Func,Arg1>& operator&() const noexcept { return *this; }

  using second_type = typename Func::second_type;
  using type = decltype( m_f( m_arg1 , declval<second_type>() ) );
  inline type operator()( const second_type& arg2 ) const { return m_f( m_arg1 , arg2 ); };

};

template <typename Ret, typename Arg1, typename Arg2>
class CppClassForCurrying<FunctionPointerType<Ret,Arg1,Arg2>,Arg1>
{

private:
  
  const FunctionPointerType<Ret,Arg1,Arg2>& m_p;
  const Arg1 m_arg1;

public:
  inline CppClassForCurrying( const FunctionPointerType<Ret,Arg1,Arg2>& p , const Arg1& arg1 ) : m_p( p ) , m_arg1( arg1 ) {}

  inline const CppClassForCurrying<FunctionPointerType<Ret,Arg1,Arg2>,Arg1>& operator*() const noexcept { return *this; }
  inline const CppClassForCurrying<FunctionPointerType<Ret,Arg1,Arg2>,Arg1>& operator&() const noexcept { return *this; }

  using second_type = Arg2;
  using type = decltype( ( *m_p )( m_arg1 , declval<Arg2>() ) );
  inline type operator()( const Arg2& arg2 ) const { return ( *m_p )( m_arg1 , arg2 ); };

};

template <typename Arg1, typename Arg2, typename... Args> inline CppClassForFunctionString CurryingStringApplication( const Arg1& arg1 , const Arg2& arg2 , const Args&... args );


template <typename Func>
class CppClassForComposition
{

private:
  
  const Func m_f;
  const uint m_n;

public:
  inline CppClassForComposition( const Func& f , const uint& n ) : m_f( f ) , m_n( n ) {}


  inline const CppClassForComposition<Func>& operator*() const noexcept { return *this; }
  inline const CppClassForComposition<Func>& operator&() const noexcept { return *this; }
  
  using type = typename Func::type;
  type operator()( const type& t ) const;

};

template <typename T>
class CppClassForComposition<FunctionPointerType<T,T> >
{

private:
  
  const FunctionPointerType<T,T>& m_p;
  const uint m_n;

public:
  inline CppClassForComposition( const FunctionPointerType<T,T>& p , const uint& n ) : m_p( p ) , m_n( n ) {}

  inline const CppClassForComposition<FunctionPointerType<T,T> >& operator*() const noexcept { return *this; }
  inline const CppClassForComposition<FunctionPointerType<T,T> >& operator&() const noexcept { return *this; }

  using type = T;
  T operator()( const T& t ) const;

};


inline CppClassForFunctionString operator^( const CppClassForFunctionString& func , const CppClassForString& n );
inline CppClassForFunctionString operator^( const CppClassForFunctionString& func , const uint& n );
