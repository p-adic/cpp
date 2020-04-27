// c:/Users/user/Documents/Programming/Mathematics/Function/Computable/Type/TypeName/a_Body.hpp

#pragma once
#include "a.hpp"

#include "../Valid/a_Body.hpp"
#include "../../Syntax/a_Body.hpp"

inline TypeNameOfComputableFunction::TypeNameOfComputableFunction( const SyntaxOfComputableFunction& t ) : SyntaxOfComputableFunction( t ) {}


template <typename T> inline auto GetTypeString() -> typename enable_if<IsBaseType<T>::value,const string&>::type { return IsBaseType<T>::GetName(); }

template <typename T> inline auto GetTypeString() -> typename enable_if<! IsBaseType<T>::value && is_base_of<TypeOfComputableFunction,T>::value,const string&>::type { return T::GetName(); }


template <typename T> inline auto GetTypeSyntax() -> typename enable_if<IsBaseType<T>::value,const SyntaxOfComputableFunction&>::type { static const SyntaxOfComputableFunction t{ TypeString() , BasicString() , GetTypeString<T>() }; return t; }

template <typename T> inline auto GetTypeSyntax() -> typename enable_if<! IsBaseType<T>::value && is_base_of<TypeOfComputableFunction,T>::value,const SyntaxOfComputableFunction&>::type { return T::GetSyntax(); }

template <typename T> inline const TypeNameOfComputableFunction& GetTypeName() { static const TypeNameOfComputableFunction t{ GetTypeSyntax<T>() }; return t; }
