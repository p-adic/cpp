// c:/Users/user/Documents/Programming/Mathematics/Function/Computable/Function/a_Body.hpp

#pragma once

#include "a.hpp"

#include "../Expression/Condition/a_Body.hpp"
#include "../Expression/Variable/Variadic/a_Body.hpp"
#include "../Syntax/a_Body.hpp"


template <typename Ret, typename... ARGS> inline FunctionSymbol<Ret,ARGS...>::FunctionSymbol( const string& f , const VariableSymbol<ARGS>&... args ) : SyntaxOfComputableFunction( "function" , f , args.Get()... ) {}


template <typename Ret, typename... ARGS> inline ExpressionOfComputableFunction<Ret> FunctionSymbol<Ret,ARGS...>::operator()( const ExpressionOfComputableFunction<ARGS>&... args ) const { return ExpressionOfComputableFunction<Ret>( *this , args... ); }


DEFINITION_OF_FUNCTION_SYMBOL( Minus );
DEFINITION_OF_FUNCTION_SYMBOL( Slash );
DEFINITION_OF_FUNCTION_SYMBOL( Mod );

DEFINITION_OF_FUNCTION_SYMBOL_APPLICATION( Minus );
DEFINITION_OF_FUNCTION_SYMBOL_APPLICATION( Slash );
DEFINITION_OF_FUNCTION_SYMBOL_APPLICATION( Mod );

DEFINITION_OF_LOGICAL_CONNECTIVE_APPLICATION( To );
DEFINITION_OF_LOGICAL_CONNECTIVE_APPLICATION( Equiv );
