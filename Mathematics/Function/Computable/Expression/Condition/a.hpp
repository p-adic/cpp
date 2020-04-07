// c:/Users/user/Documents/Programming/Mathematics/Function/Computable/Expression/Condition/a.hpp

#pragma once
#include "a_Macro.hpp"

#include "../a.hpp"

template <>
class ExpressionOfComputableFunction<bool> :
  public SyntaxOfComputableFunction
{

protected:
  // variable
  inline ExpressionOfComputableFunction( const int& dummy , const string& x );

public:
  // constant
  inline ExpressionOfComputableFunction( const bool& t );

  // function
  template <typename... Args> inline ExpressionOfComputableFunction( const FunctionSymbol<bool,Args...>& f , const ExpressionOfComputableFunction<Args>&... args );

  // variadic function
  // template <typename... Args, typename... VA> inline ExpressionOfComputableFunction( const VariadicFunctionSymbol<bool,Args...>& f , const ExpressionOfComputableFunction<Args>&... args , const ListExpressionOfComputableFunction<VA...>& va );

  template <typename... Args, typename... VA> inline ExpressionOfComputableFunction( const VariadicFunctionSymbol<bool,Args...>& f , const ExpressionOfComputableFunction<VA>&... va );
  
  // relaion
  template <typename... Args> inline ExpressionOfComputableFunction( const RelationSymbol<Args...>& r , const ExpressionOfComputableFunction<Args>&... args );

  // variadic relation
  // template <typename... Args, typename... VA> inline ExpressionOfComputableFunction( const VariadicRelationSymbol<Args...>& r , const ExpressionOfComputableFunction<Args>&... args , const ListExpressionOfComputableFunction<VA...>& va );

  template <typename... Args, typename... VA> inline ExpressionOfComputableFunction( const VariadicRelationSymbol<bool,Args...>& r , const ExpressionOfComputableFunction<VA>&... va );

  
  using type = bool;

private:
  // 木の右端に関数fと引数va...による表現を追加
  template <typename... Args, typename... VA> inline void PushFunctionExpression( const FunctionSymbol<bool,Args...>& f , const ExpressionOfComputableFunction<VA>&... va );
  
  // 木の右端に関数fと引数の木va...による表現を追加
  template <typename... Args, typename... VA> auto PushFunctionExpression( const FunctionSymbol<bool,Args...>& f , const VA&... va ) -> typename enable_if<conjunction<is_same<VLTree<string>,VA>...>::value,void>::type;

  // 木の右端に関係rと引数va...による表現を追加
  template <typename... Args, typename... VA> inline void PushRelationExpression( const RelationSymbol<Args...>& r , const ExpressionOfComputableFunction<VA>&... va );

  // 木の右端に関係rと引数の木va...による表現を追加
  template<typename... Args, typename... VA> auto PushRelationExpression( const RelationSymbol<Args...>& f , const VA&... va ) -> typename enable_if<conjunction<is_same<VLTree<string>,VA>...>::value,void>::type;

};


template <typename Ret> DECLARATION_OF_BASIC_RELATION( Ret , == );
template <typename Ret> DECLARATION_OF_BASIC_RELATION( Ret , != );
template <typename Ret> DECLARATION_OF_BASIC_RELATION( Ret , <= );
template <typename Ret> DECLARATION_OF_BASIC_RELATION( Ret , >= );
template <typename Ret> DECLARATION_OF_BASIC_RELATION( Ret , < );
template <typename Ret> DECLARATION_OF_BASIC_RELATION( Ret , > );


inline ConditionOfComputableFunction operator!( const ConditionOfComputableFunction& b );
DECLARATION_OF_BASIC_RELATION( bool , && );
DECLARATION_OF_BASIC_RELATION( bool , || );
DECLARATION_OF_BASIC_RELATION( bool , >> );
DECLARATION_OF_BASIC_RELATION( bool , ->* );
DECLARATION_OF_BASIC_RELATION( bool , << );
