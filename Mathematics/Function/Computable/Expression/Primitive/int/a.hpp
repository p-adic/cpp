// c:/Users/user/Documents/Programming/Mathematics/Function/Computable/Expression/Primitive/int/a.hpp

#pragma once
#include "../../Body/a.hpp"

template <>
class ExpressionOfComputableFunction<int> :
  public SyntaxOfComputableFunction
{
  
protected:
  // variable
  inline DECLARATION_OF_EXPRESSION_FOR_VARIABLE_SYMBOL;

public:
  // constant
  inline DECLARATION_OF_EXPRESSION_FOR_CONSTANT_SYMBOL( int );

  // function
  template <typename... Args> inline DECLARATION_OF_EXPRESSION_FOR_FUNCTION_SYMBOL( int );

  // variadic function  
  template <typename... Args, typename... VA> inline DECLARATION_OF_EXPRESSION_FOR_VARIADIC_FUNCTION_SYMBOL( int );

  inline DECLARATION_OF_SET_SYMBOL_FOR_EXPRESSION;

  DECLARATION_OF_WRITE_TO_FOR_EXPRESSION( int );
  
  using type = int;

private:
  // 木の右端に関数fと引数va...による表現を追加
  template <typename... Args, typename... VA> inline DECLARATION_OF_PUSH_FUNCTION_EXPRESSION_FOR_EXPRESSION( int );

  // 木の右端に関数fと引数va...の木を追加
  template <typename... Args, typename... VA> inline DECLARATION_OF_PUSH_FUNCTION_EXPRESSION_FOR_EXPRESSION_BODY( int );
  
};

inline const int& infty() noexcept;
