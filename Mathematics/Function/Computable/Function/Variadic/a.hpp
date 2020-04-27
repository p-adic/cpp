// c:/Users/user/Documents/Programming/Mathematics/Function/Computable/Function/Variadic/a.hpp

#pragma once
#include "a_Macro.hpp"

#include "Guide/a.hpp"
#include "../a.hpp"
#include "../../Expression/List/a.hpp"


template <typename Ret, typename VArg, typename... Args>
class VariadicFunctionSymbol :
  public FunctionSymbol<Ret,Args...,void>
{
  
public:
  inline VariadicFunctionSymbol( const string& f , const TypeNameOfComputableFunction& type_name , const VariableSymbol<Args>&... args );
  inline VariadicFunctionSymbol( const string& f , const SeparatorOfComputableFunction& s , const TypeNameOfComputableFunction& type_name , const VariableSymbol<Args>&... args );

  template <typename... VA> inline auto operator()( const ExpressionOfComputableFunction<VA>&... va ) const -> typename enable_if<IsValidVariadicArguments<VArg,WrappedTypes<Args...>,WrappedTypes<VA...> >::value,ExpressionOfComputableFunction<Ret> >::type;

  template <typename... VA> inline auto operator()( const ExpressionOfComputableFunction<Args>&... args , const VA&... va ) const -> typename enable_if<! conjunction<is_same<ExpressionOfComputableFunction<VArg>,VA>...>::value,ExpressionOfComputableFunction<Ret> >::type;

};

#include "a_Alias.hpp"

template <typename Ret> DECLARATION_OF_VARIADIC_FUNCTION_SYMBOL( Ret , Plus );
template <> DECLARATION_OF_VARIADIC_FUNCTION_SYMBOL( string , Plus );

template <typename Ret> DECLARATION_OF_VARIADIC_FUNCTION_SYMBOL( Ret , Times );

template <typename Ret> DECLARATION_OF_VARIADIC_FUNCTION_SYMBOL_APPLICATION_ONE( Ret , Plus );
template <typename Ret> DECLARATION_OF_VARIADIC_FUNCTION_SYMBOL_APPLICATION_TWO( Ret , Plus );
template <> DECLARATION_OF_VARIADIC_FUNCTION_SYMBOL_APPLICATION_TWO( int , Plus );
template <> DECLARATION_OF_VARIADIC_FUNCTION_SYMBOL_APPLICATION_TWO( string , Plus );
template <> DECLARATION_OF_VARIADIC_FUNCTION_SYMBOL_APPLICATION_TWO( bool , Plus );
template <typename Ret, typename... Args> DECLARATION_OF_VARIADIC_FUNCTION_SYMBOL_APPLICATION_MORE( Ret , Plus );

template <typename Ret> DECLARATION_OF_VARIADIC_FUNCTION_SYMBOL_APPLICATION_ONE( Ret , Times );
template <typename Ret> DECLARATION_OF_VARIADIC_FUNCTION_SYMBOL_APPLICATION_TWO( Ret , Times );
template <> DECLARATION_OF_VARIADIC_FUNCTION_SYMBOL_APPLICATION_TWO( int , Times );
template <> DECLARATION_OF_VARIADIC_FUNCTION_SYMBOL_APPLICATION_TWO( bool , Times );
template <typename Ret, typename... Args> DECLARATION_OF_VARIADIC_FUNCTION_SYMBOL_APPLICATION_MORE( Ret , Times );

DECLARATION_OF_VARIADIC_LOGICAL_CONNECTIVE( Land );
DECLARATION_OF_VARIADIC_LOGICAL_CONNECTIVE( Lor );
DECLARATION_OF_VARIADIC_LOGICAL_CONNECTIVE_APPLICATION_ALL( Land );
DECLARATION_OF_VARIADIC_LOGICAL_CONNECTIVE_APPLICATION_ALL( Lor );
