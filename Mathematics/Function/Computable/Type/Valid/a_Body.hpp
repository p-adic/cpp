// c:/Users/user/Documents/Programming/Mathematics/Function/Computable/Type/Valid/a_Body.hpp

#pragma once
#include "a.hpp"
#include "../Basic/a_Body.hpp"
#include "../a_Body.hpp"

template <typename T> inline auto GetName() -> typename enable_if<is_base_of<TypeOfComputableFunction,T>::value,const string&>::type { return T::Name(); }
template <typename T> inline auto GetName() -> typename enable_if<IsBasicType<T>::value,const string&>::type { return IsBasicType<T>::Name(); }
