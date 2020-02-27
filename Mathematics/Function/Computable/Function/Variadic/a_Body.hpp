// c:/Users/user/Documents/Programming/Mathematics/Function/Computable/Function/Variadic/a_Body.hpp

#pragma once
#include "a.hpp"

#include "../a_Body.hpp"
#include "../../Expression/List/a_Body.hpp"

template <typename Ret, typename... Args> inline VariadicFunctionSymbol<Ret,Args...>::VariadicFunctionSymbol( const string& f , const VariableSymbol<Args>&... args ) : FunctionSymbol<Ret,Args...,void>( f , args... , LdotsSymbol() ) {}


template <typename Ret, typename... Args> template <typename... VA> inline ExpressionOfComputableFunction<Ret> VariadicFunctionSymbol<Ret,Args...>::operator()( const ExpressionOfComputableFunction<Args>&... args , const ListExpressionOfComputableFunction<VA...>& va ) const { return ExpressionOfComputableFunction<Ret>( *this , args... , va ); }


DEFINITION_OF_VARIADIC_FUNCTION_SYMBOL( Plus );
DEFINITION_OF_VARIADIC_FUNCTION_SYMBOL( Times );
DEFINITION_OF_VARIADIC_FUNCTION_SYMBOL_APPLICATION_ONE_MORE( Plus );
DEFINITION_OF_VARIADIC_FUNCTION_SYMBOL_APPLICATION_ONE_MORE( Times );


DEFINITION_OF_GLOBAL_CONSTANT_STRING_FOR_SYMBOL( Plus , + );
DEFINITION_OF_GLOBAL_CONSTANT_STRING_FOR_SYMBOL( Times , \\times );
DEFINITION_OF_GLOBAL_CONSTANT_STRING_FOR_SYMBOL( Land , \\land );
DEFINITION_OF_GLOBAL_CONSTANT_STRING_FOR_SYMBOL( Lor , \\lor );
