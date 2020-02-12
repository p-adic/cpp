// c:/Users/user/Documents/Programming/Mathematics/Function/Computable/Function/a.hpp

#pragma once

#include "a_Macro.hpp"

#include "../Expression/Condition/a.hpp"
#include "../Expression/Variable/Variadic/a.hpp"
#include "../Syntax/a.hpp"


template <typename Ret, typename... ARGS>
class FunctionSymbol :
  public SyntaxOfComputableFunction
{

public:
  inline FunctionSymbol( const string& f , const VariableSymbol<ARGS>&... args );

  inline ExpressionOfComputableFunction<Ret> operator()( const ExpressionOfComputableFunction<ARGS>&... args ) const;

};


DECLARATION_OF_FUNCTION_SYMBOL( Minus );
DECLARATION_OF_FUNCTION_SYMBOL( Slash );
DECLARATION_OF_FUNCTION_SYMBOL( Mod );

DECLARATION_OF_FUNCTION_SYMBOL_APPLICATION( Minus );
DECLARATION_OF_FUNCTION_SYMBOL_APPLICATION( Slash );
DECLARATION_OF_FUNCTION_SYMBOL_APPLICATION( Mod );

const FunctionSymbol<bool,bool>& NegSymbol();
DECLARATION_OF_LOGICAL_CONNECTIVE( To );
DECLARATION_OF_LOGICAL_CONNECTIVE( Equiv );

ConditionOfComputableFunction NegSymbolApplication( const ConditionOfComputableFunction& b );
DECLARATION_OF_LOGICAL_CONNECTIVE_APPLICATION( To );
DECLARATION_OF_LOGICAL_CONNECTIVE_APPLICATION( Equiv );
