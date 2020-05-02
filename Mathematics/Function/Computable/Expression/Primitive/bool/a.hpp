// c:/Users/user/Documents/Programming/Mathematics/Function/Computable/Expression/Primitive/bool/a.hpp

#pragma once
#include "../../Body/a.hpp"

template <>
class ExpressionOfComputableFunction<bool> :
  public SyntaxOfComputableFunction
{

protected:
  // variable
  inline DECLARATION_OF_EXPRESSION_FOR_VARIABLE_SYMBOL;

public:
  // constant
  inline DECLARATION_OF_EXPRESSION_FOR_CONSTANT_SYMBOL( bool );

  // function
  template <typename... Args> inline DECLARATION_OF_EXPRESSION_FOR_FUNCTION_SYMBOL( bool );

  // variadic function  
  template <typename... Args, typename... VA> inline DECLARATION_OF_EXPRESSION_FOR_VARIADIC_FUNCTION_SYMBOL( bool );

  // relaion
  template <typename... Args> inline DECLARATION_OF_EXPRESSION_FOR_RELATION_SYMBOL;

  // variadic relation
  template <typename... Args, typename... VA> inline DECLARATION_OF_EXPRESSION_FOR_VARIADIC_RELATION_SYMBOL;
  
  inline DECLARATION_OF_SET_SYMBOL_FOR_EXPRESSION;

  using type = bool;

private:
  // 木の右端に関数fと引数va...による表現を追加
  template <typename... Args, typename... VA> inline DECLARATION_OF_PUSH_FUNCTION_EXPRESSION_FOR_EXPRESSION( bool );

  // 木の右端に関数fと引数va...の木を追加
  template <typename... Args, typename... VA> inline DECLARATION_OF_PUSH_FUNCTION_EXPRESSION_FOR_EXPRESSION_BODY( bool );
  
  // 木の右端に関係rと引数va...による表現を追加
  template <typename... Args, typename... VA> inline DECLARATION_OF_PUSH_RELATION_EXPRESSION_FOR_EXPRESSION;

  // 木の右端に関係rと引数の木va...による表現を追加
  template<typename... Args, typename... VA> inline DECLARATION_OF_PUSH_RELATION_EXPRESSION_FOR_EXPRESSION_BODY;

};

#include "a_Alias.hpp"
