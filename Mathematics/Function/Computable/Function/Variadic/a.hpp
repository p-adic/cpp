// c:/Users/user/Documents/Programming/Mathematics/Function/Computable/Function/Variadic/a.hpp

#pragma once
#include "a_Macro.hpp"

#include "../a.hpp"
#include "../../Expression/List/a.hpp"

template <typename Ret, typename... Args>
class VariadicFunctionSymbol :
  public FunctionSymbol<Ret,Args...,void>
{

public:
  inline VariadicFunctionSymbol( const string& f , const VariableSymbol<Args>&... args );
  inline VariadicFunctionSymbol( const string& f , const SeparatorOfComputableFunction& s , const VariableSymbol<Args>&... args );

  template <typename... VA> inline ExpressionOfComputableFunction<Ret> operator()( const ExpressionOfComputableFunction<Args>&... args , const ListExpressionOfComputableFunction<VA...>& va ) const;

};


DECLARATION_OF_VARIADIC_FUNCTION_SYMBOL( Plus );
DECLARATION_OF_VARIADIC_FUNCTION_SYMBOL( Times );
DECLARATION_OF_VARIADIC_FUNCTION_SYMBOL_APPLICATION_ALL( Plus );
DECLARATION_OF_VARIADIC_FUNCTION_SYMBOL_APPLICATION_ALL( Times );

DECLARATION_OF_VARIADIC_LOGICAL_CONNECTIVE( Land );
DECLARATION_OF_VARIADIC_LOGICAL_CONNECTIVE( Lor );
DECLARATION_OF_VARIADIC_LOGICAL_CONNECTIVE_APPLICATION_ALL( Land );
DECLARATION_OF_VARIADIC_LOGICAL_CONNECTIVE_APPLICATION_ALL( Lor );

DECLARATION_OF_GLOBAL_CONSTANT_STRING_FOR_SYMBOL( Empty );
DECLARATION_OF_GLOBAL_CONSTANT_STRING_FOR_SYMBOL( Space );
