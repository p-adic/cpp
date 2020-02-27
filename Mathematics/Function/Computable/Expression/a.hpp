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

};

#include "a_Alias.hpp"

template <typename Ret> inline ExpressionOfComputableFunction<Ret> operator+( const ExpressionOfComputableFunction<Ret>& e1 , const ExpressionOfComputableFunction<Ret>& e2 );
template <typename Ret> inline ExpressionOfComputableFunction<Ret> operator-( const ExpressionOfComputableFunction<Ret>& e1 , const ExpressionOfComputableFunction<Ret>& e2 );
template <typename Ret> inline ExpressionOfComputableFunction<Ret> operator*( const ExpressionOfComputableFunction<Ret>& e1 , const ExpressionOfComputableFunction<Ret>& e2 );
template <typename Ret> inline ExpressionOfComputableFunction<Ret> operator/( const ExpressionOfComputableFunction<Ret>& e1 , const ExpressionOfComputableFunction<Ret>& e2 );
template <typename Ret> inline ExpressionOfComputableFunction<Ret> operator%( const ExpressionOfComputableFunction<Ret>& e1 , const ExpressionOfComputableFunction<Ret>& e2 );

inline const ExpressionOfComputableFunction<int>& InftySymbol();

template <typename Ret, typename... Args, typename... VA> void FunctionExpressionToSyntax( SyntaxOfComputableFunction& t , const FunctionSymbol<Ret,Args...>& f , const ExpressionOfComputableFunction<VA>&... va );


DECLARATION_OF_GLOBAL_CONSTANT_STRING_FOR_SYMBOL( Expression );
DECLARATION_OF_GLOBAL_CONSTANT_STRING_FOR_SYMBOL( Variable );
DECLARATION_OF_GLOBAL_CONSTANT_STRING_FOR_SYMBOL( Constant );
