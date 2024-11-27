// c:/Users/user/Documents/Programming/Mathematics/Function/Computable/Definition/Line/Void/a_Body.hpp

#pragma once
#include "a.hpp"
#include "../a_Body.hpp"
#include "../../../../../../Utility/WrappedType/a_Body.hpp"


DEFINITION_OF_LIST_OF_LINES( void );

// PUT
template <typename T1, typename T2> inline LineOfDefinitionOfComputableFunction<void>::LineOfDefinitionOfComputableFunction( const VariableSymbol<T1>& x , const T2& t ) : SyntaxOfComputableFunction( LineString() , PutString() , x.Get() , ExpressionOfComputableFunction<T1>( t ).Get() ) {}

template <typename T1, typename T2> inline LineOfDefinitionOfComputableFunction<void>::LineOfDefinitionOfComputableFunction( const VariableSymbol<T1>& x , const string& characterisation , const VariableSymbol<T2>& n , const VariableSymbol<T2>& bound , const ConditionOfComputableFunction& b ) : SyntaxOfComputableFunction( LineString() , CharacteriseString() , x.Get() , characterisation , n.Get() , bound.Get() , b.Get() ) {}

// PRINT
template <typename... ARGS> inline LineOfDefinitionOfComputableFunction<void>::LineOfDefinitionOfComputableFunction( const ListExpressionOfComputableFunction<ARGS...>& args ) : SyntaxOfComputableFunction( LineString() , PrintString() , args.Get() ) {}


// IF
DEFINITION_OF_IF_LINE( void );
DEFINITION_OF_SUPPOSE_LINE( void );

// EXIT
inline LineOfDefinitionOfComputableFunction<void>::LineOfDefinitionOfComputableFunction() : SyntaxOfComputableFunction( LineString() , ExitString() ) {}


template <typename T1, typename T2> inline LineOfDefinitionOfComputableFunction<void> PutLineOfComputableFunction( const VariableSymbol<T1>& x , const T2& t ){ return LineOfDefinitionOfComputableFunction<void>( x , t ); }

template <typename T1, typename T2> inline LineOfDefinitionOfComputableFunction<void> PutLineOfComputableFunction( const VariableSymbol<T1>& x , const string& characterisation , const WrappedType<VariableSymbol<T2> >& n , const WrappedType<VariableSymbol<T2> >& bound , const WrappedType<ConditionOfComputableFunction>& b ){ return LineOfDefinitionOfComputableFunction<void>( x , characterisation , n.Get() , bound.Get() , b.Get() ); }

template <typename... ARGS> inline LineOfDefinitionOfComputableFunction<void> PrintLineOfComputableFunction( const ARGS&... args ){ return LineOfDefinitionOfComputableFunction<void>( ListExpressionOfComputableFunction<ARGS...>( args... ) ); }
