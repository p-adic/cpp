// c:/Users/user/Documents/Programming/Mathematics/Function/Computable/Expression/Variable/Variadic/Body/a.hpp

#pragma once
#include "../../a.hpp"

template <typename VArg> class VariadicVariableSymbol;

template <>
class VariableSymbol<void> :
  public ExpressionOfComputableFunction<void>
{

  template <typename VArg> friend class VariadicVariableSymbol;

private:
  template <typename VArg> inline VariableSymbol( const WrappedTypes<VArg>& v );
  VariableSymbol( const VariableSymbol<void>& ) = default;
  ~VariableSymbol() = default;
  VariableSymbol<void>& operator=( const VariableSymbol<void>& ) = default;

};
