// c:/Users/user/Documents/Programming/Mathematics/Function/Computable/Expression/a_Body.hpp

#pragma once
#include "a.hpp"

#include "List/a.hpp"
#include "../Function/Variadic/a.hpp"
#include "../Relation/Variadic/a.hpp"
#include "../Type/TypeName/a.hpp"

#include "../Syntax/a_Body.hpp"

#include "List/a_Body.hpp"
#include "../Function/Variadic/a_Body.hpp"
#include "../Relation/Variadic/a_Body.hpp"
#include "../Type/TypeName/a_Body.hpp"


// variable
template <typename Ret> inline ExpressionOfComputableFunction<Ret>::ExpressionOfComputableFunction( const int& dummy , const string& x , const TypeNameOfComputableFunction& type_name ) : SyntaxOfComputableFunction( ExpressionString() , VariableString() , x , type_name.Get() ) {}

// constant
template <typename Ret> inline ExpressionOfComputableFunction<Ret>::ExpressionOfComputableFunction( const Ret& t ) : SyntaxOfComputableFunction( ExpressionString(), ConstantString() , to_string( t ) , GetSyntax<Ret>().Get() ) {}

// function
template <typename Ret> template <typename... Args> inline ExpressionOfComputableFunction<Ret>::ExpressionOfComputableFunction( const FunctionSymbol<Ret,Args...>& f , const ExpressionOfComputableFunction<Args>&... args ) : SyntaxOfComputableFunction( ExpressionString() , FunctionString() ) { PushFunctionExpression( f , args... ); }

// variadic function
template <typename Ret> template <typename... Args, typename... VA> inline ExpressionOfComputableFunction<Ret>::ExpressionOfComputableFunction( const VariadicFunctionSymbol<Ret,Args...>& f , const ExpressionOfComputableFunction<VA>&... va ) : SyntaxOfComputableFunction( ExpressionString() , FunctionString() ) { PushFunctionExpression( f , va... ); }


template <typename Ret> template <typename... Args, typename... VA>
inline void ExpressionOfComputableFunction<Ret>::PushFunctionExpression( const FunctionSymbol<Ret,Args...>& f , const ExpressionOfComputableFunction<VA>&... va ) { PushFunctionExpression( f , va.Get()... ); }

template <typename Ret> template <typename... Args, typename... VA>
inline auto ExpressionOfComputableFunction<Ret>::PushFunctionExpression( const FunctionSymbol<Ret,Args...>& f , const VA&... va ) -> typename enable_if<conjunction<is_same<VLTree<string>,VA>...>::value,void>::type
{

  VLTree<string> t_va{};
  t_va.push_RightMost( va... );
  
  TRY_CATCH
    (
     
     Ref().push_RightMost( FunctionExpressionToString( f , t_va ) , f.GetSubTree( 2 ) , f.Get() , va... ) ,

     const ErrorType& e ,

     CALL_P( e , f , va... )

     );

  return;
  
}

template <typename Ret> DEFINITION_OF_BASIC_FUNCTION( Ret , + , Plus );
DEFINITION_OF_BASIC_FUNCTION( int , + , Plus );
DEFINITION_OF_BASIC_FUNCTION( string , + , Plus );
DEFINITION_OF_BASIC_FUNCTION( bool , + , Plus );

template <typename Ret> DEFINITION_OF_BASIC_FUNCTION( Ret , - , Minus );
DEFINITION_OF_BASIC_FUNCTION( int , - , Minus );
DEFINITION_OF_BASIC_FUNCTION( bool , - , Minus );

template <typename Ret> DEFINITION_OF_BASIC_FUNCTION( Ret , * , Times );
DEFINITION_OF_BASIC_FUNCTION( int , * , Times );
DEFINITION_OF_BASIC_FUNCTION( bool , * , Times );

template <typename Ret> DEFINITION_OF_BASIC_FUNCTION( Ret , / , Slash );
DEFINITION_OF_BASIC_FUNCTION( int , / , Slash );

template <typename Ret> DEFINITION_OF_BASIC_FUNCTION( Ret , % , Mod );
DEFINITION_OF_BASIC_FUNCTION( int , % , Mod );

template <typename Ret> DEFINITION_OF_BASIC_FUNCTION( Ret , ^ , Power );
DEFINITION_OF_BASIC_FUNCTION( int , ^ , Power );

inline const ExpressionOfComputableFunction<int>& InftySymbol(){ static const ExpressionOfComputableFunction<int> n = ExpressionOfComputableFunction<int>( infty() ); return n; }
