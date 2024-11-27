// c:/Users/user/Documents/Programming/Mathematics/Function/Computable/Type/Guide/Base/a.hpp

#pragma once
#include "a_Macro.hpp"

#include "../../a.hpp"
#include "../../../../../../Utility/WrappedType/a.hpp"

#include "../Valid/a.hpp"
#include "../../../../../SetTheory/EmptySet/a.hpp"
#include "a_Alias.hpp"

template <typename T>
class BaseTypeOf :
  public EmptySet
{

public:
  using type = decltype( BaseTypeOf_Body::GetType( WrappedTypes<T>() ) );

};

template <typename T> inline const TypeOfComputableFunction& BaseType();
