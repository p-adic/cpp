// c:/Users/user/Documents/Programming/Mathematics/Function/Computable/Expression/a.hpp

#pragma once
#include "../Syntax/a.hpp"

// #include "List/a.hpp"
// #include "../Function/Variadic/a.hpp"
// #include "../Relation/Variadic/a.hpp"

template <typename Ret, typename... Args> class FunctionSymbol;
template <typename Ret, typename... Args> class VariadicFunctionSymbol;
template <typename... Args> class RelationSymbol;
template <typename... Args> class VariadicRelationSymbol;
template <typename... Args> class ListExpressionOfComputableFunction;

template <typename Ret>
class ExpressionOfComputableFunction :
  public SyntaxOfComputableFunction
{

protected:
  // variable
  inline ExpressionOfComputableFunction( const int& dummy , const string& x );

public:
  // constant
  template <typename T> inline ExpressionOfComputableFunction( const T& t ) = delete;
  inline ExpressionOfComputableFunction( const Ret& t );

  // function
  template <typename... Args> inline ExpressionOfComputableFunction( const FunctionSymbol<Ret,Args...>& f , const ExpressionOfComputableFunction<Args>&... args );

  // variadic function
  template <typename... Args, typename... VA> inline ExpressionOfComputableFunction( const VariadicFunctionSymbol<Ret,Args...>& f , const ExpressionOfComputableFunction<Args>&... args , const ListExpressionOfComputableFunction<VA...>& va );

  using type = Ret;

private:
  // 木の右端に関数fと引数va...による表現を追加
  template <typename... Args, typename... VA> inline void PushFunctionExpression( const FunctionSymbol<Ret,Args...>& f , const ExpressionOfComputableFunction<VA>&... va );

  // 木の右端に関数fと引数の木va...による表現を追加
  template<typename... Args, typename... VA>
  inline auto PushFunctionExpression( const FunctionSymbol<Ret,Args...>& f , const VA&... va ) -> typename enable_if<conjunction<is_same<VLTree<string>,VA>...>::value,void>::type;
};

#include "a_Alias.hpp"

template <typename Ret> inline ExpressionOfComputableFunction<Ret> operator+( const ExpressionOfComputableFunction<Ret>& e1 , const ExpressionOfComputableFunction<Ret>& e2 );
template <typename Ret> inline ExpressionOfComputableFunction<Ret> operator-( const ExpressionOfComputableFunction<Ret>& e1 , const ExpressionOfComputableFunction<Ret>& e2 );
template <typename Ret> inline ExpressionOfComputableFunction<Ret> operator*( const ExpressionOfComputableFunction<Ret>& e1 , const ExpressionOfComputableFunction<Ret>& e2 );
template <typename Ret> inline ExpressionOfComputableFunction<Ret> operator/( const ExpressionOfComputableFunction<Ret>& e1 , const ExpressionOfComputableFunction<Ret>& e2 );
template <typename Ret> inline ExpressionOfComputableFunction<Ret> operator%( const ExpressionOfComputableFunction<Ret>& e1 , const ExpressionOfComputableFunction<Ret>& e2 );

inline const ExpressionOfComputableFunction<int>& InftySymbol();
