// c:/Users/user/Documents/Programming/Mathematics/Function/Computable/Expression/Condition/a_Body.hpp

#pragma once
#include "a.hpp"
#include "../a_Body.hpp"
#include "../../Function/Variadic/a_Body.hpp"

// variable
inline ExpressionOfComputableFunction<bool>::ExpressionOfComputableFunction( const int& dummy , const string& x ) : SyntaxOfComputableFunction( ExpressionString() , VariableString() , x , GetName<bool>() ) {}

// constant
inline ExpressionOfComputableFunction<bool>::ExpressionOfComputableFunction( const bool& t ) : SyntaxOfComputableFunction( ExpressionString() , ConstantString() , to_string( t ) , GetName<bool>() ) {}

// function
template <typename... Args> inline ExpressionOfComputableFunction<bool>::ExpressionOfComputableFunction( const FunctionSymbol<bool,Args...>& f , const ExpressionOfComputableFunction<Args>&... args ) : SyntaxOfComputableFunction( ExpressionString() , FunctionString() ) { PushFunctionExpression( f , args... ); }

// variadic function
template <typename... Args, typename... VA> inline ExpressionOfComputableFunction<bool>::ExpressionOfComputableFunction( const VariadicFunctionSymbol<bool,Args...>& f , const ExpressionOfComputableFunction<Args>&... args , const ListExpressionOfComputableFunction<VA...>& va ) : SyntaxOfComputableFunction( ExpressionString() , FunctionString() ) { PushFunctionExpression( f , args... , va ); }

// relation
template <typename... Args> inline ExpressionOfComputableFunction<bool>::ExpressionOfComputableFunction( const RelationSymbol<Args...>& r , const ExpressionOfComputableFunction<Args>&... args ) : SyntaxOfComputableFunction( ExpressionString() , RelationString()  ) { PushRelationExpression( r , args... ); }

// variadic relation
template <typename... Args, typename... VA> inline ExpressionOfComputableFunction<bool>::ExpressionOfComputableFunction( const VariadicRelationSymbol<Args...>& r , const ExpressionOfComputableFunction<Args>&... args , const ListExpressionOfComputableFunction<VA...>& va ) : SyntaxOfComputableFunction( ExpressionString() , RelationString()  ) { PushRelationExpression( r , args... , va ); }

template <typename... Args, typename... VA>
inline void ConditionOfComputableFunction::PushFunctionExpression( const FunctionSymbol<bool,Args...>& f , const ExpressionOfComputableFunction<VA>&... va )
{

  TRY_CATCH
    (
     
     Ref().push_RightMost( FunctionExpressionToString( f , VLTree<string>( va.GetNodeString( 2 )... ) ) , GetName<bool>() , f.Get() , ListExpressionOfComputableFunction( va... ).Get() ) ,

     const ErrorType& e ,

     CALL_P( e , f , va... )

     );

  return;

}

template <typename... Args, typename... VA>
inline void ConditionOfComputableFunction::PushRelationExpression( const RelationSymbol<Args...>& r , const ExpressionOfComputableFunction<VA>&... va )
{

  TRY_CATCH
    (
     
     Ref().push_RightMost( FunctionExpressionToString( r , VLTree<string>( va.GetNodeString( 2 )... ) ) , GetName<bool>() , r.Get() , ListExpressionOfComputableFunction( va... ).Get() ) ,

     const ErrorType& e ,

     CALL_P( e , r , va... )

     );

  return;

}

inline ConditionOfComputableFunction operator==( const ExpressionOfComputableFunction<bool>& e1 , const ExpressionOfComputableFunction<bool>& e2 ){ return EquivSymbolApplication( e1 , e2 ); }
inline ConditionOfComputableFunction operator!=( const ExpressionOfComputableFunction<bool>& e1 , const ExpressionOfComputableFunction<bool>& e2 ){ return NegSymbolApplication( EquivSymbolApplication( e1 , e2 ) ); }

template <typename Ret> inline ConditionOfComputableFunction operator==( const ExpressionOfComputableFunction<Ret>& e1 , const ExpressionOfComputableFunction<Ret>& e2 ){ return EqSymbolApplication( e1 , e2 ); }
template <typename Ret> inline ConditionOfComputableFunction operator!=( const ExpressionOfComputableFunction<Ret>& e1 , const ExpressionOfComputableFunction<Ret>& e2 ){ return NeqSymbolApplication( e1 , e2 ); }
template <typename Ret> inline ConditionOfComputableFunction operator<=( const ExpressionOfComputableFunction<Ret>& e1 , const ExpressionOfComputableFunction<Ret>& e2 ){ return LeqSymbolApplication( e1 , e2 ); }
template <typename Ret> inline ConditionOfComputableFunction operator>=( const ExpressionOfComputableFunction<Ret>& e1 , const ExpressionOfComputableFunction<Ret>& e2 ){ return GeqSymbolApplication( e1 , e2 ); }
template <typename Ret> inline ConditionOfComputableFunction operator<( const ExpressionOfComputableFunction<Ret>& e1 , const ExpressionOfComputableFunction<Ret>& e2 ){ return LneqSymbolApplication( e1 , e2 ); }
template <typename Ret> inline ConditionOfComputableFunction operator>( const ExpressionOfComputableFunction<Ret>& e1 , const ExpressionOfComputableFunction<Ret>& e2 ){ return GneqSymbolApplication( e1 , e2 ); }


inline ConditionOfComputableFunction operator!( const ConditionOfComputableFunction& b ){ return NegSymbolApplication( b ); }
inline ConditionOfComputableFunction operator&&( const ConditionOfComputableFunction& b1 , const ConditionOfComputableFunction& b2 ){ return LandSymbolApplication( b1 , b2 ); }
inline ConditionOfComputableFunction operator||( const ConditionOfComputableFunction& b1 , const ConditionOfComputableFunction& b2 ){ return LorSymbolApplication( b1 , b2 ); }
inline ConditionOfComputableFunction operator>>( const ConditionOfComputableFunction& b1 , const ConditionOfComputableFunction& b2 ){ return ToSymbolApplication( b1 , b2 ); }
inline ConditionOfComputableFunction operator->*( const ConditionOfComputableFunction& b1 , const ConditionOfComputableFunction& b2 ){ return ToSymbolApplication( b1 , b2 ); }
inline ConditionOfComputableFunction operator<<( const ConditionOfComputableFunction& b1 , const ConditionOfComputableFunction& b2 ){ return ToSymbolApplication( b2 , b1 ); }
