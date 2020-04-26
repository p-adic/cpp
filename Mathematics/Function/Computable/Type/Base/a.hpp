// c:/Users/user/Documents/Programming/Mathematics/Function/Computable/Type/Base/a.hpp

#pragma once
#include "a_Macro.hpp"

#include "../a.hpp"


template <typename T>
class BaseTypeOf :
  public EmptySet
{

public:
  using type = typename enable_if<is_base_of<TypeOfComputableFunction,T>::value, typename T::type>::type;

};

DEFINITION_OF_BASE_TYPE_OF( int );
DEFINITION_OF_BASE_TYPE_OF( string );
DEFINITION_OF_BASE_TYPE_OF( bool );

inline const int& infty() noexcept;

template <typename T> inline const TypeOfComputableFunction& BaseType();
