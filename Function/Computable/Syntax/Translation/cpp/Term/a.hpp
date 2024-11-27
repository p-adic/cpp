// c:/Users/user/Documents/Programming/Mathematics/Function/Computable/Syntax/Translation/cpp/Term/a.hpp

#pragma once
#include "a_Macro.hpp"

#include <fstream>
#include "../String/a.hpp"
#include "../Function/a.hpp"
#include "../Ofstream/a.hpp"

template <typename T>
class CppClassForTerm :
  public EmptySet
{};

// int, bool
// class CppClassForTerm< T >
// {

// private:
//   T m_t;
  
// public:
//   inline CppClassForTerm( const T& t ) : m_t( t ) {};

//   inline const T& Get() const noexcept { return m_t; };
//   inline void Set( const T& t ) { m_t = t; };

// };

DEFINITION_OF_PRIMITIVE_CPP_CLASS_FOR_TERM( int );
DEFINITION_OF_PRIMITIVE_CPP_CLASS_FOR_TERM( bool );

// string
template <>
class CppClassForTerm<string>
{

private:
  string m_t;
  
public:
  inline CppClassForTerm( const string& t ) : m_t( "\"" + t + "\"" ) {};

  inline const string& Get() const noexcept { return m_t; };
  inline void Set( const string& t ) { m_t = t; };

};


template <typename Ret>
class CppClassForTerm<VariadicVariableSymbol<Ret> >
{};


template <typename Ret>
class CppClassForTerm<ArrayTypeOfComputableFunction<Ret> >
{

private:
  VLArray<Ret> m_t;

public:
  inline CppClassForTerm<ArrayTypeOfComputableFunction<Ret> >( const VLArray<Ret>& t ) : m_t( t ) {};

  inline const VLArray<Ret>& Get() const noexcept { return m_t; };
  inline void Set( const VLArray<Ret>& t ) { return m_t = t; }

};

template <typename Ret>
class CppClassForTerm<NestedArrayTypeOfComputableFunction<Ret> >
{

private:
  VLTree<Ret> m_t;

public:
  inline CppClassForTerm<NestedArrayTypeOfComputableFunction<Ret> >( const VLTree<Ret>& t ) : m_t( t ) {};

  inline const VLTree<Ret>& Get() const noexcept { return m_t; };
  inline void Set( const VLTree<Ret>& t ) { return m_t = t; }

};

template <typename... Args>
class CppClassForTerm<DirectProductTypeOfComputableFunction<Args...> >
{

private:
  DirectProduct<Args...> m_t;

public:
  inline CppClassForTerm<DirectProductTypeOfComputableFunction<Args...> >( const DirectProduct<Args...>& t ) : m_t( t ) {};
  inline CppClassForTerm<DirectProductTypeOfComputableFunction<Args...> >( const Args&... args ) : m_t( args... ) {};

  inline const DirectProduct<Args...>& Get() const noexcept { return m_t; };
  inline void Set( const DirectProduct<Args...>& t ) { return m_t = t; }
  inline void Set( const Args&... args ) { return m_t = DirectProduct<Args...>( args... ); }

};

