// c:/Users/user/Documents/Programming/Mathematics/Function/Computable/Type/Guide/Primitive/a.hpp

#pragma once
#include "a_Macro.hpp"

#include "../../../../../SetTheory/EmptySet/a.hpp"

template <typename T>
class IsPrimitiveType :
  public EmptySet
{

public:
  static constexpr const bool value = false;

};

#include "../../../Syntax/a.hpp"

DEFINITION_OF_IS_PRIMITIVE( void , Cdots );
DEFINITION_OF_IS_PRIMITIVE( int , Int );
DEFINITION_OF_IS_PRIMITIVE( bool , Bool );
DEFINITION_OF_IS_PRIMITIVE( string , String );
