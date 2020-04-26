// c:/Users/user/Documents/Programming/Mathematics/Function/Computable/Type/TypeName/a.hpp

#pragma once
#include "../Valid/a.hpp"
#include "../../Syntax/a.hpp"

class TypeNameOfComputableFunction :
  public SyntaxOfComputableFunction
{

public:
  inline TypeNameOfComputableFunction( const SyntaxOfComputableFunction& t );

};


template <typename T> inline auto GetName() -> typename enable_if<IsBaseType<T>::value,const string&>::type;
template <typename T> inline auto GetName() -> typename enable_if<! IsBaseType<T>::value && is_base_of<TypeOfComputableFunction,T>::value,const string&>::type;

template <typename T> inline auto GetSyntax() -> typename enable_if<IsBaseType<T>::value,const SyntaxOfComputableFunction&>::type;
template <typename T> inline auto GetSyntax() -> typename enable_if<! IsBaseType<T>::value && is_base_of<TypeOfComputableFunction,T>::value,const SyntaxOfComputableFunction&>::type;

template <typename T> inline const TypeNameOfComputableFunction& GetTypeName();
