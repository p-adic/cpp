// c:/Users/user/Documents/Programming/Mathematics/Function/Computable/Definition/Line/Void/a.hpp

#pragma once
#include "a_Macro.hpp"

#include "../a.hpp"

template <>
class LineOfDefinitionOfComputableFunction<void> :
  public SyntaxOfComputableFunction
{

public:
  using type = void;

  template <typename Ret1 , typename Ret2 , typename... ARGS> using Dummy = typename enable_if<IsSameOrVoidInLine<void,Ret1>::value && IsSameOrVoidInLine<void,Ret2>::value && conjunction<IsSameOrVoidInLine<void,ARGS>...>::value ,int>::type;


public:
  inline LineOfDefinitionOfComputableFunction( const LineOfDefinitionOfComputableFunction<void>& line ) = default;
  template <typename... ARGS> inline LineOfDefinitionOfComputableFunction( const LineOfDefinitionOfComputableFunction<void>& line1 , const LineOfDefinitionOfComputableFunction<void>& line2 , const LineOfDefinitionOfComputableFunction<ARGS>&... args );

  // PUT
  template <typename T> inline LineOfDefinitionOfComputableFunction( const VariableSymbol<T>& x , const ExpressionOfComputableFunction<T>& t );
  template <typename T> inline LineOfDefinitionOfComputableFunction( const VariableSymbol<T>& x , const T& t );
  
  // IF
  inline LineOfDefinitionOfComputableFunction( const int& dummy , const ConditionOfComputableFunction& condition , const LineOfDefinitionOfComputableFunction<void>& line );
  template <typename Ret1 , typename Ret2 , typename... ARGS> inline LineOfDefinitionOfComputableFunction( const Dummy<Ret1,Ret2,ARGS...>& dummy , const ConditionOfComputableFunction& condition , const Ret1& line1 , const Ret2& line2 , const ARGS&... lines );

  // FINISH
  inline LineOfDefinitionOfComputableFunction();
  
};
