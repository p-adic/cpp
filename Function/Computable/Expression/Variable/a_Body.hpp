// c:/Users/user/Documents/Programming/Mathematics/Function/Computable/Variable/a_Body.hpp

#pragma once
#include "a.hpp"

#include "../List/Body/a_Body.hpp"


template <typename T> inline VariableSymbol<T>::VariableSymbol( const string& x ) : VariableSymbol( x , GetTypeName<T>() ) {}

template <typename T> inline VariableSymbol<T>::VariableSymbol( const string& x , const TypeNameOfComputableFunction& type_name ) : ExpressionOfComputableFunction<T>( 0 , x , type_name ) {}
