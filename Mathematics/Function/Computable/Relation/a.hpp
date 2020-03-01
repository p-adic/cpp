// c:/Users/user/Documents/Programming/Mathematics/Function/Computable/Relation/a.hpp

#pragma once
#include "a_Macro.hpp"

#include "../Function/a.hpp"

template <typename... Args>
class RelationSymbol :
  public SyntaxOfComputableFunction
{

public:
  inline RelationSymbol( const string& r , const VariableSymbol<Args>&... args );
  RelationSymbol( const string& r , const SeparatorOfComputableFunction& s , const VariableSymbol<Args>&... args );

  template <typename... VA> auto SetSeparator( const VA&... va ) -> typename enable_if<conjunction<is_same<VA,string>...>::value,void>::type;

  inline ConditionOfComputableFunction operator()( const ExpressionOfComputableFunction<Args>&... args ) const;

};

DECLARATION_OF_RELATION_SYMBOL( Eq );
DECLARATION_OF_RELATION_SYMBOL( Neq );
DECLARATION_OF_RELATION_SYMBOL( Leq );
DECLARATION_OF_RELATION_SYMBOL( Geq );
DECLARATION_OF_RELATION_SYMBOL( Lneq );
DECLARATION_OF_RELATION_SYMBOL( Gneq );

DECLARATION_OF_RELATION_SYMBOL_APPLICATION( Eq );
DECLARATION_OF_RELATION_SYMBOL_APPLICATION( Neq );
DECLARATION_OF_RELATION_SYMBOL_APPLICATION( Leq );
DECLARATION_OF_RELATION_SYMBOL_APPLICATION( Geq );
DECLARATION_OF_RELATION_SYMBOL_APPLICATION( Lneq );
DECLARATION_OF_RELATION_SYMBOL_APPLICATION( Gneq );


DECLARATION_OF_GLOBAL_CONSTANT_STRING_FOR_SYMBOL( Relation );

DECLARATION_OF_GLOBAL_CONSTANT_STRING_FOR_SYMBOL( Eq );
DECLARATION_OF_GLOBAL_CONSTANT_STRING_FOR_SYMBOL( Neq );
DECLARATION_OF_GLOBAL_CONSTANT_STRING_FOR_SYMBOL( Leq );
DECLARATION_OF_GLOBAL_CONSTANT_STRING_FOR_SYMBOL( Geq );
DECLARATION_OF_GLOBAL_CONSTANT_STRING_FOR_SYMBOL( Lneq );
DECLARATION_OF_GLOBAL_CONSTANT_STRING_FOR_SYMBOL( Gneq );
