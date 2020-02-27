// c:/Users/user/Documents/Programming/Mathematics/Function/Computable/Definition/Line/Void/a_Body.hpp

#pragma once
#include "a.hpp"
#include "../a_Body.hpp"

DEFINITION_OF_LIST_OF_LINES( void );

// PUT
template <typename T1, typename T2> inline LineOfDefinitionOfComputableFunction<void>::LineOfDefinitionOfComputableFunction( const VariableSymbol<T1>& x , const T2& t ) : SyntaxOfComputableFunction( LineString() , PutString() , x.Get() , ExpressionOfComputableFunction<T1>( t ).Get() ) {}

template <typename T1, typename T2> inline LineOfDefinitionOfComputableFunction<void> PUT( const VariableSymbol<T1>& x , const T2& t ){ return LineOfDefinitionOfComputableFunction<void>( x , t ); }


// IF
DEFINITION_OF_IF_LINE( void );
DEFINITION_OF_SUPPOSE_LINE( void );

// FINISH
inline LineOfDefinitionOfComputableFunction<void>::LineOfDefinitionOfComputableFunction() : SyntaxOfComputableFunction( LineString() , FinishString() ) {}


DEFINITION_OF_GLOBAL_CONSTANT_STRING_FOR_SYMBOL( Put , put );
DEFINITION_OF_GLOBAL_CONSTANT_STRING_FOR_SYMBOL( Finish , finish );
