// c:/Users/user/Documents/Programming/Mathematics/Function/Computable/Function/a_Body.hpp

#pragma once

#include "a.hpp"

#include "../Expression/Condition/a_Body.hpp"
#include "../Expression/Variable/Variadic/a_Body.hpp"
#include "../Type/Basic/a_Body.hpp"

template <typename Ret, typename... Args> inline FunctionSymbol<Ret,Args...>::FunctionSymbol( const string& f , const VariableSymbol<Args>&... args ) : SyntaxOfComputableFunction( NestString() , FunctionString() , f , GetName<Ret>() , ListExpressionOfComputableFunction( args... ).Get() ) {}

template <typename Ret, typename... Args> inline ExpressionOfComputableFunction<Ret> FunctionSymbol<Ret,Args...>::operator()( const ExpressionOfComputableFunction<Args>&... args ) const { return ExpressionOfComputableFunction<Ret>( *this , args... ); }


DEFINITION_OF_FUNCTION_SYMBOL( Minus , MinusString() );
DEFINITION_OF_FUNCTION_SYMBOL( Slash , SlashString() );
DEFINITION_OF_FUNCTION_SYMBOL( Mod , ModString() );

DEFINITION_OF_FUNCTION_SYMBOL_APPLICATION( Minus );
DEFINITION_OF_FUNCTION_SYMBOL_APPLICATION( Slash );
DEFINITION_OF_FUNCTION_SYMBOL_APPLICATION( Mod );

inline const FunctionSymbol<bool,bool>& NegSymbol() { static const FunctionSymbol<bool,bool> f( NegString() , VariableSymbol<bool>( "x" ) ); return f; }
DEFINITION_OF_LOGICAL_CONNECTIVE_APPLICATION( To );
DEFINITION_OF_LOGICAL_CONNECTIVE_APPLICATION( Equiv );


DEFINITION_OF_GLOBAL_CONSTANT_STRING_FOR_SYMBOL( Nest , nest );
DEFINITION_OF_GLOBAL_CONSTANT_STRING_FOR_SYMBOL( Function , function );

DEFINITION_OF_GLOBAL_CONSTANT_STRING_FOR_SYMBOL( Minus , - );
DEFINITION_OF_GLOBAL_CONSTANT_STRING_FOR_SYMBOL( Slash , \\slash );
DEFINITION_OF_GLOBAL_CONSTANT_STRING_FOR_SYMBOL( Mod , % );
DEFINITION_OF_GLOBAL_CONSTANT_STRING_FOR_SYMBOL( Neg , \\neg );
DEFINITION_OF_GLOBAL_CONSTANT_STRING_FOR_SYMBOL( To , \\rightarrow );
DEFINITION_OF_GLOBAL_CONSTANT_STRING_FOR_SYMBOL( Equiv , \\equiv );
