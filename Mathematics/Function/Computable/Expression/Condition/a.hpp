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
  inline ExpressionOfComputableFunction( const bool& t );

  // function
  template <typename... ARGS> inline ExpressionOfComputableFunction( const FunctionSymbol<bool,ARGS...>& f , const ExpressionOfComputableFunction<ARGS>&... args );

  // variadic function
  template <typename... ARGS, typename... VA> inline ExpressionOfComputableFunction( const VariadicFunctionSymbol<bool,ARGS...>& f , const ExpressionOfComputableFunction<ARGS>&... args , const ExpressionOfComputableFunction<VA>&... va );

  // relaion
  template <typename... ARGS> inline ExpressionOfComputableFunction( const RelationSymbol<ARGS...>& r , const ExpressionOfComputableFunction<ARGS>&... args );

  // variadic relation
  template <typename... ARGS, typename... VA> inline ExpressionOfComputableFunction( const VariadicRelationSymbol<ARGS...>& r , const ExpressionOfComputableFunction<ARGS>&... args , const ExpressionOfComputableFunction<VA>&... va );

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
