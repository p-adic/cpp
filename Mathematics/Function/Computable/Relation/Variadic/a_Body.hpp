// c:/Users/user/Documents/Programming/Mathematics/Function/Computable/Relation/Variadic/a_Body.hpp

#pragma once
#include "a.hpp"

#include "../a_Body.hpp"
#include "../../Expression/List/a_Body.hpp"

template <typename VArg, typename... Args> inline VariadicRelationSymbol<VArg, Args...>::VariadicRelationSymbol( const string& r , const TypeNameOfComputableFunction& type_name , const VariableSymbol<Args>&... args ) : VariadicRelationSymbol( r , SeparatorOfComputableFunction( r , sizeof...( Args ) , true ) , type_name , args... ) {}

template <typename VArg, typename... Args> inline VariadicRelationSymbol<VArg, Args...>::VariadicRelationSymbol( const string& r , const SeparatorOfComputableFunction& s , const TypeNameOfComputableFunction& type_name , const VariableSymbol<Args>&... args ) : RelationSymbol<Args...,void>( r , s , type_name , args... , LdotsSymbol() ) {}

template <typename VArg, typename... Args> template <typename... VA> inline auto VariadicRelationSymbol<VArg, Args...>::operator()( const ExpressionOfComputableFunction<VA>&... va ) const -> typename enable_if<IsValidVariadicArguments<VArg,WrappedTypes<Args...>,WrappedTypes<VA...> >::value,ConditionOfComputableFunction>::type { return ConditionOfComputableFunction( *this , va... ); }

template <typename VArg, typename... Args> template <typename... VA> inline auto VariadicRelationSymbol<VArg, Args...>::operator()( const ExpressionOfComputableFunction<Args>&... args , const VA&... va ) const -> typename enable_if<! conjunction<is_same<ExpressionOfComputableFunction<VArg>,VA>...>::value,ConditionOfComputableFunction>::type { return operator()( args... , ExpressionOfComputableFunction<VArg>( va )... ); }
