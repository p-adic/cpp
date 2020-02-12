// c:/Users/user/Documents/Programming/Mathematics/Function/Computable/Expression/a.hpp

#pragma once
#include "../Syntax/a.hpp"
// #include "../Function/Variadic/Variadic/a.hpp"
// #include "../Relation/Variadic/Variadic/a.hpp"

template <typename Ret, typename... ARGS> class FunctionSymbol;
template <typename Ret, typename... ARGS> class VariadicFunctionSymbol;
template <typename... ARGS> class RelationSymbol;
template <typename... ARGS> class VariadicRelationSymbol;

template <typename Ret>
class ExpressionOfComputableFunction :
  public SyntaxOfComputableFunction
{

protected:
  // variable
  inline ExpressionOfComputableFunction( const int& dummy , const string& x );


public:
  // constant
  inline ExpressionOfComputableFunction( const Ret& t );

  // function
  template <typename... ARGS> inline ExpressionOfComputableFunction( const FunctionSymbol<Ret,ARGS...>& f , const ExpressionOfComputableFunction<ARGS>&... args );

  // variadic function
  template <typename... ARGS, typename... VA> inline ExpressionOfComputableFunction( const VariadicFunctionSymbol<Ret,ARGS...>& f , const ExpressionOfComputableFunction<ARGS>&... args , const ExpressionOfComputableFunction<VA>&... va );

  using type = Ret;

};

#include "a_Alias.hpp"

template <typename Ret> inline ExpressionOfComputableFunction<Ret> operator+( const ExpressionOfComputableFunction<Ret>& e1 , const ExpressionOfComputableFunction<Ret>& e2 );
template <typename Ret> inline ExpressionOfComputableFunction<Ret> operator-( const ExpressionOfComputableFunction<Ret>& e1 , const ExpressionOfComputableFunction<Ret>& e2 );
template <typename Ret> inline ExpressionOfComputableFunction<Ret> operator*( const ExpressionOfComputableFunction<Ret>& e1 , const ExpressionOfComputableFunction<Ret>& e2 );
template <typename Ret> inline ExpressionOfComputableFunction<Ret> operator/( const ExpressionOfComputableFunction<Ret>& e1 , const ExpressionOfComputableFunction<Ret>& e2 );
template <typename Ret> inline ExpressionOfComputableFunction<Ret> operator%( const ExpressionOfComputableFunction<Ret>& e1 , const ExpressionOfComputableFunction<Ret>& e2 );
