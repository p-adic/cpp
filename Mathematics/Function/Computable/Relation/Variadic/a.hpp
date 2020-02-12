// c:/Users/user/Documents/Programming/Mathematics/Function/Computable/Relation/Variadic/a.hpp

#pragma once
#include "../a.hpp"

template <typename... ARGS>
class VariadicRelationSymbol :
  public RelationSymbol<ARGS...>
{

public:
  inline VariadicRelationSymbol( const string& r , const VariableSymbol<ARGS>&... args );

  template <typename... VA> inline ConditionOfComputableFunction operator()( const ExpressionOfComputableFunction<ARGS>&... args , const ExpressionOfComputableFunction<VA>&... va ) const;

};
