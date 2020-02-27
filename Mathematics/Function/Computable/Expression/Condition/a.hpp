// c:/Users/user/Documents/Programming/Mathematics/Function/Computable/Expression/Condition/a.hpp

#pragma once
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
  template <typename T> inline ExpressionOfComputableFunction( const T& t ) = delete;
  inline ExpressionOfComputableFunction( const bool& t );

  // function
  template <typename... Args> inline ExpressionOfComputableFunction( const FunctionSymbol<bool,Args...>& f , const ExpressionOfComputableFunction<Args>&... args );

  // variadic function
  template <typename... Args, typename... VA> inline ExpressionOfComputableFunction( const VariadicFunctionSymbol<bool,Args...>& f , const ExpressionOfComputableFunction<Args>&... args , const ListExpressionOfComputableFunction<VA...>& va );

  // relaion
  template <typename... Args> inline ExpressionOfComputableFunction( const RelationSymbol<Args...>& r , const ExpressionOfComputableFunction<Args>&... args );

  // variadic relation
  template <typename... Args, typename... VA> inline ExpressionOfComputableFunction( const VariadicRelationSymbol<Args...>& r , const ExpressionOfComputableFunction<Args>&... args , const ListExpressionOfComputableFunction<VA...>& va );


  using type = bool;

};


template <typename Ret> inline ConditionOfComputableFunction operator==( const ExpressionOfComputableFunction<Ret>& e1 , const ExpressionOfComputableFunction<Ret>& e2 );
template <typename Ret> inline ConditionOfComputableFunction operator!=( const ExpressionOfComputableFunction<Ret>& e1 , const ExpressionOfComputableFunction<Ret>& e2 );
template <typename Ret> inline ConditionOfComputableFunction operator<=( const ExpressionOfComputableFunction<Ret>& e1 , const ExpressionOfComputableFunction<Ret>& e2 );
template <typename Ret> inline ConditionOfComputableFunction operator>=( const ExpressionOfComputableFunction<Ret>& e1 , const ExpressionOfComputableFunction<Ret>& e2 );
template <typename Ret> inline ConditionOfComputableFunction operator<( const ExpressionOfComputableFunction<Ret>& e1 , const ExpressionOfComputableFunction<Ret>& e2 );
template <typename Ret> inline ConditionOfComputableFunction operator>( const ExpressionOfComputableFunction<Ret>& e1 , const ExpressionOfComputableFunction<Ret>& e2 );


inline ConditionOfComputableFunction operator!( const ConditionOfComputableFunction& b );
inline ConditionOfComputableFunction operator&&( const ConditionOfComputableFunction& b1 , const ConditionOfComputableFunction& b2 );
inline ConditionOfComputableFunction operator||( const ConditionOfComputableFunction& b1 , const ConditionOfComputableFunction& b2 );

template <typename... Args, typename... VA> void RelationExpressionToSyntax( SyntaxOfComputableFunction& t , const RelationSymbol<Args...>& r , const ExpressionOfComputableFunction<VA>&... va );
