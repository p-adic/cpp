// c:/Users/user/Documents/Programming/Mathematics/Function/Computable/Function/Variadic/a_Body.hpp

#pragma once
#include "a.hpp"

#include "../a_Body.hpp"

template <typename Ret, typename... ARGS> inline VariadicFunctionSymbol<Ret,ARGS...>::VariadicFunctionSymbol( const string& f , const VariableSymbol<ARGS>&... args ) : FunctionSymbol<Ret,ARGS...,void>( f , args... , LDOTS ) {}


template <typename Ret, typename... ARGS> template <typename... VA> inline ExpressionOfComputableFunction<Ret> VariadicFunctionSymbol<Ret,ARGS...>::operator()( const ExpressionOfComputableFunction<ARGS>&... args , const ExpressionOfComputableFunction<VA>&... va ) const { return ExpressionOfComputableFunction<Ret>( *this , args... , va... ); }

DEFINITION_OF_VARIADIC_FUNCTION_SYMBOL( Plus );
DEFINITION_OF_VARIADIC_FUNCTION_SYMBOL( Times );
DEFINITION_OF_VARIADIC_FUNCTION_SYMBOL_APPLICATION_ONE_MORE( Plus , 0 );
DEFINITION_OF_VARIADIC_FUNCTION_SYMBOL_APPLICATION_ONE_MORE( Times , 1 );

DEFINITION_OF_VARIADIC_LOGICAL_CONNECTIVE( Land );
DEFINITION_OF_VARIADIC_LOGICAL_CONNECTIVE( Lor );
DEFINITION_OF_VARIADIC_LOGICAL_CONNECTIVE_APPLICATION_ONE_MORE( Land , true );
DEFINITION_OF_VARIADIC_LOGICAL_CONNECTIVE_APPLICATION_ONE_MORE( Lor , false );
