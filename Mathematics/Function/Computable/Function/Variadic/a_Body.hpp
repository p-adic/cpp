// c:/Users/user/Documents/Programming/Mathematics/Function/Computable/Function/Variadic/a_Body.hpp

#pragma once
#include "a.hpp"

#include "../a_Body.hpp"
#include "../../Expression/List/a_Body.hpp"

template <typename Ret, typename... Args> inline VariadicFunctionSymbol<Ret,Args...>::VariadicFunctionSymbol( const string& f , const VariableSymbol<Args>&... args ) : VariadicFunctionSymbol( f , SeparatorOfComputableFunction( f , sizeof...( Args ) , true ) , args... ) {}

template <typename Ret, typename... Args> inline VariadicFunctionSymbol<Ret,Args...>::VariadicFunctionSymbol( const string& f , const SeparatorOfComputableFunction& s , const VariableSymbol<Args>&... args ) : FunctionSymbol<Ret,Args...,void>( f , s , args... , LdotsSymbol() ) {}

template <typename Ret, typename... Args> template <typename... VA> inline ExpressionOfComputableFunction<Ret> VariadicFunctionSymbol<Ret,Args...>::operator()( const ExpressionOfComputableFunction<Args>&... args , const ListExpressionOfComputableFunction<VA...>& va ) const { return ExpressionOfComputableFunction<Ret>( *this , args... , va ); }


template <typename Ret> DEFINITION_OF_VARIADIC_FUNCTION_SYMBOL( Ret , Plus , Plus );
DEFINITION_OF_VARIADIC_FUNCTION_SYMBOL( string , Plus , Frown );

template <typename Ret> DEFINITION_OF_VARIADIC_FUNCTION_SYMBOL( Ret , Times , Times );

template <typename Ret> DEFINITION_OF_VARIADIC_FUNCTION_SYMBOL_APPLICATION_ONE( Ret , Plus );
template <typename Ret, typename... Args> DEFINITION_OF_VARIADIC_FUNCTION_SYMBOL_APPLICATION_MORE( Ret , Plus );

template <typename Ret> DEFINITION_OF_VARIADIC_FUNCTION_SYMBOL_APPLICATION_ONE( Ret , Times );
template <typename Ret, typename... Args> DEFINITION_OF_VARIADIC_FUNCTION_SYMBOL_APPLICATION_MORE( Ret , Times );


DEFINITION_OF_VARIADIC_LOGICAL_CONNECTIVE( Land );
DEFINITION_OF_VARIADIC_LOGICAL_CONNECTIVE( Lor );

DEFINITION_OF_VARIADIC_LOGICAL_CONNECTIVE_APPLICATION_ONE( Land );
DEFINITION_OF_VARIADIC_LOGICAL_CONNECTIVE_APPLICATION_MORE( Land );

DEFINITION_OF_VARIADIC_LOGICAL_CONNECTIVE_APPLICATION_ONE( Lor );
DEFINITION_OF_VARIADIC_LOGICAL_CONNECTIVE_APPLICATION_MORE( Lor );
