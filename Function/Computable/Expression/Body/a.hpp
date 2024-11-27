// c:/Users/user/Documents/Programming/Mathematics/Function/Computable/Expression/Body/a.hpp

#pragma once

#include "a_Macro.hpp"

#include "../../Syntax/a.hpp"

// #include "../List/a.hpp"
// #include "../../Operator/Function/Variadic/a.hpp"
// #include "../../Operator/Relation/Variadic/a.hpp"
// #include "../../Type/Guide/TypeName/a.hpp"


class TypeNameOfComputableFunction;
template <typename Ret, typename... Args> class FunctionSymbol;
template <typename Ret, typename VArg, typename... Args> class VariadicFunctionSymbol;
template <typename... Args> class RelationSymbol;
template <typename VArg, typename... Args> class VariadicRelationSymbol;
template <typename... Args> class ListExpressionOfComputableFunction;

template <typename Ret>
class ExpressionOfComputableFunction :
  public SyntaxOfComputableFunction
{
  
protected:
  // variable
  inline DECLARATION_OF_EXPRESSION_FOR_VARIABLE_SYMBOL;

public:
  // function
  template <typename... Args> inline DECLARATION_OF_EXPRESSION_FOR_FUNCTION_SYMBOL( Ret );

  // variadic function  
  template <typename... Args, typename... VA> inline DECLARATION_OF_EXPRESSION_FOR_VARIADIC_FUNCTION_SYMBOL( Ret );

  inline DECLARATION_OF_SET_SYMBOL_FOR_EXPRESSION;
  
  using type = Ret;

  DECLARATION_OF_WRITE_TO_FOR_EXPRESSION( Ret );
  

private:
  // 木の右端に関数fと引数va...による表現を追加
  template <typename... Args, typename... VA> inline DECLARATION_OF_PUSH_FUNCTION_EXPRESSION_FOR_EXPRESSION( Ret );

  // 木の右端に関数fと引数va...の木を追加
  template <typename... Args, typename... VA> inline DECLARATION_OF_PUSH_FUNCTION_EXPRESSION_FOR_EXPRESSION_BODY( Ret );
  
};


