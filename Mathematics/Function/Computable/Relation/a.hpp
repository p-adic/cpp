// c:/Users/user/Documents/Programming/Mathematics/Function/Computable/Relation/a.hpp

#pragma once
#include "a_Macro.hpp"

#include "../Expression/Condition/a.hpp"
#include "../Expression/Variable/Variadic/a.hpp"
#include "../Syntax/a.hpp"

template <typename... ARGS>
class RelationSymbol :
  public SyntaxOfComputableFunction
{

public:
  inline RelationSymbol( const string& r , const VariableSymbol<ARGS>&... args );

  inline ConditionOfComputableFunction operator()( const ExpressionOfComputableFunction<ARGS>&... args ) const;

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
