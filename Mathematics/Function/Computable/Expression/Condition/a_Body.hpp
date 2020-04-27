// c:/Users/user/Documents/Programming/Mathematics/Function/Computable/Expression/Condition/a_Body.hpp

#pragma once
#include "a.hpp"
#include "../a_Body.hpp"
#include "../../Function/Variadic/a_Body.hpp"

// variable
inline ExpressionOfComputableFunction<bool>::ExpressionOfComputableFunction( const int& dummy , const string& x , const TypeNameOfComputableFunction& type_name ) : SyntaxOfComputableFunction( ExpressionString() , VariableString() , x , type_name.Get() ) {}

// constant
inline ExpressionOfComputableFunction<bool>::ExpressionOfComputableFunction( const bool& t ) : SyntaxOfComputableFunction( ExpressionString() , ConstantString() , to_string( t ) , GetTypeSyntax<bool>().Get() ) {}

// function
template <typename... Args> inline ExpressionOfComputableFunction<bool>::ExpressionOfComputableFunction( const FunctionSymbol<bool,Args...>& f , const ExpressionOfComputableFunction<Args>&... args ) : SyntaxOfComputableFunction( ExpressionString() , FunctionString() ) { PushFunctionExpression( f , args... ); }

// variadic function
template <typename... Args, typename... VA> inline ExpressionOfComputableFunction<bool>::ExpressionOfComputableFunction( const VariadicFunctionSymbol<bool,Args...>& f , const ExpressionOfComputableFunction<VA>&... va ) : SyntaxOfComputableFunction( ExpressionString() , FunctionString() ) { PushFunctionExpression( f , va... ); }

// relation
template <typename... Args> inline ExpressionOfComputableFunction<bool>::ExpressionOfComputableFunction( const RelationSymbol<Args...>& r , const ExpressionOfComputableFunction<Args>&... args ) : SyntaxOfComputableFunction( ExpressionString() , RelationString()  ) { PushRelationExpression( r , args... ); }

// variadic relation
template <typename... Args, typename... VA> inline ExpressionOfComputableFunction<bool>::ExpressionOfComputableFunction( const VariadicRelationSymbol<bool,Args...>& r , const ExpressionOfComputableFunction<VA>&... va ) : SyntaxOfComputableFunction( ExpressionString() , RelationString() ) { PushFunctionExpression( r , va... ); }


template <typename... Args, typename... VA>
inline void ConditionOfComputableFunction::PushFunctionExpression( const FunctionSymbol<bool,Args...>& f , const ExpressionOfComputableFunction<VA>&... va ) { PushFunctionExpression( f , va.Get()... ); }

template <typename... Args, typename... VA>
auto ConditionOfComputableFunction::PushFunctionExpression( const FunctionSymbol<bool,Args...>& f , const VA&... va ) -> typename enable_if<conjunction<is_same<VLTree<string>,VA>...>::value,void>::type
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

template <typename... Args, typename... VA>
inline void ConditionOfComputableFunction::PushRelationExpression( const RelationSymbol<Args...>& r , const ExpressionOfComputableFunction<VA>&... va ) { PushRelationExpression( r , va.Get()... ); }

template<typename... Args, typename... VA>
auto ConditionOfComputableFunction::PushRelationExpression( const RelationSymbol<Args...>& r , const VA&... va ) -> typename enable_if<conjunction<is_same<VLTree<string>,VA>...>::value,void>::type
{

  VLTree<string> t_va{};
  t_va.push_RightMost( va... );

  TRY_CATCH
    (
     
     Ref().push_RightMost( FunctionExpressionToString( r , t_va ) , r.GetSubTree( 2 ) , r.Get() , va... ) ,

     const ErrorType& e ,

     CALL_P( e , r , va... )

     );

  return;
  
}


template <typename Ret> DEFINITION_OF_BASIC_RELATION( Ret , == , Eq );
DEFINITION_OF_BASIC_RELATION( int , == , Eq );
DEFINITION_OF_BASIC_RELATION( string , == , Eq );
DEFINITION_OF_BASIC_RELATION( bool , == , Equiv );

template <typename Ret> DEFINITION_OF_BASIC_RELATION( Ret , != , Neq );
DEFINITION_OF_BASIC_RELATION( int , != , Neq );
DEFINITION_OF_BASIC_RELATION( string , != , Neq );
DECLARATION_OF_BASIC_RELATION( bool , != ){ return NegSymbolApplication( EquivSymbolApplication( e1 , e2 ) ); }

template <typename Ret> DEFINITION_OF_BASIC_RELATION( Ret , <= , Leq );
DEFINITION_OF_BASIC_RELATION( int , <= , Leq );

template <typename Ret> DEFINITION_OF_BASIC_RELATION( Ret , >= , Geq );
DEFINITION_OF_BASIC_RELATION( int , >= , Geq );

template <typename Ret> DEFINITION_OF_BASIC_RELATION( Ret , < , Lneq );
DEFINITION_OF_BASIC_RELATION( int , < , Lneq );

template <typename Ret> DEFINITION_OF_BASIC_RELATION( Ret , > , Gneq );
DEFINITION_OF_BASIC_RELATION( int , > , Gneq );

inline ConditionOfComputableFunction operator!( const ConditionOfComputableFunction& b ){ return NegSymbolApplication( b ); }
DEFINITION_OF_BASIC_RELATION( bool , && , Land );
DEFINITION_OF_BASIC_RELATION( bool , || , Lor );
DEFINITION_OF_BASIC_RELATION( bool , >> , To );
DEFINITION_OF_BASIC_RELATION( bool , ->* , To );
DEFINITION_OF_BASIC_RELATION( bool , << , Ot );
