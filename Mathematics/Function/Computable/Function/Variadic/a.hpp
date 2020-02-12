// c:/Users/user/Documents/Programming/Mathematics/Function/Computable/Function/Variadic/a.hpp

#pragma once
#include "a_Macro.hpp"

#include "../a.hpp"

template <typename Ret, typename... ARGS>
class VariadicFunctionSymbol :
  public FunctionSymbol<Ret,ARGS...,void>
{

public:
  inline VariadicFunctionSymbol( const string& f , const VariableSymbol<ARGS>&... args );

  template <typename... VA> inline ExpressionOfComputableFunction<Ret> operator()( const ExpressionOfComputableFunction<ARGS>&... args , const ExpressionOfComputableFunction<VA>&... va ) const;

};


DECLARATION_OF_VARIADIC_FUNCTION_SYMBOL( Plus );
DECLARATION_OF_VARIADIC_FUNCTION_SYMBOL( Times );
DECLARATION_OF_VARIADIC_FUNCTION_SYMBOL_APPLICATION_ALL( Plus );
DECLARATION_OF_VARIADIC_FUNCTION_SYMBOL_APPLICATION_ALL( Times );

DECLARATION_OF_VARIADIC_LOGICAL_CONNECTIVE( Land );
DECLARATION_OF_VARIADIC_LOGICAL_CONNECTIVE( Lor );
DECLARATION_OF_VARIADIC_LOGICAL_CONNECTIVE_APPLICATION_ALL( Land );
DECLARATION_OF_VARIADIC_LOGICAL_CONNECTIVE_APPLICATION_ALL( Lor );
