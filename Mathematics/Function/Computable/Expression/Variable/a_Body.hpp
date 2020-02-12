// c:/Users/user/Documents/Programming/Mathematics/Function/Computable/Variable/a_Body.hpp

#pragma once
#include "a.hpp"
#include "../a_Body.hpp"

template <typename T> inline VariableSymbol<T>::VariableSymbol( const string& x ) : ExpressionOfComputableFunction<T>( 0 , x ) {}
