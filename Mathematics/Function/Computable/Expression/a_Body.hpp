// c:/Users/user/Documents/Programming/Mathematics/Function/Computable/Expression/a_Body.hpp

#pragma once
#include "a.hpp"
#include "../Syntax/a_Body.hpp"
// #include "../Function/Variadic/a_Body.hpp"
// #include "../Relation/Variadic/a_Body.hpp"


// variable
template <typename Ret> inline ExpressionOfComputableFunction<Ret>::ExpressionOfComputableFunction( const int& dummy , const string& x ) : SyntaxOfComputableFunction( "variable_expression" , x ) {}

// constant
template <typename Ret> inline ExpressionOfComputableFunction<Ret>::ExpressionOfComputableFunction( const Ret& t ) : SyntaxOfComputableFunction( "constant_expression" , to_string( t ) ) {}

// function
template <typename Ret> template <typename... ARGS> inline ExpressionOfComputableFunction<Ret>::ExpressionOfComputableFunction( const FunctionSymbol<Ret,ARGS...>& f , const ExpressionOfComputableFunction<ARGS>&... args ) : SyntaxOfComputableFunction( "function_expression" , f.Name() , f.Get() , args.Get()... ) {}

// variadic function
template <typename Ret> template <typename... ARGS, typename... VA> inline ExpressionOfComputableFunction<Ret>::ExpressionOfComputableFunction( const VariadicFunctionSymbol<Ret,ARGS...>& f , const ExpressionOfComputableFunction<ARGS>&... args , const ExpressionOfComputableFunction<VA>&... va ) : SyntaxOfComputableFunction( "variadic_function_expression" , f.Name() , f.Get() , args.Get()... , va.Get()... ) {}


template <typename Ret> inline ExpressionOfComputableFunction<Ret> operator+( const ExpressionOfComputableFunction<Ret>& e1 , const ExpressionOfComputableFunction<Ret>& e2 ){ return PLUS( e1 , e2 ); }
template <typename Ret> inline ExpressionOfComputableFunction<Ret> operator-( const ExpressionOfComputableFunction<Ret>& e1 , const ExpressionOfComputableFunction<Ret>& e2 ){ return MINUS( e1 , e2 ); }
template <typename Ret> inline ExpressionOfComputableFunction<Ret> operator*( const ExpressionOfComputableFunction<Ret>& e1 , const ExpressionOfComputableFunction<Ret>& e2 ){ return TIMES( e1 , e2 ); }
template <typename Ret> inline ExpressionOfComputableFunction<Ret> operator/( const ExpressionOfComputableFunction<Ret>& e1 , const ExpressionOfComputableFunction<Ret>& e2 ){ return SLASH( e1 , e2 ); }
template <typename Ret> inline ExpressionOfComputableFunction<Ret> operator%( const ExpressionOfComputableFunction<Ret>& e1 , const ExpressionOfComputableFunction<Ret>& e2 ){ return MOD( e1 , e2 ); }

#include "../Function/Variadic/a_Body.hpp"
#include "../Relation/Variadic/a_Body.hpp"
