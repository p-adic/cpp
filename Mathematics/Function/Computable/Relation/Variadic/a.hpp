// c:/Users/user/Documents/Programming/Mathematics/Function/Computable/Relation/Variadic/a.hpp

#pragma once
#include "../a.hpp"
#include "../../Expression/List/a.hpp"

template <typename... Args>
class VariadicRelationSymbol :
  public RelationSymbol<Args...,void>
{

public:
  inline VariadicRelationSymbol( const string& r , const VariableSymbol<Args>&... args );
  inline VariadicRelationSymbol( const string& r , const SeparatorOfComputableFunction& s , const VariableSymbol<Args>&... args );

  template <typename... VA> inline ConditionOfComputableFunction operator()( const ExpressionOfComputableFunction<Args>&... args , const ListExpressionOfComputableFunction<VA...>& va ) const;

};
