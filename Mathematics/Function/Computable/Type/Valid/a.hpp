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

template <typename T> inline auto GetName() -> typename enable_if<is_base_of<TypeOfComputableFunction,T>::value,const string&>::type;
template <typename T> inline auto GetName() -> typename enable_if<IsBasicType<T>::value,const string&>::type;
