// c:/Users/user/Documents/Programming/Mathematics/Function/Computable/Definition/Line/Void/a.hpp

#pragma once
#include "../a.hpp"

template <>
class LineOfDefinitionOfComputableFunction<void> :
  public SyntaxOfComputableFunction
{

public:
  using type = void;

  template <typename... Rets>
  using Dummy = typename enable_if<IsValidListOfLines<void,Rets...>::value,int>::type;


public:
  inline LineOfDefinitionOfComputableFunction( const LineOfDefinitionOfComputableFunction<void>& line ) = default;
  template <typename... Rets> inline LineOfDefinitionOfComputableFunction( const Dummy<Rets...>& dummy , const Rets&... lines );


  // PUT
  template <typename T1, typename T2> inline LineOfDefinitionOfComputableFunction( const VariableSymbol<T1>& x , const T2& t );
  
  // IF
  inline LineOfDefinitionOfComputableFunction( const int& dummy , const ConditionOfComputableFunction& condition , const LineOfDefinitionOfComputableFunction<void>& line );
  template <typename Ret1 , typename Ret2 , typename... Rets> inline LineOfDefinitionOfComputableFunction( const Dummy<Ret1,Ret2,Rets...>& dummy , const ConditionOfComputableFunction& condition , const Ret1& line1 , const Ret2& line2 , const Rets&... lines );

  // FINISH
  inline LineOfDefinitionOfComputableFunction();
  
};

template <typename T1, typename T2> inline LineOfDefinitionOfComputableFunction<void> PUT( const VariableSymbol<T1>& x , const T2& t );


DECLARATION_OF_GLOBAL_CONSTANT_STRING_FOR_SYMBOL( Put );
DECLARATION_OF_GLOBAL_CONSTANT_STRING_FOR_SYMBOL( Finish );
