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
template <typename Ret> template <typename... Args> inline ExpressionOfComputableFunction<Ret>::ExpressionOfComputableFunction( const FunctionSymbol<Ret,Args...>& f , const ExpressionOfComputableFunction<Args>&... args ) : SyntaxOfComputableFunction( ExpressionString() , FunctionString() ) { PushFunctionExpression( f , args... ); }

// variadic function
template <typename Ret> template <typename... Args, typename... VA> inline ExpressionOfComputableFunction<Ret>::ExpressionOfComputableFunction( const VariadicFunctionSymbol<Ret,Args...>& f , const ExpressionOfComputableFunction<Args>&... args , const ListExpressionOfComputableFunction<VA...>& va ) : SyntaxOfComputableFunction( ExpressionString() , FunctionString() ) { PushFunctionExpression( f , args... , va ); }


template <typename Ret> template<typename... Args, typename... VA>
inline void ExpressionOfComputableFunction<Ret>::PushFunctionExpression( const FunctionSymbol<Ret,Args...>& f , const ExpressionOfComputableFunction<VA>&... va ) { PushFunctionExpression( f , va.Get()... ); }

template <typename Ret> template<typename... Args, typename... VA>
inline auto ExpressionOfComputableFunction<Ret>::PushFunctionExpression( const FunctionSymbol<Ret,Args...>& f , const VA&... va ) -> typename enable_if<conjunction<is_same<VLTree<string>,VA>...>::value,void>::type
{

  VLTree<string> t_va{};
  t_va.push_RightMost( va... );
  
  TRY_CATCH
    (
     
     Ref().push_RightMost( FunctionExpressionToString( f , t_va ) , GetName<Ret>() , f.Get() , va... ) ,

     const ErrorType& e ,

     CALL_P( e , f , va... )

     );

  return;
  
}

template <typename Ret> inline ExpressionOfComputableFunction<Ret> operator+( const ExpressionOfComputableFunction<Ret>& e1 , const ExpressionOfComputableFunction<Ret>& e2 ){ return PlusSymbolApplication( e1 , e2 ); }
template <typename Ret> inline ExpressionOfComputableFunction<Ret> operator-( const ExpressionOfComputableFunction<Ret>& e1 , const ExpressionOfComputableFunction<Ret>& e2 ){ return MinusSymbolApplication( e1 , e2 ); }
template <typename Ret> inline ExpressionOfComputableFunction<Ret> operator*( const ExpressionOfComputableFunction<Ret>& e1 , const ExpressionOfComputableFunction<Ret>& e2 ){ return TimesSymbolApplication( e1 , e2 ); }
template <typename Ret> inline ExpressionOfComputableFunction<Ret> operator/( const ExpressionOfComputableFunction<Ret>& e1 , const ExpressionOfComputableFunction<Ret>& e2 ){ return SlashSymbolApplication( e1 , e2 ); }
template <typename Ret> inline ExpressionOfComputableFunction<Ret> operator%( const ExpressionOfComputableFunction<Ret>& e1 , const ExpressionOfComputableFunction<Ret>& e2 ){ return ModSymbolApplication( e1 , e2 ); }
template <typename Ret> inline ExpressionOfComputableFunction<Ret> operator^( const ExpressionOfComputableFunction<Ret>& e1 , const ExpressionOfComputableFunction<Ret>& e2 ){ return PowerSymbolApplication( e1 , e2 ); }

inline const ExpressionOfComputableFunction<int>& InftySymbol(){ static const ExpressionOfComputableFunction<int> n = ExpressionOfComputableFunction<int>(infty() ); return n; }
