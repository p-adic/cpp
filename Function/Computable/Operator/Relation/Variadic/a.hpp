// c:/Users/user/Documents/Programming/Mathematics/Function/Computable/Operator/Relation/Variadic/a.hpp

#pragma once
#include "../a.hpp"
#include "../../../Expression/List/a.hpp"

#include "../../Guide/a.hpp"

template <typename VArg, typename... Args>
class VariadicRelationSymbol :
  public RelationSymbol<Args...,void>
{

public:
  inline VariadicRelationSymbol( const TotalityOfComputableFunction& totality , const string& r , const TypeNameOfComputableFunction& type_name , const VariableSymbol<Args>&... args );
  inline VariadicRelationSymbol( const TotalityOfComputableFunction& totality , const string& r , const SeparatorOfComputableFunction& s , const TypeNameOfComputableFunction& type_name , const VariableSymbol<Args>&... args );
  template <typename... Ts> inline VariadicRelationSymbol( const string& r , const Ts&... ts  );

  template <typename... VA> inline auto operator()( const ExpressionOfComputableFunction<VA>&... va ) const -> typename enable_if<IsValidVariadicArguments<VArg,WrappedTypes<Args...>,WrappedTypes<VA...> >::value,ConditionOfComputableFunction>::type;

  template <typename... VA> inline auto operator()( const ExpressionOfComputableFunction<Args>&... args , const VA&... va ) const -> typename enable_if<! conjunction<is_same<ExpressionOfComputableFunction<VArg>,VA>...>::value,ConditionOfComputableFunction>::type;
  
};

#include "a_Alias.hpp"

