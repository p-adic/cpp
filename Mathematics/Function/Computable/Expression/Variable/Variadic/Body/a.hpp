// c:/Users/user/Documents/Programming/Mathematics/Function/Computable/Expression/Variable/Variadic/Body/a.hpp

#pragma once
// #include "../a.hpp"
#include "../../a.hpp"

template <typename T> class VariableSymbol;

template <>
class ExpressionOfComputableFunction<void> :
  public SyntaxOfComputableFunction
{

  friend VariableSymbol<void>;

private:
  inline ExpressionOfComputableFunction();
  ExpressionOfComputableFunction( const ExpressionOfComputableFunction<void>& ) = default;
  ~ExpressionOfComputableFunction() = default;
  ExpressionOfComputableFunction& operator=( const ExpressionOfComputableFunction<void>& ) = default;
  
};

#include "../a.hpp"
