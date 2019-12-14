// Constructor/a_Body.hpp

#pragma once
#include "a.hpp"

#include "../../a_Body.hpp"

template <typename T , typename... Args>
TYPE_OF_CONSTRUCTOR_VALID Construct( const Args&... args )
{

  return T( args... );

}

template <typename T , typename... Args>
TYPE_OF_CONSTRUCTOR_INVALID Construct( const Args&... args )
{

  ERR_IMPUT( typeid( T ) , args... );
  return T();

}
