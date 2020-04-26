// c:/Users/user/Documents/Programming/Mathematics/Function/Computable/Type/Valid/a.hpp

#pragma once
#include "a_Macro.hpp"

#include "../a.hpp"
#include "../../../../SetTheory/EmptySet/a.hpp"

template <typename T>
class IsBaseType :
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
  static constexpr const bool value = is_base_of<TypeOfComputableFunction,T>::value || IsBaseType<T>::value;

};

DEFINITION_OF_IS_BASE( void , Cdots );
DEFINITION_OF_IS_BASE( int , Int );
DEFINITION_OF_IS_BASE( bool , Bool );
DEFINITION_OF_IS_BASE( string , String );
