// c:/Users/user/Documents/Programming/Mathematics/Function/Computable/Type/Valid/a.hpp

#pragma once
#include "../Basic/a.hpp"
#include "../a.hpp"

template <typename T>
class IsValidType :
  public EmptySet
{

public:
  static constexpr const bool value = is_base_of<TypeOfComputableFunction,T>::value || IsBasicType<T>::value;

};
