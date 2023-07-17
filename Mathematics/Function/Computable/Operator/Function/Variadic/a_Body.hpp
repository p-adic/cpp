// c:/Users/user/Documents/Programming/Mathematics/Function/Computable/Operator/Function/Variadic/a_Body.hpp

#pragma once
#include "a.hpp"

#include "../a_Body.hpp"
#include "../../../Expression/List/a_Body.hpp"

template <typename Ret, typename VArg, typename... Args> inline VariadicFunctionSymbol<Ret,VArg,Args...>::VariadicFunctionSymbol( const TotalityOfComputableFunction& totality , const string& f , const TypeNameOfComputableFunction& type_name , const VariableSymbol<Args>&... args ) : VariadicFunctionSymbol( totality , f , SeparatorOfComputableFunction( f , sizeof...( Args ) , true ) , type_name , args... ) {}

template <typename Ret, typename VArg, typename... Args> inline VariadicFunctionSymbol<Ret,VArg,Args...>::VariadicFunctionSymbol( const TotalityOfComputableFunction& totality , const string& f , const SeparatorOfComputableFunction& s , const TypeNameOfComputableFunction& type_name , const VariableSymbol<Args>&... args ) : FunctionSymbol<Ret,Args...,void>( totality , f , s , type_name , args... , LdotsSymbol<VArg>() ) {}

template <typename Ret, typename VArg, typename... Args> template <typename... Ts> inline VariadicFunctionSymbol<Ret,VArg,Args...>::VariadicFunctionSymbol( const string& f , const Ts&... ts  ) : VariadicFunctionSymbol( Recursiveness() , f , ts... ) {}


template <typename Ret, typename VArg, typename... Args> template <typename... VA> inline auto VariadicFunctionSymbol<Ret,VArg,Args...>::operator()( const ExpressionOfComputableFunction<VA>&... va ) const -> typename enable_if<IsValidVariadicArguments<VArg,WrappedTypes<Args...>,WrappedTypes<VA...> >::value,ExpressionOfComputableFunction<Ret> >::type { return ExpressionOfComputableFunction<Ret>( *this , va... ); }

template <typename Ret, typename VArg, typename... Args> template <typename... VA> inline auto VariadicFunctionSymbol<Ret,VArg,Args...>::operator()( const ExpressionOfComputableFunction<Args>&... args , const VA&... va ) const -> typename enable_if<! conjunction<is_same<ExpressionOfComputableFunction<VArg>,VA>...>::value,ExpressionOfComputableFunction<Ret> >::type { return operator()( args... , ExpressionOfComputableFunction<VArg>( va )... ); }


template <typename Ret> inline DEFINITION_OF_VARIADIC_FUNCTION_SYMBOL_APPLICATION_ONE( Ret , Plus );
template <typename Ret, typename... Args> inline DEFINITION_OF_VARIADIC_FUNCTION_SYMBOL_APPLICATION_MORE( Ret , Plus , Symbol<Ret> );

template <typename Ret> inline DEFINITION_OF_VARIADIC_FUNCTION_SYMBOL_APPLICATION_ONE( Ret , Times );
template <typename Ret, typename... Args> inline DEFINITION_OF_VARIADIC_FUNCTION_SYMBOL_APPLICATION_MORE( Ret , Times , Symbol<Ret> );
