// c:/Users/user/Documents/Programming/Mathematics/Function/Computable/Type/Base/a.hpp

#pragma once
#include "a_Macro.hpp"

#include "../Valid/a.hpp"

template <typename T>
class BaseTypeOf :
  public EmptySet
{

public:
  using type = typename enable_if<IsValidType<T>::value, typename T::type>::type;

};

DEFINITION_OF_BASE_TYPE( int );
DEFINITION_OF_BASE_TYPE( string );
DEFINITION_OF_BASE_TYPE( bool );
