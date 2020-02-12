// c:/Users/user/Documents/Programming/Mathematics/Function/Computable/Definition/Line/Void/a_Body.hpp

#pragma once
#include "a.hpp"
#include "../a_Body.hpp"

DEFINITION_OF_LIST( void );

// PUT
template <typename T> inline LineOfDefinitionOfComputableFunction<void>::LineOfDefinitionOfComputableFunction( const VariableSymbol<T>& x , const ExpressionOfComputableFunction<T>& t ) : SyntaxOfComputableFunction( "line" , "put" , x.Name() , t.Get() ) {}
template <typename T> inline LineOfDefinitionOfComputableFunction<void>::LineOfDefinitionOfComputableFunction( const VariableSymbol<T>& x , const T& t ) : LineOfDefinitionOfComputableFunction( x , ExpressionOfComputableFunction<T>( t ) ) {}

// IF
DEFINITION_OF_IF( void );
DEFINITION_OF_SUPPOSE( void );

// FINISH
inline LineOfDefinitionOfComputableFunction<void>::LineOfDefinitionOfComputableFunction() : SyntaxOfComputableFunction( "line" , "finish" ) {}
