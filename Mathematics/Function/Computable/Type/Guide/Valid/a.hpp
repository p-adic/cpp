// c:/Users/user/Documents/Programming/Mathematics/Function/Computable/Type/Guide/Valid/a.hpp

#pragma once
#include "a_Macro.hpp"

#include "../../a.hpp"
#include "../../../Syntax/a.hpp"
#include "../../../../../SetTheory/EmptySet/a.hpp"

template <typename T>
class IsPrimitiveType :
  public EmptySet
{

public:
  static constexpr const bool value = false;

};

template <typename T>
class IsValidType :
  public EmptySet
{

public:
  static constexpr const bool value = is_base_of<TypeOfComputableFunction,T>::value || IsPrimitiveType<T>::value;

};

DEFINITION_OF_IS_PRIMITIVE( void , Cdots );
DEFINITION_OF_IS_PRIMITIVE( int , Int );
DEFINITION_OF_IS_PRIMITIVE( bool , Bool );
DEFINITION_OF_IS_PRIMITIVE( string , String );
