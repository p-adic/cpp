// c:/Users/user/Documents/Programming/Mathematics/Function/Computable/Expression/a_Body.hpp

#pragma once
#include "a.hpp"
#include "List/a.hpp"
#include "../Function/Variadic/a.hpp"
#include "../Relation/Variadic/a.hpp"

#include "List/a_Body.hpp"
#include "../Syntax/a_Body.hpp"
#include "../Type/Valid/a_Body.hpp"


// variable
template <typename Ret> inline ExpressionOfComputableFunction<Ret>::ExpressionOfComputableFunction( const int& dummy , const string& x ) : SyntaxOfComputableFunction( ExpressionString() , VariableString() , x , GetName<Ret>() ) {}

// constant
template <typename Ret> inline ExpressionOfComputableFunction<Ret>::ExpressionOfComputableFunction( const Ret& t ) : SyntaxOfComputableFunction( ExpressionString(), ConstantString() , to_string( t ) , GetName<Ret>() ) {}

// function
template <typename Ret> template <typename... Args> inline ExpressionOfComputableFunction<Ret>::ExpressionOfComputableFunction( const FunctionSymbol<Ret,Args...>& f , const ExpressionOfComputableFunction<Args>&... args ) : SyntaxOfComputableFunction( ExpressionString() , FunctionString() ) { FunctionExpressionToSyntax( *this , f , args... ); }

// variadic function
template <typename Ret> template <typename... Args, typename... VA> inline ExpressionOfComputableFunction<Ret>::ExpressionOfComputableFunction( const VariadicFunctionSymbol<Ret,Args...>& f , const ExpressionOfComputableFunction<Args>&... args , const ListExpressionOfComputableFunction<VA...>& va ) : SyntaxOfComputableFunction( ExpressionString() , FunctionString() ) { FunctionExpressionToSyntax( *this , f , args... , va ); }

template <typename Ret> inline ExpressionOfComputableFunction<Ret> operator+( const ExpressionOfComputableFunction<Ret>& e1 , const ExpressionOfComputableFunction<Ret>& e2 ){ return PlusSymbolApplication( e1 , e2 ); }
template <typename Ret> inline ExpressionOfComputableFunction<Ret> operator-( const ExpressionOfComputableFunction<Ret>& e1 , const ExpressionOfComputableFunction<Ret>& e2 ){ return MinusSymbolApplication( e1 , e2 ); }
template <typename Ret> inline ExpressionOfComputableFunction<Ret> operator*( const ExpressionOfComputableFunction<Ret>& e1 , const ExpressionOfComputableFunction<Ret>& e2 ){ return TimesSymbolApplication( e1 , e2 ); }
template <typename Ret> inline ExpressionOfComputableFunction<Ret> operator/( const ExpressionOfComputableFunction<Ret>& e1 , const ExpressionOfComputableFunction<Ret>& e2 ){ return SlashSymbolApplication( e1 , e2 ); }
template <typename Ret> inline ExpressionOfComputableFunction<Ret> operator%( const ExpressionOfComputableFunction<Ret>& e1 , const ExpressionOfComputableFunction<Ret>& e2 ){ return ModSymbolApplication( e1 , e2 ); }

inline const ExpressionOfComputableFunction<int>& InftySymbol(){ static const ExpressionOfComputableFunction<int> n = ExpressionOfComputableFunction<int>(infty() ); return n; }

template <typename Ret, typename... Args, typename... VA>
void FunctionExpressionToSyntax( SyntaxOfComputableFunction& t , const FunctionSymbol<Ret,Args...>& f , const ExpressionOfComputableFunction<VA>&... va )
{

  const string& function_name = f.GetNodeString( 2 );
  auto e = ListExpressionOfComputableFunction( va... );
  
  t.Ref().push_RightMost( function_name + e.GetNodeString( 2 ) , GetName<Ret>() , f.Get() , e.Get() );
  
}


DEFINITION_OF_GLOBAL_CONSTANT_STRING_FOR_SYMBOL( Expression , expression );
DEFINITION_OF_GLOBAL_CONSTANT_STRING_FOR_SYMBOL( Variable , variable );
DEFINITION_OF_GLOBAL_CONSTANT_STRING_FOR_SYMBOL( Constant , constant );
