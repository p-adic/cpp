// c:/Users/user/Documents/Programming/Mathematics/Function/Computable/Function/a.hpp

#pragma once

#include "a_Macro.hpp"

#include "../Expression/Condition/a.hpp"
#include "../Expression/Variable/Variadic/a.hpp"
#include "../Separator/a.hpp"
#include "../Type/Basic/a.hpp"


template <typename Ret, typename... Args>
class FunctionSymbol :
  public SyntaxOfComputableFunction
{

public:
  inline FunctionSymbol( const string& f , const VariableSymbol<Args>&... args );
  FunctionSymbol( const string& f , const SeparatorOfComputableFunction& s , const VariableSymbol<Args>&... args );

  void SetSeparator( const SeparatorOfComputableFunction& s );
  template <typename... VA> inline auto SetSeparator( const VA&... va ) -> typename enable_if<conjunction<is_same<VA,string>...>::value,void>::type;

  inline ExpressionOfComputableFunction<Ret> operator()( const ExpressionOfComputableFunction<Args>&... args ) const;

};


DECLARATION_OF_FUNCTION_SYMBOL( Minus );
DECLARATION_OF_FUNCTION_SYMBOL( Slash );
DECLARATION_OF_FUNCTION_SYMBOL( Mod );

DECLARATION_OF_FUNCTION_SYMBOL_APPLICATION( Minus );
DECLARATION_OF_FUNCTION_SYMBOL_APPLICATION( Slash );
DECLARATION_OF_FUNCTION_SYMBOL_APPLICATION( Mod );

inline const FunctionSymbol<bool,bool>& NegSymbol();
DECLARATION_OF_LOGICAL_CONNECTIVE( To );
DECLARATION_OF_LOGICAL_CONNECTIVE( Equiv );

ConditionOfComputableFunction NegSymbolApplication( const ConditionOfComputableFunction& b );
DECLARATION_OF_LOGICAL_CONNECTIVE_APPLICATION( To );
DECLARATION_OF_LOGICAL_CONNECTIVE_APPLICATION( Equiv );


DECLARATION_OF_GLOBAL_CONSTANT_STRING_FOR_SYMBOL( Nest );
DECLARATION_OF_GLOBAL_CONSTANT_STRING_FOR_SYMBOL( Function );

DECLARATION_OF_GLOBAL_CONSTANT_STRING_FOR_SYMBOL( Minus );
DECLARATION_OF_GLOBAL_CONSTANT_STRING_FOR_SYMBOL( Slash );
DECLARATION_OF_GLOBAL_CONSTANT_STRING_FOR_SYMBOL( Mod );
DECLARATION_OF_GLOBAL_CONSTANT_STRING_FOR_SYMBOL( Neg );
DECLARATION_OF_GLOBAL_CONSTANT_STRING_FOR_SYMBOL( To );
DECLARATION_OF_GLOBAL_CONSTANT_STRING_FOR_SYMBOL( Equiv );
DECLARATION_OF_GLOBAL_CONSTANT_STRING_FOR_SYMBOL( Empty );
DECLARATION_OF_GLOBAL_CONSTANT_STRING_FOR_SYMBOL( Space );
