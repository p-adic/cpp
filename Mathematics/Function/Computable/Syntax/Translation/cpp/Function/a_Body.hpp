// c:/Users/user/Documents/Programming/Mathematics/Function/Computable/Syntax/Translation/cpp/Function/a_Body.hpp

#pragma once
#include "a.hpp"

#include "../Type/a_Body.hpp"

template <typename Func>
typename CppClassForArrayise<Func>::type CppClassForArrayise<Func>::operator()( const uint& n ) const
{
  
  typename CppClassForArrayise<Func>::type a{};

  for( uint i = 0 ; i < n ; i++ ){

    a.push_back( m_f( n ) );

  }

  return a;

}

template <typename Func>
typename CppClassForArrayise<Func*>::type CppClassForArrayise<Func*>::operator()( const uint& n ) const
{
  
  typename CppClassForArrayise<Func*>::type a{};

  for( uint i = 0 ; i < n ; i++ ){

    a.push_back( ( *m_p )( n ) );

  }

  return a;

}

template <typename Arg> inline CppClassForFunctionString ArrayiseStringApplication( const Arg& arg ) { return "CppClassForArrayise( &" + WrapInParenthesis( ArgumentString( arg ) ) + " )"; }

template <typename Arg1, typename Arg2, typename... Args> inline CppClassForFunctionString CurryingStringApplication( const Arg1& arg1 , const Arg2& arg2 , const Args&... args ) { return "CppClassForCurrying( &" + arg1.Get() + " , " + ArgumentString( arg2 ) + " )"; }


template <typename Func>
typename CppClassForComposition<Func>::type CppClassForComposition<Func>::operator()( const typename CppClassForComposition<Func>::type& t ) const
{

  if( m_n == 0 ){

    return t;

  }

  auto f = CppClassForComposition<Func>( m_f , m_n - 1 );
  return m_f( f( t ) );

}

template <typename T>
T CppClassForComposition<FunctionPointerType<T,T> >::operator()( const T& t ) const
{

  if( m_n == 0 ){

    return t;

  }

  auto f = CppClassForComposition<FunctionPointerType<T,T> >( m_p , m_n - 1 );
  return ( *m_p )( f( t ) );

}


inline CppClassForFunctionString operator^( const CppClassForFunctionString& func , const CppClassForString& n ) { return "CppClassForComposition( &" + func.Get() + " , " + n.GetTermString() + " )"; }
inline CppClassForFunctionString operator^( const CppClassForFunctionString& func , const uint& n ) { return "CppClassForComposition( &" + func.Get() + " , " + to_string( n ) + " )"; }
