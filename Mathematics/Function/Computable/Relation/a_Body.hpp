// c:/Users/user/Documents/Programming/Mathematics/Function/Computable/Relation/a_Body.hpp

#pragma once
#include "a.hpp"

#include "../Function/a_Body.hpp"
#include "../Syntax/a_Body.hpp"

template <typename... ARGS> inline RelationSymbol<ARGS...>::RelationSymbol( const string& r , const VariableSymbol<ARGS>&... args ) : SyntaxOfComputableFunction( NestString() , RelationString() , r , args.Get()... ) {}


template <typename... ARGS> inline ConditionOfComputableFunction RelationSymbol<ARGS...>::operator()( const ExpressionOfComputableFunction<ARGS>&... args ) const { return ConditionOfComputableFunction( *this , args... ); }

DEFINITION_OF_RELATION_SYMBOL( Eq , eq );
DEFINITION_OF_RELATION_SYMBOL( Neq , neq );
DEFINITION_OF_RELATION_SYMBOL( Leq , leq );
DEFINITION_OF_RELATION_SYMBOL( Geq , geq );
DEFINITION_OF_RELATION_SYMBOL( Lneq , lneq );
DEFINITION_OF_RELATION_SYMBOL( Gneq , gneq );

DEFINITION_OF_RELATION_SYMBOL_APPLICATION( Eq );
DEFINITION_OF_RELATION_SYMBOL_APPLICATION( Neq );
DEFINITION_OF_RELATION_SYMBOL_APPLICATION( Leq );
DEFINITION_OF_RELATION_SYMBOL_APPLICATION( Geq );
DEFINITION_OF_RELATION_SYMBOL_APPLICATION( Lneq );
DEFINITION_OF_RELATION_SYMBOL_APPLICATION( Gneq );


DEFINITION_OF_GLOBAL_CONSTANT_STRING_FOR_SYMBOL( Relation , relation );

DEFINITION_OF_GLOBAL_CONSTANT_STRING_FOR_SYMBOL( Eq , = );
DEFINITION_OF_GLOBAL_CONSTANT_STRING_FOR_SYMBOL( Neq , \\neq );
DEFINITION_OF_GLOBAL_CONSTANT_STRING_FOR_SYMBOL( Leq , \\leq );
DEFINITION_OF_GLOBAL_CONSTANT_STRING_FOR_SYMBOL( Geq , \\geq );
DEFINITION_OF_GLOBAL_CONSTANT_STRING_FOR_SYMBOL( Lneq , < );
DEFINITION_OF_GLOBAL_CONSTANT_STRING_FOR_SYMBOL( Gneq , > );
