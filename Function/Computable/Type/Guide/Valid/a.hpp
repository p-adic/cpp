// c:/Users/user/Documents/Programming/Mathematics/Function/Computable/Type/Guide/Valid/a.hpp

#pragma once
#include "../Primitive/a.hpp"
#include "../../a.hpp"
#include "../../../../../SetTheory/EmptySet/a.hpp"

template <typename T>
class IsValidType :
  public EmptySet
{

public:
  static constexpr const bool value = is_base_of<TypeOfComputableFunction,T>::value || IsPrimitiveType<T>::value;

};
