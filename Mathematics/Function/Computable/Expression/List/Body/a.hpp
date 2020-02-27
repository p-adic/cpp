// c:/Users/user/Documents/Programming/Mathematics/Function/Computable/Expression/List/Body/a.hpp

#pragma once
#include "../../Variable/a.hpp"

// #include "../a.hpp"

template <typename... VA> class ListExpressionOfComputableFunction;

template <>
class ExpressionOfComputableFunction<void> :
  public SyntaxOfComputableFunction
{

  friend VariableSymbol<void>;
  template <typename... VA> friend class ListExpressionOfComputableFunction;
  
private:
  // VariadicVariable
  inline ExpressionOfComputableFunction();

  // List
  template <typename... VA> ExpressionOfComputableFunction( const ExpressionOfComputableFunction<VA>&... va );
  
  ExpressionOfComputableFunction( const ExpressionOfComputableFunction<void>& ) = default;
  ~ExpressionOfComputableFunction() = default;
  ExpressionOfComputableFunction& operator=( const ExpressionOfComputableFunction<void>& ) = default;
  
};


DECLARATION_OF_GLOBAL_CONSTANT_STRING_FOR_SYMBOL( Ldots );
