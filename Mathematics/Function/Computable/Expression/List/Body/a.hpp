// c:/Users/user/Documents/Programming/Mathematics/Function/Computable/Expression/List/Body/a.hpp

#pragma once
#include "../../../../../../Utility/WrappedType/a.hpp"

#include "../../a.hpp"

// #include "../a.hpp"
// #include "../../Variable/a.hpp"

template <typename Ret> class VariableSymbol;
template <typename... VA> class ListExpressionOfComputableFunction;

template <>
class ExpressionOfComputableFunction<void> :
  public SyntaxOfComputableFunction
{

  friend VariableSymbol<void>;
  template <typename... VA> friend class ListExpressionOfComputableFunction;

private:
  // VariadicVariable
  template <typename VArg> inline ExpressionOfComputableFunction( const WrappedTypes<VArg>& );

  // List
  template <typename... VA> ExpressionOfComputableFunction( const ExpressionOfComputableFunction<VA>&... va );
  
  ExpressionOfComputableFunction( const ExpressionOfComputableFunction<void>& ) = default;
  ~ExpressionOfComputableFunction() = default;
  ExpressionOfComputableFunction& operator=( const ExpressionOfComputableFunction<void>& ) = default;
  
};
