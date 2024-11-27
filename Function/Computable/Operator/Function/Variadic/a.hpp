// c:/Users/user/Documents/Programming/Mathematics/Function/Computable/Operator/Function/Variadic/a.hpp

#pragma once
#include "a_Macro.hpp"

#include "../a.hpp"
#include "../../Guide/a.hpp"
#include "../../../Expression/List/a.hpp"


template <typename Ret, typename VArg, typename... Args>
class VariadicFunctionSymbol :
  public FunctionSymbol<Ret,Args...,void>
{
  
public:
  inline VariadicFunctionSymbol( const TotalityOfComputableFunction& totality , const string& f , const TypeNameOfComputableFunction& type_name , const VariableSymbol<Args>&... args );
  inline VariadicFunctionSymbol( const TotalityOfComputableFunction& totality , const string& f , const SeparatorOfComputableFunction& s , const TypeNameOfComputableFunction& type_name , const VariableSymbol<Args>&... args );
  template <typename... Ts> inline VariadicFunctionSymbol( const string& f , const Ts&... ts );
  
  template <typename... VA> inline auto operator()( const ExpressionOfComputableFunction<VA>&... va ) const -> typename enable_if<IsValidVariadicArguments<VArg,WrappedTypes<Args...>,WrappedTypes<VA...> >::value,ExpressionOfComputableFunction<Ret> >::type;

  template <typename... VA> inline auto operator()( const ExpressionOfComputableFunction<Args>&... args , const VA&... va ) const -> typename enable_if<! conjunction<is_same<ExpressionOfComputableFunction<VArg>,VA>...>::value,ExpressionOfComputableFunction<Ret> >::type;

};

#include "a_Alias.hpp"

template <typename Ret> inline DECLARATION_OF_VARIADIC_FUNCTION_SYMBOL( Ret , Plus );
template <typename Ret> inline DECLARATION_OF_VARIADIC_FUNCTION_SYMBOL( Ret , Times );

template <typename Ret> inline DECLARATION_OF_VARIADIC_FUNCTION_SYMBOL_APPLICATION_ONE( Ret , Plus );
template <typename Ret, typename... Args> inline DECLARATION_OF_VARIADIC_FUNCTION_SYMBOL_APPLICATION_MORE( Ret , Plus );

template <typename Ret> inline DECLARATION_OF_VARIADIC_FUNCTION_SYMBOL_APPLICATION_ONE( Ret , Times );
template <typename Ret, typename... Args> inline DECLARATION_OF_VARIADIC_FUNCTION_SYMBOL_APPLICATION_MORE( Ret , Times );
