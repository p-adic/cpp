// c:/Users/user/Documents/Programming/Mathematics/Function/Computable/Expression/Condition/a_Body.hpp

#pragma once
#include "a.hpp"
#include "../a_Body.hpp"


// variable
inline ExpressionOfComputableFunction<bool>::ExpressionOfComputableFunction( const int& dummy , const string& x ) : SyntaxOfComputableFunction( "variable_expression" , x ) {}

// constant
inline ExpressionOfComputableFunction<bool>::ExpressionOfComputableFunction( const bool& t ) : SyntaxOfComputableFunction( "constant_expression" , to_string( t ) ) {}

// function
template <typename... ARGS> inline ExpressionOfComputableFunction<bool>::ExpressionOfComputableFunction( const FunctionSymbol<bool,ARGS...>& f , const ExpressionOfComputableFunction<ARGS>&... args ) : SyntaxOfComputableFunction( "function_expression" , f.Name() , f.Get() , args.Get()... ) {}

// variadic function
template <typename... ARGS, typename... VA> inline ExpressionOfComputableFunction<bool>::ExpressionOfComputableFunction( const VariadicFunctionSymbol<bool,ARGS...>& f , const ExpressionOfComputableFunction<ARGS>&... args , const ExpressionOfComputableFunction<VA>&... va ) : SyntaxOfComputableFunction( "variadic_function_expression" , f.Name() , f.Get() , args.Get()... , va.Get()... ) {}

// relation
template <typename... ARGS> inline ExpressionOfComputableFunction<bool>::ExpressionOfComputableFunction( const RelationSymbol<ARGS...>& r , const ExpressionOfComputableFunction<ARGS>&... args ) : SyntaxOfComputableFunction( "relation_expression" , r.Name() , r.Get() , args.Get()... ) {}

// variadic relation
template <typename... ARGS, typename... VA> inline ExpressionOfComputableFunction<bool>::ExpressionOfComputableFunction( const VariadicRelationSymbol<ARGS...>& r , const ExpressionOfComputableFunction<ARGS>&... args , const ExpressionOfComputableFunction<VA>&... va ) : SyntaxOfComputableFunction( "variadic_relation_expression" , r.Name() , r.Get() , args.Get()... , va.Get()... ) {}


inline ConditionOfComputableFunction operator==( const ExpressionOfComputableFunction<bool>& e1 , const ExpressionOfComputableFunction<bool>& e2 ){ return EQUIV( e1 , e2 ); }
inline ConditionOfComputableFunction operator!=( const ExpressionOfComputableFunction<bool>& e1 , const ExpressionOfComputableFunction<bool>& e2 ){ return NEG( EQUIV( e1 , e2 ) ); }

template <typename Ret> inline ConditionOfComputableFunction operator==( const ExpressionOfComputableFunction<Ret>& e1 , const ExpressionOfComputableFunction<Ret>& e2 ){ return EQ( e1 , e2 ); }
template <typename Ret> inline ConditionOfComputableFunction operator!=( const ExpressionOfComputableFunction<Ret>& e1 , const ExpressionOfComputableFunction<Ret>& e2 ){ return NEQ( e1 , e2 ); }
template <typename Ret> inline ConditionOfComputableFunction operator<=( const ExpressionOfComputableFunction<Ret>& e1 , const ExpressionOfComputableFunction<Ret>& e2 ){ return LEQ( e1 , e2 ); }
template <typename Ret> inline ConditionOfComputableFunction operator>=( const ExpressionOfComputableFunction<Ret>& e1 , const ExpressionOfComputableFunction<Ret>& e2 ){ return GEQ( e1 , e2 ); }
template <typename Ret> inline ConditionOfComputableFunction operator<( const ExpressionOfComputableFunction<Ret>& e1 , const ExpressionOfComputableFunction<Ret>& e2 ){ return LNEQ( e1 , e2 ); }
template <typename Ret> inline ConditionOfComputableFunction operator>( const ExpressionOfComputableFunction<Ret>& e1 , const ExpressionOfComputableFunction<Ret>& e2 ){ return GNEQ( e1 , e2 ); }


inline ConditionOfComputableFunction operator!( const ConditionOfComputableFunction& b ){ return NEG( b ); }
inline ConditionOfComputableFunction operator&&( const ConditionOfComputableFunction& b1 , const ConditionOfComputableFunction& b2 ){ return LAND( b1 , b2 ); }
inline ConditionOfComputableFunction operator||( const ConditionOfComputableFunction& b1 , const ConditionOfComputableFunction& b2 ){ return LOR( b1 , b2 ); }
