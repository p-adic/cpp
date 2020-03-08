// c:/Users/user/Documents/Programming/SFINAE/a_Body.hpp

#pragma once
#include "a.hpp"

#include "../Error/IllegalAccess/a_Body.hpp"
#include "../Error/IllegalImput/a_Body.hpp"

template <typename T , typename Ret>
auto to_Value( const T & t ) -> typename FromValueToValue<T,Ret>::type
{

  return t;

}

template <typename T , typename Ret>
auto to_Value( const T & t ) -> typename FromPointerToValue<T,Ret>::type
{

  return ACCESS( t );

}

template <typename T , typename Ret>
auto to_Value( const T & t ) -> typename FromReferenceToValue<T,Ret>::type
{

  return t;

}

template <typename T , typename Ret>
auto to_Value( const T & t ) -> typename InvalidToValue<T,Ret>::type
{

  ERR_IMPUT( t );
  return Ret ();

}

template <typename T , typename Ret>
auto to_ValueOrReference( const T & t ) -> typename FromValueToValueOrReference<T,Ret>::type
{

  return t;

}

template <typename T , typename Ret>
auto to_ValueOrReference( const T & t ) -> typename FromPointerToValueOrReference<T,Ret>::type
{

  return ACCESS( t );

}

template <typename T , typename Ret>
auto to_ValueOrReference( const T & t ) -> typename FromReferenceToValueOrReference<T,Ret>::type
{

  return t;

}

template <typename T , typename Ret>
auto to_ValueOrReference( const T & t ) -> typename InvalidToValueOrReference<T,Ret>::type
{

  ERR_IMPUT( t );
  return Ret ();

}

