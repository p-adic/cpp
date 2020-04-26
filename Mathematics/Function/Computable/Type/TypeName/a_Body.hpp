// c:/Users/user/Documents/Programming/Mathematics/Function/Computable/Type/TypeName/a_Body.hpp

#pragma once
#include "a.hpp"

#include "../a_Body.hpp"
#include "../Valid/a_Body.hpp"
#include "../../Syntax/a_Body.hpp"

inline TypeNameOfComputableFunction::TypeNameOfComputableFunction( const SyntaxOfComputableFunction& t ) : SyntaxOfComputableFunction( t ) {}


template <typename T> inline auto GetName() -> typename enable_if<IsBasicType<T>::value,const string&>::type { return IsBasicType<T>::GetName(); }

template <typename T> inline auto GetName() -> typename enable_if<! IsBasicType<T>::value && is_base_of<TypeOfComputableFunction,T>::value,const string&>::type { return T::GetName(); }


template <typename T> inline auto GetSyntax() -> typename enable_if<IsBasicType<T>::value,const SyntaxOfComputableFunction&>::type { static const SyntaxOfComputableFunction t{ TypeString() , BasicString() , GetName<T>() }; return t; }

template <typename T> inline auto GetSyntax() -> typename enable_if<! IsBasicType<T>::value && is_base_of<TypeOfComputableFunction,T>::value,const SyntaxOfComputableFunction&>::type { return T::GetSyntax(); }

template <typename T> inline const TypeNameOfComputableFunction& GetTypeName() { static const TypeNameOfComputableFunction t{ GetSyntax<T>() }; return t; }
