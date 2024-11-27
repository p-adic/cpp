// c:/Users/user/Documents/Programming/Mathematics/Function/Computable/Expression/Primitive/string/a.hpp

#pragma once
#include "../../Body/a.hpp"


template <>
class ExpressionOfComputableFunction<string> :
  public SyntaxOfComputableFunction
{
  
protected:
  // variable
  inline DECLARATION_OF_EXPRESSION_FOR_VARIABLE_SYMBOL;

public:
  // constant
  inline DECLARATION_OF_EXPRESSION_FOR_CONSTANT_SYMBOL( char* const );
  inline DECLARATION_OF_EXPRESSION_FOR_CONSTANT_SYMBOL( string );

  // function
  template <typename... Args> inline DECLARATION_OF_EXPRESSION_FOR_FUNCTION_SYMBOL( string );

  // variadic function  
  template <typename... Args, typename... VA> inline DECLARATION_OF_EXPRESSION_FOR_VARIADIC_FUNCTION_SYMBOL( string );

  inline DECLARATION_OF_SET_SYMBOL_FOR_EXPRESSION;

  DECLARATION_OF_WRITE_TO_FOR_EXPRESSION( string );

  using type = string;

private:
  // 木の右端に関数fと引数va...による表現を追加
  template <typename... Args, typename... VA> inline DECLARATION_OF_PUSH_FUNCTION_EXPRESSION_FOR_EXPRESSION( string );

  // 木の右端に関数fと引数va...の木を追加
  template <typename... Args, typename... VA> inline DECLARATION_OF_PUSH_FUNCTION_EXPRESSION_FOR_EXPRESSION_BODY( string );
  
};
